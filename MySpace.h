
// Classe dediee a l'affichage d'une scene OpenGL
#include "spaceship.h"
#include "Asteroids.h"
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>

// Classe dediee a l'affichage d'une scene OpenGL
class MySpace : public QOpenGLWidget
{
public:
    float camFrontZ ;
    // Constructeur
    MySpace(QWidget * parent = nullptr);

protected:


    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    //fonction update
    void keyPressEvent(QKeyEvent * keyEvent);

    //void mouse_callback(double xpos, double ypos)

private:
    float x=0,y=0,z=0;
        GLdouble d=0;
        Asteroids* asteroids = nullptr;
        const static int nbAst = 40;
        float tabx_[nbAst];
        float taby_[nbAst];
        float tabz_[nbAst];
        GLdouble tabd_[nbAst];


    SpaceShip* monVaisseau = nullptr;
    //float camFrontZ ;
    float camFrontX = 0;
    float phi=0;
    float teta = 90;
    float r = 0;
    float directionX = r*sin(teta)*sin(phi);
    float directionY = r*cos(teta);
    float directionZ = r*sin(teta)*cos(phi);
    float directionX2 = 4.0f*sin(teta)*sin(phi);
    float directionY2 = -8.0f*cos(teta);
    float directionZ2 = 4.0f*sin(teta)*cos(phi);
    float pitch = 0;

    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
};
