#include <gtest/gtest.h>
#include <genesis/math.hpp>

using namespace genesis::math;

TEST(Vector2Test, Sum) {
    const Vector2 a{1, 1};
    const Vector2 b{1, 1};
    const Vector2 expected{2, 2};

    EXPECT_EQ(vector2_sum(a, b), expected);
}