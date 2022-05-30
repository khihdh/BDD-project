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

class detectFist : public QOpenGLWidget
{
public:
public:
    int i=0;
    detectFist(QWidget * parent = nullptr);
    ~detectFist();
    void show();
    void setNbAst(int i);
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
    int nbAst;


};

#endif // DETECTFIST_H
