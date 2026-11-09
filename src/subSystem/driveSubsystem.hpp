#pragma once

#include "subSystemBase/subSystemBase.hpp"

class DriveSubsystem : public Subsystem {
public:
    DriveSubsystem();
    ~DriveSubsystem() override;

    void periodic() override;

private:
    double left_speed_;
    double right_speed_;
};

