#include "Asteroids.h"
#include <QImage>
#include <QDebug>

Asteroids::Asteroids(float tabx[nbAst], float taby[nbAst], float tabz[nbAst],GLdouble tabd[nbAst])
{
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


void  Asteroids::DrawAst(float x, float y, float z, GLdouble d) {

    glBindTexture(GL_TEXTURE_2D, textures[0]);

    GLUquadricObj *quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE);
    glTranslatef(x,y,z);
    c+=0.01;
    glRotatef(c,0,0,1);
    gluSphere(quad, d, 13, 13);


}

float Asteroids::RandomFloat(float min, float max)
{
    // this  function assumes max > min, you may want
    // more robust error checking for a non-debug build
    assert(max > min);
    float random = ((float) rand()) / (float) RAND_MAX;

    // generate (in your case) a float between 0 and (4.5-.78)
    // then add .78, giving you a float between .78 and 4.5
    float range = max - min;
    return (random*range) + min;
}


void Asteroids::Display(uint64_t iTimeElapsed)
{
    int j =0;

    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

    for (int i=0; i<nbAst; i++) {
        glPushMatrix();
        DrawAst(tabx_[i],taby_[i],tabz_[i], tabd_[i]);
        glPopMatrix();
    }

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

void Asteroids::incrCoordinatesZSpaceship() {
    spaceshipz_-=0.2;
}
