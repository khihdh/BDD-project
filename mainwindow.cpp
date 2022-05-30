#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QInputDialog>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QFileDialog>
#include "mainwindow.h"

// Cette classe va gérer l'interface utilisateur principale avec le joueur
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{   
    label =new QLabel;
    label->setText("Interstellar'tse Game !");
    label->setVisible(true);
    label->setAlignment(Qt::AlignCenter);

    btnPlay = new QPushButton(tr("&Play"));
    connect(btnPlay, SIGNAL(clicked()), this, SLOT(play()));

    QPushButton *btnQuit = new QPushButton(tr("&quit"));
    connect(btnQuit, SIGNAL(clicked()), this, SLOT(quit()));


    nbAst_Label = new QLabel();
    QString str = "Choose a difficulty between 1 and 3 (1=easy, 3=hard)";
    nbAst_Label->setText(str);
    nbAst_Label->setVisible(true);
    nbAst_Label->setAlignment(Qt::AlignCenter);

    winLoose_Label = new QLabel();
    winLoose_str = "Click to play to start a game!";
    winLoose_Label->setText(winLoose_str);
    winLoose_Label->setVisible(true);
    winLoose_Label->setAlignment(Qt::AlignCenter);

    spinBox = new QSpinBox();
    spinBox->setValue(0);
    spinBox->setVisible(true);
    spinBox->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(nbAst_Label);
    layout->addWidget(spinBox);
    layout->addWidget(winLoose_Label);
    layout->addWidget(l = new QLabel(this));
    l->setText(QTime(0, 0).toString());
    layout->addWidget(btnPlay);
    layout->addWidget(btnQuit);

    //On connecte le timer t à la fonction updateTime() pour actualiser le chronomètre toute les secondes
    connect(&t, SIGNAL(timeout()), this, SLOT(updateTime()));

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    timerMessageBox = new QTimer(this);

    //On connecte le timer à la fonction checkGameOver() pour qu'elle soit appeler toute les secondes 
    QObject::connect(timerMessageBox, SIGNAL(timeout()), this, SLOT(checkGameOver()));


}


MainWindow::~MainWindow()
{

}

//Cette fonction permet de initialiser une partie et offre la possibilité au joueur de rejouer
void  MainWindow::play(){
    //gameOverFlag = false => la partie est en cours
    gameOverFlag=false;
    //On (ré)initialise le chronomètre à 0. 
    l->setText(QTime(0, 0).toString());
    //On restart le timer du chronomètre après l'avoir stop à la fin de la partie précédente si le joueur rejoue
    startTime.restart();
    t.start(1000);
    //On restart le timer qui permet d'appeler la fonction checkGameOverFlag() 
    timerMessageBox->start(1000);
    //On récupère la difficulté choisis par l'utilisateur
    int diff = spinBox->value();
    nbAst = 0;
    winLoose_str = "The game is live !";
    winLoose_Label->setText(winLoose_str);
    if (diff == 1) {
        detectFist_.setNbAst(7);
    }
    else if (diff == 2) {
        detectFist_.setNbAst(10);
    }
    else if (diff == 3) {
        detectFist_.setNbAst(16);
    }
    //On lance la webcam et la scène
    detectFist_.show();
}
int MainWindow::getNbAst() {
    return nbAst;
}

// Cette fonction permet de checker toute les secondes si la partie est terminé ou pas afin d'en informer le joueur
void MainWindow::checkGameOver()
{
    if (!gameOverFlag) {
        if  (detectFist_.checkGameOverFlag()) {
            t.stop();
            //on reset les coordonnées du vaisseau
            detectFist_.reset();
            winLoose_str = "You loose ! Your score is just below. Click to play to restart the game.";
            winLoose_Label->setText(winLoose_str);
            gameOverFlag = true;
        }
        else if (detectFist_.checkForWinFlag()) {
            t.stop();
            detectFist_.reset();
            winLoose_str = "You win ! Your score is just below. Click to play to restart the game.";
            winLoose_Label->setText(winLoose_str);
            gameOverFlag = true;
        }
    }

}



void MainWindow::quit() {
    detectFist_.closeApp();
    close();
}

//Cette fonction permet de mettre à jours l'affichage du chronomètre
void MainWindow::updateTime() {
    l->setText(QTime(0, 0).addMSecs(startTime.elapsed()).toString());
}

//Cette fonction permet de lancer le chronomètre
void MainWindow::start() {
      l->setText(QTime(0, 0).toString());
      startTime.restart();
      t.start(1000);
    }




