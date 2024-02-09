#include "autonomous-skills.h"
#include "vex.h"

void main_skill_auton()
{
    chassis.setDefaultOdometryConstants();

   // chassis.set_swing_constants(12, .45, 0.00070, 2.3, 15);
    // chassis.swing_settle_error      = 0.5;
    // chassis.swing_max_voltage       = 9;
    // chassis.swing_settle_time       = 100;
    // chassis.drive_settle_time       = 100;
    // chassis.turn_settle_error = 2;
    // chassis.swing_timeout = 1000;
    chassis.setDriveTrainBrakeMode(brake);
    chassis.set_coordinates(0, 0, 330);
    chassis.drive_max_voltage = 8;
    //chassis.drive_settle_error = 6;
   // chassis.turn_to_angle(335);
    chassis.drive_distance(9.5, 335);
    MotorIntake.spin(reverse, 475, rpm);
    wait(0.80, sec);
    MotorIntake.stop();
   // chassis.drive_distance(7.5, 330);
   // chassis.drive_settle_error = 0.5;
    //chassis.turn_to_angle(43);
   
    //chassis.drive_distance(-4);
    // chassis.turn_settle_time = 0;
    chassis.turn_to_angle(-115);
    chassis.drive_distance(4);
    LeftFrontWing.set(true);
    wait(2, sec);
    LeftFrontWing.set(false);
    chassis.drive_distance(-2);
    chassis.turn_to_angle(170);
    Brain.Screen.clearScreen();
    Brain.Screen.print(chassis.get_absolute_heading());
    chassis.heading_kp = 0.2;
    chassis.drive_distance(-9.5, 170);
    chassis.heading_kp = 0.4;
    chassis.turn_to_point(5, 6);
    chassis.drive_to_point(5, 6);
    Brain.Screen.newLine();
    Brain.Screen.print(chassis.get_absolute_heading());
    chassis.turn_to_angle(80);
    // chassis.drive_settle_time  = 10;
    // LeftFrontWing.set(true);
    // wait(2, sec);
    // LeftFrontWing.set(false);
    // chassis.turn_to_angle(-170);
    // chassis.drive_settle_error = 5;
    // chassis.drive_to_point(7, 34);
    //chassis.drive_settle_time = 0;
    // vex::task intakeSideGoalListener = vex::task( [](){
    //     while(true)
    //     {
    //         if(!MotorIntake.isSpinning())
    //         {
    //             wait(0.00, sec);
    //             MotorIntake.spin(vex::reverse, 600, rpm);
    //             // wait(0.125, sec);
    //             // MotorIntake.spin(vex::forward, 600, rpm);
    //         }
    //         vex::task::yield();
    //         vex::task::sleep(25);
    //     }
    //     return 0;
    // });
    // chassis.drive_max_voltage = 12;
    // chassis.drive_distance(13.5);
    // intakeSideGoalListener.stop();
    // MotorIntake.stop();
    // //chassis.drive_settle_time = 0;
    // chassis.drive_distance(-5);
    // chassis.swing_timeout = 1000;
    // chassis.left_swing_to_angle(-75);

   
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

    // chassis.drive_to_point(0, 0, 12, 12);
    //chassis.left_swing_to_angle(90);


    chassis.leftWideSwing(30, -90, 10, 0.5);
    chassis.rightWideSwing(-30, -90, 10, 0.5);


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


    // vex::task  testTask = vex::task( [](){

    //     while ( true )
    //     {
    //         if(RightFrontWing.value()){
    //             wait(0.45, sec);
    //             RightFrontWing.set(false);
    //         } 
    //         vex::task::yield();
    //         vex::task::sleep(25);
    //     }

    //     return 0;
    // });

    // testTask.stop();

    // testTask = vex::task( [](){
    //         return 1; 
    //     });
    // testTask.stop();
}
