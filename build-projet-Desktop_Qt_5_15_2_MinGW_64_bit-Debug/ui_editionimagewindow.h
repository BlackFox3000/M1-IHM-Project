/********************************************************************************
** Form generated from reading UI file 'editionimagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITIONIMAGEWINDOW_H
#define UI_EDITIONIMAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditionImageWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pivoter_btn;
    QPushButton *zoom_btn;
    QPushButton *crop_btn;
    QPushButton *resize_btn;
    QPushButton *reset_btn;
    QSlider *zoomSlider;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *edit_label;
    QPushButton *btn_img;

    void setupUi(QDialog *EditionImageWindow)
    {
        if (EditionImageWindow->objectName().isEmpty())
            EditionImageWindow->setObjectName(QString::fromUtf8("EditionImageWindow"));
        EditionImageWindow->resize(806, 681);
        layoutWidget = new QWidget(EditionImageWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 80, 138, 175));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pivoter_btn = new QPushButton(layoutWidget);
        pivoter_btn->setObjectName(QString::fromUtf8("pivoter_btn"));

        verticalLayout_2->addWidget(pivoter_btn);

        zoom_btn = new QPushButton(layoutWidget);
        zoom_btn->setObjectName(QString::fromUtf8("zoom_btn"));

        verticalLayout_2->addWidget(zoom_btn);

        crop_btn = new QPushButton(layoutWidget);
        crop_btn->setObjectName(QString::fromUtf8("crop_btn"));

        verticalLayout_2->addWidget(crop_btn);

        resize_btn = new QPushButton(layoutWidget);
        resize_btn->setObjectName(QString::fromUtf8("resize_btn"));

        verticalLayout_2->addWidget(resize_btn);

        reset_btn = new QPushButton(layoutWidget);
        reset_btn->setObjectName(QString::fromUtf8("reset_btn"));

        verticalLayout_2->addWidget(reset_btn);

        zoomSlider = new QSlider(EditionImageWindow);
        zoomSlider->setObjectName(QString::fromUtf8("zoomSlider"));
        zoomSlider->setGeometry(QRect(750, 80, 18, 501));
        zoomSlider->setMaximum(500);
        zoomSlider->setOrientation(Qt::Vertical);
        widget = new QWidget(EditionImageWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(200, 80, 541, 541));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        edit_label = new QLabel(widget);
        edit_label->setObjectName(QString::fromUtf8("edit_label"));
        edit_label->setFrameShape(QFrame::Box);

        horizontalLayout_2->addWidget(edit_label);


        verticalLayout->addLayout(horizontalLayout_2);

        btn_img = new QPushButton(widget);
        btn_img->setObjectName(QString::fromUtf8("btn_img"));

        verticalLayout->addWidget(btn_img);


        retranslateUi(EditionImageWindow);

        QMetaObject::connectSlotsByName(EditionImageWindow);
    } // setupUi

    void retranslateUi(QDialog *EditionImageWindow)
    {
        EditionImageWindow->setWindowTitle(QCoreApplication::translate("EditionImageWindow", "Dialog", nullptr));
        pivoter_btn->setText(QCoreApplication::translate("EditionImageWindow", "Pivoter", nullptr));
        zoom_btn->setText(QCoreApplication::translate("EditionImageWindow", "zoomer", nullptr));
        crop_btn->setText(QCoreApplication::translate("EditionImageWindow", "rogner", nullptr));
        resize_btn->setText(QCoreApplication::translate("EditionImageWindow", "redimensionner", nullptr));
        reset_btn->setText(QCoreApplication::translate("EditionImageWindow", "revenir \303\240 l'originale", nullptr));
        edit_label->setText(QString());
        btn_img->setText(QCoreApplication::translate("EditionImageWindow", "Importer une image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditionImageWindow: public Ui_EditionImageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITIONIMAGEWINDOW_H
