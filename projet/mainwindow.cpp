#include "mainwindow.h"
#include "WindowFiles.h"
#include "modifinformations.h"
#include "ouvriralbum.h"
#include "mainwindow.h"
#include "WindowFiles.h"
#include <QDebug>
#include "editionimagewindow.h"
#include "modifinformations.h"
#include "creationalbumwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDirModel>
#include <vector>
#include "database.h"
#include "navigation.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    setWindowIcon(QIcon(":icon/album.png"));
    connect(actionAjouter_Fichier, SIGNAL(triggered()), this, SLOT(actionFindFile()));
    connect(actionEditer_l_image, SIGNAL(triggered()), this, SLOT(on_actionEditer_image_triggered()));
    connect(actionCr_er_un_album, SIGNAL(triggered()), this, SLOT(on_actionCreer_nouvel_album_triggered()));
    //connect(actionOuvrir_un_album,SIGNAL(triggered()), this, SLOT(viewAbumsFunctionSQL));
    connect(actionCr_er_un_album,SIGNAL(triggered()), this, SLOT(insertAlbumFunctionSQL));
    //connect(actionClassique,SIGNAL(triggered()),this,SLOT(on_actionClassiquetriggered));
    //connect(actionSombre,SIGNAL(triggered()),this,SLOT(on_actionSombretriggered));
    //connect(actionBordeaux,SIGNAL(triggered()),this,SLOT(on_actionBordeauxtriggered));




    treeView->setHeaderHidden(true);
    QStandardItemModel* model = new QStandardItemModel();
    model->appendRow(new QStandardItem("Arborescence vide"));
    treeView->setModel(model);

    album_img->setSelectionMode(QAbstractItemView::SingleSelection);
    album_img->setDragEnabled(true);
    album_img->viewport()->setAcceptDrops(true);
    album_img->setDropIndicatorShown(true);
    album_img->setDragDropMode(QAbstractItemView::InternalMove);

    //btn slider
    this->Next->setEnabled(false);
    this->Prec->setEnabled(false);

    //btn add to album
    this->addBtn->setVisible(false);
    //btn edit image
    this->editBtn->setVisible(false);

    //this->setStyleSheet("QMainWindow {background : #5b0e2d;} QDialog {background : #5b0e2d;}  QTextEdit{border: 2px solid black; width : 16px; height: 12px;} QLabel{color: white;} ");
    //this->setStyleSheet("QMainWindow {background : #5b0e2d;} QDialog{background : #5b0e2d;} QPushButton{ background: black; color: white; border: 2px solid black; border-radius: 12px; height: 25px; width: 50px;font-size: 15px; } QPushButton:hover{ background: #3A3A3A;} QLabel{color: white;} ");
}


void MainWindow::actionFindFile()
{
    Window window(this);
    if(window.exec()){
        if(filesFind.size() == 0){
            filesFind = window.getFiles();
            folderRoot = window.getFolder();
        }
        else{
            updateFilesFind(window.getFiles());
            updateFolderRoot(window.getFolder());
        }
        filesFind.sort();
        updateTreeView(folderRoot + "/",filesFind);
    }

}

void MainWindow::updateFilesFind(QStringList filesFind)
{
    int index = this->filesFind.size();
    filesFind.sort();
    for(QString fileFind : filesFind){
        bool dupli = false;
        for(int i = 0;i < index; i++){
            if(this->filesFind.at(i) == fileFind){
                dupli = true;
            }
        }
        if(!dupli){
            this->filesFind.append(fileFind);
        }
    }
}

void MainWindow::updateFolderRoot(QString folderRoot)
{
    if(this->folderRoot != folderRoot){
        QStringList folderRootSplit = this->folderRoot.split('/');
        QStringList newFolderRootSplit = folderRoot.split('/');
        int index = 0;
        bool loop = true;
        while(loop){
            if(folderRootSplit.at(index) == newFolderRootSplit.at(index)){
                index ++;
                if(newFolderRootSplit.size() <= index){
                    if(folderRootSplit.size() <= index){
                        this->folderRoot = folderRoot;
                    }
                   loop = false;
                }
                else{
                    if(folderRootSplit.size() <= index){
                        loop = false;
                    }
                }
            }
            else{
                if(index == 0){
                    this->folderRoot = "/";
                }
                else{
                    QString newRoot;
                    for(int i = 0; i < index; i++){
                        newRoot += folderRootSplit.at(i);
                        if(i < index - 1){
                            newRoot += "/";
                        }
                    }
                    this->folderRoot = newRoot;
                }
                loop = false;
            }
        }
    }
}

