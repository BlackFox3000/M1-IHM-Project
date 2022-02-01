#ifndef OUVRIRALBUM_H
#define OUVRIRALBUM_H

#include "ui_ouvriralbum.h"

class OuvrirAlbum : public QDialog, private Ui::OuvrirAlbum
{
    Q_OBJECT

public:
    explicit OuvrirAlbum(QWidget *parent = nullptr);
};

#endif // OUVRIRALBUM_H
