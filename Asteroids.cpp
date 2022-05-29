#include "Asteroids.h"
#include <QImage>
#include <QDebug>

Asteroids::Asteroids(float tabx[nbAstMax], float taby[nbAstMax], float tabz[nbAstMax],GLdouble tabd[nbAstMax], int nbAst2)
{
    nbAst = nbAst2;
    QImage ast = QImage(":/asteroids.jpg");
    QImage text_ast = ast.convertToFormat(QImage::Format_RGBA8888);
    QImage space = QImage(":/space.jpg");
    QImage text_space = space.convertToFormat(QImage::Format_RGBA8888);

    textures = new GLuint[2];
    glGenTextures(2, textures);

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

    for (int i=0; i< nbAst; i++) {
        tabx_[i] =tabx[i];
        taby_[i] =taby[i];
        tabz_[i] =tabz[i];
        tabd_[i] =  tabd[i];
    }
}

Asteroids::~Asteroids()
{
    float x=0,y=0,z=0, d=0;
}

void Asteroids::DeleteAst(int j){
    tabFlagDeleteAst[j]=true;
}


void  Asteroids::DrawAst(float x, float y, float z, GLdouble d,int i) {

    glPushMatrix();
    GLUquadricObj *quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    tabAst[i] = quad;
    tabFlagDeleteAst[i] = false;
    glTranslatef(x,y,z);
    c+=0.01;
    glRotatef(c,0,0,1);
    gluSphere(quad, d, 13, 13);
    glPopMatrix();


}

int Asteroids::CheckColSpaceship(float x, float y, float z) {
    for (int j = 0; j<nbAst; j++) {
            if (((tabx_[j]-x)*(tabx_[j]-x) + (taby_[j]-y)*(taby_[j]-y) + (tabz_[j]-z)*(tabz_[j]-z)) < 16) {
                return j;
            }
        }
   return -1;
}

void Asteroids::Display(uint64_t iTimeElapsed)
{
    int j =0;

    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, textures[0]);
    for (int i=0; i<nbAst; i++) {
        DrawAst(tabx_[i],taby_[i],tabz_[i], tabd_[i],i);

    }
    glPopMatrix();


    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, textures[1]);
    glTranslatef(0.f,0.f,0.f + spaceshipz_);
    GLUquadricObj *quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    gluSphere(quad,50, 50, 50);
    glPopMatrix();


    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

}

void Asteroids::incrSpaceShip(float x, float y, float z) {
    xSpaceShip = x;
    ySpaceShip = y;
    zSpaceShip = z;
}
