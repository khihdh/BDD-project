#include "coordinates.h"
#include <QApplication>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <QtMath>
#include <QRandomGenerator>

coordinates::coordinates(int nbAst2)
{
    nbAst = nbAst2;
    for (int i=0; i<nbAst; i++) {
        tabx_[i]=x;
        taby_[i]=y;
        tabz_[i]=z;
        tabd_[i]=d;
    }
}


float coordinates::RandomFloat(float min, float max)
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

bool coordinates::checkAstCol(float tabx[nbAstMax], float taby[nbAstMax], float tabz[nbAstMax], GLdouble tabd[nbAstMax]) {
    for (int i=0; i<nbAst; i++) {
        z=QRandomGenerator::global()->bounded(-20,-2);
        x=QRandomGenerator::global()->bounded(-20,20);
        y=QRandomGenerator::global()->bounded(-20,20);
        d = 1  + (rand() % 3);
        bool flag = false;
        while (!flag){
            int col = 0;
            z=QRandomGenerator::global()->bounded(-20,-2);
            x=QRandomGenerator::global()->bounded(-20,20);
            y=QRandomGenerator::global()->bounded(-20,20);
            for (int j = 0; j<i; j++) {
                    if (((tabx[j]-x)*(tabx[j]-x) + (taby[j]-y)*(taby[j]-y) + (tabz[j]-z)*(tabz[j]-z)) < 36) {
                        col+=1; }
                }
            qDebug()<<col;
            if (col == 0) {
                flag = true;
            }
            }



        tabx[i]=x;
        taby[i]=y;
        tabz[i]=z;
        tabd[i]=d;
    }

    return true;
}
