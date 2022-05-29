#include <qopengl.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <QColor>
#include <vector>


class Asteroids
{


private:
    GLuint * textures;
    GLuint * textures_2;
    int nbAst=0;
    const static int nbAstMax = 40;
    float c =10;
    float tabx_[nbAstMax];
    float taby_[nbAstMax];
    float tabz_[nbAstMax];
    GLUquadricObj *tabAst[nbAstMax];
    GLdouble tabd_[nbAstMax];
    float x=0, y=0, z=0;
    float spaceshipz_=0;
    bool tabFlagDeleteAst[nbAstMax];
    float xSpaceShip=0,ySpaceShip=0,zSpaceShip=0;

public:
    // Constructeur avec parametres
    Asteroids(float tabx_[nbAstMax], float taby_[nbAstMax], float tabz_[nbAstMax], GLdouble tabd_[nbAstMax], int nbAst);
    void incrCoordinatesZSpaceship();


    // Destructeur
    ~Asteroids();

    // Methode d'affichage
    float RandomFloat(float min, float max);
    void Display(uint64_t iTimeElapsed) ;
    void DrawAst(float x, float y, float z, GLdouble d, int  i);
    void DeleteAst(int j);
    int CheckColSpaceship(float x, float y, float z);
    void incrSpaceShip(float x, float y, float z);
};
