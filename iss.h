#ifndef ISS_H
#define ISS_H
#include <qopengl.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QColor>

class ISS
{
private:
    GLuint * textures;
    float c =0;

public:
    ISS();
    ~ISS();
    void Display(uint64_t iTimeElapsed);
};

#endif // ISS_H
