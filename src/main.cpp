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

	int tempV =  -1 * size.W/2;
	int tempH = size.H/2;

	float temp_i_angle = 0.0f;
	float temp_j_angle = 0.0f;

	float i_scale, j_scale;
	float temp_i_scale = 1, temp_j_scale = 1; 

	Vector* i_temp = new Vector(1,0);
	Vector* j_temp = new Vector(0,1);

	bool iDone = false, jDone = false;

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

	Matrix* transMatrix = getMatrix();

	i_scale = transMatrix->getiVector()

	float i_angle = atan(transMatrix->iy/transMatrix->ix), j_angle = atan(transMatrix->jy/transMatrix->jx);
	
	int state = 0;

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
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
		drawGrid(renderer, ver, hor, i, j, vSize, hSize);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
		if(state == 0 )
		{
			if(!iDone)
				i_temp = new Vector(cos(temp_i_angle),sin(temp_i_angle));
			if(!jDone)
				j_temp = new Vector(cos(temp_j_angle),sin(temp_j_angle));
			drawGrid(renderer, ver, hor, *i_temp, *j_temp, vSize, hSize);
			temp_i_angle+=0.0001;
			temp_j_angle+=0.0001;
			if(temp_i_angle >= i_angle)	iDone = true;
			if(temp_j_angle >= j_angle)	jDone = true;
			if(iDone && jDone) {state = 1; iDone = false; jDone = false;}
			// delete i_temp;
			// delete j_temp;
		}
		else if(state == 1)
		{

		}
		else
			drawGrid(renderer, ver, hor, *(transMatrix->getiVector()), *(transMatrix->getjVector()), vSize, hSize);
		SDL_RenderPresent(renderer);
	}

	delete offset;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}