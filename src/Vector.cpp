#include "Vector.h"

Vector::Vector()
{
    this->x = 0.0f;
    this->y = 0.0f;
}

Vector::Vector(float x ,float y)
{
    this->x = x;
    this->y = y;
}

float Vector::dotProduct(Vector v)
{
    return (this->x * v.x) + (this->y * v.y);
}