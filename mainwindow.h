#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QListWidget>
#include <QMainWindow>
#include "MySpace.h"
#include <QSpinBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QLabel *label, *label2;
    QListWidget *listTable;
    QSpinBox *spinBox;
    int nbAst =0;
    MySpace myspace_;



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getNbAst();


private slots:
    void play();
    void quit();
    void save();
    void open();
};
#endif // MAINWINDOW_H
