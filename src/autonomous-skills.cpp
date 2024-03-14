#include "autonomous-skills.h"
#include "vex.h"




void states_programming_skills_v2()
{
    vex::task wingsTask;

    chassis.setDefaultOdometryConstants();

    chassis.set_swing_constants(8, .45, 0.00070, 2.3, 15);

    chassis.set_coordinates(0,0,0);
    chassis.set_drive_constants(12, 4, 0, 20, 0);

    
    chassis.rightWideSwing(26.5, 315, 8, 0.5);
	MotorIntake.spin(reverse, 600, rpm);
	chassis.leftWideSwing(19.5, 0, 8, 1.6);
	MotorIntake.stop();

	chassis.swing_settle_error = 0.5;
	chassis.swing_max_voltage  = 12;
	chassis.swing_settle_time  = 300;
	chassis.swing_timeout      = 1000;

		
	chassis.swing_max_voltage = 10;
	chassis.swing_settle_error = 0;
	chassis.left_swing_to_angle(-110); 
	chassis.drive_distance(8.5);

    LeftFrontWing.set(true);
    catapult1.spin(vex::forward, 75 * 120, voltageUnits::mV);
    wait(24, sec);
    catapult1.spin(vex::forward, 0, voltageUnits::mV);
    
    LeftFrontWing.set(false);

    chassis.drive_to_point(5, 13.5);
    chassis.turn_to_angle(-90);
    chassis.drive_max_voltage  = 8.0;
    chassis.drive_to_point(67.5, 12);

    chassis.drive_timeout      = 1200;
    chassis.drive_settle_error = 5;
    chassis.leftWideSwing(-54.9, 180, 10, 1.7);
   

    chassis.drive_distance(11, 8, 180);
    chassis.drive_distance(-12.825, 12, 180);
// chassis.left_swing_to_angle(-80);
// chassis.drive_distance(32, 10, -80);
    
    
chassis.set_drive_constants(12, 4, 0, 20, 0);
chassis.drive_timeout  = 3000;
chassis.leftWideSwing(67, -5, 12, 0.65); 
chassis.left_swing_to_angle(55);

display_odomentry_info(0);

    // chassis.left_swing_to_angle(57.5);
    // chassis.drive_distance(25, 10, 90);

    wingsTask =  vex::task([](){

    wait(0.3, sec); 
    LeftFrontWing.set(true);
        return 0;
    });

    chassis.drive_timeout = 5000;
    chassis.leftWideSwing(60.5, 90, 7, 2.1);

    LeftFrontWing.set(false);
    wingsTask.stop();

    chassis.drive_to_point(50.5, 59.5, 6);
    display_odomentry_info(0);
    chassis.turn_to_point(53.5, 88);
    chassis.drive_to_point(53.5, 88);
    display_odomentry_info(0);
    chassis.right_swing_to_angle(90);
    RightFrontWing.set(true);
    chassis.drive_distance(37, 12, 90);
    RightFrontWing.set(false);
    chassis.drive_to_point(50.5, 66);
    display_odomentry_info(0);
    chassis.turn_to_angle(90);
    RightFrontWing.set(true);
    LeftFrontWing.set(true);
    chassis.drive_distance(37, 12, 90);
    RightFrontWing.set(false);
    LeftFrontWing.set(false);
    chassis.left_swing_to_angle(0);
    chassis.drive_distance(45, 10, 0.0);
    chassis.turn_to_angle(45);
    chassis.drive_distance(15.25, 10, 45);
    chassis.left_swing_to_angle(135);
    chassis.leftWideSwing(22.5, 180, 12, 0.75);
    chassis.drive_distance(-10, 8, 180);
    chassis.drive_distance(12, 12, 180);
    chassis.drive_distance(-8);
    // chassis.drive_to_point(52.5, 95.25);
    // chassis.right_swing_to_angle(-90);
    // chassis.drive_distance(-24, 10, -90);
    // chassis.turn_to_angle(0);
    // chassis.drive_distance(16, 8, 0.0);
    // chassis.turn_to_angle(-55);
    // chassis.rightWideSwing(-33.333, 0, 10, 2);
    // chassis.drive_distance(10, 8, 0.0);
    // chassis.drive_distance(-12, 10, 0.0);
    // 48.5, 52.1
}


