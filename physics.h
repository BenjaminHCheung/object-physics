#ifndef PHYSICS_H
#define PHYSICS_H

#include "vector3d.h"
#include "geometryobject.h"

class physics
{
public:
    physics();
    ~physics();

    void check_for_wall_collision(GeometryObject* sphereObject);
    void redirect_Velocity(GeometryObject* sphereObject, Vector3d bounceUnitVector);
    double correct_overshoot(double position);
    void set_gravity(Vector3d newGravity);
    void update_object_acceleration();
    void update_object_kinematics();
    Vector3d return_object_position();
    void create_geometry_object(Vector3d initialPosition, Vector3d initialVeclocity);

private:
    double mCollisionPerimeter{4};
    Vector3d mGravity{0,0,-9.8};
    GeometryObject* mSphereObject{nullptr};
};

#endif // PHYSICS_H
