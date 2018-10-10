#ifndef GEOMETRYOBJECT_H
#define GEOMETRYOBJECT_H

#include "vector3d.h"

class GeometryObject
{
public:
    GeometryObject(Vector3d initialPosition, Vector3d initialVelocity, Vector3d initialAcceleration);
    ~GeometryObject();

    void set_position(Vector3d newPosition);
    void set_velocity(Vector3d newVelocity);
    void set_acceleration(Vector3d newAcceleration);
    void set_Cr(double newCoefficnetOfRestitution);
    Vector3d get_position();
    Vector3d get_velocity();
    Vector3d get_acceleration();
    double get_Cr();
    void update_kinematics();

private:
    Vector3d mPosition{Vector3d(0,0,0)};
    Vector3d mVelocity{Vector3d(0,0,0)};
    Vector3d mAcceleration{Vector3d(0,0,0)};
    double mCr{.95};

};

#endif // GEOMETRYOBJECT_H
