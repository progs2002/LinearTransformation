#include "../include/SDL2/SDL.h"
#include "Vector.h"
#include "draw.h"
#include "util.h"
#include "Timer.h"

int main(int argv, char** args)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	RES size = getRES();

	offset = new Vector(size.W/2,size.H/2); 

	SDL_Window *window = SDL_CreateWindow("Linear Transformation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.W, size.H, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	//experimental(lol it works)
	size.W*=2;
	size.H*=2;

	bool isRunning = true;
	SDL_Event event;

	Vector v1(300,300);
	Vector v2(300,-300);
	Vector i(1,0) , j(0,1);
	double angle_degrees= 0;
	double angle_radians;

	//getting our grid vector pairs
	int gridSize = 50;

	int vSize = size.W/gridSize;
	int hSize = size.H/gridSize;

	int tempV =  -1 * size.W/2;
	int tempH = size.H/2;

	std::pair<Vector*,Vector*>* ver = new std::pair<Vector*,Vector*>[vSize];
	std::pair<Vector*,Vector*>* hor = new std::pair<Vector*,Vector*>[hSize];
	for(int i = 0; i < vSize; i++)
	{
		ver[i] = {new Vector(tempV,size.H/2), new Vector(tempV, -1*size.H/2)};
		tempV+=gridSize;
	}

	for(int i = 0; i < hSize; i++)
	{
		hor[i] = {new Vector(-size.W/2,tempH), new Vector(size.W/2,tempH)};
		tempH-=gridSize;
	}

	//Matrix* transMatrix = getMatrix();
	Matrix* transMatrix = new Matrix(0,0,0,0);

	while (isRunning)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				isRunning = false;
				break;
			}
		}

		angle_radians = angle_degrees * 3.14159 / 180;
		transMatrix->ix = cos(angle_radians);
		transMatrix->iy = sin(angle_radians);
		transMatrix->jx = -sin(angle_radians);
		transMatrix->jy = cos(angle_radians);

		//rendering bg color
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		//drawing other stuff
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		drawGrid(renderer, ver, hor, i, j, vSize, hSize);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		drawGrid(renderer, ver, hor, *(transMatrix->getiVector()), *(transMatrix->getjVector()), vSize, hSize);
		SDL_RenderPresent(renderer);

		//speed = 90 deg per second
		//angle_degrees += 90 * getTime() * 1e-9;
		angle_degrees += 0.01;
	}

	//cleanup
	delete offset;
	delete transMatrix;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}