#ifndef COLLISION_H
#define COLLISION_H
#include <GL/gl.h>
#include <GL/glu.h>

//cette classe permet de tirer aléatoirement dans l’espace les coordonnées des astéroïdes ainsi que leur diamètre et de vérifier 
//qu’il n’y a pas de collision entre chaque astéroïde en calculant la norme entre deux astéroïdes

class collision
{
private:
    float x=0,y=0,z=0;
    GLdouble d=0;
    const static int nbAstMax = 16;
    int nbAst=0;
    float tabx_[nbAstMax];
    float taby_[nbAstMax];
    float tabz_[nbAstMax];
    GLdouble tabd_[nbAstMax];
public:
    collision(int nbAst);
    //cette fonction permet de set le nombre d'asteroides choisit par le joueur
    void setNbAst(int nbAst2);
    float RandomFloat(float min, float max);
    //cette fonction permet de choisir aleatoirement les coordonnees des asteroides dans l'espace ainsi que leur diametre et de 
    //checker si les asteroides n'entrent pas en colission les uns avec les autres
    //param: les tableaux de flottant qui doivent être remplis par les coordonnees des asteroides et le tableau des diametres des asteroides
    bool checkAstCol(float tabx_[nbAstMax], float taby_[nbAstMax], float tabz_[nbAstMax], GLdouble tabd_[nbAstMax]);
};

#endif // COLLISION_H
