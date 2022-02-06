 #ifndef NAVIGATION_H
#define NAVIGATION_H

 #include <QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include "ui_navigation.h"
//QT_BEGIN_NAMESPACE
//namespace Ui { class Navigation; }
//QT_END_NAMESPACE
class navigation : public QWidget ,private Ui::Navigation
{
    Q_OBJECT

signals:
    void  putImage(QPixmap);
public:
    navigation(QWidget *parent = nullptr);
    ~navigation();

private slots:
    void on_butonD_clicked();
    void on_butonG_clicked();
    void on_Go_clicked();

private:

    QPixmap pix;
    QList<QPixmap> listpix;
    QList<QString> nomImage;
    QString nomImagetest;
};

#endif // NAVIGATION_H

