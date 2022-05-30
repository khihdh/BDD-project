#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include "detectfist.h"
#include <unistd.h>
#include <cstdio>
#include <iostream>

using namespace cv;
using namespace std;

detectFist::detectFist(QWidget *parent) : QOpenGLWidget(parent)
{
    frameWidth=640;
    frameHeight=480;
}

detectFist::~detectFist(){
    myspace_.hide();
}

void detectFist::reset(){
    unsigned int microsecond = 1000000;
    usleep(5 * microsecond);
    myspace_.hide();
    myspace_.reset();
    cap.release();
    gameOverFlag = false;
    winFlag = false;
}

void detectFist::closeApp() {
    myspace_.closeApp();
    close();
}
    void detectFist::show(int nbAst){

    myspace_.setNbAst(nbAst);
    myspace_.show();

    VideoCapture cap(0); // open the default camera
    cout<<"width :"<<cap.get(CAP_PROP_FRAME_WIDTH)<<endl;
    cout<<"height :"<<cap.get(CAP_PROP_FRAME_HEIGHT)<<endl;
    cap.set(CAP_PROP_FRAME_WIDTH,frameWidth);
    cap.set(CAP_PROP_FRAME_HEIGHT,frameHeight);
    moveWindow("image", 1000, 100);

    if(!cap.isOpened())  // check if we succeeded
    {
        cerr<<"Error openning the default camera"<<endl;
    }

    //CascadeClassifier face_cascade;
   if( !face_cascade.load( "/Users/ismetkerenciler/Downloads/TestDetectFist/closed_frontal_palm.xml" ) )
    {

        cerr<<"Error loading haarcascade"<<endl;
    }
    //CascadeClassifier face_cascade2;
    if( !face_cascade2.load( "/Users/ismetkerenciler/Downloads/TestDetectFist/palm.xml" ) )
    {
        cerr<<"Error loading haarcascade"<<endl;
    }

    // Init output window
    namedWindow("WebCam",1);

while (waitKey(5)<0)
{

    if (myspace_.checkGameOverFlag()){
        gameOverFlag = true;
    }

    if (myspace_.checkForWinFlag()){
        winFlag = true;
    }

    Mat frame,frame_gray;
    std::vector<Rect> faces;
    std::vector<Rect> faces2;
    std::vector<Rect> beforeSort;
    std::vector<Rect> afterSort;
    std::vector<bool> booleanBefore;
    std::vector<bool> booleanAfter;
    // Get frame
    cap >> frame;

    cv::line(frame,Point(0,160),Point(640,160),Scalar(255),2,8,0);
    cv::line(frame,Point(0,320),Point(640,320),Scalar(255),2,8,0);
    // Mirror effect
    cv::flip(frame,frame,1);
    // Convert to gray
    cv::cvtColor(frame,frame_gray,COLOR_BGR2GRAY);
    // Equalize graylevels
    //equalizeHist( frame_gray, frame_gray );

    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 4, 0|CASCADE_SCALE_IMAGE, Size(60, 60) );
    face_cascade2.detectMultiScale( frame_gray, faces2, 1.1, 4, 0|CASCADE_SCALE_IMAGE, Size(60, 60) );
    // Draw green rectangle
    for (int i=0;i<(int)faces.size();i++){
        rectangle(frame,faces[i],Scalar(0,255*i,0),2);
        //cout<<faces[i]<<faces[i].x<<"////////";
    }
    for (int i=0;i<(int)faces2.size();i++){
        rectangle(frame,faces2[i],Scalar(0,255*i,0),2);
        //cout<<faces[i]<<faces[i].x<<"////////";
    }


    for (int i=0; i<faces.size();i++){
        beforeSort.push_back(faces[i]);
        booleanBefore.push_back(true);
    }
    for (int i=0; i<faces2.size();i++){
        beforeSort.push_back(faces2[i]);
        booleanBefore.push_back(false);
    }


    if (beforeSort.size()>1)
    {
        if (beforeSort[0].x>beforeSort[1].x){

            afterSort.push_back(beforeSort[1]);
            booleanAfter.push_back(booleanBefore[1]);
            afterSort.push_back(beforeSort[0]);
            booleanAfter.push_back(booleanBefore[0]);
        }
        else{
            afterSort.push_back(beforeSort[0]);
            booleanAfter.push_back(booleanBefore[0]);
            afterSort.push_back(beforeSort[1]);
            booleanAfter.push_back(booleanBefore[1]);
        }

        if (afterSort[0].y<160 && booleanAfter[0]){
            if (160<afterSort[1].y && afterSort[1].y<320 && booleanAfter[1]){
                cout <<"rotation droite  "<<endl;
                myspace_.E();
            }
            if (afterSort[1].y<160 && booleanAfter[1]){
                cout<<"rotation haute  "<<endl;
                myspace_.Q();
            }
        }
        if (afterSort[0].y>320 && booleanAfter[0]){
            if (afterSort[1].y>320 && booleanAfter[1]){
                cout<<"rotation basse  "<<endl;
                myspace_.D();
            }
        }
        if (160<afterSort[0].y && afterSort[0].y<320 && booleanAfter[0]){
            if (afterSort[1].y<160 && booleanAfter[1]){
                cout<<"rotation gauche  "<<endl;
                myspace_.A();
            }
        }
        if (160<afterSort[0].y && afterSort[0].y<320 && !booleanAfter[0]){
            if (160<afterSort[1].y && afterSort[1].y<320 && !booleanAfter[1]){
                cout<<"avance  "<<endl;
                myspace_.Z();
            }
        }


        beforeSort.clear();
        afterSort.clear();
    }

    // Display frame
    imshow("WebCam", frame);

}
// the camera will be deinitialized automatically in VideoCapture destructor
}

    bool detectFist::checkGameOverFlag() {
        return gameOverFlag;
    }

    bool detectFist::checkForWinFlag() {
        return winFlag;
    }

