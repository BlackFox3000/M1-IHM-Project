#include "mainwindow.h"
#include "WindowFiles.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    createConnection();
    w.show();
    return a.exec();
}
