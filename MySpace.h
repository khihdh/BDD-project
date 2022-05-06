#include "Car.h"
#include "Asteroids.h"
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QApplication>

// Classe dediee a l'affichage d'une scene OpenGL
class MySpace : public QOpenGLWidget
{
public:

    // Constructeur
    MySpace(QWidget * parent = nullptr);
    ~MySpace();

protected:

    // Fonction d'initialisation
    void initializeGL();

    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();

    void keyPressEvent(QKeyEvent* event);
    float RandomFloat(float min, float max);
    //bool checkAstCol();

private:
    float x=0,y=0,z=0;
    GLdouble d=0;
    Asteroids* asteroids = nullptr;
    const static int nbAst = 16;
    float tabx_[nbAst];
    float taby_[nbAst];
    float tabz_[nbAst];
    GLdouble tabd_[nbAst];
    float m_TimeElapsed { 0.0f };
    QTimer m_AnimationTimer;
};
