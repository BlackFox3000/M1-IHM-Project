#include "ouvriralbum.h"
#include <QDebug>
#include <iostream>
#include "database.h"
using namespace std;

OuvrirAlbum::OuvrirAlbum(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    this->styleSheet() = parent->styleSheet();
    for(int i=1; i<getAlbums().size()+1;i++){
        this->comboBox_albums->addItem(QString::fromUtf8(getTitleAlbum(i).c_str()));
    }
    actualiserApercu(comboBox_albums->currentIndex()+1);
}

void OuvrirAlbum::on_button_ouverture_clicked()
{
    qDebug() << "-----------------pour ouvir----------------";
}

void OuvrirAlbum::on_button_anuler_clicked()
{
    reject();
}



void OuvrirAlbum::on_comboBox_albums_currentIndexChanged(int index)
{
    actualiserApercu(index+1);
}

void OuvrirAlbum::actualiserApercu(int idAlbum){
    listWidget_apercualbum->clear();
    std::vector<int> images = getAllImages(idAlbum);
    for(int i : images){
        QImage image;
        image.load(getPathImage(i).c_str());
        this->listWidget_apercualbum->setIconSize(QSize(200,200));
        this->listWidget_apercualbum->addItem(new QListWidgetItem(QIcon(QPixmap::fromImage(image)),getPathImage(i).c_str()));
    }
}
