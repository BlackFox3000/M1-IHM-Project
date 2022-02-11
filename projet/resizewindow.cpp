#include "resizewindow.h"
#include "editionimagewindow.h"

ResizeWindow::ResizeWindow(QWidget *parent) :
    QDialog(parent),ui_resize(new Ui::ResizeWindow)
{
    ui_resize->setupUi(this);
    this->setWindowTitle("Redimensionner l'image");
    this->styleSheet() = parent->styleSheet();
}

int ResizeWindow::getL()
{
   return ui_resize->largeur->value();
}

int ResizeWindow::getH()
{
   return ui_resize->hauteur->value();
}
