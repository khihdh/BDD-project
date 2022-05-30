#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QListWidget>
#include <QMainWindow>
#include "detectfist.h"
#include <QSpinBox>
#include <QElapsedTimer>
#include <QPushButton>

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
    void play();
    void quit();
    void checkGameOver();
    void updateTime();
    void start();
};
#endif // MAINWINDOW_H

