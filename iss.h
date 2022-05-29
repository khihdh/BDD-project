#ifndef ISS_H
#define ISS_H
#include <qopengl.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <QColor>

// Classe dediee pour la gestion de la station
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
