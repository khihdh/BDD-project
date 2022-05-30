#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QListWidget>
#include <QMainWindow>
#include "detectfist.h"
#include <QSpinBox>
#include <QElapsedTimer>
#include <QPushButton>

// Cette classe va gérer l'interface utilisateur principale avec le joueur
class MainWindow : public QMainWindow
{
    Q_OBJECT
    QLabel *label, *nbAst_Label, *winLoose_Label;
    QSpinBox *spinBox;
    int nbAst =0;
    detectFist detectFist_;
    QElapsedTimer startTime;
    QTimer t;
    QTimer *timerMessageBox;
    QString winLoose_str;
    QLabel * l;
    QPushButton * startB, * stopB;
    QPushButton *btnPlay;
    bool gameOverFlag = false;



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getNbAst();


private slots:
    //Ce slot permet de initialiser une partie et offre la possibilité au joueur de rejouer
    void play();
    //ce slot permet de fermer le mainwindow et la scene ainsi que la camera
    void quit();
    // Ce slot permet de checker toute les secondes si la partie est terminé ou pas afin d'en informer le joueur
    void checkGameOver();
    //Ce slot permet de mettre à jours l'affichage du chronomètre
    void updateTime();
    //Ce slot permet de lancer le chronomètre
    void start();
};
#endif // MAINWINDOW_H

