#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

motor MotorLeftFront  = motor(PORT10,  ratio6_1, true);
motor MotorLeftMiddle = motor(PORT20,  ratio6_1, true);
motor MotorLeftBack   = motor(PORT13, ratio6_1, true);

motor MotorRightFront  = motor(PORT1, ratio6_1, false);
motor MotorRightMiddle = motor(PORT11, ratio6_1, false);
motor MotorRightBack   = motor(PORT18, ratio6_1, false);

motor MotorIntake = motor(PORT15, ratio6_1, true);

motor catapult1 = motor(PORT9, ratio36_1, false);
// motor catapult2 = motor(PORT11, ratio36_1, false);

// digital_out blocker = digital_out(Brain.ThreeWirePort.B);

digital_out wings = digital_out(Brain.ThreeWirePort.A);
// digital_out balance = digital_out(Brain.ThreeWirePort.C);

//inertial imu = inertial(PORT9);



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {


  // MotorRightBack.setBrake(hold);
  // MotorRightMiddle.setBrake(hold);
  // MotorRightFront.setBrake(hold);
  
  // MotorLeftBack.setBrake(hold);
  // MotorLeftMiddle.setBrake(hold);
  // MotorLeftFront.setBrake(hold);


}