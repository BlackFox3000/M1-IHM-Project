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
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *edit_label;
    QPushButton *btn_img;

    void setupUi(QDialog *EditionImageWindow)
    {
        if (EditionImageWindow->objectName().isEmpty())
            EditionImageWindow->setObjectName(QString::fromUtf8("EditionImageWindow"));
        EditionImageWindow->resize(1280, 720);
        layoutWidget = new QWidget(EditionImageWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 80, 151, 302));
        layoutWidget->setCursor(QCursor(Qt::PointingHandCursor));
        layoutWidget->setFocusPolicy(Qt::StrongFocus);
        layoutWidget->setAutoFillBackground(false);
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(25);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pivoter_btn = new QPushButton(layoutWidget);
        pivoter_btn->setObjectName(QString::fromUtf8("pivoter_btn"));
        pivoter_btn->setEnabled(true);
        pivoter_btn->setMinimumSize(QSize(0, 40));
        pivoter_btn->setCursor(QCursor(Qt::PointingHandCursor));
        pivoter_btn->setFocusPolicy(Qt::StrongFocus);
        pivoter_btn->setAutoFillBackground(false);

        verticalLayout_2->addWidget(pivoter_btn);

        zoom_btn = new QPushButton(layoutWidget);
        zoom_btn->setObjectName(QString::fromUtf8("zoom_btn"));
        zoom_btn->setMinimumSize(QSize(0, 40));
        zoom_btn->setCursor(QCursor(Qt::PointingHandCursor));
        zoom_btn->setFocusPolicy(Qt::StrongFocus);
        zoom_btn->setAutoFillBackground(false);

        verticalLayout_2->addWidget(zoom_btn);

        crop_btn = new QPushButton(layoutWidget);
        crop_btn->setObjectName(QString::fromUtf8("crop_btn"));
        crop_btn->setMinimumSize(QSize(0, 40));
        crop_btn->setCursor(QCursor(Qt::PointingHandCursor));
        crop_btn->setFocusPolicy(Qt::StrongFocus);
        crop_btn->setAutoFillBackground(false);

        verticalLayout_2->addWidget(crop_btn);

        resize_btn = new QPushButton(layoutWidget);
        resize_btn->setObjectName(QString::fromUtf8("resize_btn"));
        resize_btn->setMinimumSize(QSize(0, 40));
        resize_btn->setCursor(QCursor(Qt::PointingHandCursor));
        resize_btn->setFocusPolicy(Qt::StrongFocus);
        resize_btn->setAutoFillBackground(false);

        verticalLayout_2->addWidget(resize_btn);

        reset_btn = new QPushButton(layoutWidget);
        reset_btn->setObjectName(QString::fromUtf8("reset_btn"));
        reset_btn->setMinimumSize(QSize(0, 40));
        reset_btn->setCursor(QCursor(Qt::PointingHandCursor));
        reset_btn->setFocusPolicy(Qt::StrongFocus);
        reset_btn->setAutoFillBackground(false);

        verticalLayout_2->addWidget(reset_btn);

        zoomSlider = new QSlider(EditionImageWindow);
        zoomSlider->setObjectName(QString::fromUtf8("zoomSlider"));
        zoomSlider->setGeometry(QRect(940, 80, 30, 501));
        zoomSlider->setMaximum(600);
        zoomSlider->setOrientation(Qt::Vertical);
        layoutWidget1 = new QWidget(EditionImageWindow);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(370, 80, 551, 561));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        edit_label = new QLabel(layoutWidget1);
        edit_label->setObjectName(QString::fromUtf8("edit_label"));
        edit_label->setCursor(QCursor(Qt::CrossCursor));
        edit_label->setFrameShape(QFrame::Box);

        horizontalLayout_2->addWidget(edit_label);


        verticalLayout->addLayout(horizontalLayout_2);

        btn_img = new QPushButton(layoutWidget1);
        btn_img->setObjectName(QString::fromUtf8("btn_img"));
        btn_img->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btn_img);


        retranslateUi(EditionImageWindow);

        QMetaObject::connectSlotsByName(EditionImageWindow);
    } // setupUi

    void retranslateUi(QDialog *EditionImageWindow)
    {
        EditionImageWindow->setWindowTitle(QCoreApplication::translate("EditionImageWindow", "Dialog", nullptr));
        pivoter_btn->setText(QCoreApplication::translate("EditionImageWindow", "Pivoter", nullptr));
        zoom_btn->setText(QCoreApplication::translate("EditionImageWindow", "Zoomer", nullptr));
        crop_btn->setText(QCoreApplication::translate("EditionImageWindow", "Rogner", nullptr));
        resize_btn->setText(QCoreApplication::translate("EditionImageWindow", "Redimensionner", nullptr));
        reset_btn->setText(QCoreApplication::translate("EditionImageWindow", "Revenir \303\240 l'originale", nullptr));
        edit_label->setText(QString());
        btn_img->setText(QCoreApplication::translate("EditionImageWindow", "Importer une image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditionImageWindow: public Ui_EditionImageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITIONIMAGEWINDOW_H
