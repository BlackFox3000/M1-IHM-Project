#include "resizewindow.h"
#include "editionimagewindow.h"

/* ================ Fenetre de redimensionnement d'image ================== */
ResizeWindow::ResizeWindow(QWidget *parent) :
    QDialog(parent),ui_resize(new Ui::ResizeWindow)
{
    ui_resize->setupUi(this);
    this->setWindowTitle("Redimensionner l'image");
    this->styleSheet() = parent->styleSheet();
}

/* ================ Recupere la valeur de largeur entree par l'utilisateur ================== */
int ResizeWindow::getL()
{
   return ui_resize->largeur->value();
}

/* ================ Recupere la valeur de hauteur entree par l'utilisateur ================== */
int ResizeWindow::getH()
{
   return ui_resize->hauteur->value();
}
