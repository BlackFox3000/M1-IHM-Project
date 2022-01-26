#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QPainter>
#include <QtWidgets/QMainWindow>
#include "qrubberband.h"
#include "editionimagewindow.h"
#include <QMainWindow>
#include<QLabel>
#include<QDesktopWidget>
#include<QKeyEvent>
#include<QEvent>
#include <QPushButton>

namespace Ui{
class MainWindow;
}

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QTreeView* getTreeView();

protected slots:
        void on_actionEditer_image_triggered();
        void on_actionCreer_nouvel_album_triggered();
        void actionFindFile();


private:
    Ui::MainWindow *ui;
    EditionImageWindow *e;
};
#endif // MAINWINDOW_H
