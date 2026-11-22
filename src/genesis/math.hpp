#pragma once

namespace genesis::math {
    struct Vector2 {
        float x;
        float y;
    };

    inline bool operator==(const Vector2& a, const Vector2& b) {
        return (a.x == b.x) && (a.y == b.y);
    }

    inline Vector2 vector2_sum(Vector2 a, Vector2 b) {
        return Vector2 {
            .x = a.x + b.x,
            .y = a.y + b.y
        };
    }
}