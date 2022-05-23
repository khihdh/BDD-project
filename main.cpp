#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    // Creation de l'application QT
        QApplication app(argc, argv);
        // Creation du widget opengl
        //MySpace myspace;
        //myspace.show();
        MainWindow w;
        w.show();


        // Execution de l'application QT
        return app.exec();

}
