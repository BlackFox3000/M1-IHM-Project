/********************************************************************************
** Form generated from reading UI file 'WindowFiles.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWFILES_H
#define UI_WINDOWFILES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
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
    QLabel *filesFoundLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *folderLabel;
    QComboBox *directoryComboBox;
    QPushButton *browseButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->setEnabled(true);
        Window->resize(684, 465);
        filesTable = new QTableWidget(Window);
        filesTable->setObjectName(QString::fromUtf8("filesTable"));
        filesTable->setGeometry(QRect(20, 60, 641, 192));
        filesFoundLabel = new QLabel(Window);
        filesFoundLabel->setObjectName(QString::fromUtf8("filesFoundLabel"));
        filesFoundLabel->setGeometry(QRect(20, 270, 391, 31));
        layoutWidget = new QWidget(Window);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 642, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        folderLabel = new QLabel(layoutWidget);
        folderLabel->setObjectName(QString::fromUtf8("folderLabel"));
        folderLabel->setMinimumSize(QSize(50, 0));
        folderLabel->setMaximumSize(QSize(60, 20));

        horizontalLayout->addWidget(folderLabel);

        directoryComboBox = new QComboBox(layoutWidget);
        directoryComboBox->setObjectName(QString::fromUtf8("directoryComboBox"));
        directoryComboBox->setMinimumSize(QSize(300, 20));

        horizontalLayout->addWidget(directoryComboBox);

        browseButton = new QPushButton(layoutWidget);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        browseButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(browseButton);

        buttonBox = new QDialogButtonBox(Window);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(480, 310, 166, 24));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QDialog *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Dialog", nullptr));
        filesFoundLabel->setText(QString());
        folderLabel->setText(QCoreApplication::translate("Window", "R\303\251pertoir", nullptr));
        browseButton->setText(QCoreApplication::translate("Window", "Parcourir ...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWFILES_H
