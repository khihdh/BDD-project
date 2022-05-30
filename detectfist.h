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

//La classe detectFist permet de gérer la détection des positions des mains de l’utilisateur par rapport à la webcam. 
class detectFist : public QOpenGLWidget
{
public:
public:
    int i=0;
    int nbAst;
    int frameWidth;
    int frameHeight;
    bool gameOverFlag = false;
    bool winFlag = false;
    VideoCapture cap;
    CascadeClassifier face_cascade;
    CascadeClassifier face_cascade2;
    MySpace myspace_;

    detectFist(QWidget * parent = nullptr);
    ~detectFist();

    //retourne le flag permettant de savoir si la partie est perdu
    bool checkGameOverFlag();
    //retourne le flag permettant de savoir si la partie est gagné
    bool checkForWinFlag();
    //Cette fonction permet de fermer la scène du jeu et de reinitaliser les coordonees du vaisseau et le statut de la partie
    void reset();
    void closeApp();
    //Cette fonction permet de lancer la camera et de gerer les interactions entre le joueur et la webcam
    //Elle permet egalement d'initaliser la scene du jeu
    void show();
    //Permet de set le nombre d'asteroides choisis par le joueur
    void setNbAst(int i);


};

#endif // DETECTFIST_H
