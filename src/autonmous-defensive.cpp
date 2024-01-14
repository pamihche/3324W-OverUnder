#include "autonmous-defensive.h"
#include "vex.h"

void defensive_awp_nine_points()
{
    chassis.drive_distance(-12);
    wings.set(true);
    chassis.drive_distance(9);
    chassis.drive_distance(-20);
    chassis.turn_to_angle(45);
}