#include "Renderer.h"

Renderer::Renderer(const char* title, RES size)
{
	offset = new Vector(size.W / 2, size.H / 2);
	window = SDL_CreateWindow(title , SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.W, size.H, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
}

int Renderer::drawLine(Vector& v1, Vector& v2)
{
	SDL_RenderDrawLine(this->renderer, v1.x, v1.y, v2.x, v2.y);
	return 1;
}

int Renderer::drawVector(Vector& v)
{
	SDL_RenderDrawLine(this->renderer, this->offset->x, this->offset->y, v.x + this->offset->x, this->offset->y - v.y);
	return 1;
}

int Renderer::drawVector(Vector& v, Vector& i, Vector& j)
{
	SDL_RenderDrawLine(this->renderer, this->offset->x, this->offset->y, v.dotProduct(i) + this->offset->x, this->offset->y - v.dotProduct(j));
	return 1;
}

int Renderer::drawIsoVector(Vector& v1, Vector& v2, Vector& i, Vector& j)
{
	SDL_RenderDrawLine(this->renderer, v1.dotProduct(i) + this->offset->x, this->offset->y - v1.dotProduct(j), v2.dotProduct(i) + this->offset->x, this->offset->y - v2.dotProduct(j));
	return 1;
}

int Renderer::drawBackGround()
{
	SDL_RenderClear(renderer);
	return 1;
}

void Renderer::setColour(int R, int G, int B)
{
	SDL_SetRenderDrawColor(renderer, R, G, B, SDL_ALPHA_OPAQUE);
}

void Renderer::present()
{
	SDL_RenderPresent(renderer);
}

int Renderer::drawGrid(Grid* g)
{
	Vector i(1, 0);
	Vector j(0, 1);

	for (int k = 0; k < g->vSize; k++)
		drawIsoVector(*(g->ver[k].first), *(g->ver[k].second), i, j);

	for (int k = 0; k < g->hSize; k++)
		drawIsoVector(*(g->hor[k].first), *(g->hor[k].second), i, j);
		
	return 1;
}

int Renderer::drawtransGrid(Grid* g, Matrix* trans)
{
	Vector i = *(trans->getiVector());
	Vector j = *(trans->getjVector());

	for (int k = 0; k < g->vSize; k++)
		drawIsoVector(*(g->ver[k].first), *(g->ver[k].second), i, j);

	for (int k = 0; k < g->hSize; k++)
		drawIsoVector(*(g->hor[k].first), *(g->hor[k].second), i, j);

	return 1;
}


Renderer::~Renderer()
{
	delete offset;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	std::cout << "deleted window and renderer" << std::endl;
}

