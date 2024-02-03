#include "Pose.h"

/**
 * @brief Create a new pose
 *
 * @param x component
 * @param y component
 * @param theta heading. Defaults to 0
 */
Pose::Pose(float XCoordinate, float YCoordinate, float ThetaRotation)
{
	this->XCoordinate   = XCoordinate;
	this->YCoordinate   = YCoordinate;
	this->ThetaRotation = ThetaRotation; 
}


/**
 * @brief Add a pose to this pose
 *
 * @param otherPose Pose pose
 * @return Pose
 */
Pose Pose::operator+(const Pose& otherPose) {
    return Pose(this->XCoordinate + otherPose.XCoordinate, this->YCoordinate + otherPose.YCoordinate, this->ThetaRotation);
}

/**
 * @brief Subtract a pose from this pose
 *
 * @param otherPose Pose pose
 * @return Pose
 */
Pose Pose::operator-(const Pose& otherPose) {
    return Pose(this->XCoordinate - otherPose.XCoordinate, this->YCoordinate - otherPose.YCoordinate, this->ThetaRotation);
}

/**
 * @brief Multiply a pose by this pose
 *
 * @param otherPose Pose pose
 * @return Pose
 */
float Pose::operator*(const Pose& otherPose) { 
	return this->XCoordinate * otherPose.XCoordinate + this->YCoordinate * otherPose.YCoordinate; 
}

/**
 * @brief Multiply a pose by a float
 *
 * @param otherPose float
 * @return Pose
 */
Pose Pose::operator*(const float& otherPose) {
    return Pose(this->XCoordinate * otherPose, this->YCoordinate * otherPose, this->ThetaRotation);
}

/**
 * @brief Divide a pose by a float
 *
 * @param otherPose float
 * @return Pose
 */
Pose Pose::operator/(const float& otherPose) {
    return Pose(this->XCoordinate / otherPose, this->YCoordinate / otherPose, this->ThetaRotation);
}

/**
 * @brief Linearly interpolate between two poses
 *
 * @param otherPose the otherPose pose
 * @param t t value
 * @return Pose
 */
Pose Pose::lerp(Pose otherPose, float t) {
    return Pose(this->XCoordinate + (otherPose.XCoordinate - this->XCoordinate) * t, this->YCoordinate + (otherPose.YCoordinate - this->YCoordinate) * t, this->ThetaRotation);
}

/**
 * @brief Get the distance between two poses
 *
 * @param otherPose the otherPose pose
 * @return float
 */
float Pose::distance(Pose otherPose) { 
	return std::hypot(this->XCoordinate - otherPose.XCoordinate, this->YCoordinate - otherPose.YCoordinate); 
}

/**
 * @brief Get the angle between two poses
 *
 * @param otherPose the otherPose pose
 * @return float in radians
 */
float Pose::angle(Pose otherPose) { 
	return std::atan2(otherPose.YCoordinate - this->YCoordinate, otherPose.XCoordinate - this->XCoordinate); 
}

/**
 * @brief Rotate a pose by an angle
 *
 * @param angle angle in radians
 * @return Pose
 */
Pose Pose::rotate(float angle) {
    return Pose(this->XCoordinate * std::cos(angle) - this->YCoordinate * std::sin(angle),
                        this->XCoordinate * std::sin(angle) + this->YCoordinate * std::cos(angle), this->ThetaRotation);
}