#include "geometryobject.h"
#include <cmath>

GeometryObject::GeometryObject(Vector3d initialPosition, Vector3d initialVelocity, Vector3d initialAcceleration)
{
    mPosition = initialPosition;
    mVelocity = initialVelocity;
    mAcceleration = initialAcceleration;
}

GeometryObject::~GeometryObject(){}

void GeometryObject::set_position(Vector3d newPosition)
{
    mPosition = newPosition;
}
void GeometryObject::set_velocity(Vector3d newVelocity)
{
    mVelocity = newVelocity;
}
void GeometryObject::set_acceleration(Vector3d newAcceleration)
{
    mAcceleration = newAcceleration;
}
Vector3d GeometryObject::get_position()
{
    return mPosition;
}
Vector3d GeometryObject::get_velocity()
{
    return mVelocity;
}
Vector3d GeometryObject::get_acceleration()
{
    return mAcceleration;
}

void GeometryObject::update_kinematics()
{
    double framesPerSecond{30};
    double frameTimeStep{1/framesPerSecond};

    Vector3d positionStep{mVelocity*frameTimeStep};
    mPosition = mPosition + positionStep;

    Vector3d velocitStep{mAcceleration*frameTimeStep};
    mVelocity = mVelocity + velocitStep;
}


void GeometryObject::check_collision()
{
    double collisionPerimeter{4};
    if(abs(mPosition.get_x_value()) >= collisionPerimeter)
    {
        Vector3d xBounce{-1,0,0};
        mVelocity = mVelocity*xBounce;
        double xOverShoot{abs(mPosition.get_x_value()) - collisionPerimeter};
        double signOfPosition{mPosition.get_x_value()/abs(mPosition.get_x_value())};
        double newXPosition{signOfPosition*(collisionPerimeter-xOverShoot)};
        mPosition.set_x_value(newXPosition);
    }
    if(abs(mPosition.get_y_value()) >= collisionPerimeter)
    {
        Vector3d yBounce{0,-1,0};
        mVelocity = mVelocity*yBounce;
        double yOverShoot{abs(mPosition.get_y_value()) - collisionPerimeter};
        double signOfPosition{mPosition.get_y_value()/abs(mPosition.get_y_value())};
        double newYPosition{signOfPosition*(collisionPerimeter-yOverShoot)};
        mPosition.set_y_value(newYPosition);
    }
    if(abs(mPosition.get_z_value()) >= collisionPerimeter)
    {
        Vector3d zBounce{0,0,-1};
        mVelocity = mVelocity*zBounce;
        double zOverShoot{abs(mPosition.get_z_value()) - collisionPerimeter};
        double signOfPosition{mPosition.get_z_value()/abs(mPosition.get_z_value())};
        double newZPosition{signOfPosition*(collisionPerimeter-zOverShoot)};
        mPosition.set_z_value(newZPosition);
    }
}
