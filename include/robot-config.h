using namespace vex;

class Drive;
class SmartDrive;

extern SmartDrive chassis;

extern brain Brain;

extern motor MotorLeftFront; 
extern motor MotorLeftMiddle;
extern motor MotorLeftBack; 
extern motor MotorRightFront; 
extern motor MotorRightMiddle;
extern motor MotorRightBack;
extern digital_out wings;
//extern digital_out balance;
//extern digital_out blocker;
extern motor catapult1;
// extern motor catapult2;
extern motor MotorIntake;




/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );