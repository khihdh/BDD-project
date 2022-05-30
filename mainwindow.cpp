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
    //layout->addWidget(startB = new QPushButton("start", this));
    //layout->addWidget(stopB = new QPushButton("stop", this));
    layout->addWidget(label);
    layout->addWidget(nbAst_Label);
    layout->addWidget(spinBox);
    layout->addWidget(winLoose_Label);
    layout->addWidget(l = new QLabel(this));
    l->setText(QTime(0, 0).toString());
    layout->addWidget(btnPlay);
    layout->addWidget(btnQuit);

    connect(&t, SIGNAL(timeout()), this, SLOT(updateTime()));
    //connect(btnPlay, SIGNAL(clicked(bool)), this, SLOT(start()));
    //connect(stopB, SIGNAL(clicked(bool)), &t, SLOT(stop()));

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    timerMessageBox = new QTimer(this);

    QObject::connect(timerMessageBox, SIGNAL(timeout()), this, SLOT(checkGameOver()));


}


MainWindow::~MainWindow()
{

}

void  MainWindow::play(){
    gameOverFlag=false;
    l->setText(QTime(0, 0).toString());
    startTime.restart();
    t.start(1000);
    timerMessageBox->start(1000);
    int diff = spinBox->value();
    nbAst = 0;
    winLoose_str = "The game is live !";
    winLoose_Label->setText(winLoose_str);
    if (diff == 1) {
        nbAst = 7;
    }
    else if (diff == 2) {
        nbAst = 10;
    }
    else if (diff == 3) {
        nbAst = 16;
    }
    detectFist_.show(nbAst);
}
int MainWindow::getNbAst() {
    return nbAst;
}
void MainWindow::checkGameOver()
{
    if (!gameOverFlag) {
        if  (detectFist_.checkGameOverFlag()) {
            t.stop();
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

void MainWindow::updateTime() {
    l->setText(QTime(0, 0).addMSecs(startTime.elapsed()).toString());
}

void MainWindow::start() {
      l->setText(QTime(0, 0).toString());
      startTime.restart();
      t.start(1000);
    }


