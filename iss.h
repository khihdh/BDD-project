#ifndef ISS_H
#define ISS_H
#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>

//La classe ISS permet de dessiner la station orbitale, de lui associer une texture et la faire tourner sur elle-même. Elle gère également l’arrimage 
//avec le vaisseau à l’aide d’une fonction basé sur le même principe de la détection de collision entre astéroïdes. La station tourne sur elle-même 
//autour de l’axe y. 
class ISS
{
private:
    GLuint * textures;
    float c =0;

public:
    ISS();
    ~ISS();
    void Display(uint64_t iTimeElapsed);
    //cette fonction permet de checker si le vaisseau s'est arrimé à la station orbital en utilisant le principe de detection de colission
    //param : coordonnées du vaisseau
    //return : 1 si il y a arrimage et -1 sinon
    int CheckAshing(float x, float y, float z);
};

#endif // ISS_H
