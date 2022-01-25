#include "mainwindow.h"
#include "window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Window window;
   // window.show();
    w.show();
    return a.exec();
}
