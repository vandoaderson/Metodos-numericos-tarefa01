#ifndef RAY
#define RAY

#include "point.h"
#include "vec3.h"

class Ray {
    public:
        Ray() {};
        Ray(const Point& p, const Vec3& v) : o(p), d (v) { }

        Point operator()(float t) const{
            return o + d*t;
        }

        Vec3 ray() {
            Vec3 ray;
            ray = (o-d);
            ray.normalize();
            return ray;
        }

        Point o;
        Vec3 d;
};

#endif // RAY

