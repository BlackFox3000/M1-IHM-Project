#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
}

QTreeView* MainWindow::getTreeView()
{
    return ui.treeView;
}

MainWindow::~MainWindow()
{

}

