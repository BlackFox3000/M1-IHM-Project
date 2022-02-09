#include "ouvriralbum.h"

OuvrirAlbum::OuvrirAlbum(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    this->styleSheet() = parent->styleSheet();
}
