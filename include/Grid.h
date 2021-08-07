#pragma once
#include "stdlib.h"
#include "util.h"
#include <utility>

class Grid
{
public:
    int gridSize;
    int vSize, hSize;
    std::pair<Vector*,Vector*>* ver;
    std::pair<Vector*,Vector*>* hor;
    RES size;
    Matrix* trans;
    Grid();
    Grid(int gridSize, RES size);
    Grid(int gridSize, RES size, Matrix* trans);
};