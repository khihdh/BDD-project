#ifndef DETECTFIST_H
#define DETECTFIST_H
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <QOpenGLWidget>
#include "MySpace.h"

#include <cstdio>
#include <iostream>



using namespace cv;
using namespace std;

// Classe dediee pour la gestion de la camera

class detectFist : public QOpenGLWidget
{
public:
    int i=0;
    detectFist(QWidget * parent = nullptr);
    ~detectFist();
    void show(int nbAst);
    int frameWidth;
    int frameHeight;
    VideoCapture cap;
    bool gameOverFlag = false;
    bool winFlag = false;
    CascadeClassifier face_cascade;
    CascadeClassifier face_cascade2;
    MySpace myspace_;
    bool checkGameOverFlag();
    bool checkForWinFlag();
    void reset();
    void closeApp();

};

#endif // DETECTFIST_H
