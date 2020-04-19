
#include "geometry3d/position.h"

namespace Geometry3D
{
double Position::x() const
{
    return data.at(0);
}

double Position::y() const
{
    return data.at(1);
}

double Position::z() const
{
    return data.at(2);
}

double Position::altitude() const 
{
    return z();
}


} // namespace Geometry3D