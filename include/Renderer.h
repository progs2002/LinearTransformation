#pragma once
#include "SDL.h"
#include "Grid.h"

class Renderer
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	Vector* offset;
public:
	Renderer(const char* title, RES size);
	~Renderer();
	int drawLine(Vector& v1, Vector& v2);
	int drawVector(Vector& v);
	int drawVector(Vector& v, Vector& i, Vector& j);
	int drawIsoVector(Vector& v1, Vector& v2, Vector& i, Vector& j);
	int drawBackGround();
	int drawGrid(Grid* g);
	int drawtransGrid(Grid* g, Matrix* trans);
	void setColour(int R, int G, int B);
	void present();
};