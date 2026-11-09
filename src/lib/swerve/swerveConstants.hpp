#pragma once
#include "rotation2d/Rotation2d.hpp"

struct SwerveModuleConstants {
    int driveMotorID;
    int angleMotorID;
    int cancoderID;
    Rotation2d angleOffset;

    SwerveModuleConstants(int driveMotorID, int angleMotorID, int canCoderID, Rotation2d angleOffset)
        : driveMotorID(driveMotorID), angleMotorID(angleMotorID), cancoderID(cancoderID), angleOffset(angleOffset) {}
};