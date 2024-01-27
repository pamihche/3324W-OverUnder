#include "autonmous-defensive.h"
#include "vex.h"

void defensive_awp_nine_points()
{
    chassis.setDefaultConstants();

   chassis.set_turn_constants(9, 0.25, 0, 1.5, 0);
   chassis.turn_settle_time = 0;
   chassis.turn_settle_error = 5;
   //chassis.heading_kp = 3.5;
   chassis.drive_distance(26.0);
   chassis.turn_to_angle(45);
   MotorIntake.spin(reverse, 60, vex::velocityUnits::pct);
   chassis.drive_distance(4);
   wait(0.4, vex::sec);
   MotorIntake.stop();
   chassis.turn_to_angle(-135);
   chassis.drive_distance(-12.5);
   chassis.drive_max_voltage = 8;
   chassis.drive_distance(12);
   chassis.turn_to_angle(180);

   
   chassis.drive_distance(17);

   // RightBackArm.set(true);
    wait(0.35, vex::sec);
  
   chassis.swing_max_voltage  = 12;
   chassis.swing_settle_error = 0.2;
   chassis.swing_settle_time  = 100;
   
   chassis.right_swing_to_angle(-220);
   //RightBackArm.set(false);





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