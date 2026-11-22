#pragma once

#include <cmath>

namespace genesis::math {
    struct Vector2 {
        float x = 0.0f;
        float y = 0.0f;

        Vector2 operator-() const {
            return {-this->x, -this->y};
        }
        
        Vector2& operator+=(const Vector2& other) {
            this->x += other.x;
            this->y += other.y;
            return *this;
        }

        Vector2& operator-=(const Vector2& other) {
            this->x -= other.x;
            this->y -= other.y;
            return *this;
        }

        Vector2& operator*=(float scalar) {
            this->x *= scalar;
            this->y *= scalar;
            return *this;
        }

        Vector2& operator*=(const Vector2& other) {
            this->x *= other.x;
            this->y *= other.y;
            return *this;
        }

        Vector2& operator/=(float scalar) {
            this->x /= scalar;
            this->y /= scalar;
            return *this;
        }

        Vector2& operator/=(const Vector2& other) {
            this->x /= other.x;
            this->y /= other.y;
            return *this;
        }

        friend Vector2 operator+(Vector2 a, const Vector2& b) {
            a += b;
            return a;
        }

        friend Vector2 operator-(Vector2 a, const Vector2& b) {
            a -= b;
            return a;
        }

        friend Vector2 operator*(Vector2 a, const Vector2& b) {
            a *= b;
            return a;
        }

        friend Vector2 operator*(Vector2 a, float scalar) {
            a *= scalar;
            return a;
        }

        friend Vector2 operator*(float scalar, Vector2 a) {
            a *= scalar;
            return a;
        }

        friend Vector2 operator/(Vector2 a, const Vector2& b) {
            a /= b;
            return a;
        }

        friend Vector2 operator/(Vector2 a, float scalar) {
            a /= scalar;
            return a;
        }

        float magnitude_squared() const {
            return (x * x) + (y * y);
        }

        float magnitude() const {
            return std::sqrt(magnitude_squared());
        }

        float distance_squared(const Vector2& other) const {
            Vector2 sub = other - *this;
            return sub.magnitude_squared();
        }

        float distance(const Vector2& other) const {
            return std::sqrt(distance_squared(other));
        }

        float dot(const Vector2& other) const {
            return (this->x * other.x) + (this->y * other.y);
        }

        Vector2 normalized() const {
            float mag = magnitude();
            if (mag == 0) {
                return *this;
            }

            return *this / mag;
        }

        Vector2& normalize() {
            *this = normalized();
            return *this;
        }
    };

    inline bool operator==(const Vector2& a, const Vector2& b) {
        return 
            (a.x == b.x) &&
            (a.y == b.y);
    }

    inline bool operator!=(const Vector2& a, const Vector2& b) {
        return 
            (a.x != b.x) &&
            (a.y != b.y);
    }
}