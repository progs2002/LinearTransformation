#pragma once
#include "SDL.h"
#include "Vector.h"
#include <utility>

extern Vector* offset;

int drawLine(SDL_Renderer* renderer, Vector& v1, Vector& v2);
int drawVector(SDL_Renderer* renderer, Vector& v);
int drawVector(SDL_Renderer* renderer, Vector& v, Vector& i, Vector& j);
int drawIsoVector(SDL_Renderer* renderer, Vector& v1, Vector& v2, Vector& i, Vector& j);
int drawGrid(SDL_Renderer* renderer,std::pair<Vector*,Vector*>* ver,std::pair<Vector*,Vector*>* hor, Vector& i, Vector& j, int vSize,int hSize);