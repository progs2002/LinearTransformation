#include "Matrix.h"

Matrix::Matrix(float ix, float iy, float jx, float jy)
{
  this->ix=ix;
  this->iy=iy;
  this->jx=jx;
  this->jy=jy;
}

Vector* Matrix::getiVector()
{
  return new Vector(ix,iy);
}

Vector* Matrix::getjVector()
{
  return new Vector(jx,jy);
}