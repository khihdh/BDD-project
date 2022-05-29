#include "iss.h"
#include <QImage>
#include <QDebug>

ISS::ISS()
{
    QImage white = QImage(":/monochrome.jpeg");
    QImage text_white = white.convertToFormat(QImage::Format_RGBA8888);
    QImage grey = QImage(":/grey.jpeg");
    QImage text_grey = grey.convertToFormat(QImage::Format_RGBA8888);

    textures = new GLuint[2];
    glGenTextures(2, textures);

    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexImage2D(GL_TEXTURE_2D,0,4,text_white.width(),
    text_white.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,text_white.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTexImage2D(GL_TEXTURE_2D,0,4,text_grey.width(),
    text_grey.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,text_grey.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
}

ISS::~ISS()
{

}

void ISS::Display(uint64_t iTimeElapsed)  {


    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    c+=0.1;
    glPushMatrix();
    glTranslatef(0.f,0.f,-30.f);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    GLUquadricObj *quad = gluNewQuadric();
    glRotatef(60,1,0,0);
    glRotatef(0+c,0,0,1.);
    gluQuadricTexture(quad, GL_TRUE);
    gluDisk(quad, 7, 8., 30, 2);

    glRotatef(-60,1,0,0);
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    gluQuadricTexture(quad, GL_TRUE);
    gluSphere(quad,4, 50, 50);

    glBindTexture(GL_TEXTURE_2D, textures[0]);
    //glTranslatef(4.0f, 0.0f, 1.f);
    glRotatef(-30,1,0,0);
    gluQuadricTexture(quad, GL_TRUE);
    gluCylinder(quad, 0.2, 0.2, 7.5,20., 20.);

    //glTranslatef(4.0f, 0.0f, 1.f);
    glRotatef(-60,0,1,0);
    gluQuadricTexture(quad, GL_TRUE);
    gluCylinder(quad, 0.2, 0.2, 7.5,20., 20.);

    glRotatef(-60,0,1,0);
    gluQuadricTexture(quad, GL_TRUE);
    gluCylinder(quad, 0.2, 0.2, 7.5,20., 20.);

    //glTranslatef(4.0f, 0.0f, 1.f);
    glRotatef(-60,0,1,0);
    gluQuadricTexture(quad, GL_TRUE);
    gluCylinder(quad, 0.2, 0.2, 7.5,20., 20.);

    //glTranslatef(4.0f, 0.0f, 1.f);
    glRotatef(-60,0,1,0);
    gluQuadricTexture(quad, GL_TRUE);
    gluCylinder(quad, 0.2, 0.2, 7.5,20., 20.);

    glRotatef(-60,0,1,0);
    gluQuadricTexture(quad, GL_TRUE);
    gluCylinder(quad, 0.2, 0.2, 7.5,20., 20.);

    glRotatef(-60,0,1,0);
    gluQuadricTexture(quad, GL_TRUE);
    gluCylinder(quad, 0.2, 0.2, 7.5,20., 20.);
    glPopMatrix();

    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);


}

