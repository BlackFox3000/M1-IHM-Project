#include "mainwindow.h"
#include "WindowFiles.h"
#include <QDebug>
#include <QDirModel>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    connect(actionAjouter_Fichier, SIGNAL(triggered()), this, SLOT(actionFindFile()));
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

void MainWindow::updateTreeView(QString root,QStringList filesFind)
{
    QStandardItemModel * model = new QStandardItemModel();

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
        while(!condition){
            if(splitList.length() == 1){
                QStandardItem* item = new QStandardItem(QIcon("icon_file.ico"),splitList[0]);
                item->setEditable(false);
                item->setAccessibleDescription(rootLoop + splitList[0]);
                items.at(index)->appendRow(item);
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
        icon.paint()
    }

    const QModelIndex index = model->indexFromItem(items.at(0));
    treeView->expand(index);
    treeView->scrollTo(index);
    treeView->setCurrentIndex(index);
    treeView->resizeColumnToContents(0);
    treeView->setHeaderHidden(true);
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

