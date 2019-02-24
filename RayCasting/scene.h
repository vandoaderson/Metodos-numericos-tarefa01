#ifndef SCENE_H
#define SCENE_H

#include<vector>
#include "sphere.h"
#include "cone.h"
#include "polygon.h"


struct Light {
    Color color;
    Point position;
    float attenuation;
};

class Scene
{
public:
    Scene();

    bool intersect(const Ray& ray, Intersection &intersect);

    void addLight(const Point& center, float r, float g, float b, float att);

    void addSphere(const Point& center, float radius, Material mat);

    void addCone(const Point& top, const Point& base, float radius, Material mat);

    std::vector<Polygon*> objects;

    std::vector<Light> lights;
};





#endif // SCENE_H
