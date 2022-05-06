#include <qopengl.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <QColor>
#include <QKeyEvent>

// Classe dediee pour la gestion de la voiture
class Car
{
public:
    // Constructeur avec parametres
    Car();

    // Destructeur
    ~Car();

    // Methode d'affichage
    void Display(uint64_t iTimeElapsed) const;
    void Display_Phare(uint64_t iTimeElapsed) const;
    void updatePos(float xm=0, float ym=0, float zm=0);
    void resetPos();

private:
    GLUquadric * m_Roue { nullptr };
    float x=0,y=0,z=0;
    float rot_x, rot_y, rot_z;
};
