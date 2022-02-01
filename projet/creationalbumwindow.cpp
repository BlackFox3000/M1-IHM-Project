#include "creationalbumwindow.h"

CreationAlbumWindow::CreationAlbumWindow(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    this->setWindowTitle("Créer un album");
    this->setStyleSheet("QDialog{background : #5b0e2d;} QPushButton{ background: black; color: white; border: 2px solid black; border-radius: 12px; height: 25px; width: 50px;font-size: 15px; transition-duration: 0.4s;} QPushButton:hover{transition-duration: 0.1s; background: #3A3A3A;} QLabel{color: white;} ");

}

