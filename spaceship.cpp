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
    glBegin(GL_QUADS);
    glColor3ub(100, 0, 0);
    glTranslatef(0.8f, 0.0f, 0.0f);
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

    //roue arrière droite
    glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslatef(0.8f, 0.1f, -0.9f);
    glRotated(180.0, 0., 1., 0.);
    gluCylinder(m_Roue, 0.2, 0.2, 1.1, 32, 32);
    gluDisk(m_Roue, 0.0, 0.2, 30, 1);
    //glRotatef(180.f, 1.f, 0.f, 0.f);
    //gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glPopMatrix();

    //roue arrière gauche
    glPushMatrix();
    glTranslatef(-0.8f, 0.1f, -0.9f);
    glRotated(180.0, 0., 1., 0.);
    gluCylinder(gluNewQuadric(), 0.2, 0.2, 1.1, 32, 32);
    gluDisk(m_Roue, 0.0, 0.2, 30, 1);
    //glRotatef(180.f, 1.f, 0.f, 0.f);
    //gluDisk(m_Roue, 0.0, 0.1, 30, 1);
    glPopMatrix();


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
    QImage grass (":/grass.jpg");
    QImage ImageOpenGL = grass.convertToFormat(QImage::Format_RGBA8888);
}
