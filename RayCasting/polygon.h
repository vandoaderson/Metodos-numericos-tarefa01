#ifndef POLYGON_H
#define POLYGON_H

#include "ray.h"
#include "intersection.h"

class Polygon
{
public:

    virtual Intersection intersect(const Ray ray) { }
};

#endif // POLYGON_H
