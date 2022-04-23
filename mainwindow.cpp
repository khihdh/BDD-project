#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //image background
    QPixmap pix("C:/Users/33651/Projet_Avril/texture/start2");
    ui -> label -> setStyleSheet("border-image:url(C:/Users/33651/Projet_Avril/texture/start2);");
    ui->label->setPixmap(pix);

    //play button
    ui -> playButton -> setStyleSheet("QPushButton{ background-color : #585858; color : red;}");
     ui -> asteroideNumber -> setStyleSheet("QLabel{ background-color : black; color : red;}");
    ui -> title -> setStyleSheet("QLabel {color: rgb(255, 0, 0);background-color:black}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

