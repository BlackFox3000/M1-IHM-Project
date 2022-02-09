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
#include "album.h"
#include <QDebug>
#include <QDirModel>
#include <vector>
#include "database.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    setWindowIcon(QIcon(":icon/album.png"));
    connect(actionAjouter_Fichier, SIGNAL(triggered()), this, SLOT(actionFindFile()));
    connect(actionEditer_l_image, SIGNAL(triggered()), this, SLOT(on_actionEditer_image_triggered()));
    connect(actionCr_er_un_album, SIGNAL(triggered()), this, SLOT(on_actionCreer_nouvel_album_triggered()));
    connect(actionOuvrir_un_album,SIGNAL(triggered()), this, SLOT(viewAbumsFunctionSQL));
    connect(actionCr_er_un_album,SIGNAL(triggered()), this, SLOT(insertAlbumFunctionSQL));
    connect(test,&QPushButton::clicked, this, &MainWindow::testFunctionSQL);


    treeWidget->setHeaderHidden(true);
}


void MainWindow::testFunctionSQL(){
    Album album = Album("Le premier");
    createAlbum("monsecond albumm");
    createImage(1, "premiere image", "c/path","descrrription", 1, 0,0, 0, 0);
    view();
}

void MainWindow::actionFindFile()
{
    Window window;
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
QStandardItemModel * model;
void MainWindow::updateTreeView(QString root,QStringList filesFind)
{
    model = new QStandardItemModel();

    std::vector<QStandardItem*> items;

    QStandardItem* itemRoot = new QStandardItem(QIcon("icon_folder.ico"),root);
    itemRoot->setAccessibleDescription(root);
    items.push_back(itemRoot);
    itemRoot->setEditable(false);
    model->appendRow(itemRoot);


    for(QString file : filesFind){
        QStringList splitList = file.split(root)[1].split('/');
        QString rootLoop = root;
         bool condition = false;
         int index = 0;
         int maxSize = 0;
         QString maxSizeValue;
        while(!condition){
            if(splitList.length() == 1){
                QStandardItem* item = new QStandardItem(QIcon("icon_file.ico"),splitList[0]);
                item->setEditable(false);
                item->setAccessibleDescription(rootLoop + splitList[0]);
                items.at(index)->appendRow(item);
                if(maxSizeValue.length() > maxSize){
                    maxSize = maxSizeValue.length();
                }
                condition = true;
            }
            else{
                int secondIndex = getIndexItemTreeViewModel(items,rootLoop + splitList[0]);
                if(secondIndex == -1){
                    QStandardItem* item = new QStandardItem(QIcon("icon_folder.ico"),splitList[0]);
;                    item->setAccessibleDescription(rootLoop + splitList[0]);
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
            }
        }
    }

    treeView->setModel(model);
    treeView->header()->setSortIndicator(0,Qt::AscendingOrder);
    treeView->header()->setSortIndicatorShown(true);

    for(int i = 0; i < items.size(); i++){
        QModelIndex index = model->indexFromItem(items.at(i));
        QIcon icon = items.at(i)->icon();
        //icon.paint()
    }

    const QModelIndex index = model->indexFromItem(items.at(0));

    treeView->expand(index);
    treeView->scrollTo(index);
    treeView->setCurrentIndex(index);
    treeView->resizeColumnToContents(0);
    treeView->setHeaderHidden(true);
    treeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    treeView->setColumnWidth(0, 200);
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

void MainWindow::on_button_modif_infos_clicked()
{
    QStringList etiquettes;
    for(int i=0; i<comboBox_listeTags->count(); i++){
        etiquettes.append(comboBox_listeTags->itemText(i));
    }
    ModifInformations m(this,label_titre->text(),label_extension->text(),label_dimensions->text(),
                        label_creation->text(),label_modif->text(),etiquettes);
    m.exec();
}


void MainWindow::on_button_ouvrir_album_clicked()
{
    OuvrirAlbum o;
    o.exec();
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
    }
    e.exec();

}
void MainWindow::on_actionCreer_nouvel_album_triggered()
{

    for(int i=0; i<filesFind.size(); i++){
       // c.ui_creationAlbum->images_list->addItem(filesFind.at(i));
        itm = new QListWidgetItem();
        QPushButton *supp = new QPushButton("supp");
        itm->setIcon(QIcon(filesFind.at(i)));
        supp->setFixedSize(55,35);
        c.ui_creationAlbum->images_list->setIconSize(QSize(500,500));
        c.ui_creationAlbum->images_list->addItem(itm);
        c.ui_creationAlbum->images_list->setItemWidget(itm,supp);
        connect(supp,SIGNAL(clicked()),this,SLOT(supprimer()));
    }
    c.exec();
}
void MainWindow::supprimer(){
    qDebug() << "supp test";
    int itmIndex = c.ui_creationAlbum->images_list->selectionModel()->currentIndex().row();
    c.ui_creationAlbum->images_list->model()->removeRow(itmIndex);

}
void MainWindow::on_button_creer_album_clicked()
{
    CreationAlbumWindow c;
    c.exec();
}
QString MainWindow::getElementTreeViewClicked()
{
    QString element = model->itemFromIndex(treeView->selectionModel()->selectedIndexes().at(0))->accessibleDescription();
         if(element.split('.').size() > 1){
             return element;
         }
   return NULL;
}

void MainWindow::on_treeView_doubleClicked()
{
    path = getElementTreeViewClicked();
    if(path != NULL){
        qDebug() << path;
        EditionImageWindow e;
        e.img_path = path;
        qDebug() << "img : "+e.img_path;
        if(QString::compare(e.img_path, QString()) != 0){
            bool valid = e.edit_image.load(e.img_path);
            if(valid){
                e.edit_image = e.edit_image.scaledToWidth(e.ui_edit->edit_label->width(), Qt::SmoothTransformation);
                e.ui_edit->edit_label->setPixmap(QPixmap::fromImage(e.edit_image));
                e.ui_edit->edit_label->setScaledContents(true);
            }
            else{
            }
        }
        if(e.exec()){}
    }
}



void MainWindow::on_treeView_clicked()
{
    QString element = getElementTreeViewClicked();
    if(element != NULL){
        qDebug() << "file cliked : " << element;
    }
}

//SQL
void MainWindow::viewAbumsFunctionSQL(){
    //createImage(1, "premiere image", "c/path","descrrription", 1, 0,0, 0, 0);
    view();
}

void MainWindow::insertAlbumFunctionSQL(){
    createAlbum("monsecond albumm");
}
