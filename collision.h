#ifndef COLLISION_H
#define COLLISION_H
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// Classe dediee pour la gestion des collisions

class collision
{
private:
    float x=0,y=0,z=0;
    GLdouble d=0;
    const static int nbAstMax = 50;
    int nbAst=0;
    float tabx_[nbAstMax];
    float taby_[nbAstMax];
    float tabz_[nbAstMax];
    GLdouble tabd_[nbAstMax];
public:
    collision(int nbAst);
    float RandomFloat(float min, float max);
    bool checkAstCol(float tabx_[nbAstMax], float taby_[nbAstMax], float tabz_[nbAstMax], GLdouble tabd_[nbAstMax]);
};

#endif // COLLISION_H
