#include "MySpace.h"
#include "coordinates.h"
#include <OpenGL/glu.h>
#include <QApplication>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <QtMath>


// Declarations des constantes
const unsigned int WIN = 900;

// Constructeur
MySpace::MySpace(QWidget * parent) : QOpenGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN, WIN);
    coordinates *cor = new  coordinates();
    cor->checkAstCol(tabx_, taby_, tabz_, tabd_);
    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f;
        update();
    });
    m_AnimationTimer.setInterval(20);
    m_AnimationTimer.start();
}

MySpace::~MySpace()
{

}


// Fonction d'initialisation
void MySpace::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f);
    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    asteroids = new Asteroids(tabx_,taby_,tabz_, tabd_);
}


/*bool MySpace::checkAstCol() {
    for (int i=0; i<nbAst; i++) {
        z=RandomFloat(-30,-2);
        x=RandomFloat(-30,30);
        y=RandomFloat(-30, 30);
        d = 1  + (rand() % 3);
        qDebug()<<d;
        bool flag = false;
        while (!flag){
            flag = true;
            z=RandomFloat(-30,-2);
            x=RandomFloat(-30,30);
            y=RandomFloat(-30, 30);
            for (int j = 0; j<i; j++) {
                    //if (fabs(tabx_[j]-x)<16 && fabs(tabz_[j]-z)<9 && fabs(taby_[j]-y)<11) {
                    if ((tabx_[j]-x)*(tabx_[j]-x) + (taby_[j]-y)*(taby_[j]-y) + (tabz_[j]-z)*(tabz_[j]-z) < 1) {
                        flag = false;
                }
            }
        }


        tabx_[i]=x;
        taby_[i]=y;
        tabz_[i]=z;
        tabd_[i]=d;
    }

    return true;
}*/

// Fonction de redimensionnement
void MySpace::resizeGL(int width, int height)
{

    // Definition du viewport (zone d'affichage)
    glViewport(0, 0, width, height);

    // Definition de la matrice de projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(width != 0)
       glFrustum(-5, 5, -5, 5, 2, 2000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

float MySpace::RandomFloat(float min, float max)
{
    // this  function assumes max > min, you may want
    // more robust error checking for a non-debug build
    assert(max > min);
    float random = ((float) rand()) / (float) RAND_MAX;

    // generate (in your case) a float between 0 and (4.5-.78)
    // then add .78, giving you a float between .78 and 4.5
    float range = max - min;
    return (random*range) + min;
}

void MySpace::keyPressEvent(QKeyEvent * keyEvent)
{

    switch (keyEvent->key())
    {

     case Qt::Key_Right :
        qDebug() << "test";
        break;

    case Qt::Key_Left :
       break;

    case Qt::Key_Up :
        break;

    case Qt::Key_Down :
        break;

    case Qt::Key_R:
        //reset
        return;
        break;
    }
    update();
}

// Fonction d'affichage
void MySpace::paintGL()
{
    // Reinitialisation des tampons
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Definition de la position de la camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 4.f, 4.f, 0.0f, 0.0f, 0.f, 0.0f, 1.0f, 0.0f);

    // Affichage de la voiture
    glPushMatrix();
    asteroids->Display(m_TimeElapsed);
    glPopMatrix();
}