void MainWindow::updateTreeView(QString root,QStringList filesFind)
{
    model = new QStandardItemModel();
    treeView->setIconSize(QSize(20,20));
    int sizeChar = 7;
    
    std::vector<QStandardItem*> items;

    QStandardItem* itemRoot = new QStandardItem(QIcon("../projet/icon/icon_folder.ico"),root);
    itemRoot->setAccessibleDescription(root);
    items.push_back(itemRoot);
    itemRoot->setEditable(false);
    model->appendRow(itemRoot);

    int maxSize = root.length() * sizeChar;

    for(QString file : filesFind){
        QStringList splitList = file.split(root)[1].split('/');
        QString rootLoop = root;
        bool condition = false;
        int index = 0;
        int indent = 0;
        QString maxSizeValue = splitList[0];
        while(!condition){
            if(splitList.length() == 1){
                QStandardItem* item = new QStandardItem(QIcon("../projet/icon/icon_file.ico"),splitList[0]);
                item->setEditable(false);
                item->setAccessibleDescription(rootLoop + splitList[0]);
                items.at(index)->appendRow(item);
                if(((maxSizeValue.length() + indent ) * sizeChar) > maxSize){
                    maxSize = (maxSizeValue.length() + indent) * sizeChar;
                }
                condition = true;
            }
            else{
                int secondIndex = getIndexItemTreeViewModel(items,rootLoop + splitList[0]);
                if(secondIndex == -1){
                    QStandardItem* item = new QStandardItem(QIcon("../projet/icon/icon_folder.ico"),splitList[0]);
                    item->setAccessibleDescription(rootLoop + splitList[0]);
                    item->setEditable(false);
                    items.push_back(item);
                    items.at(index)->appendRow(item);
                    index = items.size() - 1;
                }
                else{
                    index = secondIndex;
                }
                rootLoop = rootLoop + splitList[0] + "/";
                splitList = file.split(rootLoop)[1].split('/');
                maxSizeValue = splitList[0];
                indent += 4;
            }
        }
    }

    treeView->setModel(model);
    treeView->header()->setSortIndicator(0,Qt::AscendingOrder);
    treeView->header()->setSortIndicatorShown(true);

    const QModelIndex index = model->indexFromItem(items.at(0));

    treeView->expand(index);
    treeView->scrollTo(index);
    treeView->setCurrentIndex(index);
    treeView->resizeColumnToContents(0);
    treeView->setHeaderHidden(true);
    treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    treeView->setColumnWidth(0, maxSize);
}


int MainWindow::getIndexItemTreeViewModel(std::vector<QStandardItem*> items,QString file)
{
    for(int i = 0; i < items.size(); i++){
        if(items.at(i)->accessibleDescription().compare(file) == 0){
            return i;
        }
    }
    return -1;
}

MainWindow::~MainWindow()
{

}

//======== modifier informations =========
void MainWindow::on_button_modif_infos_clicked()
{
    if(path_modif != ""){
        QStringList etiquettes;
        for(int i=0; i<comboBox_listeTags->count(); i++){
            etiquettes.append(comboBox_listeTags->itemText(i));
        }
        //ModifInformations m(this,label_titre->text(),label_extension->text(),label_dimensions->text(),
                            //label_creation->text(),label_modif->text(),etiquettes,2,path_modif);
        ModifInformations m(this,1);
        qDebug() << getPathImage(1).c_str();
        m.exec();
    }
}


void MainWindow::on_button_ouvrir_album_clicked()
{
    OuvrirAlbum o(this);
    album_img->clear();
    if(o.exec()){
        album_img->clear();
        album_img->setIconSize(QSize(150,150));
        //album_img->addItem(new QListWidgetItem("Titre album"));

        QListWidgetItem *itm;
        for(int i=0; i< o.img_paths.size(); i++){
            itm = new QListWidgetItem();
            QPushButton * button = new QPushButton("X");
            connect(button, &QPushButton::clicked, this, &MainWindow::deletePictureGalerie);
            button->setMinimumSize(QSize(22, 22));
            button->setMaximumSize(QSize(22,22));
            QString itmPath = o.img_paths.at(i);
            itm->setText(itmPath);
            itm->setTextColor(QColor(255,255,255));
            itm->setIcon(QIcon(o.img_paths.at(i)));
            album_img->addItem(itm);
            album_img->setItemWidget(itm,button);
        }
        o.img_paths.clear();

        this->editBtn->setVisible(true);

        titreAlbum->setText("Titre album : "+o.name);
        currentIdAlbum = o.idalbum;
        updateNavigation();

    }
}

