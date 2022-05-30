#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>

// Cette classe permet de dessiner le vaisseau et de representer le vaisseau dans un repere spherique
class SpaceShip
{
public:
    // Constructeur avec parametres
    SpaceShip();

    // Destructeur
    ~SpaceShip();

    // Methode d'affichage
    //cette fonction permet de dessiner le vaisseau et de lui appliquer des rotations et des translation dans le repère sphérique
    void Display(uint64_t iTimeElapsed) const;
    void incrCoordinatesZSpaceship(float teta2,float phi2,float r);
    void incrCoordinatesYSpaceship();
    void incrCoordinatesXSpaceship();
    //on exprime les coordonnes cartesiennes du vaisseau en fonction de ses coordonees spherique
    void rotPhi(float phi,float teta,float r);
    //ces fonctions permettent de changer le flag de l'angle theta ou phi
    void changeFlagTeta(bool flag);
    void changeFlagPhi(bool flag);
    //cette fonction permet de reinitialiser les coordonnees spheriques du vaisseau
    void reset();

private:
    GLUquadric * m_Roue { nullptr };
    float spaceshipx_=0,spaceshipy_=0,spaceshipz_=0;
    float phi=0;
    float teta = 90;
    bool flagTeta = true,flagPhi=true;
};


#endif // SPACESHIP_H
