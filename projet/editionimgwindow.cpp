#include "editionimgwindow.h"
#include "mainwindow.h"

EditionImgWindow::EditionImgWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_edit(new Ui::EditionImgWindow), scrollArea(new QScrollArea)
{
    ui_edit->setupUi(this);
    ui_edit->edit_label->setBackgroundRole(QPalette::Base);

    ui_edit->edit_label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui_edit->edit_label->setScaledContents(true);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(edit_label);
}

void EditionImgWindow::on_btn_img_clicked()
{


    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"), "", tr("Images(*.png *.jpg *.jpeg)"));
    if(QString::compare(filename, QString()) != 0){
        bool valid = image.load(filename);
        if(valid){
            image = image.scaledToWidth(ui_edit->edit_label->width(), Qt::SmoothTransformation);
            ui_edit->edit_label->setPixmap(QPixmap::fromImage(image));
            ui_edit->edit_label->setScaledContents(true);
        }else{

        }
    }

}
