#pragma once
#include <string>

using namespace std;

enum AutonomousType{

Offsensive = 1,
Defensive  = 2,
Skills     = 3

};


extern int autonomousType;
extern int autonomousTypeStrategy;
extern int autonomousOffensiveStrategy;
extern int autonomousDefensiveStrategy;

extern bool autonomousSelected;

void displayAutonmousSelector(void);

void drawAutonmousType(void);
void drawAutonomousStrategies(int autonType);
int getSelectedAutonStrategyRectangle(int xCoordinate, int yCoordinate);
string getAutonDescription(int autonType);

