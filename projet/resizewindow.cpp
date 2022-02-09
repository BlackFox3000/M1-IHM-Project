#include "resizewindow.h"
#include "editionimagewindow.h"

ResizeWindow::ResizeWindow(QWidget *parent) :
    QDialog(parent),ui_resize(new Ui::ResizeWindow)
{
    ui_resize->setupUi(this);
    this->setWindowTitle("Redimensionner l'image");
    //this->setStyleSheet("QDialog {background : #5b0e2d;}  QSpinBox{width : 15px; height: 50px;} QLabel{background: white; border: 2px solid black; border-radius: 5px} QPushButton{ background: black; color: white; border: 2px solid black; border-radius: 12px; height: 25px; width: 50px;font-size: 15px; } QPushButton:hover{background: #3A3A3A;} ");
    this->styleSheet() = parent->styleSheet();
}

int ResizeWindow::getL()
{
  // QString l_string = ui_resize->largeur_txt->toPlainText();
   int L = ui_resize->largeur->value();
   //int l = l_string.toInt();
   return L;
}

int ResizeWindow::getH()
{
  // QString h_string = ui_resize->hauteur_txt->toPlainText();
   //int h = h_string.toInt();
   int H = ui_resize->hauteur->value();
   return H;
}
