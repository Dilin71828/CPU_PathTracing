#ifndef RAY_H
#define RAY_H

#include <Eigen/Dense>
using namespace Eigen;

class Ray
{
public:
    Ray(){}

    Ray(const Vector3d& origin, const Vector3d& direction)
        : orig(origin), dir(direction)
    {}

    Vector3d origin() const {return this->orig; }
    Vector3d direction() const {return this->dir; }

    Vector3d at(double t)
    {
        return orig + t * dir;
    }

public:
    Vector3d orig;
    Vector3d dir;
};

#endif