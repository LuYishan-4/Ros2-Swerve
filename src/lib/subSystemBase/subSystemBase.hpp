#pragma once
class Subsystem {
public:
    virtual ~Subsystem() = default;

    virtual void periodic() = 0;
};
