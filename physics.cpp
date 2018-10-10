#include "physics.h"
#include <cmath>

physics::physics()
{

}

void physics::check_for_wall_collision(GeometryObject* sphereObject)
{
    if(abs(sphereObject->get_position().get_x_value()) >= mCollisionPerimeter)
    {
        Vector3d xBounce{-1,0,0};
        redirect_Velocity(sphereObject, xBounce);
        double newXPosition{correct_overshoot(sphereObject->get_position().get_x_value())};
        sphereObject->get_position().set_x_value(newXPosition);
    }
    if(abs(sphereObject->get_position().get_y_value()) >= mCollisionPerimeter)
    {
        Vector3d yBounce{0,-1,0};
        redirect_Velocity(sphereObject, yBounce);
        double newYPosition{correct_overshoot(sphereObject->get_position().get_y_value())};
        sphereObject->get_position().set_y_value(newYPosition);
    }
    if(abs(sphereObject->get_position().get_z_value()) >= mCollisionPerimeter)
    {
        Vector3d zBounce{0,0,-1};
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
    double signOfPosition{position/abs(position)};
    double newPosition{signOfPosition*(mCollisionPerimeter - overshoot)};
    return newPosition;
}

void physics::set_gravity(Vector3d newGravity)
{
    mGravity = newGravity;
}

void physics::update_object_acceleration(GeometryObject* sphereObject)
{
    Vector3d objectAcceleration{mGravity};
    sphereObject->set_acceleration(objectAcceleration);
}
