#include "collision.h"
#include <QApplication>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <QtMath>
#include <QRandomGenerator>

//cette classe permet de tirer aléatoirement dans l’espace les coordonnées des astéroïdes ainsi que leur diamètre et de vérifier qu’il n’y a pas de collision entre chaque astéroïde en calculant la norme entre deux astéroïdes
collision::collision(int nbAst2)
{
    nbAst = nbAst2;
    for (int i=0; i<nbAstMax; i++) {
        tabx_[i]=x;
        taby_[i]=y;
        tabz_[i]=z;
        tabd_[i]=d;
    }
}

//cette fonction permet de set le nombre d'asteroides choisit par le joueur
void collision::setNbAst(int nbAst2) {
    nbAst = nbAst2;
}

//cette fonction permet de choisir aleatoirement les coordonnees des asteroides dans l'espace ainsi que leur diametre et de 
//checker si les asteroides n'entrent pas en colission les uns avec les autres
bool collision::checkAstCol(float tabx[nbAstMax], float taby[nbAstMax], float tabz[nbAstMax], GLdouble tabd[nbAstMax]) {
    for (int i=0; i<nbAstMax; i++) {
        //on choisit aleatoirement des coordonnees pour l'asteroide i 
        z=QRandomGenerator::global()->bounded(-20,-1);
        x=QRandomGenerator::global()->bounded(-22,22);
        y=QRandomGenerator::global()->bounded(-18,18);
        //on choisir aleatoirement un diametre a l'asteroide i 
        d = 1  + (rand() % 3);
        bool flag = false;
        //tant qu'il y a colission possible
        while (!flag){
            int col = 0;
            z=QRandomGenerator::global()->bounded(-20,-1);
            x=QRandomGenerator::global()->bounded(-22,22);
            y=QRandomGenerator::global()->bounded(-18,18);
            for (int j = 0; j<i; j++) {
                //on calcul la distance entre l'asteroide j et les asteroides i avec i<j
                    if (((tabx[j]-x)*(tabx[j]-x) + (taby[j]-y)*(taby[j]-y) + (tabz[j]-z)*(tabz[j]-z)) < 36) {
                        //on incremente la variable col si il y a collision
                        col+=1; }
                }
            //cas ou il n'y a pas eu de collision on sort de la boucle while
            if (col == 0) {
                flag = true;
            }
            }

        //on remplit le tableau avec les coordonnées de l'asteroide i et son diamètre
        tabx[i]=x;
        taby[i]=y;
        tabz[i]=z;
        tabd[i]=d;
    }

    return true;
}
