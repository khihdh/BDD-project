#include "Car.h"

Car::Car()
{
    // Initialisation des paramètres
    m_Roue = gluNewQuadric();
}

Car::~Car()
{
    // Destruction de la quadrique
    if(m_Roue){
        gluDeleteQuadric(m_Roue);
    }
}

void Car::Display(uint64_t iTimeElapsed) const
{
    // Car

    GLfloat colorAmbiente_tab0[] = {0.25, 0.25, 0.25, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT,colorAmbiente_tab0 );

    GLfloat colorDiffuse_tab0[] = {0.4, 0.4, 0.4, 1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE,colorDiffuse_tab0 );

    GLfloat colorSpeculaire_tab0[] = {0.774597, 0.774597, 0.774597,1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR,colorSpeculaire_tab0 );

    float shininess = 76.8;
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);

    /*
    glBegin(GL_QUADS);

    //glColor3ub(100, 0, 0);

    //back (z)
    glNormal3f(0.0,0.0,1.0);
    glVertex3f(-1.f+x, -1.f+y, 0.f+z);
    glVertex3f(1.f+x, -1.f+y, 0.f+z);
    glVertex3f(1.f+x, 1.f+y, 0.f+z);
    glVertex3f(-1.f+x, 1.f+y, 0.f+z);

    //up (y)
    glNormal3f(0.0,1.0,0.0);
    glVertex3f(-1.f+x, 1.f+y, 0.f+z);
    glVertex3f(1.f+x, 1.f+y, 0.f+z);
    glVertex3f(1.f+x, 1.f+y, -3.f+z);
    glVertex3f(-1.f+x, 1.f+y,-3.f+z);

    //down(-y)
    glNormal3f(0.0,-1.0,0.0);
    glVertex3f(-1.f+x, -1.f+y, 0.f+z);
    glVertex3f(1.f+x, -1.f+y, 0.f+z);
    glVertex3f(1.f+x, -1.f+y, -3.f+z);
    glVertex3f(-1.f+x, -1.f+y, -3.f+z);

    //rigth (x)
    glNormal3f(1.0,0.0,0.0);
    glVertex3f(1.f+x, 1.f+y, 0.f+z);
    glVertex3f(1.f+x, -1.f+y, 0.f+z);
    glVertex3f(1.f+x, -1.f+y, -3.f+z);
    glVertex3f(1.f+x, 1.f+y, -3.f+z);

    //left(-x)
    glNormal3f(-1.0,0.0,0.0);
    glVertex3f(-1.f+x, 1.f+y, 0.f+z);
    glVertex3f(-1.f+x, -1.f+y, 0.f+z);
    glVertex3f(-1.f+x, -1.f+y, -3.f+z);
    glVertex3f(-1.f+x, 1.f+y, -3.f+z);

    //front (-z)
    glNormal3f(0.0,0.0,-1.0);
    glVertex3f(-1.f+x, -1.f+y, -3.f+z);
    glVertex3f(1.f+x, -1.f+y, -3.f+z);
    glVertex3f(1.f+x, 1.f+y, -3.f+z);
    glVertex3f(-1.f+x, 1.f+y, -3.f+z);
    glEnd();

    GLfloat colorAmbiente_tab1[] = {0.0, 0.0, 0.0, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT,colorAmbiente_tab1 );

    GLfloat colorDiffuse_tab1[] = {0.25, 0.25, 0.25, 1.0};
    glMaterialfv(GL_FRONT, GL_DIFFUSE,colorDiffuse_tab1 );

    GLfloat colorSpeculaire_tab1[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT, GL_SPECULAR,colorSpeculaire_tab1);

    // Wheels

    //back right
    //glColor3ub(0, 0, 0);
    glPushMatrix();
    glTranslatef(1.f+x, -1.f+y, -0.5f+z);
    glRotated(90.0, 0., 1., 0.);
    gluCylinder(m_Roue, 0.5, 0.5, 0.3, 32, 32);
    glTranslatef(0.f, 0.f, 0.3f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glRotatef(180.f, 1.f, 0.f, 0.f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glPopMatrix();

    //back left
    glPushMatrix();
    glTranslatef(-1.3f+x, -1.f+y, -0.5f+z);
    glRotated(90.0, 0., 1., 0.);
    gluCylinder(m_Roue, 0.5, 0.5, 0.3, 32, 32);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glRotatef(180.f, 1.f, 0.f, 0.f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.f+x, -1.f+y, -2.5f+z);
    glRotated(90.0, 0., 1., 0.);
    gluCylinder(m_Roue, 0.5, 0.5, 0.3, 32, 32);
    glTranslatef(0.f, 0.f, 0.3f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glRotatef(180.f, 1.f, 0.f, 0.f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.3f+x, -1.f+y, -2.5f+z);
    glRotated(90.0, 0., 1., 0.);
    gluCylinder(m_Roue, 0.5, 0.5, 0.3, 32, 32);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glRotatef(180.f, 1.f, 0.f, 0.f);
    gluDisk(m_Roue, 0.0, 0.5, 30, 1);
    glPopMatrix();

    */

    Display_Phare(iTimeElapsed);

}


void Car::Display_Phare(uint64_t iTimeElapsed) const {
    //feux

    /*
    bool flag = false;

    if (iTimeElapsed % 20 < 10) {
        flag = true;

        GLfloat colorAmbiente_tab2[] = {1.0, 0.0, 0.0, 1.0};
        glMaterialfv(GL_FRONT, GL_AMBIENT,colorAmbiente_tab2 );
    }
    else if (iTimeElapsed % 20 > 10) {
        flag = false;
        GLfloat colorAmbiente_tab2[] = {1.0, 1.0, 0.0, 1.0};
        glMaterialfv(GL_FRONT, GL_AMBIENT,colorAmbiente_tab2 );

    }

        glPushMatrix();
        glTranslatef(0.5f+x, -1.f+y, -0.2f+z);
        glRotated(0.0, 0., 1., 0.);
        gluCylinder(m_Roue, 0.10, 0.10, 0.3, 32, 32);
        glTranslatef(0.f, 0.f, 0.3f);
        gluDisk(m_Roue, 0.0, 0.10, 30, 1);
        glRotatef(180.f, 1.f, 0.f, 0.f);
        gluDisk(m_Roue, 0.0, 0.10, 30, 1);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.5f+x, -1.f+y, -0.2f+z);
        glRotated(0.0, 0., 1., 0.);
        gluCylinder(m_Roue, 0.10, 0.10, 0.3, 32, 32);
        glTranslatef(0.f, 0.f, 0.3f);
        gluDisk(m_Roue, 0.0, 0.10, 30, 1);
        glRotatef(180.f, 1.f, 0.f, 0.f);
        gluDisk(m_Roue, 0.0, 0.10, 30, 1);
        glPopMatrix();
        */


}

void Car::updatePos(float xm, float ym, float zm) {
    gluLookAt(0.0f, 4.f, 4.f, 0.0f+2.f, 0.0f+2.f, 0.f+2.f, 0.0f, 1.0f, 0.0f);
}
void Car::resetPos() {
    x=0;
    y=0;
    z=0;
}
