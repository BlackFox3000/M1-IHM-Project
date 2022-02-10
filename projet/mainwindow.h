#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QFileSystemModel>
#include <QDirModel>
#include <QStandardItemModel>
#include "creationalbumwindow.h"
#include "navigation.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public:
    QList<QStandardItem*> findItemsRecurse( QStandardItemModel* model, const QString &text, int column, const QModelIndex& modelIndex = QModelIndex());
    QString path;
    CreationAlbumWindow c;
    Ui::MainWindow ui;
    navigation n;
    QString path_modif;


private:
    void updateTreeView(QString root,QStringList filesFind);
    void updateListWidget();
    void updateNavigation();
    int getIndexItemTreeViewModel(std::vector<QStandardItem*> items,QString file);
    void updateFilesFind(QStringList filesFind);
    void updateFolderRoot(QString folderRoot);
    void deletePictureGalerie();

    QString folderRoot;
    QStringList filesFind;
    QStandardItemModel * model;

protected slots:
    void actionFindFile();
    void on_button_modif_infos_clicked();
    void on_actionEditer_image_triggered();
    void on_actionCreer_nouvel_album_triggered();
    void supprimer();
    void ajouter();
    void viewAbumsFunctionSQL();
    void insertAlbumFunctionSQL();
    QString getElementTreeViewClicked();
    void on_actionClassique_triggered();
    void on_actionSombre_triggered();
    void on_actionBordeaux_triggered();
    void on_actionEditer_les_informations_triggered();
    void on_actionOuvrir_un_album_triggered();

private slots:
    void on_button_ouvrir_album_clicked();
    void on_button_creer_album_clicked();
    void on_treeView_doubleClicked();
    void on_treeView_clicked();
    void on_Next_clicked();
    void on_Prec_clicked();
    void on_addBtn_clicked();
    void on_editBtn_clicked();
};
#endif // MAINWINDOW_H
