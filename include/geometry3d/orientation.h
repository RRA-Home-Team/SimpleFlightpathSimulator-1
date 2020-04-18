#pragma once
#include <array>

namespace Geometry3D
{
class Orientation
{
public:
    double pitch() const;
    double roll() const;
    double yaw() const;

private:
    std::array<double, 3> data;
};
} // namespace Geometry3D