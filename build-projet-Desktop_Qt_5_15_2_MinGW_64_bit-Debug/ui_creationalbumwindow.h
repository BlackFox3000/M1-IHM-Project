/********************************************************************************
** Form generated from reading UI file 'creationalbumwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATIONALBUMWINDOW_H
#define UI_CREATIONALBUMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreationAlbumWindow
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QTextEdit *textEdit;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *CreationAlbumWindow)
    {
        if (CreationAlbumWindow->objectName().isEmpty())
            CreationAlbumWindow->setObjectName(QString::fromUtf8("CreationAlbumWindow"));
        CreationAlbumWindow->resize(918, 595);
        layoutWidget = new QWidget(CreationAlbumWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 40, 701, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setBold(false);
        font.setItalic(false);
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_3->addWidget(textEdit);

        widget = new QWidget(CreationAlbumWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(100, 90, 701, 461));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setBold(true);
        label_5->setFont(font1);

        verticalLayout->addWidget(label_5);

        listWidget = new QListWidget(widget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CreationAlbumWindow);

        QMetaObject::connectSlotsByName(CreationAlbumWindow);
    } // setupUi

    void retranslateUi(QDialog *CreationAlbumWindow)
    {
        CreationAlbumWindow->setWindowTitle(QCoreApplication::translate("CreationAlbumWindow", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("CreationAlbumWindow", "Titre", nullptr));
        label_5->setText(QCoreApplication::translate("CreationAlbumWindow", "Images selectionn\303\251es", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CreationAlbumWindow", "Cr\303\251er", nullptr));
        pushButton->setText(QCoreApplication::translate("CreationAlbumWindow", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreationAlbumWindow: public Ui_CreationAlbumWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATIONALBUMWINDOW_H
