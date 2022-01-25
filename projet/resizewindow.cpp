#include "resizewindow.h"
#include "editionimagewindow.h"

ResizeWindow::ResizeWindow(QWidget *parent) :
    QDialog(parent),ui_resize(new Ui::ResizeWindow)
{
    ui_resize->setupUi(this);
    this->setWindowTitle("Redimensionner");
}

int ResizeWindow::getL()
{
   QString l_string = ui_resize->largeur_txt->toPlainText();
   int l = l_string.toInt();
   return l;
}

int ResizeWindow::getH()
{
   QString h_string = ui_resize->hauteur_txt->toPlainText();
   int h = h_string.toInt();
   return h;
}


