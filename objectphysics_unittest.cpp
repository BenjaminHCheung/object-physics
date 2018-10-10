#include "gtest/gtest.h"
#include "geometryobject.h"

TEST(GivenAGeometryObject, WhenUpdateKinematicsIsCalled_ThePostionAndVelocityVectorsUpdate)
{
    Vector3d position{Vector3d(0,0,0)};
    Vector3d velocity{Vector3d(30,30,30)};
    Vector3d acceleration{Vector3d(0,0,-30)};
    GeometryObject sphere{GeometryObject(position, velocity, acceleration)};
    Vector3d expectedVelocity{Vector3d(10,10,9)};
    Vector3d expectedPosition{Vector3d(1,1,1)};
    sphere.update_kinematics();
    EXPECT_EQ(expectedPosition, sphere.get_position());
    EXPECT_EQ(expectedVelocity, sphere.get_velocity());
}
