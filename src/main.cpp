#include "../include/SDL2/SDL.h"
#include "Vector.h"
#include "draw.h"
#include "util.h"

int main(int argv, char** args)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	RES size = getRES();

	offset = new Vector(size.W/2,size.H/2); 

	SDL_Window *window = SDL_CreateWindow("Linear Transformation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.W, size.H, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	bool isRunning = true;
	SDL_Event event;

	Vector v1(300,300);
	Vector v2(300,-300);
	Vector i(1,0) , j(0,1);

	//getting our grid vector pairs
	int gridSize = 50;

	int vSize = size.W/gridSize;
	int hSize = size.H/gridSize;

	int tempV =  -1 * size.H/2;
	int tempH =  -1 * size.W/2;

	std::pair<Vector*,Vector*>* ver = new std::pair<Vector*,Vector*>[vSize];
	std::pair<Vector*,Vector*>* hor = new std::pair<Vector*,Vector*>[hSize];
	for(int i = 0; i < vSize; i++)
	{
		ver[i] = {new Vector(tempV,size.H), new Vector(tempV, -1*size.H)};
		tempV+=gridSize;
	}

	for(int i = 0; i < hSize; i++)
	{
		hor[i] = {new Vector(-size.W,tempH), new Vector(size.W,tempH)};
		tempH-=gridSize;
	}

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

		//rendering bg color
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		//drawing other stuff
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		drawGrid(renderer, ver, hor, i, j, vSize, hSize);

		SDL_RenderPresent(renderer);
	}

	delete offset;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}