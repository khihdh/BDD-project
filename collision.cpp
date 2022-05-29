#include "collision.h"
#include <QApplication>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <QtMath>
#include <QRandomGenerator>

collision::collision(int nbAst2)
{
    nbAst = nbAst2;
    for (int i=0; i<nbAst; i++) {
        tabx_[i]=x;
        taby_[i]=y;
        tabz_[i]=z;
        tabd_[i]=d;
    }
}

bool collision::checkAstCol(float tabx[nbAstMax], float taby[nbAstMax], float tabz[nbAstMax], GLdouble tabd[nbAstMax]) {
    for (int i=0; i<nbAst; i++) {
        z=QRandomGenerator::global()->bounded(-20,-1);
        x=QRandomGenerator::global()->bounded(-22,22);
        y=QRandomGenerator::global()->bounded(-18,18);
        d = 1  + (rand() % 3);
        bool flag = false;
        while (!flag){
            int col = 0;
            z=QRandomGenerator::global()->bounded(-20,-1);
            x=QRandomGenerator::global()->bounded(-22,22);
            y=QRandomGenerator::global()->bounded(-18,18);
            for (int j = 0; j<i; j++) {
                    if (((tabx[j]-x)*(tabx[j]-x) + (taby[j]-y)*(taby[j]-y) + (tabz[j]-z)*(tabz[j]-z)) < 36) {
                        col+=1; }
                }
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
