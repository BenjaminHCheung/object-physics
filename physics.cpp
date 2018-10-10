#include "physics.h"
#include <cmath>

physics::physics(){}

physics::~physics()
{
    delete mSphereObject;
    mSphereObject = nullptr;
}

void physics::check_for_wall_collision(GeometryObject* sphereObject)
{
    if(abs(sphereObject->get_position().get_x_value()) >= mCollisionPerimeter)
    {
        Vector3d xBounce{-1,1,1};
        redirect_Velocity(sphereObject, xBounce);
        double newXPosition{correct_overshoot(sphereObject->get_position().get_x_value())};
        sphereObject->get_position().set_x_value(newXPosition);
    }
    if(abs(sphereObject->get_position().get_y_value()) >= mCollisionPerimeter)
    {
        Vector3d yBounce{1,-1,1};
        redirect_Velocity(sphereObject, yBounce);
        double newYPosition{correct_overshoot(sphereObject->get_position().get_y_value())};
        sphereObject->get_position().set_y_value(newYPosition);
    }
    if(abs(sphereObject->get_position().get_z_value()) >= mCollisionPerimeter)
    {
        Vector3d zBounce{1,1,-1};
        redirect_Velocity(sphereObject, zBounce);
        double newZPosition{correct_overshoot(sphereObject->get_position().get_z_value())};
        sphereObject->get_position().set_z_value(newZPosition);
    }
}

void physics::redirect_Velocity(GeometryObject* sphereObject, Vector3d bounceUnitVector)
{
    sphereObject->set_velocity(sphereObject->get_velocity()*sphereObject->get_Cr()*bounceUnitVector);
}

double physics::correct_overshoot(double position)
{
    double overshoot{abs(position) - mCollisionPerimeter};
    double signOfPosition{mSphereObject->get_Cr()*position/abs(position)};
    double newPosition{signOfPosition*(mCollisionPerimeter - overshoot)};
    return newPosition;
}

void physics::set_gravity(Vector3d newGravity)
{
    mGravity = newGravity;
}

void physics::update_object_acceleration()
{
    Vector3d objectAcceleration{mGravity};
    mSphereObject->set_acceleration(objectAcceleration);
}

void physics::update_object_kinematics()
{
    update_object_acceleration();
    mSphereObject->update_kinematics();
    check_for_wall_collision(mSphereObject);
}

Vector3d physics::return_object_position()
{
    return mSphereObject->get_position();
}
void physics::create_geometry_object(Vector3d initialPosition, Vector3d initialVeclocity)
{
    mSphereObject = new GeometryObject(initialPosition, initialVeclocity, mGravity);
}
