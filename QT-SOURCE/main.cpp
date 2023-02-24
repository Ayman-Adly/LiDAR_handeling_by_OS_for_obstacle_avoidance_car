#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //object from mainWindow class
    MainWindow w;
    w.show();
    //Run MainWindow
    return a.exec();
}
