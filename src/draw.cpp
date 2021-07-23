#include "draw.h"

int drawLine(SDL_Renderer* renderer, Vector v1, Vector v2)
{
    SDL_RenderDrawLine(renderer, v1.x, v1.y, v2.x, v2.y);
}