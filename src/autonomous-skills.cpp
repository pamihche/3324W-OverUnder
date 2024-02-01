#include "autonomous-skills.h"
#include "vex.h"

void main_skill_auton()
{
    chassis.set_swing_constants(12, .45, 0.00070, 2.3, 15);
    chassis.swing_settle_error      = 0.5;
    chassis.swing_max_voltage       = 9;
    chassis.swing_settle_time       = 100;
    chassis.drive_settle_time       = 100;
    chassis.swing_timeout = 3000;
    chassis.set_coordinates(0, 0, 0);
    chassis.drive_max_voltage = 12;
    chassis.drive_distance(29);
    chassis.left_swing_to_angle(45);
    chassis.drive_settle_time  = 10;
    //chassis.drive_settle_time = 0;
    chassis.drive_distance(12);
    //chassis.drive_settle_time = 0;
    chassis.drive_distance(-10);
    chassis.left_swing_to_angle(-85);

   
   //x = 6.9 y = 35.1;

}

void backup_skills_auton()
{
   
}

void just_test_skills_auton()
{

    chassis.setDefaultOdometryConstants();
    chassis.set_drive_constants(12, 4, 0, 20, 0);
    chassis.set_drive_exit_conditions(1.5, 0, 1000);

    chassis.drive_max_voltage = 5;

    //chassis.drive_distance(20 ,270, 6, 6);

    chassis.set_coordinates(0, 0, 0);

    chassis.drive_distance(20);

    // chassis.drive_to_point(0, 0, 12, 12);
    //chassis.left_swing_to_angle(90);


    chassis.leftWideSwing(-30, -90, 10, 0.5);
















    // auto openRighWingCallback = [] () -> int 
    // {
    //     while ( true )
    //     {
    //         wait(25, msec);
    //         if(!RightFrontWing.value())
    //             continue;
    //         wait(0.45, sec);
    //         RightFrontWing.set(false);
    //     }
            
    //     return 0;
    // };

    //vex::task  testTask = vex::task( openRighWingCallback );


    vex::task  testTask = vex::task( [](){

        while ( true )
        {
            if(RightFrontWing.value()){
                wait(0.45, sec);
                RightFrontWing.set(false);
            } 
            vex::task::yield();
            vex::task::sleep(25);
        }

        return 0;
    });

    testTask.stop();

    testTask = vex::task( [](){
            return 1; 
        });
    testTask.stop();
}