void google_programming_skills()
{
    chassis.setDefaultOdometryConstants();

    chassis.set_swing_constants(8, .45, 0.00070, 2.3, 15);

    chassis.set_coordinates(0,0,0);
    chassis.set_drive_constants(12, 4, 0, 20, 0);

    // chassis.rightWideSwing(25.5, 315, 8, 0.5);
    // MotorIntake.spin(reverse, 600, rpm);
    // chassis.leftWideSwing(19.5, 0, 8, 1.6);
    // MotorIntake.stop();

    // chassis.swing_settle_error = 0.5;
    // chassis.swing_max_voltage  = 12;
    // chassis.swing_settle_time  = 300;
    // chassis.swing_timeout      = 1000;

   
    // chassis.swing_max_voltage = 10;
    // chassis.swing_settle_error = 0;
    // chassis.left_swing_to_angle(-115); //  it was -110
    // chassis.drive_distance(8.1); // it was 8

    chassis.rightWideSwing(23.5, 315, 8, 0.5);
	MotorIntake.spin(reverse, 600, rpm);
	chassis.leftWideSwing(19.5, 0, 8, 1.6);
	MotorIntake.stop();

	chassis.swing_settle_error = 0.5;
	chassis.swing_max_voltage  = 12;
	chassis.swing_settle_time  = 300;
	chassis.swing_timeout      = 1000;

		
	chassis.swing_max_voltage = 10;
	chassis.swing_settle_error = 0;
	chassis.left_swing_to_angle(-110); //  it was -110
	chassis.drive_distance(8.5);

    LeftFrontWing.set(true);
    catapult1.spin(vex::forward, 75 * 120, voltageUnits::mV);
    wait(2, sec);
    catapult1.spin(vex::forward, 0, voltageUnits::mV);
    
    LeftFrontWing.set(false);
//wait(250, msec);
 //chassis.drive_settle_error = 3.9; 

    chassis.drive_to_point(5, 12);
    //chassis.turn_kp = 3.7;
    chassis.turn_to_angle(-90);
    chassis.drive_max_voltage  = 8.0;
    chassis.drive_to_point(67.5, 12);

    chassis.drive_timeout      = 1200;
    chassis.drive_settle_error = 5;
    chassis.leftWideSwing(-54.9, 180, 10, 1.7);
   

    chassis.drive_distance(11, 8, 180);
    chassis.drive_distance(-11.5, 12, 180);

    chassis.set_drive_constants(12, 4, 0, 20, 0);
    chassis.drive_timeout  = 3000;

    chassis.leftWideSwing(57, -5, 7.5, 2.6); 

    chassis.left_swing_to_angle(55);

    chassis.drive_to_point(50.375, 53.825, 8);

    MotorIntake.spin(reverse, 600, rpm);
    LeftFrontWing.set(true);
    
    chassis.turn_to_angle(58);
    chassis.leftWideSwing(30, 90, 10, 2);
    
    LeftFrontWing.set(false);
     //wait(250, msec);
    MotorIntake.stop();

    chassis.drive_distance(-32, 10, 95);
    chassis.turn_to_angle(90);
    MotorIntake.spin(reverse, 600, rpm);
    LeftFrontWing.set(true);
    RightFrontWing.set(true);
   // wait(250, msec);
    chassis.drive_distance(30, 10, 90);
    
    LeftFrontWing.set(false);
    RightFrontWing.set(false);
    wait(250, msec);
    MotorIntake.stop();


    chassis.rightWideSwing(-39, 141.5, 8, 2.5);
    chassis.turn_to_angle(105);
    RightFrontWing.set(true);
    chassis.rightWideSwing(30, 90, 10, 2.3);
    RightFrontWing.set(false);

    chassis.left_swing_to_angle(0);
    chassis.drive_to_point(70, 132.5, 8);

   
    chassis.turn_to_angle(292.5);
    chassis.rightWideSwing(-40, 0, 10, 1.775);
    chassis.drive_distance(12, 8, 0.0);

    chassis.drive_distance(-12, 8, 0.0);
    chassis.drive_to_point(70, 135);
    chassis.turn_to_angle(-90);


    HangingPneumatics.open();
    chassis.drive_max_voltage = 10;
    chassis.drive_distance(44);
    HangingPneumatics.close();

}





