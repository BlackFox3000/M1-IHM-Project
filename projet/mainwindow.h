#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QFileSystemModel>
#include <QDirModel>
#include <QStandardItemModel>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QList<QStandardItem*> findItemsRecurse( QStandardItemModel* model, const QString &text, int column, const QModelIndex& modelIndex = QModelIndex());

private:
    void updateTreeView(QString root,QStringList filesFind);
    int getIndexItemTreeViewModel(std::vector<QStandardItem*> items,QString file);
    void updateFilesFind(QStringList filesFind);
    void updateFolderRoot(QString folderRoot);

    QString folderRoot;
    QStringList filesFind;

protected slots:
    void actionFindFile();
    void on_button_modif_infos_clicked();
    void on_actionEditer_image_triggered();
    void on_actionCreer_nouvel_album_triggered();

private slots:
    void on_button_ouvrir_album_clicked();
};
#endif // MAINWINDOW_H
