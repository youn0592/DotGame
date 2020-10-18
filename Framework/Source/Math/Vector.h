#pragma once

#include <cmath>

namespace fw {

    class vec2
    {
    public:
        vec2() { x = 0; y = 0; }
        vec2(float nx, float ny) { x = nx; y = ny; }

        //Float Operators
        vec2 operator*(const float o) const { return vec2(x * o, y * o); }
        vec2 operator/(const float o) const { return vec2(x / o, y * o); }
        vec2 operator+(const float o) const { return vec2(x + o, y + o); }
        vec2 operator-(const float o) const { return vec2(x - o, y - o); }

        vec2 operator=(const float o)  { return vec2(x = o, y = o); }
        vec2 operator+=(const float o) { return vec2(x += o, y += o); }
        vec2 operator-=(const float o) { return vec2(x -= o, y -= o); }
        vec2 operator*=(const float o) { return vec2(x *= o, y *= o); }
        vec2 operator/=(const float o) { return vec2(x /= o, y /= o); }



        //Vec2 Operators
        vec2 operator+(const vec2& o) const { x + o.x, y + o.y; return *this; }
        vec2 operator-(const vec2& o) const { x - o.x, y - o.y; return *this; }
        vec2 operator*(const vec2& o) const { x * o.x, y * o.y; return *this; }
        vec2 operator/(const vec2& o) const { x / o.x, y / o.y; return *this; }

        vec2 operator=(const vec2& o) { x = o.x, y = o.y; return *this; }
        vec2 operator+=(const vec2& o) { x += o.x; y += o.y; return *this; }
        vec2 operator-=(const vec2& o) { x -= o.x; y -= o.y; return *this; }
        vec2 operator*=(const vec2& o) { x *= o.x, y *= o.y; return *this; }
        vec2 operator/=(const vec2& o) { x /= o.x, y /= o.y; return *this; }

        bool operator==(const vec2& o) const { return x == o.x && y == o.y; }
        bool operator!=(const vec2& o) const { return x != o.x && y != o.y; }

        vec2 normalize(const vec2 o) {
            if (magnitude() == 0) return *this;
            *this /= magnitude();
            return *this;
        }
        float magnitude() { return std::sqrt(x * x + y * y);}
        float distance(vec2& o) const { vec2 dis(o.x - x, o.y - y); return dis.magnitude(); }
        vec2 normalized() { vec2 temp = *this; temp /= magnitude(); return temp; };

        static float dot(const vec2 vect1, const vec2 vect2) { return vect1.x * vect2.x + vect1.y * vect2.y; }



    public:
        float x;
        float y;
    };

} // namespace fw
