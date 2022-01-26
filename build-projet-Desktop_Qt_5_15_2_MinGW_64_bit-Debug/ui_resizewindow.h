/********************************************************************************
** Form generated from reading UI file 'resizewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZEWINDOW_H
#define UI_RESIZEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResizeWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QTextEdit *largeur_txt;
    QTextEdit *hauteur_txt;

    void setupUi(QDialog *ResizeWindow)
    {
        if (ResizeWindow->objectName().isEmpty())
            ResizeWindow->setObjectName(QString::fromUtf8("ResizeWindow"));
        ResizeWindow->resize(358, 231);
        buttonBox = new QDialogButtonBox(ResizeWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(100, 120, 167, 29));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(ResizeWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 30, 61, 71));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        widget1 = new QWidget(ResizeWindow);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(90, 30, 171, 71));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        largeur_txt = new QTextEdit(widget1);
        largeur_txt->setObjectName(QString::fromUtf8("largeur_txt"));

        verticalLayout->addWidget(largeur_txt);

        hauteur_txt = new QTextEdit(widget1);
        hauteur_txt->setObjectName(QString::fromUtf8("hauteur_txt"));

        verticalLayout->addWidget(hauteur_txt);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(ResizeWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), ResizeWindow, SLOT(accept()));

        QMetaObject::connectSlotsByName(ResizeWindow);
    } // setupUi

    void retranslateUi(QDialog *ResizeWindow)
    {
        ResizeWindow->setWindowTitle(QCoreApplication::translate("ResizeWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ResizeWindow", "Largeur", nullptr));
        label_2->setText(QCoreApplication::translate("ResizeWindow", "Hauteur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResizeWindow: public Ui_ResizeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEWINDOW_H
