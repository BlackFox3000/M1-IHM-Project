#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"

#include <QMainWindow>

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QTreeView* getTreeView();

protected slots:
        void actionFindFile();

private slots:
        void on_modifier_infos_clicked();
        void on_ouvrir_album_clicked();
};
#endif // MAINWINDOW_H
