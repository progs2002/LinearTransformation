#include"anim.h"

int rotate(SDL_Renderer* renderer,std::pair<Vector*,Vector*>* ver,std::pair<Vector*,Vector*>* hor, Matrix* trans, int vSize, int hSize)
{
    Vector* i = trans->getiVector();
    Vector* j = trans->getjVector();
    
    Vector* i_basis = new Vector(trans->ix/i->magnitude(),trans->iy/i->magnitude());
    Vector* j_basis = new Vector(trans->jx/j->magnitude(),trans->jy/j->magnitude());

    float i_angle = atanf(i->y/i->x);
    float j_angle = atanf(j->y/j->x);

    float max_angle = i_angle > j_angle ? i_angle : j_angle;

    int steps = max_angle/0.0001;

    float i_scale = i->magnitude();
    float j_scale = j->magnitude();

    float i_scale_increment = i_scale/steps;
    float j_scale_increment = j_scale/steps;

    Matrix* demoMatrix;

    for(int i = 1; i <= steps; i++)
    {
        float temp_i_angle = i_angle/(steps - 1) * (i - 1);
        float temp_j_angle = j_angle/(steps - 1) * (i - 1);
        float temp_i_scale = (i_scale/(steps - 1) * (i - 1)) + 1;
        float temp_j_scale = (j_scale/(steps - 1) * (i - 1)) + 1;
        demoMatrix->ix = temp_i_scale * cos(temp_i_angle);
		demoMatrix->iy = temp_i_scale * sin(temp_i_angle);
		demoMatrix->jx = temp_j_scale * -sin(temp_j_angle);
		demoMatrix->jy = temp_j_scale * cos(temp_j_angle);
        drawGrid(renderer, ver, hor, *(demoMatrix->getiVector()), *(demoMatrix->getjVector()), vSize, hSize);
        SDL_RenderPresent(renderer);
    }

    /*
    for(float angle = 0.0f; angle < i_angle; angle+=0.01)
    {
		demoMatrix->ix = cos(angle);
		demoMatrix->iy = sin(angle);
		demoMatrix->jx = -sin(angle);
		demoMatrix->jy = cos(angle);
        drawGrid(renderer, ver, hor, *(demoMatrix->getiVector()), *(demoMatrix->getjVector()), vSize, hSize);
        SDL_RenderPresent(renderer);
    }
    */

    std::cout << "rotaion done\n";
    return 1;

}