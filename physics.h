#ifndef PHYSICS_H
#define PHYSICS_H

#include "vector3d.h"
#include "geometryobject.h"

class physics
{
public:
    physics();

    void check_for_wall_collision(GeometryObject* sphereObject);
    void redirect_Velocity(GeometryObject* sphereObject, Vector3d bounceUnitVector);
    double correct_overshoot(double position);
    void set_gravity(Vector3d newGravity);
    void update_object_acceleration(GeometryObject* sphereObject);
    void update_object_kinematics(GeometryObject* sphereObject);

private:
    double mCollisionPerimeter{4};
    Vector3d mGravity{0,0,-9.8};
};

#endif // PHYSICS_H
