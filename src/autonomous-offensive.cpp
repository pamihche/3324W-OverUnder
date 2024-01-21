#include "autonomous-offensive.h"
#include "vex.h"

using namespace vex;

void offensive_awp_four_triballs()
{
    chassis.set_swing_constants(12, .45, 0.00070, 2.3, 15);
    chassis.set_turn_constants(9, 0.32, 0.2, 1.3, 0);
    chassis.turn_settle_time = 0;
    chassis.drive_settle_time = 100;
    chassis.swing_settle_error = 0.5;
    chassis.swing_max_voltage = 9;
    chassis.swing_settle_time = 300;
    chassis.swing_timeout = 250;
    Brain.Screen.clearScreen();
    chassis.set_coordinates(0, 0, 0);
    chassis.drive_max_voltage = 11;
    MotorIntake.spin(vex::forward, 600, rpm);
    frontWings.set(true);
    wait(150, msec);
    frontWings.set(false);
    chassis.drive_to_point(7, 65);
    MotorIntake.stop();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    chassis.right_swing_to_angle(-45);
    chassis.drive_distance(-32);
    chassis.drive_distance(24);

    chassis.set_swing_constants(7, .45, 0.00070, 2.3, 15);

    //chassis.right_swing_to_angle(-135);
    //chassis.turn_to_point(-10, 5);
    chassis.drive_max_voltage = 12;
    chassis.drive_to_point(-8, 2);
    chassis.turn_to_angle(90);
    chassis.drive_distance(17);
    chassis.turn_to_angle(45);
    MotorIntake.spin(reverse, 600, rpm);
    chassis.drive_distance(9);
    MotorIntake.stop();
    chassis.drive_distance(-3);
    chassis.turn_settle_time = 100;
    chassis.turn_to_angle(-133);
    chassis.drive_distance(-11.5);
    chassis.drive_distance(3.5);
    chassis.drive_max_voltage = 12;
    chassis.drive_settle_error = 9;
    chassis.drive_to_point(-12, 12);
    chassis.turn_to_angle(-45);
    chassis.drive_distance(30);
}  

void offensive_five_triballs()
{
  chassis.drive_distance(-24);
}

void offensive_six_triballs()
{
  chassis.left_swing_to_angle(90);
}