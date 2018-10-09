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
    Vector3d get_position();
    Vector3d get_velocity();
    Vector3d get_acceleration();
    void update_kinematics();

private:
    Vector3d mPosition;
    Vector3d mVelocity;
    Vector3d mAcceleration;

    void check_collision();

};

#endif // GEOMETRYOBJECT_H
