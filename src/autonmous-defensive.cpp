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

			/* code */
	}
		
	return 0;
}

void defensive_awp_nine_points()
{
    chassis.setDefaultConstants();
    chassis.set_coordinates(0, 0, 0);

   chassis.set_turn_constants(9, 0.25, 0, 1.5, 0);
   chassis.set_swing_constants(12, .45, 0.00070, 2.3, 15);
   chassis.turn_settle_time = 0;
   chassis.turn_settle_error = 5;
   //chassis.heading_kp = 3.5;

    // Scoring Preload
   chassis.drive_distance(27.75);
   chassis.turn_to_angle(45);
   MotorIntake.spin(reverse, 60, vex::velocityUnits::pct);
   chassis.drive_distance(4);
   wait(0.4, vex::sec);
   MotorIntake.stop();
   chassis.drive_distance(-4);
   chassis.turn_kp = 0.2;
   chassis.turn_to_angle(-135);
   chassis.turn_kp = 0.25;
   chassis.drive_max_voltage = 12;
   chassis.drive_settle_error = 9;
   chassis.drive_to_point(13, 38);
   chassis.drive_settle_error = 1.5;
   chassis.drive_max_voltage = 8;


    //Descoring Triball From Corner
   chassis.drive_distance(16);
   chassis.turn_to_angle(180);

   
   chassis.drive_distance(11);
   RightFrontWing.set(true);

   //RightBackArm.set(true);
    wait(0.35, vex::sec);
  
    chassis.swing_settle_error = 0.5;
    chassis.swing_max_voltage = 12;
    chassis.swing_settle_time = 300;
    chassis.swing_timeout = 250;

   rightWingListener = vex::task(testFunction);
   
   chassis.right_swing_to_angle(-230);
   RightFrontWing.set(false);
   rightWingListener.stop();

    chassis.drive_settle_error = 9;
    MotorIntake.spin(reverse, 600, rpm);
   chassis.drive_to_point(22, -19);
   MotorIntake.stop();
   chassis.drive_settle_error = 1.5;
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