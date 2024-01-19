#include "autonomous-skills.h"
#include "vex.h"

void main_skill_auton()
{
   chassis.right_swing_to_angle(-90);
}

void backup_skills_auton()
{
    chassis.drive_distance(-24);
    chassis.drive_distance(24);
}