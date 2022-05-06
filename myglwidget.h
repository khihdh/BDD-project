#include "spaceship.h"
#include "Asteroids.h"
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>

// Classe dediee a l'affichage d'une scene OpenGL
class MyGLWidget : public QOpenGLWidget
{
public:
    float camFrontZ ;
    // Constructeur
    MyGLWidget(QWidget * parent = nullptr);

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
        const static int nbAst = 16;
        float tabx_[nbAst];
        float taby_[nbAst];
        float tabz_[nbAst];
        GLdouble tabd_[nbAst];


    SpaceShip* monVaisseau = nullptr;
    //float camFrontZ ;
    float camFrontX = 0;
    float yaw=0;
    float directionX = 0;
    float directionY = 0;
    float directionZ = 0;
    float pitch = 0;

    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
};
