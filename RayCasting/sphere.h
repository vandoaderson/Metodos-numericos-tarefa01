#ifndef SPHERE_H
#define SPHERE_H

#include "point.h"
#include "vec3.h"
#include "ray.h"
#include "intersection.h"
#include "polygon.h"

class Sphere: public Polygon
{
public:
    Sphere();
    Sphere(const Point& center, float radius);

    Vec3 getNormal(const Point p) { return (p - center)/radius; }

    Intersection intersect(const Ray ray);

    float radius;
    Point center;
    Material material;
};

#endif // SPHERE_H
