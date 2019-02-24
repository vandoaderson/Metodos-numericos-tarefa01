#include "sphere.h"

Sphere::Sphere()
{

}

Sphere::Sphere(const Point& center, float radius) : center(center), radius(radius) {

}

Intersection Sphere::intersect(const Ray ray)
{
    Vec3 c = Vec3(center.x, center.y, center.z);
    Vec3 origin = Vec3(ray.o.x, ray.o.y, ray.o.z);
    float eqa = Dot(ray.d, ray.d);

    float eqb = 2*(Dot(origin, ray.d) - Dot(ray.d, c) );
    float eqc = Dot(c, c) - Dot(c, origin)*2 + Dot(origin, origin) - radius*radius;

    float delta = eqb*eqb - 4*eqa*eqc;

    Intersection intersectPoint;
    intersectPoint.dist = 0.0;

    if (delta < 0) {
        return intersectPoint;
    }
    else if (delta == 0) {                  ///delta == 0  one root
        Intersection intersectPoint;
        intersectPoint.dist = -eqb/(2*eqa);
        intersectPoint.point = ray.o + ray.d*intersectPoint.dist;
        intersectPoint.material = this->material;
        intersectPoint.norm  = this->getNormal(intersectPoint.point);
    }
    else {          ///delta > 0  two roots

        float sqrtDelta = sqrtf(delta);
        float t0 = (-eqb - sqrtDelta)/(2*eqa);
        float t1 = (-eqb + sqrtDelta)/(2*eqa);

        float smallest = (t0 < t1)?t0:t1;

        intersectPoint.dist = smallest;
        intersectPoint.point = ray.o + ray.d*intersectPoint.dist;
        intersectPoint.norm  = this->getNormal(intersectPoint.point);
        intersectPoint.material = this->material;
    }

    return intersectPoint;
}

