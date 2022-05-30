#include "iss.h"
#include <QImage>
#include <QDebug>

ISS::ISS()
{
    QImage grey = QImage(":/grey.jpeg");
    QImage white = QImage(":/monochrome.jpeg");
    QImage text_white = white.convertToFormat(QImage::Format_RGBA8888);
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

    GLUquadricObj *quad = gluNewQuadric();
    glPushMatrix();
    glTranslatef(0.f,0.f,-30.f);
    glRotatef(60,1,0,0);

    glPushMatrix();
    glTranslatef(0.f, 0.f, 7.7f);
    gluQuadricTexture(quad, GL_TRUE);
    gluSphere(quad, 0.5, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.f, 0.f, -7.7f);
    gluQuadricTexture(quad, GL_TRUE);
    gluSphere(quad, 0.5, 50, 50);
    glPopMatrix();



    //parameter
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    //where's the ligth
    GLfloat light_tab[] = {0,0,7.7f,1};
    /*GLfloat light_tab2[] = {10.4,0,10.15,1.0};
    GLfloat light_tab3[] = {10.4,0,10.15,1.0};
    GLfloat light_tab4[] = {10.4,0,10.15,1.0};
    GLfloat light_tab5[] = {10.4,0,10.15,1.0};
    GLfloat light_tab6[] = {10.4,0,10.15,1.0};*/

    glLightfv(GL_LIGHT1,GL_POSITION,light_tab);
    /*glLightfv(GL_LIGHT1,GL_POSITION,light_tab2);
    glLightfv(GL_LIGHT1,GL_POSITION,light_tab3);
    glLightfv(GL_LIGHT1,GL_POSITION,light_tab4);
    glLightfv(GL_LIGHT1,GL_POSITION,light_tab5);
    glLightfv(GL_LIGHT1,GL_POSITION,light_tab6);*/

    GLfloat ambient_lampr2[] = {0.0, 0.0, 0.0,1.0};
    glLightfv(GL_LIGHT1,GL_AMBIENT,ambient_lampr2);
    GLfloat diffuse_lampr2[] = {.9, .9, 0.0,1.0};
    glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse_lampr2);
    GLfloat speculaire_lampr2[]={100.,100.,0.,1.0};
    glLightfv(GL_LIGHT1,GL_SPECULAR,speculaire_lampr2);

    if (iTimeElapsed%50<25){

            GLfloat ambient_lampr2[] = {0.0, 0.0, 0.0,1.0};
            glLightfv(GL_LIGHT1,GL_AMBIENT,ambient_lampr2);
            GLfloat diffuse_lampr2[] = {.0, .0, 0.0,1.0};
            glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse_lampr2);
            GLfloat speculaire_lampr2[]={0.,0.,0.,1.0};
            glLightfv(GL_LIGHT1,GL_SPECULAR,speculaire_lampr2);
}

    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    c+=0.1;
    glBindTexture(GL_TEXTURE_2D, textures[1]);
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



    /*
    //clignotant droit
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT1);
    //où est la lumière
    GLfloat light_tab2[] = {10.4,10.7,10.15,1.0};
    glLightfv(GL_LIGHT1,GL_POSITION,light_tab2);

    GLfloat ambient_lampr2[] = {0.0, 0.0, 0.0,1.0};
    glLightfv(GL_LIGHT1,GL_AMBIENT,ambient_lampr2);
    GLfloat diffuse_lampr2[] = {.9, .9, 0.0,1.0};
    glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse_lampr2);
    GLfloat speculaire_lampr2[]={100.,100.,0.,1.0};
    glLightfv(GL_LIGHT1,GL_SPECULAR,speculaire_lampr2);

*/

    glPopMatrix();
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT1);


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
int ISS::CheckAshing(float x, float y, float z) {
      if (((x)*(x) + (y)*(y) + ((-30)-z)*((-30)-z)) < 40) {
          return 1;
      }
   return -1;
}

