#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QListWidget>
#include <QMainWindow>
#include <QSpinBox>
 #include "detectfist.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QLabel *label, *label2;
    QListWidget *listTable;
    QSpinBox *spinBox;
    int nbAst =0;
    detectFist detectFist_ = nullptr;



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getNbAst();


private slots:
    void play();
    void quit();
    void quit2();
    void save();
    void open();
};
#endif // MAINWINDOW_H
