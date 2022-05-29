
// Classe dediee a l'affichage d'une scene OpenGL
#include "spaceship.h"
#include "Asteroids.h"
#include "iss.h"
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>

// Classe dediee a l'affichage de la scene du jeu
class MySpace : public QOpenGLWidget
{
public:
    int nbAst = 20;
    float camFrontZ ;
    // Constructeur
    MySpace(QWidget * parent = nullptr);
    ~MySpace();

    void setNbAst(int nbAst);

    void E();
    void Z();
    void A();
    void D();
    void S();
    void Q();

    bool checkGameOverFlag();

protected:


    // Fonction d'initialisation
    void initializeGL();


    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();
    void keyPressEvent(QKeyEvent * keyEvent);

private:
        float x=0,y=0,z=0;
        GLdouble d=0;
        Asteroids* asteroids = nullptr;
        const static int nbAstMax = 50;
        float tabx_[nbAstMax];
        float taby_[nbAstMax];
        float tabz_[nbAstMax];
        GLdouble tabd_[nbAstMax];
        bool gameOverFlag = false;

        SpaceShip* monVaisseau = nullptr;
        ISS* myStation = nullptr;
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

        const float cameraSpeed = 0.2f;
        float xoffset;

        float m_TimeElapsed { 0.0f };
        QTimer m_AnimationTimer;
};