void MainWindow::on_actionOuvrir_un_album_triggered()
{
    on_button_ouvrir_album_clicked();
}


void MainWindow::on_actionEditer_image_triggered()
{
    EditionImageWindow e(this);
    e.img_path = path;
    qDebug() << "img : "+e.img_path;
    if(QString::compare(e.img_path, QString()) != 0){
        bool valid = e.edit_image.load(e.img_path);
        if(valid){
            e.edit_image = e.edit_image.scaledToWidth(e.ui_edit->edit_label->width(), Qt::SmoothTransformation);
            e.ui_edit->edit_label->setPixmap(QPixmap::fromImage(e.edit_image));
            e.ui_edit->edit_label->setScaledContents(true);

        }else{
        }
    }else{
        e.edit_image.load(path_img->text());
        qDebug() << "=>"+path_img->text();
        e.edit_image = e.edit_image.scaledToWidth(e.ui_edit->edit_label->width(), Qt::SmoothTransformation);
        e.ui_edit->edit_label->setPixmap(QPixmap::fromImage(e.edit_image));
        e.ui_edit->edit_label->setScaledContents(true);

    }
    e.exec();
}

void MainWindow::on_actionEditer_les_informations_triggered(){
    on_button_modif_infos_clicked();
}


void MainWindow::deletePictureGalerie()
{
    album_img->takeItem(album_img->currentRow());
    if(album_img->currentRow() == album_img->count()-1){
        removeImage(getAllImages(currentIdAlbum)[album_img->currentRow()+1]);
    }else{
        removeImage(getAllImages(currentIdAlbum)[album_img->currentRow()]);
    }
    if(album_img->count() <= 1){
        Next->setEnabled(false);
        Prec->setEnabled(false);
    }
}
void MainWindow::updateListWidget(){
    qDebug() << c.img_paths;
    album_img->clear();
    album_img->setIconSize(QSize(150,150));
    //album_img->addItem(new QListWidgetItem("Titre album"));
    QListWidgetItem *itm;
    for(int i=0; i< c.img_paths.size(); i++){
        itm = new QListWidgetItem();
        QPushButton * button = new QPushButton("X");
        connect(button, &QPushButton::clicked, this, &MainWindow::deletePictureGalerie);
        button->setMinimumSize(QSize(22, 22));
        button->setMaximumSize(QSize(22,22));
        QString itmPath = c.img_paths.at(i);
        itm->setText(itmPath);
        itm->setTextColor(QColor(255,255,255));
        itm->setIcon(QIcon(c.img_paths.at(i)));
        album_img->addItem(itm);
        album_img->setItemWidget(itm,button);
    }
    this->editBtn->setVisible(true);

    titreAlbum->setText("Titre album : "+c.name);

}

void MainWindow::updateNavigation()
{
    //btn slider
    this->addBtn->setVisible(false);
    if(album_img->count() == 0){
        this->Next->setEnabled(false);
        this->Prec->setEnabled(false);
    }else{
    this->Next->setEnabled(true);
    this->Prec->setEnabled(true);
    this->editBtn->setVisible(true);

    QListWidgetItem *firstItem = album_img->item(0);
    qDebug() << firstItem->text();
    qDebug() << "affichage des info sur navigation";
    qDebug() << n.listpix;
    path_img->setText(album_img->item(0)->text());
    n.pix.load(firstItem->text());
    n.pix = n.pix.scaledToWidth(apercu_img->width(), Qt::SmoothTransformation);
    apercu_img->setPixmap(QPixmap::fromImage(n.pix));
    apercu_img->setScaledContents(true);
    path_modif = firstItem->text();
    }
}

