#include "vex.h"

using namespace vex;
competition Competition;

const bool USE_AUTONOMOUS_SELECTOR = true;

// bool back_wings_set = false;
// bool front_wings_set = false;

// bool frontWingsLastPress = false;
// bool backWingsLastPress = false;

bool cata_set = false;
bool cataLastPress = false;
const int CATA_SPEED = 75;


SmartDrive chassis( 
	ZERO_TRACKER_ODOM, 
	motor_group(MotorLeftFront, MotorLeftMiddle, MotorLeftBack), 
	motor_group(MotorRightFront, MotorRightMiddle, MotorRightBack),

	PORT8, // inertial sensor port
	3.25, 
	0.6,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:

4.5,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);


void pre_auton(void) {

  // Initializing Robot Configuration. DO NOT REMOVE!
	vexcodeInit();
	
	chassis.setDriveTrainBrakeMode(brakeType::hold);

	chassis.setDefaultConstants();

	if(USE_AUTONOMOUS_SELECTOR == true)
	{
		displayAutonmousSelector();
	}

	wait(10, vex::timeUnits::msec);
  
}




void autonomous(void) 
{
	Brain.Screen.clearScreen();

	if(autonomousType == 0)
	{
		Brain.Screen.printAt(90, 125, true, "No Autonomous Type Selected");
	}


	switch (autonomousType)
	{

		case AutonomousType::Offsensive :

				switch (autonomousTypeStrategy)
				{
					case 1 : 
						offensive_six_triballs();
					break;
					case 2 : 
						offensive_five_triballs();
					break;
					case 3:
						offensive_awp_four_triballs();
					break;
					default: break;
				}

		break;

		case AutonomousType::Defensive :

				switch (autonomousTypeStrategy)
				{
					case 1 : 
						defensive_awp_nine_points();
					break;
					case 2 : 
						defensive_awp_seventeen_points();
					break;
					case 3:
						defensive_awp_fourteen_points();
					break;
					default: break;
				}
		break;

		case AutonomousType::Skills :
				switch (autonomousTypeStrategy)
				{
					case 1 : 
						main_skill_auton();
					case 2:
						backup_skills_auton();
					default: break;
				}

		break;

		default: 

			// chassis.drive_max_voltage = 4;

			// leftWingListener = vex::task(testFunction);

			// LeftFrontWing.set(true);

			// chassis.drive_distance(25);
			
			// leftWingListener.stop();

			// LeftFrontWing.set(true);

			// chassis.drive_distance(25);

			

			chassis.setDriveTrainBrakeMode(coast);

			//odom_test();
			// chassis.drive_distance(20);
			// chassis.left_swing_to_angle(-90);
			// chassis.right_swing_to_angle(0);
			//swing_test();
			//just_test_skills_auton();

			defensive_awp_nine_points();
			//offensive_awp_four_triballs();
			//main_skill_auton();
			
			//odom_test();
			// chassis.setDefaultConstants();
			// chassis.turn_kd = 3.35;

			

    

			break;
	}

}

void catapult_ButtonControl()
{
	if(controller(primary).ButtonA.pressing() and cataLastPress == false)
	{
		cata_set = !cata_set;
	}
	// keep track of press
		cataLastPress = controller(primary).ButtonA.pressing();
	if (cata_set) 
	{
		catapult1.spin(vex::forward, CATA_SPEED * 120, voltageUnits::mV);
	//catapult2.spin(reverse, CATA_SPEED*120, voltageUnits::mV);
	} else
	{
		catapult1.spin(vex::forward, 0, voltageUnits::mV);
	//catapult2.spin(reverse, 0, voltageUnits::mV);
	}

  
}

 void intake_ButtonControl()
{
	if(controller(primary).ButtonR2.pressing())
	{
		MotorIntake.setVelocity(600, rpm);
		MotorIntake.spin(reverse, 600, rpm);
	}
	else if(controller(primary).ButtonR1.pressing())
	{
		MotorIntake.setVelocity(600, rpm);
		MotorIntake.spin(vex::forward, 600, rpm);
	}
	else
	{
		MotorIntake.stop();
	}

}


// void back_right_arm_control(vex::controller::button controllerButton)
// {
// 	static bool buttonPressed = false;

// 	if(!buttonPressed && controllerButton.pressing()){
// 		RightBackArm.set(!RightBackArm.value());
// 	}

// 	buttonPressed = controllerButton.pressing();

// }

void front_left_wing_control(vex::controller::button controllerButton)
{
	static bool buttonPressed = false;

	if(!buttonPressed && controllerButton.pressing()){
		LeftFrontWing.set( ! LeftFrontWing.value() );
	}

	buttonPressed = controllerButton.pressing();

}

void front_right_wing_control(vex::controller::button controllerButton)
{
	static bool buttonPressed = false;

	if(!buttonPressed && controllerButton.pressing()){
		RightFrontWing.set( ! RightFrontWing.value() );
	}

	buttonPressed = controllerButton.pressing();

}


// void frontWings_control(void)
// {
// 	if(controller(primary).ButtonL1.pressing() && frontWingsLastPress == false)
// 	{
// 		front_wings_set = !front_wings_set;
		
// 	}

// 	frontWingsLastPress = controller(primary).ButtonL1.pressing();
// 	frontWings.set(front_wings_set);
// }

// void backWings_control(void)
// {
// 	if(controller(primary).ButtonL2.pressing() && backWingsLastPress == false)
// 	{
// 		back_wings_set = !back_wings_set;
		
// 	}

// 	backWingsLastPress = controller(primary).ButtonL2.pressing();

// 	backWings.set(back_wings_set);
// }




/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
	
	chassis.setDriveTrainBrakeMode(brakeType::hold);

  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    //Replace this line with chassis.control_tank(); for tank drive 
    //or chassis.control_holonomic(); for holo drive.
	intake_ButtonControl();
	// frontWings_control();
	// backWings_control();
	catapult_ButtonControl();


	//back_right_arm_control(Controller.ButtonL2);
	front_left_wing_control(Controller.ButtonL1);
	front_right_wing_control(Controller.ButtonL1);



    //chassis.control_tank();
	chassis.drive_max_voltage = 12;
	chassis.control_tank();


    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