void states_programming_skills_v1()
{
    vex::task wingsTask;

    chassis.setDefaultOdometryConstants();

    chassis.set_swing_constants(8, .45, 0.00070, 2.3, 15);

    chassis.set_coordinates(0,0,0);
    chassis.set_drive_constants(12, 4, 0, 20, 0);

    
    chassis.rightWideSwing(26.5, 315, 8, 0.5);
	MotorIntake.spin(reverse, 600, rpm);
	chassis.leftWideSwing(19.5, 0, 8, 1.75);
	MotorIntake.stop();

	chassis.swing_settle_error = 0.5;
	chassis.swing_max_voltage  = 12;
	chassis.swing_settle_time  = 300;
	chassis.swing_timeout      = 1000;

		
	chassis.swing_max_voltage = 10;
	chassis.swing_settle_error = 0;
	chassis.left_swing_to_angle(-115); 
	chassis.drive_distance(8.5);

    LeftFrontWing.set(true);
   catapult1.spin(vex::forward, 70 * 120, voltageUnits::mV);
    wait(24, sec);
   catapult1.spin(vex::forward, 0, voltageUnits::mV);
    
    LeftFrontWing.set(false);

    chassis.drive_to_point(5, 13.5);
    chassis.turn_to_angle(-90);
    chassis.drive_max_voltage  = 8.0;
    chassis.drive_to_point(67.5, 12);

    chassis.drive_timeout      = 1200;
    chassis.drive_settle_error = 5;
    chassis.leftWideSwing(-54.9, 180, 10, 1.7);
   

    chassis.drive_distance(11, 8, 180);
    chassis.drive_distance(-12.825, 12, 180);
    chassis.left_swing_to_angle(-80);
    //chassis.drive_distance(32, 10, -80);
    chassis.drive_distance(32, 10, -80);
    //chassis.left_swing_to_angle(50);
    //chassis.left_swing_to_angle(-80);
    //chassis.drive_distance(12, 10, -80);
    // chassis.left_swing_to_angle(57.5);
    // chassis.drive_distance(25, 10, 90);

    // wingsTask =  vex::task([](){

    // wait(0.3, sec); 
    // LeftFrontWing.set(true);
    //     return 0;

    // });

    chassis.drive_timeout = 5000;
    MotorIntake.spin(reverse, 600, rpm);
    chassis.leftWideSwing(60.5, 90, 12, 0.5);

  

    MotorIntake.stop();
    LeftFrontWing.set(false);

    wingsTask.stop();

    chassis.drive_to_point(50.5, 59.5, 6);
    display_odomentry_info(0);
    chassis.turn_to_point(53.5, 88);
    chassis.drive_to_point(53.5, 88);
    display_odomentry_info(0);
    chassis.right_swing_to_angle(90);
    RightFrontWing.set(true);
    MotorIntake.spin(reverse, 600, rpm);
    chassis.drive_distance(37, 12, 90);
    MotorIntake.stop();
    RightFrontWing.set(false);
    chassis.drive_to_point(50.5, 66);
    display_odomentry_info(0);
    chassis.turn_to_angle(90);
    RightFrontWing.set(true);
    LeftFrontWing.set(true);
    MotorIntake.spin(reverse, 600, rpm);
    chassis.drive_distance(37, 12, 90);
    MotorIntake.stop();
    RightFrontWing.set(false);
    LeftFrontWing.set(false);
    chassis.left_swing_to_angle(0);
    chassis.drive_distance(60, 11, 0.0);
    // chassis.turn_to_angle(45);
    // chassis.drive_distance(15.25, 10, 45);
    chassis.left_swing_to_angle(135);
    MotorIntake.spin(reverse, 600, rpm);
    chassis.leftWideSwing(35.5, 180, 12, 1.2);
    chassis.drive_distance(-10, 8, 180);
    chassis.drive_distance(12, 12, 180);
    chassis.drive_distance(-14);
    MotorIntake.stop();
    chassis.turn_to_angle(-100);
    chassis.rightWideSwing(80, 180, 12, 1.3);
    chassis.rightWideSwing(30, 135, 10, 0.9);
   // chassis.turn_to_angle(180);
    
    // chassis.drive_to_point(52.5, 95.25);
    // chassis.right_swing_to_angle(-90);
    // chassis.drive_distance(-24, 10, -90);
    // chassis.turn_to_angle(0);
    // chassis.drive_distance(16, 8, 0.0);
    // chassis.turn_to_angle(-55);
    // chassis.rightWideSwing(-33.333, 0, 10, 2);
    // chassis.drive_distance(10, 8, 0.0);
    // chassis.drive_distance(-12, 10, 0.0);
    // 48.5, 52.1
}


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
    chassis.turn_to_angle(90);
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