void MainWindow::on_actionCreer_nouvel_album_triggered()
{

    album_img->clear();
    c.ui_creationAlbum->images_list->clear();
    c.img_paths.clear();
    for(int i=0; i<filesFind.size(); i++){
        QListWidgetItem * itm = new QListWidgetItem();
        QString itmPath = filesFind.at(i);
        itm->setText(itmPath);
        itm->setTextColor(QColor(255,255,255));
        QPushButton *ajouter = new QPushButton("ajouter");
        itm->setIcon(QIcon(filesFind.at(i)));
        ajouter->setFixedSize(55,35);
        c.ui_creationAlbum->img_show->setIconSize(QSize(200,200));
        c.ui_creationAlbum->img_show->addItem(itm);
        c.ui_creationAlbum->img_show->setItemWidget(itm,ajouter);

        connect(ajouter,SIGNAL(clicked()),this,SLOT(ajouter()));
    }
        if(c.exec()){
            updateListWidget();
            // add to navigation
            updateNavigation();

        }
        currentIdAlbum = c.id_album;
        c.ui_creationAlbum->img_show->clear();

}
void MainWindow::ajouter(){
    qDebug() << "ajouter test";
    int itmIndex = c.ui_creationAlbum->img_show->selectionModel()->currentIndex().row();
    QList<QString> texts;
    for(int i=0; i < c.ui_creationAlbum->images_list->count(); i++){
        texts.append(c.ui_creationAlbum->images_list->model()->index(i,0).data(Qt::DisplayRole).toString());
    }
    qDebug() << texts;
    qDebug() << itmIndex;
    if(texts.contains(filesFind.at(itmIndex))){
        qDebug() << "item exist déja";
    }else{
        QListWidgetItem *itm = new QListWidgetItem();
        QString itmPath = filesFind.at(itmIndex);
        itm->setText(itmPath);
        itm->setTextColor(QColor(255,255,255));
        QPushButton *supprimer = new QPushButton("supprimer");
        supprimer->setFixedSize(80,35);
        itm->setIcon(c.ui_creationAlbum->img_show->item(itmIndex)->icon());
        c.ui_creationAlbum->images_list->setIconSize(QSize(400,200));
        c.ui_creationAlbum->images_list->addItem(itm);
        c.ui_creationAlbum->images_list->setItemWidget(itm,supprimer);
        connect(supprimer,SIGNAL(clicked()),this,SLOT(supprimer()));
    }



}
void MainWindow::supprimer(){
    qDebug() << "supp test";
    int itmIndex = c.ui_creationAlbum->images_list->selectionModel()->currentIndex().row();
    c.ui_creationAlbum->images_list->model()->removeRow(itmIndex);
    c.img_paths.removeAt(itmIndex);

}
void MainWindow::on_button_creer_album_clicked()
{
    on_actionCreer_nouvel_album_triggered();
    //CreationAlbumWindow c;
    //c.exec();
}
QString MainWindow::getElementTreeViewClicked()
{
    QString element = model->itemFromIndex(treeView->selectionModel()->selectedIndexes().at(0))->accessibleDescription();
    QFileInfo fi(element);
         if(fi.isFile()){
             return element;
         }
   return NULL;
}

void MainWindow::on_treeView_doubleClicked()
{
    path = getElementTreeViewClicked();
    if(path != NULL){
        qDebug() << path;
        EditionImageWindow e(this);
        e.img_path = path;
        qDebug() << "img : "+e.img_path;
        if(QString::compare(e.img_path, QString()) != 0){
            bool valid = e.edit_image.load(e.img_path);
            if(valid){

                e.edit_image = e.edit_image.scaledToWidth(e.ui_edit->edit_label->width(), Qt::SmoothTransformation);
                e.ui_edit->edit_label->setPixmap(QPixmap::fromImage(e.edit_image));
                e.ui_edit->edit_label->setScaledContents(true);

            }
        }

        if(e.exec()){}
    }
}



void MainWindow::on_treeView_clicked()
{
    QString element = getElementTreeViewClicked();
    if(element != NULL){
        editBtn->setVisible(true);
        QList<QString> paths;
        for(int i=0; i <album_img->count(); i++){
            paths.append(album_img->model()->index(i,0).data(Qt::DisplayRole).toString());
        }

        if(paths.contains(element)){
            addBtn->setVisible(false);
            Next->setEnabled(true);
            Prec->setEnabled(true);
        }else{
        qDebug() << "file cliked : " << element;
        n.pix.load(element);
        n.pix = n.pix.scaledToWidth(apercu_img->width(), Qt::SmoothTransformation);
        apercu_img->setText(element);
        path_img->setText(element);
        path_modif = element;
        apercu_img->setPixmap(QPixmap::fromImage(n.pix));
        apercu_img->setScaledContents(true);
        Next->setEnabled(false);
        Prec->setEnabled(false);
        addBtn->setVisible(true);
        }
    }
}


