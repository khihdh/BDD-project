#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>

// Classe dediee pour la gestion de la voiture
class SpaceShip
{
public:
    // Constructeur avec parametres
    SpaceShip();

    // Destructeur
    ~SpaceShip();

    // Methode d'affichage
    void Display(uint64_t iTimeElapsed) const;
    void incrCoordinatesZSpaceship(float phi,float teta,float r);
    void incrCoordinatesYSpaceship();
    void incrCoordinatesXSpaceship();
    void rotPhi(double phi,double teta);

private:
    GLUquadric * m_Roue { nullptr };
    float spaceshipx_=0,spaceshipy_=0,spaceshipz_=0;
};


#endif // SPACESHIP_H
