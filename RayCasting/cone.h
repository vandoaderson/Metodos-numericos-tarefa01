#ifndef CONE_H
#define CONE_H

#include "point.h"
#include "vec3.h"
#include "ray.h"
#include "intersection.h"
#include "polygon.h"

class Cone: public Polygon
{
public:
    Cone();
    Cone(const Point& top, const Point& base, float radius);

//    Vec3 getNormal(const Point p) { return (p - center)/radius; } // Precisamos disso? Se sim, como?

    Intersection intersect(const Ray ray);

    float radius;
    Point top;
    Point base;
    Material material;
};

#endif // CONE_H
