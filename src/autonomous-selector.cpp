
#include "vex.h"

#include <string>



using namespace vex;
using namespace std;

int autonomousType              = 0;
int autonomousTypeStrategy      = 0;
int autonomousOffensiveStrategy = 0;
int autonomousDefensiveStrategy = 0;

bool autonomousSelected = false;

void displayAutonmousSelector(void) 
{

	drawAutonmousType();

	while ( ! autonomousSelected )
	{
		int xCoordinate, yCoordinate;

		if ( autonomousType == 0 )
		{

			while (!Brain.Screen.pressing())
			{
				wait(100, msec);
			}

			xCoordinate = Brain.Screen.xPosition();
			yCoordinate = Brain.Screen.yPosition();

			if( xCoordinate > 0 && yCoordinate > 0 && xCoordinate < 240 && yCoordinate < 120 ) // Brain.Screen.drawRectangle(0, 0, 240, 120);
			{
				autonomousType = AutonomousType::Offsensive;
			}
			else if(  xCoordinate > 240 && yCoordinate > 0 && xCoordinate < 480 && yCoordinate < 120 ) // Brain.Screen.drawRectangle(240, 0, 240, 120);
			{
				autonomousType = AutonomousType::Defensive;
			}
			else if(  xCoordinate > 0 && yCoordinate > 120 && xCoordinate < 480 && yCoordinate < 240 )  //Brain.Screen.drawRectangle(0, 120, 480, 120);
			{
				autonomousType = AutonomousType::Skills;
			}
			else
			{
				autonomousType = 0;
			}

		}
		else if(! Brain.Screen.pressing())
		{

			drawAutonomousStrategies(autonomousType);

 			xCoordinate = yCoordinate =  0;

			while (autonomousTypeStrategy == 0 && !(xCoordinate + yCoordinate))
			{
				xCoordinate = yCoordinate = 0;
				while ( ! Brain.Screen.pressing() )
				{
					wait(100, msec);
				}
				
				xCoordinate = Brain.Screen.xPosition();
				yCoordinate = Brain.Screen.yPosition();

				autonomousTypeStrategy = getSelectedAutonStrategyRectangle(xCoordinate, yCoordinate);
				if( ! autonomousTypeStrategy ){
					continue;;
				}

				Brain.Screen.clearScreen();
				Brain.Screen.setFillColor(black);
				Brain.Screen.setFont(propXL);

					switch (autonomousTypeStrategy)
					{
						case 1 :
							if(autonomousType == AutonomousType::Offsensive)
							{
								Brain.Screen.printAt(115, 75, true, "%s", getAutonDescription(autonomousType).c_str());
								Brain.Screen.setFont(propM);
								Brain.Screen.printAt(77, 110, true, "Target: All 6 Triballs in Goal (24 Points)");
							}
							if(autonomousType == AutonomousType::Defensive)
							{
								Brain.Screen.printAt(115, 75, true, "%s", getAutonDescription(autonomousType).c_str());
								Brain.Screen.setFont(propM);
								Brain.Screen.printAt(35, 110, true, "Target: Score Preload in Opponent's Goal + AWP");

							}
							if(autonomousType == AutonomousType::Skills)
							{
								Brain.Screen.printAt(205, 75, true, "%s", getAutonDescription(autonomousType).c_str());
								Brain.Screen.setFont(propM);
								Brain.Screen.printAt(135, 110, true, "Target: Main Skill Auton");
							}

						break;


						case 2 :
							if(autonomousType == AutonomousType::Offsensive)
							{
								Brain.Screen.printAt(115, 75, true, "%s", getAutonDescription(autonomousType).c_str());
								Brain.Screen.setFont(propM);
								Brain.Screen.printAt(65, 110, true, "Target: 5 Triballs & Steal Middle Triballs");
								Brain.Screen.printAt(190, 130, true, "(19 Points)");
							}
							if(autonomousType == AutonomousType::Defensive)
							{
								Brain.Screen.printAt(115, 75, true, "%s", getAutonDescription(autonomousType).c_str());
								Brain.Screen.setFont(propM);
								Brain.Screen.printAt(20, 110, true, "Target: Push Middle Triballs Over + AWP (17 Points)");

							}
							if(autonomousType == AutonomousType::Skills)
							{
								Brain.Screen.printAt(90, 125, true, "No Auton Selected");
							}

						break;

						case 3 :
							if(autonomousType == AutonomousType::Offsensive)
							{
								Brain.Screen.printAt(115, 75, true, "%s", getAutonDescription(autonomousType).c_str());
								Brain.Screen.setFont(propM);
								Brain.Screen.printAt(85, 110, true, "Target: 4 Triballs + AWP (14 Points)");
							}
							if(autonomousType == AutonomousType::Defensive)
							{
								Brain.Screen.printAt(115, 75, true, "%s", getAutonDescription(autonomousType).c_str());
								Brain.Screen.setFont(propM);
								Brain.Screen.printAt(30, 110, true, "Target: Steal Middle Triballs + AWP (14 Points)");
								Brain.Screen.printAt(190, 130, true, "Less Risky!");

							}
							if(autonomousType == AutonomousType::Skills)
							{
								Brain.Screen.printAt(90, 125, true, "No Auton Selected");
							}

						break;	

						case 4 :
						case 5 :
						case 6 :
						Brain.Screen.printAt(90, 125, true, "No Auton Selected");
						break;

						default : break;
					}

				autonomousSelected = true;
			}

		}

		vex::wait(100, vex::timeUnits::msec);
	}
}


