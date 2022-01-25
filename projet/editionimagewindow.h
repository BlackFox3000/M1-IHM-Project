#ifndef EDITIONIMAGEWINDOW_H
#define EDITIONIMAGEWINDOW_H

#include "ui_editionimagewindow.h"
#include "qrubberband.h"
class EditionImageWindow : public QDialog, private Ui::EditionImageWindow
{
    Q_OBJECT

public:
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

private:
    Ui::EditionImageWindow *ui_edit;
    QRubberBand* rubberBand = nullptr;
    QPoint origin;

};

#endif // EDITIONIMAGEWINDOW_H
