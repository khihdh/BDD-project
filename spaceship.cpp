#include "spaceship.h"
#include <iostream> using namespace std;
#include <QImage>

SpaceShip::SpaceShip()
{
    // Initialisation des paramètres
    m_Roue = gluNewQuadric();
}

SpaceShip::~SpaceShip()
{
    // Destruction de la quadrique
    if(m_Roue)
        gluDeleteQuadric(m_Roue);
}

void SpaceShip::Display(uint64_t iTimeElapsed) const
{
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    //lumière ambiante venant du ciel
    glEnable(GL_LIGHT0);
    //d'où vient la lumière
    GLfloat light_tab[] = {0.0,1.0,0.50,0.0};
    glLightfv(GL_LIGHT0,GL_POSITION,light_tab);
    float shininess=76.0;
    glMaterialf(GL_FRONT, GL_SHININESS, shininess );
    GLfloat ambient_material[] = {0.25f,0.25f,0.25f,1.0f};
    glMaterialfv(GL_FRONT,GL_AMBIENT,ambient_material);
    /*glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_lampr);
    glMaterialfv(GL_FRONT, GL_SPECULAR, speculaire_lampr);
*/

    // rectangle
    glPushMatrix();
    glTranslatef(0.0f+spaceshipx_, 0.0f+spaceshipy_, 0.0f+spaceshipz_);
    //glRotated(phi,0,0,0);
    glBegin(GL_QUADS);
    //face derrière
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-0.5f, -0.5f, 0.f);
    glVertex3f(0.5f, -0.5f, 0.f);
    glVertex3f(0.5f, 0.5f, 0.f);
    glVertex3f(-0.5f, 0.5f, 0.f);

    //face dessus
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(-0.5f, 0.5f, 0.f);
    glVertex3f(0.5f, 0.5, 0.f);
    glVertex3f(0.5f, 0.5f, -3.f);
    glVertex3f(-0.5f, 0.5f, -3.f);

    //face dessous
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(-0.5f, -0.5f, 0.f);
    glVertex3f(0.5f, -0.5f, 0.f);
    glVertex3f(0.5f, -0.5f, -3.f);
    glVertex3f(-0.5f, -0.5f, -3.f);

    //face droite
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(0.5f, 0.5f, 0.f);
    glVertex3f(0.5f, -0.5f, 0.f);
    glVertex3f(0.5f, -0.5f, -3.f);
    glVertex3f(0.5f, 0.5f, -3.f);

    //face de gauche
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(-0.5f, 0.5f, 0.f);
    glVertex3f(-0.5f, -0.5f, 0.f);
    glVertex3f(-0.5f, -0.5f, -3.f);
    glVertex3f(-0.5f, 0.5f, -3.f);

    //face devant
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(-0.5f, -0.5f, -3.f);
    glVertex3f(0.5f, -0.5f, -3.f);
    glVertex3f(0.5f, 0.5f, -3.f);
    glVertex3f(-0.5f, 0.5f, -3.f);
    glEnd();

    // Wings
    glBegin(GL_TRIANGLES);
    glNormal3f(0.0,1.,0.0);
    glVertex3f(-2.f, 1.f, 0.f);
    glVertex3f(2.0f, 1., 0.f);
    glVertex3f(0.0f, 0.0f, -3.f);
    glEnd();
    glPopMatrix();
    //roue arrière droite
    glPushMatrix();
    glTranslatef(0.8f+spaceshipx_, 0.1f+spaceshipy_, -0.9f+spaceshipz_);
    glRotated(180.0, 0., 1., 0.);
    gluCylinder(m_Roue, 0.2, 0.2, 1.1, 32, 32);
    gluDisk(m_Roue, 0.0, 0.2, 30, 1);
    //glRotatef(180.f, 1.f, 0.f, 0.f);
    //gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glPopMatrix();

    //roue arrière gauche
    glPushMatrix();
    glTranslatef(-0.8f+spaceshipx_, 0.1f+spaceshipy_, -0.9f+spaceshipz_);
    glRotated(180.0, 0., 1., 0.);
    gluCylinder(gluNewQuadric(), 0.2, 0.2, 1.1, 32, 32);
    gluDisk(m_Roue, 0.0, 0.2, 30, 1);
    //glRotatef(180.f, 1.f, 0.f, 0.f);
    //gluDisk(m_Roue, 0.0, 0.1, 30, 1);
    glPopMatrix();

    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    /*/repère
    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslatef(0.8f, 0.0f, 0.0f);
    glTranslatef(5.f, 2.f, -0.5f);
    glRotated(90.0, 90., 1., 0.);
    gluCylinder(m_Roue, 0.7, 0.7, 1.5, 32, 32);
    glTranslatef(0.f, 0.f, 1.5f);
    gluDisk(m_Roue, 0.0, 0.7, 30, 1);
    glPopMatrix();

    /* Load textures */
}

void SpaceShip::incrCoordinatesZSpaceship(float teta2,float phi2,float r) {
    teta = teta2;
    phi=phi2;
    spaceshipx_ = r*sin(teta)*sin(phi);
    spaceshipy_ = r*-cos(teta);
    spaceshipz_ = r*sin(teta)*cos(phi);
}

void SpaceShip::rotPhi(float teta2,float phi2,float r){
    teta = teta2;
    phi=phi2;
    spaceshipx_ = sin(teta)*sin(phi);
    spaceshipy_ = cos(teta);
    spaceshipz_ = sin(teta)*cos(phi);

}

void SpaceShip::incrCoordinatesXSpaceship() {
    spaceshipz_-=0.2;
}
void SpaceShip::incrCoordinatesYSpaceship() {
    spaceshipz_-=0.2;
}
