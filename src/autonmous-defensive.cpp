#include "autonmous-defensive.h"
#include "vex.h"

void defensive_awp_nine_points()
{
    // chassis.drive_distance(18);
    // chassis.turn_to_angle(45);
    // MotorIntake.spin(reverse, 600, rpm);
    // wait(0.5, sec);
    // MotorIntake.stop();
    // chassis.turn_to_angle(-135);
    // chassis.drive_distance(-4);
    // chassis.drive_distance(8);
    chassis.drive_distance(16);
    
}

void defensive_awp_seventeen_points()
{
    chassis.turn_to_angle(90);
}

void defensive_awp_fourteen_points()
{
    chassis.drive_distance(12);
    chassis.turn_to_angle(180);
}