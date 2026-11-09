#pragma once
#include <cmath>

class Rotation2d {
public:
    Rotation2d() : m_value(0.0) {}
    explicit Rotation2d(double radians) : m_value(radians) {}

    static Rotation2d FromDegrees(double degrees) {
        return Rotation2d(degrees * M_PI / 180.0);
    }

    double Radians() const { return m_value; }
    double Degrees() const { return m_value * 180.0 / M_PI; }
    double Cos() const { return std::cos(m_value); }
    double Sin() const { return std::sin(m_value); }

private:
    double m_value;
};