#ifndef POINT_H
#define POINT_H

#include "vec3.h"
#include "cmath"

class Point
{
public:
public:

    Point() { x = y = z = 0.0; }
    Point(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { }

    Point operator+(const Vec3& v) const {
        return Point(x + v.x, y + v.y, z + v.z);
    }

    Point& operator+=(const Vec3& v) {
        x += v.x; y += v.y; z += v.z;
        return *this;
    }

    Vec3 operator-(const Point& p) const {
        return Vec3(x - p.x, y - p.y, z - p.z);
    }

    Point operator-(const Vec3& v) const {
        return Point(x - v.x, y - v.y, z- v.z);
    }

    Point& operator-=(const Vec3& v){
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }

    Point operator/(float div) const {
        return Point(x/div, y/div, z/div);
    }
    Point& operator/=(float div) {
        x /= div; y/= div; z /= div;
        return *this;
    }


    void normalize() {
        float len = sqrt(x*x + y*y + z*z );
        x/=len; y /= len; z /= len;
    }


    float x, y, z;
};

#endif // POINT_H
