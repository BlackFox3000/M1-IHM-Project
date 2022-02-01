#include "mainwindow.h"
#include "window.h"
#include "modifinformations.h"
#include "ouvriralbum.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);

     connect(actionAjouter_Fichier, SIGNAL(triggered()), this, SLOT(actionFindFile()));
}

QTreeView* MainWindow::getTreeView()
{
    return treeView;
}

void MainWindow::actionFindFile()
{
    qDebug() <<"test";
    Window window(getTreeView());
    window.show();
    QEventLoop loop;
    loop.exec();

}

MainWindow::~MainWindow()
{

}


void MainWindow::on_modifier_infos_clicked()
{
    ModifInformations m;
    m.exec();
}


void MainWindow::on_ouvrir_album_clicked()
{
    OuvrirAlbum o;
    o.exec();
}

