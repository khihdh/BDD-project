#include "iss.h"
#include <QImage>
#include <QDebug>

ISS::ISS()
{
    QImage ast = QImage(":/10946.jpg");
    QImage text_ast = ast.convertToFormat(QImage::Format_RGBA8888);
    QImage space = QImage(":/monochrome.jpeg");
    QImage text_space = space.convertToFormat(QImage::Format_RGBA8888);
    QImage blue = QImage(":/blue.jpg");
    QImage text_blue = blue.convertToFormat(QImage::Format_RGBA8888);
    QImage grey = QImage(":/grey.jpeg");
    QImage text_grey = grey.convertToFormat(QImage::Format_RGBA8888);

    textures = new GLuint[4];
    glGenTextures(4, textures);

    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexImage2D(GL_TEXTURE_2D,0,4,text_ast.width(),
    text_ast.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,text_ast.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTexImage2D(GL_TEXTURE_2D,0,4,text_space.width(),
    text_space.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,text_space.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, textures[2]);
    glTexImage2D(GL_TEXTURE_2D,0,4,text_blue.width(),
    text_blue.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,text_blue.bits());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, textures[3]);
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
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    GLUquadricObj *quad = gluNewQuadric();
    glRotatef(60,1,0,0);
    glRotatef(0+c,0,0,1.);
    gluQuadricTexture(quad, GL_TRUE);
    gluDisk(quad, 7, 8., 30, 2);

    glRotatef(-60,1,0,0);
    glBindTexture(GL_TEXTURE_2D, textures[3]);
    gluQuadricTexture(quad, GL_TRUE);
    gluSphere(quad,4, 50, 50);

    glBindTexture(GL_TEXTURE_2D, textures[1]);
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



    /*
    glTranslatef(0.0f, 0.0f, -6.f);
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    GLUquadricObj *quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    gluSphere(quad,5, 50, 50);

    glTranslatef(4.0f, 0.0f, 1.f);
    gluQuadricDrawStyle(quad, GLU_LINE);
    glRotatef(30,0,1,0);
    gluCylinder(quad, 2.0, 0., 6.,20., 20.);

    glTranslatef(-7.0f, 0.0f, -3.f);
    gluQuadricDrawStyle(quad, GLU_LINE);
    glRotatef(-60,0,1,0);
    gluCylinder(quad, 2.0, 0., 6.,20., 20.);
    */

    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);


}