// chassis.Gyro.calibrate();
// wait(5, sec);

    chassis.setDefaultOdometryConstants();
    chassis.set_swing_constants(8, .45, 0.00070, 2.3, 15);

  //  chassis.setDriveTrainBrakeMode(brake);
    chassis.set_coordinates(0,0,0);

    chassis.set_drive_constants(12, 4, 0, 20, 0);

    chassis.rightWideSwing(25.5, 315, 8, 0.5);

    MotorIntake.spin(reverse, 600, rpm);
    chassis.leftWideSwing(19.5, 0, 8, 1.6);
    MotorIntake.stop();

    chassis.swing_settle_error = 0.5;
    chassis.swing_max_voltage = 12;
    chassis.swing_settle_time = 300;
    chassis.swing_timeout = 1000;

   
    chassis.swing_max_voltage = 10;
    chassis.swing_settle_error = 0;
    chassis.left_swing_to_angle(-110);
    chassis.drive_distance(8);


    
    LeftFrontWing.set(true);
    
    wait(1, sec);

    LeftFrontWing.set(false);
    

//chassis.drive_settle_error = 3.9; 

    chassis.drive_to_point(7, 12);
    
    chassis.turn_to_angle(-90);
    chassis.drive_max_voltage = 8;
    chassis.drive_to_point(67.5, 12);

   

    chassis.drive_timeout = 1200;
    chassis.drive_settle_error = 5;
    chassis.leftWideSwing(-54.9, 180, 10, 1.575);
   

    chassis.drive_distance(11, 8, 180);
    chassis.drive_distance(-11.5, 12, 180);

    chassis.set_drive_constants(12, 4, 0, 20, 0);
    chassis.drive_timeout  = 3000;



 chassis.leftWideSwing(70, -5, 7.5, 2.5);

/*
 
//chassis.turn_to_angle(90, 8);
chassis.drive_distance(-28, 9, 45) ;
LeftFrontWing.open();
chassis.leftWideSwing(30, 90, 10, 2.2);
LeftFrontWing.close();


    chassis.drive_distance(-32, 10, 100);
    chassis.turn_to_angle(90);
    MotorIntake.spin(reverse, 600, rpm);
    LeftFrontWing.open();
    RightFrontWing.open();
    chassis.drive_distance(30, 10, 90);

    LeftFrontWing.close();
    RightFrontWing.close();
    
    MotorIntake.stop();
    chassis.rightWideSwing(-40, 141.5, 8, 2.5);
    chassis.turn_to_angle(105);
    RightFrontWing.set(true);
    chassis.rightWideSwing(30, 90, 10, 2.3);
    RightFrontWing.set(false);
    chassis.left_swing_to_angle(0);
    chassis.turn_to_angle(0);


   
    chassis.drive_max_voltage = 10;
    chassis.drive_to_point(70, 132.5);
    chassis.turn_to_angle(292.5);
    chassis.rightWideSwing(-44, 0, 10, 1.775);
    chassis.drive_distance(12, 8, 0.0);

   chassis.drive_distance(-12, 8, 0.0);
   chassis.drive_to_point(70, 132.5);
   chassis.turn_to_angle(-90);
   HangingPneumatics.open();
   chassis.drive_max_voltage = 4;
   chassis.drive_distance(40);
    HangingPneumatics.close();



*/



/*
//chassis.leftWideSwing(57, -5, 7.5, 2.5); 
   // LeftFrontWing.set(true);
    chassis.left_swing_to_angle(55);

    chassis.drive_max_voltage = 8;
    chassis.drive_to_point(50.375, 56.825);




    Brain.Screen.print(chassis.get_absolute_heading());
    MotorIntake.spin(reverse, 600, rpm);
    LeftFrontWing.set(true);
    
    chassis.turn_to_angle(58);
    chassis.leftWideSwing(30, 90, 10, 2.2);
    

    LeftFrontWing.set(false);
    MotorIntake.stop();



    chassis.drive_distance(-32, 10, 100);
    chassis.turn_to_angle(90);
    MotorIntake.spin(reverse, 600, rpm);
     LeftFrontWing.set(true);
    RightFrontWing.set(true);
    chassis.drive_distance(30, 10, 90);
    LeftFrontWing.set(false);
    RightFrontWing.set(false);
    MotorIntake.stop();
    chassis.rightWideSwing(-40, 141.5, 8, 2.5);
    chassis.turn_to_angle(105);
    RightFrontWing.set(true);
    chassis.rightWideSwing(30, 90, 10, 2.3);
    RightFrontWing.set(false);
    chassis.left_swing_to_angle(0);
    chassis.drive_max_voltage = 10;
    chassis.drive_to_point(70, 132.5);
    chassis.turn_to_angle(292.5);
    chassis.rightWideSwing(-44, 0, 10, 1.775);
    chassis.drive_distance(12, 8, 0.0);

   chassis.drive_distance(-12, 8, 0.0);
   chassis.drive_to_point(70, 132.5);
   chassis.turn_to_angle(-90);
   HangingPneumatics.open();
   chassis.drive_max_voltage = 4;
   chassis.drive_distance(40);
    HangingPneumatics.close();


*/
   

}


