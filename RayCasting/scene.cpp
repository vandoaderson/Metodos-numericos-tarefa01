#include "scene.h"
#include <list>
#include <float.h>


Scene::Scene()
{

}


/**
 * Function to check an ray intersection of an entire scene.
 * Returns true if there is any intersection, false otherwise.
**/
bool Scene::intersect(const Ray& ray, Intersection &intersect) {

    float dist = FLT_MAX;
    Intersection closest;   //we want the closest intersection

    for(std::vector<Polygon*>::iterator iter = objects.begin(); iter != objects.end(); iter++) {

        Intersection inter = (*iter)->intersect(ray);

        if( inter.dist > 0.0 && inter.dist<=dist )  //There is an intersection
        {
            dist = inter.dist;
            closest = inter;
        }
    }

    if ( dist == FLT_MAX )
        return false;

    intersect = closest;

    return true;
}

/**
 * Add a new light
 **/
void Scene::addLight(const Point& center, float r, float g, float b, float att)
{
    Light luz;
    luz.color.setColor(r, g, b);
    luz.position = center;
    luz.attenuation = att;

    lights.push_back(luz);
}

/**
 * Add a Sphere
 **/
void Scene::addSphere(const Point& center, float radius, Material mat)
{
    Sphere *s = new Sphere(center, radius);
    s->material=mat;

    objects.push_back(s);
}

/**
 * Add a Cone
 **/
void Scene::addCone(const Point& top, const Point& base, float radius, Material mat)
{
    Cone *c = new Cone(top, base, radius);
    c->material=mat;

    objects.push_back(c);
}
