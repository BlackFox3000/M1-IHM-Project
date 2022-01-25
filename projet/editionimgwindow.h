#ifndef EDITIONIMGWINDOW_H
#define EDITIONIMGWINDOW_H

#include "ui_editionimgwindow.h"

class EditionImgWindow : public QMainWindow, private Ui::EditionImgWindow
{
    Q_OBJECT

public:
    explicit EditionImgWindow(QWidget *parent = nullptr);
private slots:
    void on_btn_img_clicked();
    //void on__my_slider_valueChanged(int value);

private:
    Ui::EditionImgWindow *ui_edit;
    QLabel *edit_label;
    QImage image;
    QScrollArea *scrollArea;

};

#endif // EDITIONIMGWINDOW_H
