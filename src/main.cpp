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

	PORT6, // inertial sensor port
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

	vexcodeInit();

	chassis.Gyro.calibrate();
	while(chassis.Gyro.isCalibrating()){  // https://www.vexforum.com/t/inertial-calibration-during-skills/75137
		 vex::task::sleep(50);
	}


	if(USE_AUTONOMOUS_SELECTOR == true){
		displayAutonmousSelector();
	}

	wait(25, vex::timeUnits::msec);
  
}




void autonomous(void) 
{
	while(chassis.Gyro.isCalibrating()){  // https://www.vexforum.com/t/inertial-calibration-during-skills/75137
		 vex::task::sleep(50);
	}

	chassis.Gyro.resetRotation();
	chassis.Gyro.resetHeading();
	chassis.DriveL.resetPosition();
	chassis.DriveR.resetPosition();

	chassis.setDriveTrainBrakeMode(brakeType::hold);
	chassis.setDefaultConstants();

	Brain.Screen.clearScreen();
	if(autonomousType == 0){
		Brain.Screen.printAt(90, 125, true, "No Autonomous Type Selected");
	}

	switch (autonomousType)
	{

		case AutonomousType::Offsensive :

				switch (autonomousTypeStrategy)
				{
					case 1 : 
						//offensive_six_triballs();
					break;
					case 2 : 
						//offensive_five_triballs();
					break;
					case 3:
						google_offensive_awp_four_triballs();;
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
						//defensive_awp_fourteen_points();
					break;
					default: break;
				}
		break;

		case AutonomousType::Skills :
				switch (autonomousTypeStrategy)
				{
					case 1 : 
						google_programming_skills();
					case 2:
						//backup_skills_auton();
					default: break;
				}

		break;

		default: 
			//defensive_awp_nine_points();
		//defensive_awp_seventeen_points();
		states_programming_skills_v1();
			//google_programming_skills();	
			//odom_test();
			//drive_test();
			//google_offensive_awp_four_triballs();

//full_test();


//offensive_five_triballs();
//offensive_awp_four_triballs();
//backup_skills_auton_1();
// chassis.setDefaultOdometryConstants(); -38.3 51.4 305

    

			break;
	}

}

//void balance_Control();

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
		LeftFrontWing.set(true);
	//catapult2.spin(reverse, CATA_SPEED*120, voltageUnits::mV);
	} else
	{	
		//LeftFrontWing.set(false);	
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


void front_left_wing_control(const vex::controller::button& controllerButton)
{
	static bool buttonPressed = false;

	if(!buttonPressed && controllerButton.pressing()){
		LeftFrontWing.set( ! LeftFrontWing.value() );
	}

	buttonPressed = controllerButton.pressing();

}

void front_right_wing_control(const vex::controller::button& controllerButton)
{
	static bool buttonPressed = false;

	if(!buttonPressed && controllerButton.pressing()){
		RightFrontWing.set( ! RightFrontWing.value() );
	}

	buttonPressed = controllerButton.pressing();

}

void balance_control(vex::controller::button controllerButton)
{
	static bool buttonPressed = false;

	if(!buttonPressed && controllerButton.pressing()){
		balance.set( ! balance.value() );
	}

	buttonPressed = controllerButton.pressing();

}



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
	
	chassis.setDriveTrainBrakeMode(brakeType::brake);
	chassis.drive_max_voltage = 12;

	Controller.ButtonL1.pressed( [] () {
		RightFrontWing.set( ! RightFrontWing.value() );
		LeftFrontWing.set( ! LeftFrontWing.value() );
    } );

	Controller.ButtonDown.pressed([] () {
		HangingPneumatics.set(!HangingPneumatics.value());
    });


	Controller.ButtonA.pressed([] () {

		static bool buttonPressed = false;

		if(!buttonPressed && Controller.ButtonA.pressing())
		{
			LeftFrontWing.set( true);
			catapult1.spin(vex::forward, CATA_SPEED * 120, voltageUnits::mV);

		}
		else
		{
			LeftFrontWing.set( false);
			catapult1.stop();
		}

		buttonPressed = Controller.ButtonA.pressing();
	});


	while ( true ) 
	{

		intake_ButtonControl();
		catapult_ButtonControl();

		//balance_control(Controller.ButtonL2);

		//front_left_wing_control(Controller.ButtonL1);
		//front_right_wing_control(Controller.ButtonL1);


		if (Controller.ButtonLeft.pressing())
		{
			chassis.setDefaultOdometryConstants();

			chassis.set_swing_constants(8, .45, 0.00070, 2.3, 15);

			chassis.set_coordinates(0,0,0);
			chassis.set_drive_constants(12, 4, 0, 20, 0);

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
			chassis.drive_distance(8.5); // it was 8

			//LeftFrontWing.set(true);
			// catapult1.spin(vex::forward, 75 * 120, voltageUnits::mV);
			// wait(26, sec);
			// catapult1.spin(vex::forward, 0, voltageUnits::mV);
			
			// LeftFrontWing.set(false);

		//wait(250, msec);
		//chassis.drive_settle_error = 3.9; 
/*
			chassis.drive_to_point(5, 12);
			//chassis.turn_kp = 3.7;
			chassis.turn_to_angle(-90);
			chassis.drive_max_voltage  = 8.0;
			chassis.drive_to_point(67.5, 12);

			chassis.drive_timeout      = 1200;
			chassis.drive_settle_error = 5;
			chassis.leftWideSwing(-54.9, 180, 10, 1.575);
		

			chassis.drive_distance(11, 8, 180);
			chassis.drive_distance(-11.5, 12, 180);
*/

		}
		
		
		chassis.control_tank(Controller);




		wait(20, msec); 

	}
}


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Run the pre-autonomous function.
  pre_auton();

 Competition.bStopTasksBetweenModes = true;

  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);


  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
