/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QTableWidget *filesTable;
    QComboBox *fileComboBox;
    QComboBox *textComboBox;
    QPushButton *findButton;
    QLabel *filesFoundLabel;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *folderLabel;
    QComboBox *directoryComboBox;
    QPushButton *browseButton;

    void setupUi(QDialog *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->setEnabled(true);
        Window->resize(684, 465);
        filesTable = new QTableWidget(Window);
        filesTable->setObjectName(QString::fromUtf8("filesTable"));
        filesTable->setGeometry(QRect(20, 60, 641, 192));
        fileComboBox = new QComboBox(Window);
        fileComboBox->setObjectName(QString::fromUtf8("fileComboBox"));
        fileComboBox->setGeometry(QRect(180, 70, 72, 24));
        textComboBox = new QComboBox(Window);
        textComboBox->setObjectName(QString::fromUtf8("textComboBox"));
        textComboBox->setGeometry(QRect(450, 80, 72, 24));
        findButton = new QPushButton(Window);
        findButton->setObjectName(QString::fromUtf8("findButton"));
        findButton->setGeometry(QRect(560, 280, 80, 24));
        filesFoundLabel = new QLabel(Window);
        filesFoundLabel->setObjectName(QString::fromUtf8("filesFoundLabel"));
        filesFoundLabel->setGeometry(QRect(20, 270, 391, 31));
        widget = new QWidget(Window);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 642, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        folderLabel = new QLabel(widget);
        folderLabel->setObjectName(QString::fromUtf8("folderLabel"));
        folderLabel->setMinimumSize(QSize(50, 0));
        folderLabel->setMaximumSize(QSize(60, 20));

        horizontalLayout->addWidget(folderLabel);

        directoryComboBox = new QComboBox(widget);
        directoryComboBox->setObjectName(QString::fromUtf8("directoryComboBox"));
        directoryComboBox->setMinimumSize(QSize(300, 20));

        horizontalLayout->addWidget(directoryComboBox);

        browseButton = new QPushButton(widget);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        browseButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(browseButton);


        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QDialog *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Dialog", nullptr));
        findButton->setText(QCoreApplication::translate("Window", "PushButton", nullptr));
        filesFoundLabel->setText(QString());
        folderLabel->setText(QCoreApplication::translate("Window", "R\303\251pertoir", nullptr));
        browseButton->setText(QCoreApplication::translate("Window", "Parcourir ...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
