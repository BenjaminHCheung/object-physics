#include "gtest/gtest.h"
#include "vector3d.h"

TEST(GivenTooEqualVectors, WhenUsingIsEqualOperator_ReturnsTrue)
{
    Vector3d leftSide{Vector3d(1,2,3)};
    Vector3d rightSide{Vector3d(1,2,3)};
    EXPECT_TRUE(leftSide==rightSide);
}

TEST(GivenTooNonEqualVectors, WhenUsingIsEqualOperator_ReturnsFalse)
{
    Vector3d leftSide{Vector3d(13,22,3.6)};
    Vector3d rightSide{Vector3d(1.123,2.25,334)};
    EXPECT_FALSE(leftSide == rightSide);
}

TEST(GivenScalerValueOfTypeDouble, WhenUsingMultiplicationOperatore_IsEqual)
{
    double scaler{9.8};
    Vector3d baseVector{Vector3d(1,2,2)};
    Vector3d calculatedVector{baseVector*scaler};
    Vector3d expectedVector{Vector3d(9.8,19.6,19.6)};
    EXPECT_EQ(expectedVector.get_x_value(),calculatedVector.get_x_value());
    EXPECT_EQ(expectedVector.get_y_value(),calculatedVector.get_y_value());
    EXPECT_EQ(expectedVector.get_z_value(),calculatedVector.get_z_value());
}

