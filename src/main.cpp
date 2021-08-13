#include "Renderer.h"

Renderer* pen;
Matrix* trans;

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;

SDL_Event event;

bool isRunning = false;

Grid* grid;
RES size;

void update()
{
	//get delta time

	lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentTick - lastTick) * 1000 / (double)SDL_GetPerformanceFrequency()); // in milliseconds
	
	//handle events

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
			break;
		}
	}
	
}

void render()
{
	//display simpleWindow
	pen->setColour(40, 52, 156);
	pen->drawBackGround();
	pen->setColour(0, 0, 0);
	pen->drawGrid(grid);
	pen->setColour(255, 255, 255);
	pen->drawtransGrid(grid, trans);
	pen->present();
}

int init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	size = getRES();
	trans = getMatrix();
	pen = new Renderer("Linear Transformations", size);
	

	//create grid
	int gridSize = 50;
	int tempV = -1 * size.H / 2;
	int tempH = size.W / 2;
	int vSize = size.W / gridSize;
	int hSize = size.H / gridSize;

	std::pair<Vector*, Vector*>* ver = new std::pair<Vector*, Vector*>[vSize];
	std::pair<Vector*, Vector*>* hor = new std::pair<Vector*, Vector*>[hSize];

	for (int k = 0; k < vSize; k++)
	{
		ver[k].first = new Vector(tempV, size.H);
		ver[k].second = new Vector(tempV, -1*size.H);
		tempV += gridSize;
	}

	for (int k = 0; k < hSize; k++)
	{
		hor[k].first = new Vector(-1 * size.W, tempH);
		hor[k].second = new Vector(size.W, tempH);
		tempH -= gridSize;
	}

	grid = new Grid(gridSize,vSize,hSize,ver,hor);

	isRunning = true;
	return 1;
}

int main(int argc, char* args[])
{
	init();

	while (isRunning)
	{
		update();
		render();
	}

	delete pen;
	delete trans;
	delete grid;

	return 0;
}