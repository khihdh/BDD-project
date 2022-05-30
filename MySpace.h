// Classe dediee a l'affichage d'une scene OpenGL
#include "spaceship.h"
#include "Asteroids.h"
#include "iss.h"
#include "collision.h"
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

    //les fonctions E,Z,A,D,S et Q permettent de faire avancer le vaisseau, tout en checkant s'il y a colission avec les asteroides ou si 
    //le vaisseau s'est arrimé à la station orbital
    //Permet d'appliquer une rotation droite au vaisseau 
    void E();
    //Permet de faire avancer le vaisseau 
    void Z();
    //permet d'appliquer une rotation gauche au vaisseau
    void A();
    //permet d'appliquer une rotation basse au vaisseau
    void D();
    //permet de faire reculer le vaisseau
    void S();
    //permet d'appliquer une rotation haute au vaisseau
    void Q();

    //cette fonction permet de renvoyer le boolean permettant de verifier si la partie est perdu
    //param: none
    //return : boolean 
    bool checkGameOverFlag();
    //cette fonction permet de renvoyer le boolean permettant de verifier si la partie est gagné
    //param: none
    //return : boolean 
    bool checkForWinFlag();
    //cette fonction permet de reinitailiser les coordonnées de la camera et du vaisseau
    void reset();
    void closeApp();

protected:


    // Fonction d'initialisation
    void initializeGL();


    // Fonction de redimensionnement
    void resizeGL(int width, int height);

    // Fonction d'affichage
    void paintGL();
    //permet de gerer les touches du clavier pour faire avancer le vaisseau si le joueur veut utiliser les touches plutot que la caméra
    void keyPressEvent(QKeyEvent * keyEvent);

private:
        float x=0,y=0,z=0;
        GLdouble d=0;
        Asteroids* asteroids = nullptr;
        const static int nbAstMax = 16;
        float tabx_[nbAstMax];
        float taby_[nbAstMax];
        float tabz_[nbAstMax];
        GLdouble tabd_[nbAstMax];
        bool gameOverFlag = false;
        bool winFlag = false;

        SpaceShip* monVaisseau = nullptr;
        collision *col = nullptr;
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
