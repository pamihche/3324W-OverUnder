
#pragma once
#include "vex.h"

class SmartDrive : public Drive
{

private:
    int  driveMode;
    int  slew(int speed);
    void arc(bool mirror, int arc_length, double rad, int max, int type);

public:
    SmartDrive(enum::drive_setup drive_setup, motor_group DriveL, motor_group DriveR, int gyro_port, float wheel_diameter, float wheel_ratio, float gyro_scale, int DriveLF_port, int DriveRF_port, int DriveLB_port, int DriveRB_port, int ForwardTracker_port, float ForwardTracker_diameter, float ForwardTracker_center_distance, int SidewaysTracker_port, float SidewaysTracker_diameter, float SidewaysTracker_center_distance);
    ~SmartDrive();

    void setDefaultConstants(void);
    void setDefaultOdometryConstants(void);

    void arc_left_turn(int length, double rad, int max = 100, int type = 0);
    void arc_right_turn(int length, double rad, int max = 100, int type = 0);
    void setDriveTrainBrakeMode(vex::brakeType brakeMode);

    void swingWithScalarSpeed(float distance, float heading, float drive_max_voltage, float speedratio, bool isRight);


    //void sCurveLeft(int arc1, int mid, int arc2, int max = 100);

};





