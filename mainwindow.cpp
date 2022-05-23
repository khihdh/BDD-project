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


    listTable = new QListWidget;

    QPushButton *btnPlay = new QPushButton(tr("&Play"));
    connect(btnPlay, SIGNAL(clicked()), this, SLOT(play()));

    label2 = new QLabel();
    QString str = "Choose the number of Asteroids (between 0 and 40)";
    label2->setText(str);
    label2->setVisible(true);
    label2->setAlignment(Qt::AlignCenter);

    spinBox = new QSpinBox();
    spinBox->setValue(0);
    spinBox->setVisible(true);
    spinBox->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(label2);
    layout->addWidget(spinBox);
    layout->addWidget(btnPlay);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}


MainWindow::~MainWindow()
{

}

void  MainWindow::play(){
    nbAst = spinBox->value();
    qDebug()<<nbAst;
    myspace_.setNbAst(nbAst);
    myspace_.show();
}
int MainWindow::getNbAst() {
    return nbAst;
}
void MainWindow::open()
{

}

void MainWindow::save()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));
}

void MainWindow::quit() {

    close();
}

