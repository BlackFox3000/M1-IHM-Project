#include "editionimagewindow.h"
#include "mainwindow.h"
#include "resizewindow.h"
#include "QPushButton"
#include "QMouseEvent"
#include <QDebug>
#include <QScrollArea>


EditionImageWindow::EditionImageWindow(QWidget *parent) :
    QDialog(parent),ui_edit(new Ui::EditionImageWindow)
{
    qDebug() <<"lancement de la fenetre";

    ui_edit->setupUi(this);
    this->setWindowTitle("Edit image");
    setWindowIcon(QIcon(":icon/edit-album.png"));


    ui_edit->zoomSlider->setVisible(false);
    ui_edit->crop_btn->setEnabled(false);
    ui_edit->zoom_prc->setVisible(false);
    ui_edit->size_img->setText("taille de l'image "+QString::number(ui_edit->edit_label->width())+"x"+QString::number(ui_edit->edit_label->height()));
    //QPushButton{ background: white; border: 2px solid black; border-radius: 12px; height: 25px; width: 50px;color: black;font-size: 15px;}
    //this->setStyleSheet("QDialog {background : #5b0e2d;}  QLabel#size_img{padding-left: 200px;} QLabel#edit_label{ border: 2px solid white;} QPushButton{ background: black; color: white; border: 2px solid black; border-radius: 12px; height: 25px; width: 50px;font-size: 15px;} QPushButton:hover{background: #3A3A3A;}  ");
    this->styleSheet() = parent->styleSheet();
}

/* ================ Importer une image ================== */

void EditionImageWindow::on_btn_img_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"), "", tr("Images(*.png *.jpg *.jpeg)"));
    qDebug() << filename;

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

/* ================ Redimensionner une image ================== */

void EditionImageWindow::on_resize_btn_clicked()
{
    ResizeWindow r;
    QImage resized_img = edit_image;
    if(r.exec()){
        ui_edit->edit_label->setFixedSize(r.getL(),r.getH());
        ui_edit->edit_label->setPixmap(QPixmap::fromImage(resized_img));
        ui_edit->edit_label->setScaledContents(true);
        ui_edit->size_img->setText("taille de l'image "+QString::number(r.getL())+"x"+QString::number(r.getH()));

    }else{

    }
}

/* ================ Zoomer une image ================== */

int nbrClick = 1;
void EditionImageWindow::on_zoom_btn_clicked()
{
    if(nbrClick%2==0){
      ui_edit->zoomSlider->setVisible(false);
      ui_edit->zoom_prc->setVisible(false);

      nbrClick += 1;
    }else{
      ui_edit->zoomSlider->setVisible(true);
      ui_edit->zoom_prc->setVisible(true);
      nbrClick += 1;
    }
}


void EditionImageWindow::on_zoomSlider_valueChanged(int value)
{

    QImage img_zoom = edit_image;
    ui_edit->edit_label->setFixedSize(value,value);
    ui_edit->edit_label->setPixmap(QPixmap::fromImage(img_zoom));
    ui_edit->edit_label->setScaledContents(true);
    ui_edit->size_img->setText("taille de l'image "+QString::number(value)+"x"+QString::number(value));
    ui_edit->zoom_prc->setVisible(true);
    ui_edit->zoom_prc->setText(QString::number(value/5.5)+"%");





}

/* ================ Revenir à l'image originale ================== */

void EditionImageWindow::on_reset_btn_clicked()
{
    ui_edit->edit_label->setFixedSize(500,500);
    QImage or_image = edit_image.scaledToWidth(ui_edit->edit_label->width(), Qt::SmoothTransformation);
    ui_edit->edit_label->setPixmap(QPixmap::fromImage(or_image));
    ui_edit->edit_label->setScaledContents(true);
}

/* ================ Rogner une image ================== */

void EditionImageWindow::mousePressEvent(QMouseEvent *event){
    origin = event->pos();
        if (!rubberBand)
            rubberBand = new QRubberBand(QRubberBand::Rectangle, this);



}
void EditionImageWindow::mouseMoveEvent(QMouseEvent *event){
     rubberBand->setGeometry(QRect(origin, event->pos()).normalized());
     ui_edit->crop_btn->setEnabled(true);
     rubberBand->show();
}
void EditionImageWindow::mouseReleaseEvent(QMouseEvent *event){
    rect.setTopLeft(origin);
    rect.setBottomRight(event->pos());
}

void EditionImageWindow::on_crop_btn_clicked()
{

      rubberBand->hide();
      ui_edit->edit_label->setPixmap(grab(rect));
      ui_edit->edit_label->setScaledContents(true);
      ui_edit->crop_btn->setEnabled(false);


}

/* ================ Pivoter une image ================== */

void EditionImageWindow::on_pivoter_btn_clicked()
{
    qDebug() <<"test";
    QTransform t;
    ui_edit->edit_label->setPixmap(QPixmap::fromImage(edit_image.transformed(t.rotate(90))));
    ui_edit->edit_label->setScaledContents(true);
    edit_image = edit_image.transformed(t.rotate(0));

}

