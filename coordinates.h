#ifndef COORDINATES_H
#define COORDINATES_H
#include <GL/gl.h>
#include <GL/glu.h>


class coordinates
{
private:
    float x=0,y=0,z=0;
    GLdouble d=0;
    const static int nbAst = 40;
    float tabx_[nbAst];
    float taby_[nbAst];
    float tabz_[nbAst];
    GLdouble tabd_[nbAst];
public:
    coordinates();
    float RandomFloat(float min, float max);
    bool checkAstCol(float tabx_[nbAst], float taby_[nbAst], float tabz_[nbAst], GLdouble tabd_[nbAst]);
};

#endif // COORDINATES_H
