#include "coordinates.h"
#include <QApplication>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <QtMath>
#include <QRandomGenerator>

coordinates::coordinates()
{
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

bool coordinates::checkAstCol(float tabx[nbAst], float taby[nbAst], float tabz[nbAst], GLdouble tabd[nbAst]) {
    for (int i=0; i<nbAst; i++) {
        z=QRandomGenerator::global()->bounded(-20,-2);
        x=QRandomGenerator::global()->bounded(-20,20);
        y=QRandomGenerator::global()->bounded(-20,20);
        d = 1  + (rand() % 3);
        bool flag = false;
        while (!flag){
            flag = true;
            z=QRandomGenerator::global()->bounded(-20,-2);
            x=QRandomGenerator::global()->bounded(-20,20);
            y=QRandomGenerator::global()->bounded(-20,20);
            for (int j = 0; j<i; j++) {
                    if ((tabx_[j]-x)*(tabx_[j]-x) + (taby_[j]-y)*(taby_[j]-y) + (tabz_[j]-z)*(tabz_[j]-z) < 12) {
                        flag = false;
                }
            }
        }


        tabx[i]=x;
        taby[i]=y;
        tabz[i]=z;
        tabd[i]=d;
    }

    return true;
}
