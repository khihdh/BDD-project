#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>
#include <vector>


//Cette classe permet de permet de dessiner l’espace et puis de dessiner les astéroïdes dans l’espace et de les faire tourner sur eux même autour de l’axe y. 
class Asteroids
{


private:
    GLuint * textures;
    GLuint * textures_2;
    int nbAst=0;
    const static int nbAstMax = 16;
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
    void setNbAst(int nbAst2);


    // Destructeur
    ~Asteroids();

    // Methode d'affichage
    float RandomFloat(float min, float max);
    void Display(uint64_t iTimeElapsed) ;
    //Cette fonction permet de dessiner un asteroide en fonction des coordonees x, y et z choisis, et du diamètre d choisis
    //param : coordonnees x,y et z, diametre de l'asteroide et son numero
    void DrawAst(float x, float y, float z, GLdouble d, int  i);
    void DeleteAst(int j);
    //cette fonction permet de checker si le vaisseau entre en collision avec un des asteroides dessinee 
    //param: coordonnees x,y,z du vaisseau
    //return: -1 si il n'y a pas de colission et 1 si il y a colission
    int CheckColSpaceship(float x, float y, float z);
    void incrSpaceShip(float x, float y, float z);
};
