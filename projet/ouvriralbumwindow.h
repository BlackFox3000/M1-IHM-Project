#ifndef OUVRIRALBUMWINDOW_H
#define OUVRIRALBUMWINDOW_H

#include "ui_ouvriralbumwindow.h"

class OuvrirAlbumWindow : public QDialog, private Ui::OuvrirAlbumWindow
{
    Q_OBJECT

public:
    explicit OuvrirAlbumWindow(QWidget *parent = nullptr);
};

#endif // OUVRIRALBUMWINDOW_H
