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

	//gearSetting


}

void SmartDrive::arc_left_turn(int length, double rad, int max, int type)
{
	this->arc(false, length, rad, max, type);
}


void SmartDrive::arc_right_turn(int length, double rad, int max, int type)
{
	this->arc(true, length, rad, max, type);
}

// void SmartDrive::sCurveLeft(int arc1, int mid, int arc2, int max)
// {
// 	this->arc(false, arc1, 1, max, 1);
 
// 	//middle movement
// 	this->drive_max_voltage = 8;
// 	this->drive_distance(mid);

//   //final arc
//   this->arc(true, arc2, 1, max, 2);
// }



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


SmartDrive::~SmartDrive()
{}