void MainWindow::on_addBtn_clicked()
{
    QString element = getElementTreeViewClicked();
    QListWidgetItem *itm = new QListWidgetItem();
    itm->setIcon(QIcon(element));
    QPushButton * button = new QPushButton("X");
    connect(button, &QPushButton::clicked, this, &MainWindow::deletePictureGalerie);
    button->setMinimumSize(QSize(22, 22));
    button->setMaximumSize(QSize(22,22));
    QString itmPath = element;
    QString img_name = itmPath.split("/").last().split(".").first();
    itm->setText(itmPath);
    itm->setTextColor(QColor(255,255,255));
    album_img->setIconSize(QSize(200,200));
    album_img->addItem(itm);
    album_img->setItemWidget(itm,button);
    addBtn->setVisible(false);
    Next->setEnabled(true);
    Prec->setEnabled(true);
    createImage(currentIdAlbum,img_name.toStdString(),itmPath.toStdString(),"",0,0,0,0,0);


}
//SQL
void MainWindow::viewAbumsFunctionSQL(){
    //createImage(1, "premiere image", "c/path","descrrription", 1, 0,0, 0, 0);
    view();
}

void MainWindow::insertAlbumFunctionSQL(){
    createAlbum("monsecond albumm");
}


//======== navigation =========
int num=0;
void MainWindow::on_Next_clicked()
{
    num++;
    if(num >= album_img->count()){
        num=0;
    }
    n.pix.load(album_img->item(num)->text());
    qDebug() << album_img->item(num)->text();
    path_img->setText(album_img->item(num)->text());
    n.pix = n.pix.scaledToWidth(apercu_img->width(), Qt::SmoothTransformation);
    apercu_img->setPixmap(QPixmap::fromImage(n.pix));
    apercu_img->setScaledContents(true);
    path_modif = album_img->item(num)->text();

}


void MainWindow::on_Prec_clicked()
{
    num--;
    if(num < 0){
        num=album_img->count()-1;
    }
    n.pix.load(album_img->item(num)->text());
    path_img->setText(album_img->item(num)->text());
    n.pix = n.pix.scaledToWidth(apercu_img->width(), Qt::SmoothTransformation);
    apercu_img->setPixmap(QPixmap::fromImage(n.pix));
    apercu_img->setScaledContents(true);
    path_modif = album_img->item(num)->text();

}


void MainWindow::on_editBtn_clicked()
{
    EditionImageWindow e(this);

        e.edit_image.load(path_img->text());
        qDebug() << "=>"+path_img->text();
        e.edit_image = e.edit_image.scaledToWidth(e.ui_edit->edit_label->width(), Qt::SmoothTransformation);
        e.ui_edit->edit_label->setPixmap(QPixmap::fromImage(e.edit_image));
        e.ui_edit->edit_label->setScaledContents(true);


    e.exec();
}

void MainWindow::on_actionClassique_triggered()
{
    qDebug() << "classique";
    this->setStyleSheet("");
    c.setStyleSheet(this->styleSheet());
}

void MainWindow::on_actionSombre_triggered()
{
    qDebug() << "sombre";
    this->setStyleSheet("QMainWindow {background : #202124;} QDialog{background : #202124;} QPushButton{ background: black; color: white; border: 2px solid black; border-radius: 12px; height: 25px; width: 50px;font-size: 15px; } QPushButton:hover{ background: #3A3A3A;} QLabel{color: white;} ");
    c.setStyleSheet(this->styleSheet());
}

void MainWindow::on_actionBordeaux_triggered()
{
    qDebug() << "bordeaux";
    this->setStyleSheet("QMainWindow {background : #5b0e2d;} QDialog{background : #5b0e2d;} QPushButton{ background: black; color: white; border: 2px solid black; border-radius: 12px; height: 25px; width: 50px;font-size: 15px; } QPushButton:hover{ background: #3A3A3A;} QLabel{color: white;} ");
    c.setStyleSheet(this->styleSheet());

}

