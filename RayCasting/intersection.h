#ifndef INTERSECTION
#define INTERSECTION

#include "point.h"
#include "material.h"

struct Intersection {
    float dist;
    Point point;
    Vec3 norm;
    Material material;
};

#endif // INTERSECTION

