#include "Grid.h"

Grid::Grid(int gridSize, int vSize, int hSize, std::pair<Vector*, Vector*>* ver, std::pair<Vector*, Vector*>* hor)
{
	this->gridSize = gridSize; 
	this->vSize = vSize;
	this->hSize = hSize;
	this->ver = ver;
	this->hor = hor;
}

Grid::~Grid()
{
	for (int i = 0; i < vSize; i++)
	{
		delete ver[i].first;
		delete ver[i].second;
	}

	for (int i = 0; i < hSize; i++)
	{
		delete hor[i].first;
		delete hor[i].second;
	}

	std::cout << "Grid cleaned up";
}
