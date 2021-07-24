#pragma once
#include "Vector.h"

class Matrix
{
public:
    float ix,iy,jx,jy;

    Matrix();
    Matrix(float,float,float,float);

    Vector getiVector();
    Vector getjVector();
};