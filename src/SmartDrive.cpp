#include "SmartDrive.h"
#include <cmath>
using namespace std;




SmartDrive::SmartDrive(enum::drive_setup drive_setup, motor_group DriveL, motor_group DriveR, int gyro_port, float wheel_diameter, float wheel_ratio, float gyro_scale, int DriveLF_port, int DriveRF_port, int DriveLB_port, int DriveRB_port, int ForwardTracker_port, float ForwardTracker_diameter, float ForwardTracker_center_distance, int SidewaysTracker_port, float SidewaysTracker_diameter, float SidewaysTracker_center_distance) 
: Drive( drive_setup,  DriveL,  DriveR,  gyro_port,  wheel_diameter,  wheel_ratio,  gyro_scale,  DriveLF_port,  DriveRF_port,  DriveLB_port,  DriveRB_port,  ForwardTracker_port,  ForwardTracker_diameter,  ForwardTracker_center_distance,  SidewaysTracker_port,  SidewaysTracker_diameter,  SidewaysTracker_center_distance)
{
	this->driveMode = 0;

}

void SmartDrive::setDefaultConstants(void)
{
	// Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
	this->set_drive_constants(10, 1.5, 0, 10, 0);
	this->set_heading_constants(6, .4, 0, 1, 0);
	this->set_turn_constants(12, .4, .03, 3, 15);
	this->set_swing_constants(12, .3, .001, 2, 15);

	// Each exit condition set is in the form (settle_error, settle_time, timeout).
	this->set_drive_exit_conditions(1.5, 300, 5000);
	this->set_turn_exit_conditions(1, 300, 3000);
	this->set_swing_exit_conditions(1, 300, 3000);
}

void SmartDrive::setDefaultOdometryConstants(void)
{
	this->setDefaultConstants();
	this->drive_max_voltage = 8;
	this->drive_settle_error = 3;

}


void SmartDrive::leftWideSwing(float distance, float heading, float drive_max_voltage, float speedratio)
{
	this->swingWithScalarSpeed(distance, heading, drive_max_voltage, speedratio, false);
}
void SmartDrive::rightWideSwing(float distance, float heading, float drive_max_voltage, float speedratio)
{
	this->swingWithScalarSpeed(distance, heading, drive_max_voltage, speedratio, true);
}


void SmartDrive::swingWithScalarSpeed(float distance, float heading, float drive_max_voltage, float speedratio, bool isRight)
{
	this->desired_heading = heading;
	
	PID drivePID(distance, drive_kp, drive_ki, drive_kd, drive_starti, drive_settle_error, drive_settle_time, drive_timeout);
	PID headingPID(reduce_negative_180_to_180(heading - this->get_absolute_heading()), heading_kp, heading_ki, heading_kd, heading_starti);
	
	float start_average_position = (this->get_left_position_in() + this->get_right_position_in()) / 2.0;
	float average_position = start_average_position;

  	while( ! drivePID.is_settled() )
	{
		average_position     = (this->get_left_position_in() + this->get_right_position_in()) / 2.0;
		
		float drive_error    = distance + start_average_position - average_position;
		float heading_error  = reduce_negative_180_to_180(heading - get_absolute_heading());
		
		float drive_output   = drivePID.compute(drive_error);
		float heading_output = headingPID.compute(heading_error);

		drive_output         = clamp(drive_output, -drive_max_voltage, drive_max_voltage);
		heading_output       = clamp(heading_output, -heading_max_voltage, heading_max_voltage);

		if(isRight)
		{
			this->drive_with_voltage((drive_output + heading_output) * speedratio, drive_output - heading_output);
		}
		else
		{
			this->drive_with_voltage(drive_output + heading_output, (drive_output - heading_output)*speedratio);
		}

	    task::sleep(10);
  }

  DriveL.stop(hold);
  DriveR.stop(hold);

}


void SmartDrive::arc_left_turn(int length, double rad, int max, int type)
{
	this->arc(false, length, rad, max, type);
}


