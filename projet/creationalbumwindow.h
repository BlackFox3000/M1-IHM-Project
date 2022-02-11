#ifndef CREATIONALBUMWINDOW_H
#define CREATIONALBUMWINDOW_H

#include "ui_creationalbumwindow.h"

class CreationAlbumWindow : public QDialog, private Ui::CreationAlbumWindow
{
    Q_OBJECT

public:
    explicit CreationAlbumWindow(QWidget *parent = nullptr);
    Ui::CreationAlbumWindow *ui_creationAlbum;
    QImage selectedImg;
    QList<QString> img_paths;
    QString name;
    int id_album;

private slots:
    void on_create_album_btn_clicked();
};

#endif // CREATIONALBUMWINDOW_H
