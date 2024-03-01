#include "autonmous-defensive.h"
#include "vex.h"

int testFunction()
{

	Brain.Screen.print("Running");
	Brain.Screen.newLine();

	while ( true )
	{
		wait(25, msec);

		if(!RightFrontWing.value())
			continue;

		wait(0.45, sec);

		RightFrontWing.set(false);

	}
		
	return 0;
}

void defensive_awp_nine_points()
{
    chassis.setDefaultConstants();
    chassis.set_coordinates(0, 0, 0);
    chassis.drive_max_voltage = 7;

   chassis.set_turn_constants(9, 0.25, 0, 1.5, 0);
   chassis.set_swing_constants(8, .45, 0.00070, 2.3, 15);
   chassis.turn_settle_time = 0;
   chassis.turn_settle_error = 5;
   //chassis.heading_kp = 3.5;

    // Scoring Preload
    catapult1.spinFor(0.5, rev, false);
   chassis.drive_distance(26.75);
   chassis.turn_to_angle(42);
   MotorIntake.spin(reverse, 75, vex::velocityUnits::pct);
   chassis.drive_distance(4);
   wait(0.4, vex::sec);
   MotorIntake.stop();
   chassis.drive_distance(-4);
   chassis.turn_kp = 0.2;
   chassis.turn_to_angle(-141.5);
   chassis.turn_kp = 0.25;
   chassis.drive_max_voltage = 12;
   chassis.drive_settle_error = 9;
   chassis.drive_distance(-14.5);
   chassis.drive_settle_error = 1.5;
   chassis.drive_max_voltage = 6;


    //Descoring Triball From Corner
   chassis.drive_distance(16);
   chassis.turn_to_angle(180);

   
   chassis.drive_distance(5.5);
   RightFrontWing.set(true);

   //RightBackArm.set(true);
    wait(0.35, vex::sec);
  
    chassis.swing_settle_error = 0.5;
    chassis.swing_max_voltage = 12;
    chassis.swing_settle_time = 300;
    chassis.swing_timeout = 1000;

   //rightWingListener = vex::task(testFunction);
   
   chassis.swing_max_voltage = 10;
    chassis.swing_settle_error = 0;
   chassis.right_swing_to_angle(-235);
   RightFrontWing.set(false);
   //rightWingListener.stop();
   wait(0.75, sec);
   chassis.turn_to_angle(-200);
   chassis.drive_distance(17);
   chassis.turn_to_angle(-225);
   MotorIntake.spin(vex::reverse, 600, rpm);
    chassis.drive_distance(25);
    MotorIntake.stop();
   //Brain.Screen.print(chassis.get_absolute_heading());
   //chassis.turn_to_angle()

    chassis.drive_settle_error = 6;
//     MotorIntake.spin(reverse, 600, rpm);
//     chassis.drive_max_voltage = 9; 
//    //chassis.drive_to_point(22, -19);
//    MotorIntake.stop();
   chassis.drive_settle_error = 1.5;
   //RightBackArm.set(false);
}

void defensive_awp_seventeen_points()
{

    chassis.setDefaultOdometryConstants();
    chassis.set_turn_constants(9, 0.25, 0, 1.5, 0);
    chassis.set_swing_constants(8, .45, 0.00070, 2.3, 15);
    chassis.turn_settle_time = 0;
    chassis.turn_settle_error = 5;

    chassis.set_coordinates(0,0,45);
    chassis.set_drive_constants(12, 4, 0, 20, 0);

    Pose middleTriBallPose(22.75, 51.75);

    MotorIntake.spin(vex::forward, 600, rpm);

    chassis.drive_max_voltage = 10;


    LeftFrontWing.set(true);
    wait(0.35, sec);    
    LeftFrontWing.set(false);
    chassis.drive_to_point(middleTriBallPose.XCoordinate, middleTriBallPose.YCoordinate, 11);
    chassis.turn_to_angle(90);
    LeftFrontWing.set(true);
    chassis.drive_distance(8.5, 12, 90);
    chassis.turn_to_angle(-165);
    LeftFrontWing.set(false);
    MotorIntake.stop();
    chassis.drive_to_point(2, 6, 8.5);
    chassis.turn_to_angle(125);
    chassis.rightWideSwing(-32, 180, 8, 3.4);
    //MotorIntake.stop();

    chassis.drive_max_voltage  = 7;
    chassis.drive_distance(12);
   chassis.turn_to_angle(135);

   
   chassis.drive_distance(12);
   RightFrontWing.set(true);

   //RightBackArm.set(true);
    wait(0.35, vex::sec);
  
    chassis.swing_settle_error = 0.5;
    chassis.swing_max_voltage = 12;
    chassis.swing_settle_time = 300;
    chassis.swing_timeout = 1000;

   //rightWingListener = vex::task(testFunction);
   
   chassis.swing_max_voltage = 10;
    chassis.swing_settle_error = 0;
   chassis.right_swing_to_angle(85);
   RightFrontWing.set(false);
   //rightWingListener.stop();
   wait(0.75, sec);
   chassis.turn_to_angle(135);
   chassis.drive_distance(12);
   chassis.turn_to_angle(90);
   MotorIntake.spin(vex::reverse, 600, rpm);
    chassis.drive_distance(28);
    MotorIntake.stop();
   //Brain.Screen.print(chassis.get_absolute_heading());
   //chassis.turn_to_angle()

    chassis.drive_settle_error = 6;
//     MotorIntake.spin(reverse, 600, rpm);
//     chassis.drive_max_voltage = 9; 
//    //chassis.drive_to_point(22, -19);
//    MotorIntake.stop();
   chassis.drive_settle_error = 1.5;

}

void defensive_awp_fourteen_points()
{
    chassis.drive_distance(12);
    chassis.turn_to_angle(180);
}