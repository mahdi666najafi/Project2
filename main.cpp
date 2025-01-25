#include "mainwindow403.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow403 w;
    w.resize(2000,1250);
    w.show();
    return a.exec();
}
