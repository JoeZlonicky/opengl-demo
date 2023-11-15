#ifndef OPENGL_DEMO_QUATERNION_H_
#define OPENGL_DEMO_QUATERNION_H_

#include <cmath>
#include "vector_3.h"
#include "matrix_4.h"
#include "matrix_3.h"

// Implementation takes inspiration from
// 1) Foundation of Game Engine Development, Volume 1: Mathematics by Eric Lengyel
// 2) Godot Game Engine source code
struct Quaternion {
    union {
        struct {
            float x;
            float y;
            float z;
            float w;
        };
        float components[4] = {0.f, 0.f, 0.f, 1.f};
    };

    Quaternion() : Quaternion({1.0f, 0.f, 0.f}, 0.f) {}

    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    Quaternion(Vector3 axis, float angle_degrees);

    void set(float x, float y, float z, float w);

    [[nodiscard]] Matrix3 calcRotationMatrix3() const;
    [[nodiscard]] Matrix4 calcRotationMatrix4() const;

    [[nodiscard]] Vector3& getVectorPart();
    [[nodiscard]] const Vector3& getVectorPart() const;

    float& operator[](int i);
    const float& operator[](int i) const;

    Quaternion& operator*=(const Quaternion& q);
};

Quaternion operator*(Quaternion a, const Quaternion& b);

#endif
