#include "myspace.h"
#include "coordinates.h"

#include <QApplication>
#include <cmath>
#include <algorithm>



const unsigned int WIN = 900;
// Constructeur
MySpace::MySpace(QWidget *parent) : QOpenGLWidget(parent)
{
    // Reglage de la taille/position
    setFixedSize(WIN, WIN);
    coordinates *cor = new  coordinates(nbAst);
    cor->checkAstCol(tabx_, taby_, tabz_, tabd_);

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f;
        update();
    });

    m_AnimationTimer.setInterval(20);
    m_AnimationTimer.start();
}


// Fonction d'initialisation
void MySpace::initializeGL()
{
    // Reglage de la couleur de fond
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f);

    // Activation du zbuffer
    glEnable(GL_DEPTH_TEST);

    monVaisseau = new SpaceShip();
    myStation = new ISS();
    camFrontZ = 0;

    asteroids = new Asteroids(tabx_,taby_,tabz_, tabd_, nbAst);
}


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

void MySpace::setNbAst(int nbAst2) {
    nbAst = nbAst2;
}
// Fonction d'affichage
void MySpace::paintGL()
{
    // Reinitialisation des tampons
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Definition de la position de la camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    const float radius = 10.0f;
    float camX = sin(m_TimeElapsed/1000) * radius;
    float camZ = cos(m_TimeElapsed/1000) * radius;
    //gluLookAt(0.0f, 4.f, 4.f, 0.0f, 0.0f, 0.f, 0.0f, 1.0f, 0.0f);
    //direction2 correspond à la position de la caméra qui de base est en 0,+4,+4
    if (sin(teta)>0){
        gluLookAt(directionX+directionX2 , directionY+directionY2, directionZ+directionZ2, directionX, directionY, directionZ, 0.0f, 1.0f, 0.0f);
    }
    else {
        gluLookAt(directionX+directionX2 , directionY+directionY2, directionZ+directionZ2, directionX, directionY, directionZ, 0.0f, -1.0f, 0.0f);

    }

    // Affichage du vaisseau
    glPushMatrix();
    //glTranslatef(camFrontZ,0.0f,0.0f);
    monVaisseau->Display(m_TimeElapsed);
    myStation->Display(m_TimeElapsed);

    // Affichage des asteroides
    asteroids->Display(m_TimeElapsed);
    glPopMatrix();
}

    void MySpace::keyPressEvent(QKeyEvent * keyEvent)
    {

        const float cameraSpeed = 0.2f;
        float xoffset;
        switch(keyEvent->key())
        {
            // Les cas
            case Qt::Key_Z:
            {
                qDebug() << "Button Z was pressed !";
                r += cameraSpeed *-1.0f;
                directionX = r*sin(teta)*sin(phi);
                directionY = r*-cos(teta);
                directionZ = r*sin(teta)*cos(phi);
                monVaisseau -> incrCoordinatesZSpaceship(teta,phi,r);
                asteroids -> incrSpaceShip(directionX,directionY,directionZ);
                int checkCol = asteroids->CheckCol(directionX, directionY, directionZ);
                if (checkCol !=-1) {
                    asteroids -> DeleteAst(checkCol);
                }
                break;
            }
        case Qt::Key_S:
        {
            qDebug() << "Button S was pressed !";
            r += cameraSpeed *1.0f;
            directionX = r*sin(teta)*sin(phi);
            directionY = r*-cos(teta);
            directionZ = r*sin(teta)*cos(phi);
            monVaisseau -> incrCoordinatesZSpaceship(teta,phi,r);
            asteroids -> incrSpaceShip(directionX,directionY,directionZ);
            int checkCol = asteroids->CheckCol(directionX, directionY, directionZ);
            if (checkCol !=-1) {
                asteroids -> DeleteAst(checkCol);
            }
            break;
        }
        case Qt::Key_Q:
        {
            qDebug() << "Button Q was pressed !";
            teta -= .01f;
            directionX = r*sin(teta)*sin(phi);
            directionY = r*-cos(teta);
            directionZ = r*sin(teta)*cos(phi);
            directionX2 = 4.0f*sin(teta)*sin(phi);
            directionY2 = -8.0f*cos(teta);
            directionZ2 = 4.0f*sin(teta)*cos(phi);
            monVaisseau -> changeFlagPhi(false);
            monVaisseau -> incrCoordinatesZSpaceship(teta,phi,r);
            asteroids -> incrSpaceShip(directionX,directionY,directionZ);
            monVaisseau -> changeFlagPhi(true);
            int checkCol = asteroids->CheckCol(directionX, directionY, directionZ);
            if (checkCol !=-1) {
                asteroids -> DeleteAst(checkCol);
            }
            break;
        }
        case Qt::Key_D:
        {
            qDebug() << "Button D was pressed !";
            teta += .01f;
            directionX = r*sin(teta)*sin(phi);
            directionY = r*-cos(teta);
            directionZ = r*sin(teta)*cos(phi);
            directionX2 = 4.0f*sin(teta)*sin(phi);
            directionY2 = -8.0f*cos(teta);
            directionZ2 = 4.0f*sin(teta)*cos(phi);
            qDebug() << sin(teta);
            monVaisseau -> changeFlagPhi(false);
            monVaisseau -> incrCoordinatesZSpaceship(teta,phi,r);
            monVaisseau -> changeFlagPhi(true);
            asteroids -> incrSpaceShip(directionX,directionY,directionZ);
            int checkCol = asteroids -> CheckCol(directionX, directionY, directionZ);
            if (checkCol !=-1) {
                asteroids -> DeleteAst(checkCol);
            }
            break;
        }
        case Qt::Key_A:
        {
            qDebug() << "Button A was pressed !";
            phi += .01f;
            directionX = r*sin(teta)*sin(phi);
            directionY = r*-cos(teta);
            directionZ = r*sin(teta)*cos(phi);
            directionX2 = 4.0f*sin(teta)*sin(phi);
            directionY2 = -8.0f*cos(teta);
            directionZ2 = 4.0f*sin(teta)*cos(phi);
            monVaisseau -> changeFlagTeta(false);
            monVaisseau -> incrCoordinatesZSpaceship(teta,phi,r);
            monVaisseau -> changeFlagTeta(true);
            asteroids -> incrSpaceShip(directionX,directionY,directionZ);
            int checkCol = asteroids -> CheckCol(directionX, directionY, directionZ);
            if (checkCol !=-1) {
                asteroids -> DeleteAst(checkCol);
            }
            break;
        }
        case Qt::Key_E:
        {
            qDebug() << "Button E was pressed !";
            phi -= .01f;
            directionX = r*sin(teta)*sin(phi);
            directionY = r*-cos(teta);
            directionZ = r*sin(teta)*cos(phi);
            directionX2 = 4.0f*sin(teta)*sin(phi);
            directionY2 = -8.0f*cos(teta);
            directionZ2 = 4.0f*sin(teta)*cos(phi);
            monVaisseau -> changeFlagTeta(false);
            monVaisseau -> incrCoordinatesZSpaceship(teta,phi,r);
            monVaisseau -> changeFlagTeta(true);
            asteroids -> incrSpaceShip(directionX,directionY,directionZ);
            int checkCol = asteroids -> CheckCol(directionX, directionY, directionZ);
            if (checkCol !=-1) {
                asteroids -> DeleteAst(checkCol);
            }
            break;
        }


        keyEvent->accept();
        update();
}
    }
