#include "mainwindow.h"
#include "window.h"
#include <QDebug>
#include "editionimagewindow.h"
#include "creationalbumwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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

void MainWindow::on_actionEditer_image_triggered()
{
    EditionImageWindow e(this);
    e.exec();

}
void MainWindow::on_actionCreer_nouvel_album_triggered()
{
    CreationAlbumWindow c;
    c.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
MainWindow::~MainWindow()
{

}

