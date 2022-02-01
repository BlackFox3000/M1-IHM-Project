#ifndef CREATIONALBUMWINDOW_H
#define CREATIONALBUMWINDOW_H

#include "ui_creationalbumwindow.h"

class CreationAlbumWindow : public QDialog, private Ui::CreationAlbumWindow
{
    Q_OBJECT

public:
    explicit CreationAlbumWindow(QWidget *parent = nullptr);
};

#endif // CREATIONALBUMWINDOW_H
