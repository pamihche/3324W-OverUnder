//#include "autonomous-offensive.h"
#include "vex.h"

void offensive_awp_four_triballs()
{
  chassis.set_coordinates(0,0,0);
  //wings.set(true);  
  chassis.drive_distance(24);
  //wings.set(false);
  chassis.turn_to_angle(90);
  MotorIntake.spin(reverse, 600, rpm);
  chassis.drive_distance(12);
  MotorIntake.stop();
  chassis.drive_distance(-18);
  chassis.turn_to_angle(-120);
  MotorIntake.spin(vex::forward, 600, rpm);
  chassis.drive_distance(31);
  MotorIntake.stop();
  chassis.drive_distance(-4);
  chassis.turn_to_angle(60);
  MotorIntake.spin(reverse, 525, rpm);
  chassis.drive_distance(10);
  MotorIntake.stop();
  chassis.turn_to_angle(-30);
  MotorIntake.spin(vex::forward, 600, rpm);
  chassis.drive_distance(25);
  MotorIntake.stop();
  chassis.turn_to_angle(90);
  MotorIntake.spin(reverse, 600, rpm);
  wings.set(true);
  chassis.drive_distance(36);
  MotorIntake.stop();
  wings.set(false);
}  