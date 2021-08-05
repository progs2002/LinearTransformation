#pragma once
#include "draw.h"
#include "Matrix.h"
#include <math.h>
#include <iostream>
int rotate(SDL_Renderer* renderer,std::pair<Vector*,Vector*>* ver,std::pair<Vector*,Vector*>* hor, Matrix* trans, int vSize, int hSize);