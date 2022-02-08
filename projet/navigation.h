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
   void  putImage(QImage);
public:
   navigation(QWidget *parent = nullptr);
   ~navigation();
   QImage pix;
   QList<QImage> listpix;
   QList<QString> nomImage;
   QString nomImagetest;

private slots:
   void on_butonD_clicked();
   void on_butonG_clicked();
   void on_Go_clicked();


};

#endif // NAVIGATION_H

