#pragma once

namespace fw {

    class vec2
    {
    public:
        vec2() { x = 0; y = 0; }
        vec2(float nx, float ny) { x = nx; y = ny; }

        vec2 operator*(float o) const { return vec2(x * o, y * o); }

        vec2 operator+=(const vec2& o) { x += o.x; y += o.y; return *this; }

    public:
        float x;
        float y;
    };

} // namespace fw
