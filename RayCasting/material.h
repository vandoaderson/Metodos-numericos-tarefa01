#ifndef MATERIAL_H
#define MATERIAL_H

#include "color.h"

class Material
{
public:
    Material();
    Material(const Color& amb, const Color& diff, const Color& spec, int k);
    Material(const Color& amb, const Color& diff, const Color& spec, int k, float ka, float kd, float ks);

    Color ambient;
    Color diffuse;
    Color specular;

    float Ka, Kd, Ks;

    int k;
};

#endif // MATERIAL_H
