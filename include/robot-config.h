using namespace vex;

class Drive;
class SmartDrive;

extern SmartDrive chassis;

extern brain Brain;
extern controller Controller;

extern motor MotorLeftFront; 
extern motor MotorLeftMiddle;
extern motor MotorLeftBack; 
extern motor MotorRightFront; 
extern motor MotorRightMiddle;
extern motor MotorRightBack;

extern motor catapult1;
extern motor MotorIntake;


//extern pneumatics RightBackArm;
extern digital_out LeftFrontWing;
extern digital_out RightFrontWing;
extern digital_out balance;

extern pneumatics HangingPneumatics;


extern vex::task rightWingListener;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );