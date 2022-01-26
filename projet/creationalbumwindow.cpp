#include "creationalbumwindow.h"

CreationAlbumWindow::CreationAlbumWindow(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    this->setWindowTitle("Créer un album");
    this->setStyleSheet("QDialog{background : #5b0e2d;} QLabel{color: white;} QPushButton{background: white; border: 2px solid black; border-radius: 12px; height: 25px; width: 50px;color: black;font-size: 15px;}");

}

