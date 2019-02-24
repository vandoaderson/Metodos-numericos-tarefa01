#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>
class vec3
{
    private:
        float x, y, z, w;

    public:
        // ------------ Constructores ------------

        // Construtor
        vec3() { x = y = z = 0; }

        vec3(float xValue, float yValue, float zValue)
        {
            x = xValue;
            y = yValue;
            z = zValue;
        }

        // ------------ Getters e setters ------------

        void set(const float &xValue, const float &yValue, const float &zValue)
        {
            x = xValue;
            y = yValue;
            z = zValue;
        }

        float getX() const { return x; }
        float getY() const { return y; }
        float getZ() const { return z; }

        void setX(const float &xValue) { x = xValue; }
        void setY(const float &yValue) { y = yValue; }
        void setZ(const float &zValue) { z = zValue; }


        // Metodo zerar vetor
        void zero()
        {
            x = y = z = 0;
        }

        // normalisa  vetor
        void normalise()
        {
            // Calcula o tamanho do vetor
            float magnitude = sqrt((x * x) + (y * y) + (z * z));

            if (magnitude != 0)
            {
                x /= magnitude;
                y /= magnitude;
                z /= magnitude;
            }
        }

        //Produto vetorial
        static float dotProduct(const vec3 &vec1, const vec3 &vec2)
        {
            return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
        }

        //produto escalar
        float dotProduct(const vec3 &vec) const
        {
            return x * vec.x + y * vec.y + z * vec.z;
        }


        // Produto vetorial
        static vec3 crossProduct(const vec3 &vec1, const vec3 &vec2)
        {
            return Vec3(vec1.y * vec2.z - vec1.z * vec2.y, vec1.z * vec2.x - vec1.x * vec2.z, vec1.x * vec2.y - vec1.y * vec2.x);
        }


        void addX(float value) { x += value; }
        void addY(float value) { y += value; }
        void addZ(float value) { z += value; }


        static float getDistance(const vec3 &v1, const vec3 &v2)
        {
            float dx = v2.x - v1.x;
            float dy = v2.y - v1.y;
            float dz = v2.z - v1.z;

            return sqrt(dx * dx + dy * dy + dz * dz);
        }

        void display()
        {
            std::cout << "X: " << x << "\t Y: " << y << "\t Z: " << z << std::endl;
        }

        vec3 operator+(const vec3 &vector) const
        {
            return vec3(x + vector.x, y + vector.y, z + vector.z);
        }

        void operator+=(const vec3 &vector)
        {
            x += vector.x;
            y += vector.y;
            z += vector.z;
        }

        vec3 operator-(const vec3 &vector) const
        {
            return vec3(x - vector.x, y - vector.y, z - vector.z);
        }

        void operator-=(const vec3 &vector)
        {
            x -= vector.x;
            y -= vector.y;
            z -= vector.z;
        }

        vec3 operator*(const vec3 &vector) const
        {
            return vec3(x * vector.x, y * vector.y, z * vector.z);
        }

        // multiplica por um escalar
        vec3 operator*(const float &value) const
        {
            return vec3(x * value, y * value, z * value);
        }

        void operator*=(const float &value)
        {
            x *= value;
            y *= value;
            z *= value;
        }

        vec3 operator/(const float &value) const
        {
            return vec3(x / value, y / value, z / value);
        }

        void operator/=(const float &value)
        {
            x /= value;
            y /= value;
            z /= value;
        }
};

#endif // VEC3_H
