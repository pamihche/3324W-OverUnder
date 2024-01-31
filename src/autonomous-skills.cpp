#include "autonomous-skills.h"
#include "vex.h"

void main_skill_auton()
{
    chassis.set_swing_constants(12, .45, 0.00070, 2.3, 15);
    chassis.swing_settle_error = 0.5;
    chassis.swing_max_voltage = 9;
    chassis.swing_settle_time = 100;
    chassis.drive_settle_time = 100;
    chassis.swing_timeout = 3000;
    // chassis.set_coordinates(0, 0, 0);
    chassis.drive_max_voltage = 12;
    chassis.drive_distance(29);
    chassis.left_swing_to_angle(45);
    chassis.drive_distance(14);
    //chassis.drive_settle_time = 0;
    chassis.drive_distance(-10);
    chassis.left_swing_to_angle(-85);

   
   //x = 6.9 y = 35.1;

}

void backup_skills_auton()
{
    chassis.drive_distance(-24);
    chassis.drive_distance(24);
}