void SmartDrive::arc_right_turn(int length, double rad, int max, int type)
{
	this->arc(true, length, rad, max, type);
}


void SmartDrive::arc(bool mirror, int arc_length, double rad, int max, int type)
{
	
	this->DriveL.resetPosition();
	this->DriveR.resetPosition();

	int time_step = 0;
	//int driveMode = 0;
	bool reversed = false;

	const double arcKP = .075;


  	//reverse the movement if the length is negative
	if(arc_length < 0)
	{
		reversed = true;
		arc_length = -arc_length;
	}

	if(type < 2)
	{
    	this->DriveL.stop();
    	this->DriveR.stop();
    	wait(10, vex::msec);
	}

	

	while(time_step < arc_length)
	{
		
		//speed
		int error = arc_length - time_step;
		int speed = error * arcKP;

		if(type == 1 || type == 2)
			speed = max;

		//speed limiting
		if(speed > max)
			speed = max;
		if(speed < -max)
			speed = -max;

		//prevent backtracking
		if(speed < 0)
			speed = 0;

		speed = slew(speed); //slew

		if(reversed)
			speed = -speed;

		double scaled_speed = speed*rad;

		if(type == 1)
			scaled_speed *= (double)time_step / arc_length;
		else if(type == 2)
			scaled_speed *= std::abs( 2 * ( 0.5 - (double)time_step / arc_length ));
		else if(type == 3)
			scaled_speed *= (1-(double)time_step/arc_length);

		//assign drive motor speeds

		this->DriveL.spin(fwd, mirror ? speed : scaled_speed, pct);
		this->DriveR.spin(fwd, mirror ? scaled_speed : speed, pct);




		// this->DriveL.spin(fwd, to_volt(mirror ? speed : scaled_speed), vex::volt);
		// this->DriveR.spin(fwd, to_volt(mirror ? scaled_speed : speed), vex::volt);



		//increment time step
		time_step += 10;
		wait(10, vex::msec);
	}

}

int SmartDrive::slew(int speed)
{
	const int accel_step  = 8; //smaller number = more slew
	const int deccel_step = 200; //200 = no slew
	const int arc_step    = 2; // acceleration for arcs

	static int lastSpeed = 0;
	int step;

	if(abs(lastSpeed) < abs(speed))
	{
		if(this->driveMode == 0)
		{
			step = arc_step;
		}
		else
		{
			step = accel_step;
		}
	}
	else
	{
		step = deccel_step;
	}

	if(speed > lastSpeed + step)
	{
		lastSpeed += step;
	}
	else if(speed < lastSpeed - step)
	{
		lastSpeed -= step;
	}
	else
	{
		lastSpeed = speed;
	}

  return lastSpeed;

}

void SmartDrive::setDriveTrainBrakeMode(vex::brakeType brakeMode)
{
	this->DriveL.setStopping(brakeMode);
	this->DriveR.setStopping(brakeMode);
}

void SmartDrive::control_tank(const vex::controller& primaryController) 
{

	float leftThrottle  = primaryController.Axis3.value();
	float rightThrottle = primaryController.Axis2.value();

	if( std::fabs(leftThrottle) < 5 )
		leftThrottle = 0;

	if( std::fabs(rightThrottle) < 5 )
		rightThrottle = 0;

 	this->DriveL.spin(fwd, (leftThrottle  * 12 / 100) , vex::voltageUnits::volt);
	this->DriveR.spin(fwd, (rightThrottle * 12 / 100) , vex::voltageUnits::volt);

 //  float leftthrottle = deadband(controller(primary).Axis3.value(), 5);
//   float rightthrottle = deadband(controller(primary).Axis2.value(), 5);

  //DriveL.spin(fwd, to_volt(leftthrottle), volt);
  //DriveR.spin(fwd, to_volt(rightthrottle), volt);

}

SmartDrive::~SmartDrive()
{}


