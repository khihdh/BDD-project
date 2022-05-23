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
    detectFist(QWidget * parent = nullptr);
    ~detectFist();
    void show(int nbAst);
    int frameWidth=640;
    int frameHeight=480;
    CascadeClassifier face_cascade;
    CascadeClassifier face_cascade2;
    MySpace myspace_;

};

#endif // DETECTFIST_H
