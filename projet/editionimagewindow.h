#ifndef EDITIONIMAGEWINDOW_H
#define EDITIONIMAGEWINDOW_H

#include "qrubberband.h"
#include "ui_editionimagewindow.h"
#include "image.h"


class EditionImageWindow : public QDialog, private Ui::EditionImageWindow
{
    Q_OBJECT

public:
    //add an argument *image
    explicit EditionImageWindow(QWidget *parent = nullptr);
    QImage cropped;

private slots:
    void on_btn_img_clicked();
    void on_resize_btn_clicked();
    void on_zoom_btn_clicked();
    void on_zoomSlider_valueChanged(int value);
    void on_reset_btn_clicked();
    void on_crop_btn_clicked();
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void on_pivoter_btn_clicked();

private:
    Ui::EditionImageWindow *ui_edit;
    QRubberBand* rubberBand = nullptr;
    QPoint origin;
    QRect rect;


};

#endif // EDITIONIMAGEWINDOW_H
