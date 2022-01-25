#include "editionimagewindow.h"
#include "mainwindow.h"
#include "resizewindow.h"
#include "resizerubberband.h"
#include "QPushButton"
#include "QMouseEvent"


EditionImageWindow::EditionImageWindow(QWidget *parent) :
    QDialog(parent),ui_edit(new Ui::EditionImageWindow)
{
    ui_edit->setupUi(this);
    this->setWindowTitle("Edit imge");
    ui_edit->zoomSlider->setVisible(false);



}
QImage edit_image;
void EditionImageWindow::on_btn_img_clicked()
{

    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"), "", tr("Images(*.png *.jpg *.jpeg)"));
    if(QString::compare(filename, QString()) != 0){
        bool valid = edit_image.load(filename);
        if(valid){
            edit_image = edit_image.scaledToWidth(ui_edit->edit_label->width(), Qt::SmoothTransformation);
            ui_edit->edit_label->setPixmap(QPixmap::fromImage(edit_image));
            ui_edit->edit_label->setScaledContents(true);
        }else{
        }
    }

}



void EditionImageWindow::on_resize_btn_clicked()
{
    ResizeWindow r;
    QImage resized_img = edit_image;
    if(r.exec()){
        ui_edit->edit_label->setFixedSize(r.getL(),r.getH());
        ui_edit->edit_label->setPixmap(QPixmap::fromImage(resized_img));
        ui_edit->edit_label->setScaledContents(true);
    }else{

    }


}



int nbrClick = 1;
void EditionImageWindow::on_zoom_btn_clicked()
{
    if(nbrClick%2==0){
      ui_edit->zoomSlider->setVisible(false);
      nbrClick += 1;
    }else{
      ui_edit->zoomSlider->setVisible(true);
      nbrClick += 1;
    }
}




void EditionImageWindow::on_zoomSlider_valueChanged(int value)
{
    QImage img_zoom = edit_image;
//    ui_edit->edit_label->setAlignment(Qt::AlignHCenter);
    ui_edit->edit_label->setFixedSize(value,value);
    ui_edit->edit_label->setPixmap(QPixmap::fromImage(img_zoom));
    ui_edit->edit_label->setScaledContents(true);
}





void EditionImageWindow::on_reset_btn_clicked()
{
    ui_edit->edit_label->setFixedSize(500,500);
    QImage or_image = edit_image.scaledToWidth(ui_edit->edit_label->width(), Qt::SmoothTransformation);
    ui_edit->edit_label->setPixmap(QPixmap::fromImage(or_image));
    ui_edit->edit_label->setScaledContents(true);
}


void EditionImageWindow::mousePressEvent(QMouseEvent *event){
    origin = event->pos();
        if (!rubberBand)
            rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
        rubberBand->setGeometry(QRect(origin, QSize()));
        rubberBand->show();

}
void EditionImageWindow::mouseMoveEvent(QMouseEvent *event){
     rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
     QRect rect = rubberBand->frameGeometry();
     cropped = edit_image.copy(rect.x(), rect.y(), rect.width(), rect.height());






}
void EditionImageWindow::mouseReleaseEvent(QMouseEvent *event){}

void EditionImageWindow::on_crop_btn_clicked()
{
    ui_edit->edit_label->setFixedSize(rubberBand->frameGeometry().width(), rubberBand->frameGeometry().height());
    ui_edit->edit_label->setPixmap(QPixmap::fromImage(cropped));
    ui_edit->edit_label->setScaledContents(true);
    rubberBand->hide();
}

