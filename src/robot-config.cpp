#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;
controller Controller;

vex::task rightWingListener;

motor MotorLeftFront  = motor(PORT17,  ratio6_1, true);
motor MotorLeftMiddle = motor(PORT5,  ratio6_1, true);
motor MotorLeftBack   = motor(PORT15, ratio6_1, true);

motor MotorRightFront  = motor(PORT1, ratio6_1, false);
motor MotorRightMiddle = motor(PORT9, ratio6_1, false);
motor MotorRightBack   = motor(PORT18, ratio6_1, false);

motor MotorIntake = motor(PORT20, ratio6_1, true);

motor catapult1 = motor(PORT4, ratio36_1, false);
// motor catapult2 = motor(PORT11, ratio36_1, false);

// digital_out blocker = digital_out(Brain.ThreeWirePort.B);

 digital_out LeftFrontWing  = digital_out(Brain.ThreeWirePort.H);
 digital_out RightFrontWing = digital_out(Brain.ThreeWirePort.B);
 
 digital_out balance = digital_out(Brain.ThreeWirePort.F);
 pneumatics HangingPneumatics = pneumatics(Brain.ThreeWirePort.A);
 //digital_out RightBackArm   = digital_out(Brain.ThreeWirePort.F);



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
}