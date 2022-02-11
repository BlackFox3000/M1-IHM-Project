#include "ouvriralbum.h"
#include <QDebug>
#include <iostream>
#include "database.h"
#include "mainwindow.h"

using namespace std;

OuvrirAlbum::OuvrirAlbum(QWidget *parent) :
    QDialog(parent), ui_ouvrirAlbum(new Ui::OuvrirAlbum)
{
    setupUi(this);
    this->styleSheet() = parent->styleSheet();
    for(int i : getAlbums()){
        this->comboBox_albums->addItem(QString::fromUtf8(getTitleAlbum(i).c_str()));
    }
    actualiserApercu(comboBox_albums->currentText());
}

void OuvrirAlbum::on_button_ouverture_clicked()
{
    name = this->comboBox_albums->currentText();
    for(int i : getAlbums()){
        if(getTitleAlbum(i).c_str() == name){
            idalbum = i;
        }
    }
    idalbum = this->comboBox_albums->currentIndex()+1;
    int nbrOfItems = this->listWidget_apercualbum->count();
    for(int i=0; i<nbrOfItems; i++){
         img_paths.append(this->listWidget_apercualbum->item(i)->text());
    }
}

void OuvrirAlbum::on_button_anuler_clicked()
{
    reject();
}



void OuvrirAlbum::on_comboBox_albums_currentIndexChanged(int index)
{
    actualiserApercu(comboBox_albums->currentText());
}

void OuvrirAlbum::actualiserApercu(QString name)
{
    int id_search;
    for(int i : getAlbums()){
        if(getTitleAlbum(i).c_str() == name){
            id_search = i;
        }
    }
    listWidget_apercualbum->clear();
    std::vector<int> images = getAllImages(id_search);
    for(int i : images){
        QImage image;
        image.load(getPathImage(i).c_str());
        this->listWidget_apercualbum->setIconSize(QSize(200,200));
        this->listWidget_apercualbum->addItem(new QListWidgetItem(QIcon(QPixmap::fromImage(image)),getPathImage(i).c_str()));
    }
}
