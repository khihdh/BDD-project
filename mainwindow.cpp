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
    layout->addWidget(btnPlay);
    layout->addWidget(l = new QLabel(this));
    l->setText(QTime(0, 0).toString());
    layout->addWidget(btnQuit);

    connect(&t, SIGNAL(timeout()), this, SLOT(updateTime()));
    //connect(btnPlay, SIGNAL(clicked(bool)), this, SLOT(start()));
    //connect(stopB, SIGNAL(clicked(bool)), &t, SLOT(stop()));

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    QTimer *timer = new QTimer(this);

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(checkGameOver()));

    timer->start(1000);
}


MainWindow::~MainWindow()
{

}

void  MainWindow::play(){
    l->setText(QTime(0, 0).toString());
    startTime.restart();
    t.start(1000);
    int diff = spinBox->value();
    nbAst = 0;
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
    if  (detectFist_.checkGameOverFlag()) {
        qDebug()<<"gameOVER";
        t.stop();
        detectFist_.reset();
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


