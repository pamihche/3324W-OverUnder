#include "SmartDrive.h"


SmartDrive::SmartDrive(enum::drive_setup drive_setup, motor_group DriveL, motor_group DriveR, int gyro_port, float wheel_diameter, float wheel_ratio, float gyro_scale, int DriveLF_port, int DriveRF_port, int DriveLB_port, int DriveRB_port, int ForwardTracker_port, float ForwardTracker_diameter, float ForwardTracker_center_distance, int SidewaysTracker_port, float SidewaysTracker_diameter, float SidewaysTracker_center_distance) 
: Drive( drive_setup,  DriveL,  DriveR,  gyro_port,  wheel_diameter,  wheel_ratio,  gyro_scale,  DriveLF_port,  DriveRF_port,  DriveLB_port,  DriveRB_port,  ForwardTracker_port,  ForwardTracker_diameter,  ForwardTracker_center_distance,  SidewaysTracker_port,  SidewaysTracker_diameter,  SidewaysTracker_center_distance)
{

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

void SmartDrive::arc(bool mirror, int arc_length, double rad, int max, int type)
{
	
	this->DriveL.resetPosition();
	this->DriveR.resetPosition();

	int time_step = 0;
int driveMode = 0;
	bool reversed = false;


  //reverse the movement if the length is negative
	if(arc_length < 0)
	{
		reversed = true;
		arc_length = -arc_length;
	}


	





}

SmartDrive::~SmartDrive()
{}


