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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreationAlbumWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QLabel *label_5;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *CreationAlbumWindow)
    {
        if (CreationAlbumWindow->objectName().isEmpty())
            CreationAlbumWindow->setObjectName(QString::fromUtf8("CreationAlbumWindow"));
        CreationAlbumWindow->resize(1280, 720);
        layoutWidget = new QWidget(CreationAlbumWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(230, 20, 781, 541));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(0, 50));
        comboBox->setAcceptDrops(true);
        comboBox->setEditable(true);

        verticalLayout->addWidget(comboBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(0, 300));

        verticalLayout->addWidget(listWidget);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CreationAlbumWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), CreationAlbumWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreationAlbumWindow);
    } // setupUi

    void retranslateUi(QDialog *CreationAlbumWindow)
    {
        CreationAlbumWindow->setWindowTitle(QCoreApplication::translate("CreationAlbumWindow", "Dialog", nullptr));
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
