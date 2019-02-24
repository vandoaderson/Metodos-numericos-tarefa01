#ifndef VEC3_H
#define VEC3_H

class Point;

class Vec3
{
public:
    Vec3();
    Vec3(const Point& p);
    Vec3(float _x, float _y, float _z);

    Vec3 operator+(const Vec3& v) const;
    Vec3& operator+=(const Vec3& v);
    Vec3 operator-(const Vec3& v) const;
    Vec3& operator-=(const Vec3& v);

    Vec3 operator*(float f) const;
    Vec3& operator*=(float f);
    Vec3 operator/(float f) const;
    Vec3& operator/=(float f);

    float length();

    void normalize();

    float x,y,z;

};

double Dot(const Vec3& v1, const Vec3& v2);

Vec3 Cross(const Vec3& v1, const Vec3& v2);


#endif // VEC3_H
