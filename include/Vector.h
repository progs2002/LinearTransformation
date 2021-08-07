#pragma once
#include <math.h>

class Vector
{
public:
    float x,y;

    Vector(); 

    Vector(float x, float y);

    float dotProduct(Vector v);

    void rotate(float angle);


    float magnitude();
};

Vector* unitCircle(float angle);
