#include "mainwindow.h"
#include "WindowFiles.h"
#include "database.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    createConnection();
    MainWindow w;
    w.show();
    qDebug() << getAlbums()[3];
    return a.exec();
}
