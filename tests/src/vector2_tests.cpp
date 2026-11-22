#include <gtest/gtest.h>
#include <genesis/vectors/vector2.hpp>
#include <cmath>

using namespace genesis::math;

TEST(Vector2Test, Sum) {
    const Vector2 a{1, 1};
    const Vector2 b{1, 1};
    const Vector2 expected{2, 2};

    EXPECT_EQ(a + b, expected);
}

TEST(Vector2Test, CompostedSum) {
    Vector2 a{1, 1};
    a += Vector2{1, 2};
    a += Vector2{2, 2};

    const Vector2 expected{4, 5};

    EXPECT_EQ(a, expected);
}

TEST(Vector2Test, Subtraction) {
    const Vector2 a{1, 1};
    const Vector2 b{1, 1};
    const Vector2 expected{0, 0};

    EXPECT_EQ(a - b, expected);
}

TEST(Vector2Test, CompostedSubtraction) {
    Vector2 a{4, 5};
    a -= Vector2{2, 2};
    a -= Vector2{1, 2};

    const Vector2 expected{1, 1};

    EXPECT_EQ(a, expected);
}

TEST(Vector2Test, Multiplication) {
    const Vector2 a{3, 2};
    const Vector2 b{2, 3};
    const Vector2 expected{6, 6};

    EXPECT_EQ(a * b, expected);
}

TEST(Vector2Test, CompostedMultiplication) {
    Vector2 a{2, 3};
    a *= Vector2{2, 2};
    a *= Vector2{0.5f, 3};

    const Vector2 expected{2, 18};

    EXPECT_EQ(a, expected);
}

TEST(Vector2Test, Division) {
    const Vector2 a{2, 4};
    const Vector2 b{2, 2};
    const Vector2 expected{1, 2};

    EXPECT_EQ(a / b, expected);
}

TEST(Vector2Test, CompostedDivision) {
    Vector2 a{12, 20};
    a /= Vector2{2, 5};
    a /= Vector2{6, 2};

    const Vector2 expected{1, 2};

    EXPECT_EQ(a, expected);
}

TEST(Vector2Test, DivisionByZero) {
    Vector2 inf{2, 2};
    inf /= Vector2{0, 0};
    EXPECT_TRUE(std::isinf(inf.x) && std::isinf(inf.y));

    Vector2 nan{0, 0};
    nan /= Vector2{0, 0};
    EXPECT_TRUE(std::isnan(nan.x) && std::isnan(nan.y));
}