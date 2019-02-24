#include "camera.h"

Camera::Camera() :  ic(Vec3(1.0, 0.0, 0.0)), jc(Vec3(0.0, 1.0, 0.0)),
                    kc(Vec3(0.0, 0.0, 1.0)), pos(0.0, 0.0, 17.0)
{

}

Camera::Camera(int width, int height)
{
    imgWidth = width;
    imgHeight = height;

    ic = Point(1.0, 0.0, 0.0);
    jc = (Point(0.0, -1.0, 0.0));
    kc = (Point(0.0, 0.0, 1.0));
}

Camera::~Camera() {

}

Ray Camera::createRay(int wImg, int hImg) {
    float xw = (-1.0/2.0) + ((1.0 / imgWidth) + (wImg *(1.0 / imgWidth)));
    float yw = (1.0/2.0) - ((1.0 / imgHeight) + (hImg * (1.0 / imgHeight)));

    //projected point
    Point p = pos + kc*(-1.0) + ic*xw + jc*yw;
    Vec3 dir = p - pos;
    dir.normalize();

    //Create ray
    return Ray(pos, dir);
}

Point Camera::getPos() {
    return this->pos;
}

void Camera::setPos(Point pos) {
    this->pos = pos;
}

Vec3 Camera::getLookAt()
{
    return this->kc;
}

void Camera::lookAt(Point point )
{
    this->kc = this->pos - point;
    this->kc.normalize();

    this->ic = Cross( ( ( point + Point(0, 1.0, 0) ) - this->pos  ), this->kc );
    this->ic.normalize();

    this->jc = Cross( this->kc, this->ic  );
}
