#include "creationalbumwindow.h"
#include "mainwindow.h"
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
    connect(ui_creationAlbum->album_name,SIGNAL(textChanged()),this,SLOT(checkAlbumNameNotEmpty()));
    ui_creationAlbum->create_album_btn->setEnabled(false);
}


void CreationAlbumWindow::on_create_album_btn_clicked()
{
   name = ui_creationAlbum->album_name->toPlainText();

   id_album = createAlbum(name.toStdString());
   int nbrOfItems = ui_creationAlbum->images_list->count();
   QString img_name;
   for(int i=0; i<nbrOfItems; i++){
        img_paths.append(ui_creationAlbum->images_list->item(i)->text());
        img_name = img_paths.at(i).split("/").last().split(".").first();
        createImage(id_album,img_name.toStdString(),img_paths.at(i).toStdString(),"",0,0,0,0,0);
   }
   cout << getTitleAlbum(id_album);
   std::vector<int> images = getAllImages(id_album);
}

void CreationAlbumWindow::checkAlbumNameNotEmpty()
{
    QString field = ui_creationAlbum->album_name->toPlainText();
    QStringList str = field.split("\n");
    if(field == ""){
         ui_creationAlbum->create_album_btn->setEnabled(false);
    }
    else{
        if(str.length() >= 0 && str[0] == ""){
            ui_creationAlbum->create_album_btn->setEnabled(false);
        }
        else{
            ui_creationAlbum->create_album_btn->setEnabled(true);
        }
    }
}


