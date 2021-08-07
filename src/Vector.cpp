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
    return ((this->x * v.x) + (this->y * v.y));
}

float Vector::magnitude()
{
    return sqrt(pow(this->x,2)+pow(this->y,2));
}

void Vector::rotate(float angle)
{
    this->x = this->magnitude() * cosf(angle);
    this->y = this->magnitude() * sinf(angle);
}

Vector* unitCircle(float angle)
{
    return new Vector(cosf(angle),sinf(angle));
}

