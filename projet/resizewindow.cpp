#include "resizewindow.h"
#include "editionimagewindow.h"

ResizeWindow::ResizeWindow(QWidget *parent) :
    QDialog(parent),ui_resize(new Ui::ResizeWindow)
{
    ui_resize->setupUi(this);
    this->setWindowTitle("Redimensionner");
    this->setStyleSheet("QDialog {background : #5b0e2d;}  QTextEdit{border: 2px solid black; width : 16px; height: 12px;} QLabel{background: white; border: 2px solid black; border-radius: 5px} QPushButton{ background: white; border: 2px solid black; border-radius: 5px; height: 25px; width: 50px;color: black;font-size: 15px;} ");

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


