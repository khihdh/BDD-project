#ifndef COLLISION_H
#define COLLISION_H
#include <GL/gl.h>
#include <GL/glu.h>

// Classe dediee pour la gestion des collisions

class collision
{
private:
    float x=0,y=0,z=0;
    GLdouble d=0;
    const static int nbAstMax = 16;
    int nbAst=0;
    float tabx_[nbAstMax];
    float taby_[nbAstMax];
    float tabz_[nbAstMax];
    GLdouble tabd_[nbAstMax];
public:
    collision(int nbAst);
    void setNbAst(int nbAst2);
    float RandomFloat(float min, float max);
    bool checkAstCol(float tabx_[nbAstMax], float taby_[nbAstMax], float tabz_[nbAstMax], GLdouble tabd_[nbAstMax]);
};

#endif // COLLISION_H
