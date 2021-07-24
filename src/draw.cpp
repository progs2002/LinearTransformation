#include "draw.h"

Vector* offset = nullptr;

int drawLine(SDL_Renderer* renderer, Vector& v1, Vector& v2)
{
    SDL_RenderDrawLine(renderer, v1.x, v1.y, v2.x, v2.y);
    return 1;
}

int drawVector(SDL_Renderer* renderer, Vector& v)
{
    SDL_RenderDrawLine(renderer, offset->x, offset->y, v.x + offset->x, offset->y -  v.y);
    return 1;
}

int drawVector(SDL_Renderer* renderer, Vector& v, Vector& i, Vector& j)
{
    SDL_RenderDrawLine(renderer, offset->x, offset->y, v.dotProduct(i) + offset->x,offset->y -  v.dotProduct(j)); 
    return 1;
}

int drawIsoVector(SDL_Renderer* renderer, Vector& v1, Vector& v2, Vector& i, Vector& j)
{
    SDL_RenderDrawLine(renderer, v1.dotProduct(i) + offset->x, offset->y - v1.dotProduct(j), v2.dotProduct(i) + offset->x, offset->y - v2.dotProduct(j));
    return 1;
}
 
int drawGrid(SDL_Renderer* renderer,std::pair<Vector*,Vector*>* ver,std::pair<Vector*,Vector*>* hor, Vector& i, Vector& j, int vSize,int hSize)
{
    for(int k=0;k<vSize;k++)
        drawIsoVector(renderer, *(ver[k].first), *(ver[k].second), i, j);

    for(int k=0;k<hSize;k++)
        drawIsoVector(renderer, *(hor[k].first), *(hor[k].second), i, j); 
}