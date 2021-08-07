#include "Grid.h"

Grid::Grid(int gridSize, RES size)
{
    this->gridSize = gridSize;

    this->size = size;

    this->vSize = this->size.W/gridSize;
    this->hSize = this->size.H/gridSize;
    
    int tempV = -1 * this->size.W / 2;
    int tempH = this->size.H / 2;

    this->ver = new std::pair<Vector*,Vector*>[this->vSize];
    this->hor = new std::pair<Vector*,Vector*>[this->hSize];

    for(int i = 0; i < vSize; i++)
	{
		this->ver[i] = {new Vector(tempV,this->size.H/2), new Vector(tempV, -1*this->size.H/2)};
		tempV+=this->gridSize;
	}

    for(int i = 0; i < hSize; i++)
	{
		this->hor[i] = {new Vector(-this->size.W/2,tempH), new Vector(this->size.W/2,tempH)};
		tempH-=this->gridSize;
	}

    this->trans = new Matrix(1,0,0,1);
}

Grid::Grid(int gridSize, RES size, Matrix* trans)
{
    this->gridSize = gridSize;

    this->size = size;

    this->vSize = this->size.W/gridSize;
    this->hSize = this->size.H/gridSize;
    
    int tempV = -1 * this->size.W / 2;
    int tempH = this->size.H / 2;

    this->ver = new std::pair<Vector*,Vector*>[this->vSize];
    this->hor = new std::pair<Vector*,Vector*>[this->hSize];

    for(int i = 0; i < vSize; i++)
	{
		this->ver[i] = {new Vector(tempV,this->size.H/2), new Vector(tempV, -1*this->size.H/2)};
		tempV+=this->gridSize;
	}

    for(int i = 0; i < hSize; i++)
	{
		this->hor[i] = {new Vector(-this->size.W/2,tempH), new Vector(this->size.W/2,tempH)};
		tempH-=this->gridSize;
	}

    this->trans = trans;
}
