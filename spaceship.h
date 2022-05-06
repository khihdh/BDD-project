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

private:
    GLUquadric * m_Roue { nullptr };
};
