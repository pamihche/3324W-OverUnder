#include "autonomous-offensive.h"
#include "vex.h"

using namespace vex;

int testFunctionTwo()
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

			/* code */
	}
		
	return 0;
}

void offensive_awp_four_triballs()
{
    chassis.setDefaultOdometryConstants();
    chassis.set_swing_constants(12, .45, 0.00070, 2.3, 15);
    chassis.set_turn_constants(9, 0.32, 0.2, 2.2, 0);
    MotorIntake.setBrake(hold);
    chassis.turn_settle_time = 0;
    chassis.turn_settle_error = 2; 
    chassis.drive_settle_time = 100;
    chassis.swing_settle_error = 0.5;
    chassis.swing_max_voltage = 9;
    chassis.swing_settle_time = 300;
    chassis.swing_timeout = 250;
    Brain.Screen.clearScreen();
    chassis.Gyro.resetRotation();
    chassis.set_coordinates(0, 0, 0);
    chassis.drive_max_voltage = 11;
    MotorIntake.spin(vex::forward, 600, rpm);
    RightFrontWing.set(true);
    wait(200, msec);
    RightFrontWing.set(false);
    //chassis.set_heading(0);
    chassis.drive_to_point(4.5, 64.5);
    wait(0.1, sec);
    MotorIntake.stop();

    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    
    chassis.right_swing_to_angle(-43.5);
    chassis.drive_distance(-31.5);
    chassis.drive_distance(24);

    chassis.set_swing_constants(7, .45, 0.00070, 2.3, 15);

    //chassis.right_swing_to_angle(-135);
    //chassis.turn_to_point(-10, 5);
    chassis.drive_max_voltage = 12;
    chassis.drive_to_point(-7.5, 6.5);
    chassis.turn_to_angle(90);
    chassis.drive_max_voltage = 8;
    
    RightFrontWing.set(true);
    //LeftFrontWing.set(true);
    chassis.drive_distance(8);
    //RightFrontWing.set(false);
    LeftFrontWing.set(false);
    //chassis.turn_to_angle(45);
    //wait(0.5, sec);
    //chassis.turn_to_angle(45);
    chassis.turn_kp = 0.25;
   // rightWingListener = vex::task(testFunctionTwo);
    chassis.turn_settle_error = 5;
    chassis.turn_max_voltage = 12;
    chassis.turn_to_angle(42.5);
    //rightWingListener.stop();
    RightFrontWing.set(false);
    chassis.turn_kp = 0.32;
    chassis.turn_to_angle(50);

    MotorIntake.spin(reverse, 600, rpm);
    wait(0.5, sec);
    MotorIntake.stop();
   //MotorIntake.spin(reverse, 600, rpm);
   //chassis.turn_to_angle(75);
    //MotorIntake.spin(reverse, 600, rpm);
    chassis.drive_distance(-9);
    chassis.turn_to_angle(-120);
    chassis.drive_settle_error = 9;
    chassis.heading_kp = 0.3;
    chassis.drive_distance(-33);
    chassis.drive_distance(12);
    chassis.turn_to_angle(-116);
    chassis.drive_distance(-12);

    
    MotorIntake.stop();
    //MotorIntake.stop();
    // chassis.drive_distance(3);
    // chassis.turn_settle_time = 100;
    // //chassis.turn_to_angle(-133);
    // // chassis.drive_distance(-11.5);
    // // chassis.drive_distance(3.5);
    // chassis.drive_max_voltage = 12;
    // chassis.drive_settle_error = 9;
    // chassis.drive_to_point(-12, 12);
    // chassis.turn_to_angle(-45);
    // chassis.drive_distance(30);
}  

void offensive_five_triballs()
{
  chassis.drive_distance(-24);
}

void offensive_six_triballs()
{
  chassis.left_swing_to_angle(90);
}