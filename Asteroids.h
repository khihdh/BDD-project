#include <qopengl.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <QColor>
#include <vector>


// Classe dediee pour la gestion du sol
class Asteroids
{


private:
    GLuint * textures;
    GLuint * textures_2;
    const static int nbAst = 16;
    float c =10;
    float tabx_[nbAst];
    float taby_[nbAst];
    float tabz_[nbAst];
    GLdouble tabd_[nbAst];
    float x=0, y=0, z=0;

public:
    // Constructeur avec parametres
    Asteroids(float tabx_[nbAst], float taby_[nbAst], float tabz_[nbAst], GLdouble tabd_[nbAst]);


    // Destructeur
    ~Asteroids();

    // Methode d'affichage
    float RandomFloat(float min, float max);
    void Display(uint64_t iTimeElapsed) ;
    void DrawAst(float x, float y, float z, GLdouble d);
};
