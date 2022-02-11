#include "supprimeralbumwindow.h"
#include "database.h"
#include <QDebug>

Supprimeralbumwindow::Supprimeralbumwindow(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    this->styleSheet() = parent->styleSheet();
    for(int i : getAlbums()){
        this->comboBox_albums->addItem(QString::fromUtf8(getTitleAlbum(i).c_str()));
    }
    actualiserApercu(comboBox_albums->currentText());
}

void Supprimeralbumwindow::on_button_suppr_clicked()
{
    int id_currentalbum = comboBox_albums->currentIndex()+1;
    std::vector<int> idsimages = getAllImages(id_currentalbum);
    for(int i : idsimages){
        removeImagesTagsByImage(i);
        removeImage(i);
    }
    removeAlbum(id_currentalbum);
    accept();
}


void Supprimeralbumwindow::on_button_anuler_clicked()
{
    reject();
}


void Supprimeralbumwindow::on_comboBox_albums_currentIndexChanged(int index)
{
    actualiserApercu(comboBox_albums->currentText());
}

void Supprimeralbumwindow::actualiserApercu(QString name)
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



