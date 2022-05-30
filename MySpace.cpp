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
    col = new  collision(nbAst);
    col->checkAstCol(tabx_, taby_, tabz_, tabd_);

    // Connexion du timer
    connect(&m_AnimationTimer,  &QTimer::timeout, [&] {
        m_TimeElapsed += 1.0f;
        update();
    });

    m_AnimationTimer.setInterval(20);
    m_AnimationTimer.start();
}

MySpace::~MySpace(){
    r = 0;
    phi=0;
    teta = 90;
    gameOverFlag = false;
};

void MySpace::reset(){
    r = 0;
    phi=0;
    teta = 90;
    gameOverFlag = false;
    winFlag = false;
    monVaisseau->reset();
    D();
};

void MySpace::closeApp() {
    close();
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
    //asteroids ->setNbAst(nbAst2);
    //col -> setNbAst(nbAst2);
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

        switch(keyEvent->key())
        {
            // Les cas
            case Qt::Key_Z:
            {
                if (gameOverFlag == false) {
                qDebug() << "Button Z was pressed !";
                r += cameraSpeed *-1.0f;
                directionX = r*sin(teta)*sin(phi);
                directionY = r*-cos(teta);
                directionZ = r*sin(teta)*cos(phi);
                monVaisseau -> incrCoordinatesZSpaceship(teta,phi,r);
                asteroids -> incrSpaceShip(directionX,directionY,directionZ);
                int checkCol = asteroids->CheckColSpaceship(directionX, directionY, directionZ);
                int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
                if (checkCol !=-1) {
                    asteroids -> DeleteAst(checkCol);
                }
                if (checkAsh ==1) {
                                    winFlag = true;
                                }
                }
                break;
            }
        case Qt::Key_S:
        {
            if (gameOverFlag == false) {
            qDebug() << "Button S was pressed !";
            r += cameraSpeed *1.0f;
            directionX = r*sin(teta)*sin(phi);
            directionY = r*-cos(teta);
            directionZ = r*sin(teta)*cos(phi);
            monVaisseau -> incrCoordinatesZSpaceship(teta,phi,r);
            asteroids -> incrSpaceShip(directionX,directionY,directionZ);
            int checkCol = asteroids->CheckColSpaceship(directionX, directionY, directionZ);
            int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
            if (checkCol !=-1) {
                asteroids -> DeleteAst(checkCol);
            }
            if (checkAsh ==1) {
                                winFlag = true;
                            }
            }
            break;
        }
        case Qt::Key_Q:
                {
                    if (gameOverFlag == false) {
                    qDebug() << "Button Q was pressed !";
                    teta -= .02f;
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
                    int checkCol = asteroids->CheckColSpaceship(directionX, directionY, directionZ);
                    int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
                    if (checkCol !=-1) {
                        asteroids -> DeleteAst(checkCol);
                        gameOverFlag = true;
                    }
                    if (checkAsh ==1) {
                        winFlag = true;
                    }
                    }
                    break;
                }
                case Qt::Key_D:
                {
                    if (gameOverFlag == false) {
                    qDebug() << "Button D was pressed !";
                    teta += .02f;
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
                    int checkCol = asteroids -> CheckColSpaceship(directionX, directionY, directionZ);
                    int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
                    if (checkCol !=-1) {
                        asteroids -> DeleteAst(checkCol);
                        gameOverFlag = true;
                    }
                    if (checkAsh ==1) {
                        winFlag = true;
                    }
                    }
                    break;
                }
                case Qt::Key_A:
                {
                    if (gameOverFlag == false) {
                    qDebug() << "Button A was pressed !";
                    phi += .02f;
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
                    int checkCol = asteroids -> CheckColSpaceship(directionX, directionY, directionZ);
                    int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
                    if (checkCol !=-1) {
                        asteroids -> DeleteAst(checkCol);
                        gameOverFlag = true;
                    }
                    if (checkAsh ==1) {
                        winFlag = true;
                    }
                    }
                    break;
                }
                case Qt::Key_E:
                {
                   if (gameOverFlag == false) {
                    qDebug() << "Button E was pressed !";
                    phi -= .02f;
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
                    int checkCol = asteroids -> CheckColSpaceship(directionX, directionY, directionZ);
                    int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
                    if (checkCol !=-1) {
                        asteroids -> DeleteAst(checkCol);
                        gameOverFlag = true;
                    }
                    if (checkAsh ==1) {
                        winFlag = true;
                    }
                   }
                    break;
                }


                keyEvent->accept();
                update();
        }
            }
            //avancer
                void MySpace::Z(){

                    if (gameOverFlag == false) {
                    r += cameraSpeed *-1.0f;
                    directionX = r*sin(teta)*sin(phi);
                    directionY = r*-cos(teta);
                    directionZ = r*sin(teta)*cos(phi);
                    monVaisseau -> incrCoordinatesZSpaceship(teta,phi,r);
                    asteroids -> incrSpaceShip(directionX,directionY,directionZ);
                    int checkCol = asteroids->CheckColSpaceship(directionX, directionY, directionZ);
                    int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
                    if (checkCol !=-1) {
                        asteroids -> DeleteAst(checkCol);
                        gameOverFlag = true;
                    }
                    if (checkAsh ==1) {
                        winFlag = true;
                    }
                    }

                }

                //reculer
                void MySpace::S() {

                if (gameOverFlag == false) {
                r += cameraSpeed *1.0f;
                directionX = r*sin(teta)*sin(phi);
                directionY = r*-cos(teta);
                directionZ = r*sin(teta)*cos(phi);
                monVaisseau -> incrCoordinatesZSpaceship(teta,phi,r);
                asteroids -> incrSpaceShip(directionX,directionY,directionZ);
                int checkCol = asteroids->CheckColSpaceship(directionX, directionY, directionZ);
                int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
                if (checkCol !=-1) {
                    asteroids -> DeleteAst(checkCol);
                    gameOverFlag = true;
                }
                if (checkAsh ==1) {
                    winFlag = true;
                }
                }
                }

                //rotation haute
                void MySpace::Q(){

                if (gameOverFlag == false) {
                teta -= .02f;
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
                int checkCol = asteroids->CheckColSpaceship(directionX, directionY, directionZ);
                int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
                if (checkCol !=-1) {
                    asteroids -> DeleteAst(checkCol);
                    gameOverFlag = true;

                }
                if (checkAsh ==1) {
                    winFlag = true;
                }
                }
            }
                //rotation haute
                void MySpace::D(){

                if (gameOverFlag == false) {
                teta += .02f;
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
                int checkCol = asteroids -> CheckColSpaceship(directionX, directionY, directionZ);
                int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
                if (checkCol !=-1) {
                    asteroids -> DeleteAst(checkCol);
                    gameOverFlag = true;
                }
                if (checkAsh ==1) {
                    winFlag = true;
                }
                }

            }
                //tourner gauche
                void MySpace::A(){
                if (gameOverFlag == false) {
                phi += .02f;
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
                int checkCol = asteroids -> CheckColSpaceship(directionX, directionY, directionZ);
                int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
                if (checkCol !=-1) {
                    asteroids -> DeleteAst(checkCol);
                    gameOverFlag = true;
                    }
                if (checkAsh ==1) {
                    winFlag = true;
                }
                }
            }
                //tourner droite
                void MySpace::E(){

                if (gameOverFlag == false) {
                phi -= .02f;
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
                int checkCol = asteroids -> CheckColSpaceship(directionX, directionY, directionZ);
                int checkAsh = myStation -> CheckAshing(directionX, directionY, directionZ);
                if (checkCol !=-1) {
                    asteroids -> DeleteAst(checkCol);
                    gameOverFlag = true;
                }
                if (checkAsh ==1) {
                    winFlag = true;
                }
                }

            }

                bool MySpace::checkGameOverFlag() {
                    return gameOverFlag;
                }

                bool MySpace::checkForWinFlag() {
                    return winFlag;
                }

