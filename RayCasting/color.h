#ifndef COLOR_H
#define COLOR_H


class Color
{
public:
    Color(float red = 0, float green = 0, float blue = 0);

    Color operator*(const Color& c) const;
    Color& operator*=(const Color& c);

    void setColor(float red, float green, float blue);

    float r, g, b;
};

bool operator==(Color c1, Color c2);

#endif // COLOR_H
