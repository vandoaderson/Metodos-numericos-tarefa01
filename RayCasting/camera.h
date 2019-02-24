#ifndef CAMERA_H_
#define CAMERA_H_

#include "vec3.h"
#include "point.h"
#include "ray.h"

class Camera {
public:
    Camera();
    Camera(int width, int height);
    ~Camera();

    Ray createRay(int wImg, int hImg);
    void render();

    Vec3 getLookAt();
    void lookAt( Point point );

    Point getPos();
    void setPos(Point pos);

    int imgWidth;
    int imgHeight;

    Vec3 ic;
    Vec3 jc;
    Vec3 kc;
    Point pos;
};

#endif


