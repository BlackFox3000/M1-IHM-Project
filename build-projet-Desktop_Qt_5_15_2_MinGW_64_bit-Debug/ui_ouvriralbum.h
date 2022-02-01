/********************************************************************************
** Form generated from reading UI file 'ouvriralbum.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUVRIRALBUM_H
#define UI_OUVRIRALBUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OuvrirAlbum
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *frame;

    void setupUi(QDialog *OuvrirAlbum)
    {
        if (OuvrirAlbum->objectName().isEmpty())
            OuvrirAlbum->setObjectName(QString::fromUtf8("OuvrirAlbum"));
        OuvrirAlbum->resize(800, 550);
        widget = new QWidget(OuvrirAlbum);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 510, 781, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        widget1 = new QWidget(OuvrirAlbum);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(30, 60, 741, 391));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        frame = new QFrame(widget1);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);

        verticalLayout->setStretch(1, 1);

        retranslateUi(OuvrirAlbum);
        QObject::connect(pushButton, SIGNAL(clicked()), OuvrirAlbum, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), OuvrirAlbum, SLOT(reject()));

        QMetaObject::connectSlotsByName(OuvrirAlbum);
    } // setupUi

    void retranslateUi(QDialog *OuvrirAlbum)
    {
        OuvrirAlbum->setWindowTitle(QCoreApplication::translate("OuvrirAlbum", "Ouvrir un album", nullptr));
        pushButton->setText(QCoreApplication::translate("OuvrirAlbum", "Ouvrir", nullptr));
        pushButton_2->setText(QCoreApplication::translate("OuvrirAlbum", "Annuler", nullptr));
        label->setText(QCoreApplication::translate("OuvrirAlbum", "Albums disponibles :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OuvrirAlbum: public Ui_OuvrirAlbum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUVRIRALBUM_H