void drawAutonmousType(void)
{
	Brain.Screen.clearScreen();
	Brain.Screen.setFillColor(blue);
	Brain.Screen.drawRectangle(0, 0, 240, 120);
	Brain.Screen.printAt(50, 60, "Offensive Zone");


	Brain.Screen.setFillColor(red);
	Brain.Screen.drawRectangle(240, 0, 240, 120);
	Brain.Screen.printAt(290, 60, "Defensive Zone");

	Brain.Screen.setFillColor("#2f4b26");
	Brain.Screen.drawRectangle(0, 120, 480, 120);
	Brain.Screen.printAt(150, 180, "Programming Skills");
}

// Brain Screen is 480 x 272 pixels (*240 with menu bar*)
//  156 x 115
int getSelectedAutonStrategyRectangle(int xCoordinate, int yCoordinate)
{
	if(xCoordinate > 10 && yCoordinate > 40 && xCoordinate < 156 && yCoordinate < 115) //Brain.Screen.drawRectangle(10, 40, 146, 75);
		return 1;

	if(xCoordinate > 10 && yCoordinate > 125 && xCoordinate < 156 && yCoordinate < 230) //Brain.Screen.drawRectangle(10, 125, 146, 105);
		return 4;

	if(xCoordinate > 166 && yCoordinate > 40 && xCoordinate < 312 && yCoordinate < 115) //Brain.Screen.drawRectangle(166, 40, 146, 75);
		return 2;

	if(xCoordinate > 166 && yCoordinate > 125 && xCoordinate < 312 && yCoordinate < 230) //Brain.Screen.drawRectangle(166, 125, 146, 105);
		return 5;

	if(xCoordinate > 322 && yCoordinate > 40 && xCoordinate < 468 && yCoordinate < 115) //Brain.Screen.drawRectangle(322, 40, 146, 75);
		return 3;

	if(xCoordinate > 322 && yCoordinate > 125 && xCoordinate < 468 && yCoordinate < 230) //Brain.Screen.drawRectangle(322, 125, 146, 105);
		return 6;

	return 0;
}

string getAutonDescription(int autonType)
{

	switch (autonType)
	{
		case AutonomousType::Defensive  : return "Defensive Zone";
		case AutonomousType::Offsensive : return "Offensive Zone";
		case AutonomousType::Skills     : return "Skills";
	}

	return NULL;

}

void drawAutonomousStrategies(int autonType)
{
	Brain.Screen.clearScreen();
	Brain.Screen.setFillColor(black);
	Brain.Screen.setFont(mono20);
	Brain.Screen.printAt(60, 25, false,  "%s Autonomous Strategies", (getAutonDescription(autonType).c_str()));

	Brain.Screen.setFillColor(red);
	Brain.Screen.drawRectangle(10, 40, 146, 75); // Rectangle 1

	Brain.Screen.setFont(monoXS);
	switch (autonType)
	{
		case AutonomousType::Offsensive :
			Brain.Screen.printAt(55, 80, "6 Triball");
			break;

		case AutonomousType::Defensive :
			Brain.Screen.printAt(38, 80, "AWP + 9 Points");				
			break;

		case AutonomousType::Skills :
			Brain.Screen.printAt(35, 80, "Main Skill Auton");				
			break;

	}

	Brain.Screen.setFillColor(red);
	Brain.Screen.drawRectangle(166, 40, 146, 75); //// Rectangle 2
	switch (autonType)
	{
		case AutonomousType::Offsensive :
			Brain.Screen.printAt(177, 80, "5 Triball (JAR Auton)");
			break;

		case AutonomousType::Defensive :
			Brain.Screen.printAt(192, 80, "AWP + 17 Points");				
			break;

		case AutonomousType::Skills :
			Brain.Screen.printAt(192, 80, "");				
			break;

	}

	Brain.Screen.setFillColor(red);
	Brain.Screen.drawRectangle(322, 40, 146, 75);// Rectangle 3
	switch (autonType)
	{
		case AutonomousType::Offsensive :
			Brain.Screen.printAt(347, 80, "4 Triball + AWP");
			break;

		case AutonomousType::Defensive :
			Brain.Screen.printAt(350, 75, "AWP + 14 Points");
			Brain.Screen.printAt(360, 88, "(Less Risk)");								
			break;

		case AutonomousType::Skills :
			Brain.Screen.printAt(347, 80, "");					
			break;

	}

	Brain.Screen.setFillColor(blue);
	Brain.Screen.drawRectangle(10, 125, 146, 105);// Rectangle 4
	switch (autonType)
	{
		case AutonomousType::Offsensive :
			Brain.Screen.printAt(30, 178, "");
			break;

		case AutonomousType::Defensive :
			Brain.Screen.printAt(30, 178, "");				
			break;

		case AutonomousType::Skills :
			Brain.Screen.printAt(37, 178, "");			
			break;

	}


	Brain.Screen.setFillColor(blue);
	Brain.Screen.drawRectangle(166, 125, 146, 105);// Rectangle 5
	switch (autonType)
	{
		case AutonomousType::Offsensive :
			Brain.Screen.printAt(185, 178, "");			
			break;

		case AutonomousType::Defensive :
			Brain.Screen.printAt(185, 178, "");							
			break;

		case AutonomousType::Skills :
			Brain.Screen.printAt(192, 178, "");							
			break;

	}

	Brain.Screen.setFillColor(blue);
	Brain.Screen.drawRectangle(322, 125, 146, 105);// Rectangle 6

	switch (autonType)
	{
		case AutonomousType::Offsensive :
			Brain.Screen.printAt(342, 178, "");	
			break;

		case AutonomousType::Defensive :
			Brain.Screen.printAt(342, 178, "");					
			break;

		case AutonomousType::Skills :
			Brain.Screen.printAt(347, 178, "");					
			break;

	}
	
}