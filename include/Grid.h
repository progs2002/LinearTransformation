#pragma once
#include "util.h"

class Grid
{
public:
	int gridSize, vSize, hSize;
	std::pair<Vector*, Vector*>* ver;
	std::pair<Vector*, Vector*>* hor;
	Grid(int gridSize, int vSize,int hSize, std::pair<Vector*, Vector*>* ver, std::pair<Vector*, Vector*>* hor);
	~Grid();
};