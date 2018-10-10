#include "geometryobject.h"

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
void GeometryObject::set_Cr(double newCoefficnetOfRestitution)
{
    mCr = newCoefficnetOfRestitution;
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
double GeometryObject::get_Cr()
{
    return mCr;
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
