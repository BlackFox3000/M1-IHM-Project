#ifndef RESIZEWINDOW_H
#define RESIZEWINDOW_H

#include "ui_resizewindow.h"
#include "editionimagewindow.h"

class ResizeWindow : public QDialog, private Ui::ResizeWindow
{
    Q_OBJECT

public:
    explicit ResizeWindow(QWidget *parent = nullptr);
    int getL();
    int getH();

private:
    Ui::ResizeWindow *ui_resize;
};

#endif // RESIZEWINDOW_H
