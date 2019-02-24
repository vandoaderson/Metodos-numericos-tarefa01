#include "cone.h"

Cone::Cone()
{

}

Cone::Cone(const Point& top, const Point& base, float radius) : top(top), base(base), radius(radius) {

}

Intersection Cone::intersect(const Ray ray)
{
    // Precisamos criar uma esfera imaginária centrada em c
    // c está no centro do cone, ou seja, |cb| = raio da base do cone (b é o centro da base)
    Vec3 c = Vec3(base.x + radius, base.y + radius, base.z + radius);
    Vec3 origin = Vec3(ray.o.x, ray.o.y, ray.o.z);
    double r = sqrt((radius*radius)+(radius*radius)); // Hipotenusa é o raio da esfera

    float eqa = Dot(ray.d, ray.d);

    float eqb = 2*(Dot(origin, ray.d) - Dot(ray.d, c) );
    float eqc = Dot(c, c) - Dot(c, origin)*2 + Dot(origin, origin) - r*r;

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
        intersectPoint.norm  = (intersectPoint.point - c)/r;
    }
    else {          ///delta > 0  two roots

        float sqrtDelta = sqrtf(delta);
        float t0 = (-eqb - sqrtDelta)/(2*eqa);
        float t1 = (-eqb + sqrtDelta)/(2*eqa);

        float smallest = (t0 < t1)?t0:t1;

        intersectPoint.dist = smallest;
        intersectPoint.point = ray.o + ray.d*intersectPoint.dist;
        intersectPoint.norm  = (intersectPoint.point - c)/r;
        intersectPoint.material = this->material;
    }

    return intersectPoint;
}
