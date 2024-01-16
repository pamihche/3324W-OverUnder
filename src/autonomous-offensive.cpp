#include "autonomous-offensive.h"
#include "vex.h"

using namespace vex;

void offensive_awp_four_triballs()
{
  chassis.set_coordinates(0,0,0);
  //wings.set(true);  
  chassis.drive_to_point(0, 54);
  //wings.set(false);
  chassis.turn_to_angle(90);
  //MotorIntake.spin(reverse, 300, rpm);
  chassis.drive_max_voltage = 12;
  chassis.drive_to_point(17, chassis.get_Y_position());
  
  chassis.drive_timeout = 100;
  //MotorIntake.stop();
  chassis.drive_distance(-50);
  chassis.drive_max_voltage = 7;
  chassis.drive_timeout = 5000;
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