void backup_skills_auton_1()
{
    chassis.setDefaultOdometryConstants();
    chassis.set_swing_constants(8, .45, 0.00070, 2.3, 15);

  
    chassis.set_coordinates(0,0,0);

    chassis.set_drive_constants(12, 4, 0, 20, 0);

    chassis.rightWideSwing(25.5, 315, 8, 0.5);

    MotorIntake.spin(reverse, 600, rpm);
    chassis.leftWideSwing(19.5, 0, 8, 1.6);
    MotorIntake.stop();

    chassis.swing_settle_error = 0.5;
    chassis.swing_max_voltage = 12;
    chassis.swing_settle_time = 300;
    chassis.swing_timeout = 1000;

   
   
   chassis.swing_max_voltage = 10;
    chassis.swing_settle_error = 0;
    chassis.left_swing_to_angle(-110);
    chassis.drive_distance(8);

    LeftFrontWing.set(true);
    
    wait(2, sec);

    LeftFrontWing.set(false);



 //chassis.drive_settle_error = 3.9; 

    chassis.drive_to_point(5, 12);
    chassis.turn_to_angle(-90);
    chassis.drive_max_voltage = 8.0;
    chassis.drive_to_point(67.5, 12);
    // chassis.turn_to_angle(-90);
    // chassis.drive_max_voltage = 8;


    //chassis.drive_settle_time = 1;
    chassis.drive_timeout = 1200;
    chassis.drive_settle_error = 5;
    chassis.leftWideSwing(-54.9, 180, 10, 1.575);
   

    chassis.drive_distance(11, 8, 180);
    chassis.drive_distance(-11.5, 12, 180);

    chassis.set_drive_constants(12, 4, 0, 20, 0);
    chassis.drive_timeout  = 3000;


 //chassis.leftWideSwing(70, -5, 7.5, 2.5);
//chassis.turn_to_angle(90, 8);
//chassis.drive_distance(-28, 9, 45) ;
//chassis.turn_to_angle(45, 9);


chassis.leftWideSwing(57, -5, 7.5, 2.5); 
   // LeftFrontWing.set(true);
    chassis.left_swing_to_angle(55);

    chassis.drive_max_voltage = 8;
    chassis.drive_to_point(50.375, 56.825);




    Brain.Screen.print(chassis.get_absolute_heading());
    MotorIntake.spin(reverse, 600, rpm);
    LeftFrontWing.set(true);
    
    chassis.turn_to_angle(58);
    chassis.leftWideSwing(30, 90, 10, 2.2);
    

    LeftFrontWing.set(false);
    MotorIntake.stop();



    chassis.drive_distance(-32, 10, 100);
    chassis.turn_to_angle(90);
    MotorIntake.spin(reverse, 600, rpm);
     LeftFrontWing.set(true);
    RightFrontWing.set(true);
    chassis.drive_distance(30, 10, 90);
    LeftFrontWing.set(false);
    RightFrontWing.set(false);
    MotorIntake.stop();


    chassis.rightWideSwing(-39, 141.5, 8, 2.5);
    chassis.turn_to_angle(105);
    RightFrontWing.set(true);
    chassis.rightWideSwing(30, 90, 10, 2.3);
    RightFrontWing.set(false);

    chassis.left_swing_to_angle(0);
    chassis.drive_max_voltage = 8;
    chassis.drive_to_point(70, 132.5);

   
    chassis.turn_to_angle(292.5);
    chassis.rightWideSwing(-44, 0, 10, 1.775);
    chassis.drive_distance(12, 8, 0.0);

   chassis.drive_distance(-12, 8, 0.0);
   chassis.drive_to_point(70, 135);
   chassis.turn_to_angle(-90);


   HangingPneumatics.open();
   chassis.drive_max_voltage = 6;
   chassis.drive_distance(40);
    HangingPneumatics.close();



   

}









void test()
{
    chassis.setDefaultOdometryConstants();
    LeftFrontWing.set(true);
    RightFrontWing.set(true);
    chassis.drive_max_voltage = 12;
    chassis.drive_distance(40);
    LeftFrontWing.set(false);
    RightFrontWing.set(false);
    chassis.drive_distance(-20);
    chassis.drive_distance(25);
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
