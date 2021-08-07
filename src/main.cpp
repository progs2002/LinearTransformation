#include "Vector.h"
#include <utility>
#include "Grid.h"
#include <iostream>
#include "../include/SDL2/SDL.h"

SDL_Window *window;
SDL_Renderer *renderer;
bool isRunning = false;
SDL_Event event;

RES size;

Matrix* transMatrix;

Grid* ogGrid;
Grid* transGrid;

Vector* offset;

//rotation testing
Vector* test;
Vector* test2;
Vector i(1,0), j(0,1);
float angle,angle2;

int drawLine(Vector& v1, Vector& v2)
{
    SDL_RenderDrawLine(renderer, v1.x, v1.y, v2.x, v2.y);
    return 1;
}

int drawVector(Vector& v)
{
    SDL_RenderDrawLine(renderer, offset->x, offset->y, v.x + offset->x, offset->y -  v.y);
    return 1;
}

int drawVector(Vector& v, Vector& i, Vector& j)
{
    SDL_RenderDrawLine(renderer, offset->x, offset->y, v.dotProduct(i) + offset->x,offset->y -  v.dotProduct(j)); 
    return 1;
}

int drawIsoVector(Vector& v1, Vector& v2, Vector& i, Vector& j)
{
    SDL_RenderDrawLine(renderer, v1.dotProduct(i) + offset->x, offset->y - v1.dotProduct(j), v2.dotProduct(i) + offset->x, offset->y - v2.dotProduct(j));
    return 1;
}


int drawGrid(std::pair<Vector*,Vector*>* ver,std::pair<Vector*,Vector*>* hor, Vector& i, Vector& j, int vSize,int hSize)
{
    for(int k=0;k<vSize;k++)
        drawIsoVector(*(ver[k].first), *(ver[k].second), i, j);

    for(int k=0;k<hSize;k++)
        drawIsoVector(*(hor[k].first), *(hor[k].second), i, j); 
}

int init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    RES size = getRES();
    transMatrix = getMatrix();
    offset = new Vector(size.W/2,size.H/2);
    test = new Vector(200,0);
    test2 = new Vector(200,100);
    angle = 0.0f; angle2 = 3.14/2;
    window = SDL_CreateWindow("Linear Transformation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.W, size.H, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
    isRunning = true;
    return 1;
}

int draw(Grid* grid)
{
    for(int k=0;k<grid->vSize;k++)
        drawIsoVector(*(grid->ver[k].first), *(grid->ver[k].second), *(grid->trans->getiVector()), *(grid->trans->getjVector()));
    for(int k=0;k<grid->hSize;k++)
        drawIsoVector(*(grid->hor[k].first), *(grid->hor[k].second), *(grid->trans->getiVector()), *(grid->trans->getjVector()));
    return 1;
}

int render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    
    delete test;
    delete test2;
    test = new Vector(200*cos(angle),200*sin(angle));
    test2 = new Vector(100*cos(angle2)+200*cos(angle),100*sin(angle2)+200*sin(angle));
    drawVector(*test);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    drawIsoVector(*test2,*test,i,j);
    //this is not working
    // draw(ogGrid);
	// SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    // draw(transGrid);

    SDL_RenderPresent(renderer);
}

int main(int argv, char** args)
{
    init();
    ogGrid = new Grid(50, size);
    transGrid = new Grid(50, size, transMatrix);

    

    while(isRunning)
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
        render();
        angle += 0.0005;
        angle2 += 0.001;
    }

    delete offset;
    delete transGrid;
    delete ogGrid;

    SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

    return 1;
}
