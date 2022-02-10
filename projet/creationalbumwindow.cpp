#include "creationalbumwindow.h"
#include "database.h"
#include <QDebug>
#include <iostream>
using namespace std;

CreationAlbumWindow::CreationAlbumWindow(QWidget *parent) :
    QDialog(parent), ui_creationAlbum(new Ui::CreationAlbumWindow)
{
    ui_creationAlbum->setupUi(this);
    this->setWindowTitle("Créer un album");
    setWindowIcon(QIcon(":icon/add-album.png"));

    //this->setStyleSheet("QDialog{background : #5b0e2d;} QPushButton{ background: black; color: white; border: 2px solid black; border-radius: 12px; height: 25px; width: 50px;font-size: 15px; } QPushButton:hover{ background: #3A3A3A;} QLabel{color: white;} ");

}



void CreationAlbumWindow::on_create_album_btn_clicked()
{
   name = ui_creationAlbum->album_name->toPlainText();
   int id_album = createAlbum(name.toStdString());
   int nbrOfItems = ui_creationAlbum->images_list->count();
   qDebug() << name;
   qDebug() << nbrOfItems;
   for(int i=0; i<nbrOfItems; i++){
        img_paths.append(ui_creationAlbum->images_list->item(i)->text());
        createImage(id_album,"",img_paths.at(i).toStdString(),"",0,0,0,0,0);
   }
   qDebug() << img_paths;
   qDebug() << "======================================================";
   qDebug() << "les albums : ";
   qDebug() << getAlbums();
   qDebug() << "le titre de l'album crée : ";
   cout << getTitleAlbum(id_album);
   qDebug() << "les images de l'album crée : ";
   qDebug() << getAllImages(id_album);
   std::vector<int> images = getAllImages(id_album);
   for(int i : images){
       qDebug() << i;
       qDebug() << getPathImage(i).c_str();
   }
   qDebug() << "======================================================";

}

