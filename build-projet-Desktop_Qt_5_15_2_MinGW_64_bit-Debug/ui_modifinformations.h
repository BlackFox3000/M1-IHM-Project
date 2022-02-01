/********************************************************************************
** Form generated from reading UI file 'modifinformations.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFINFORMATIONS_H
#define UI_MODIFINFORMATIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifInformations
{
public:
    QFrame *frame;
    QLabel *label_4;
    QTextEdit *textEdit;
    QFrame *frame_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_titre;
    QLabel *label_dimensions;
    QLabel *label_2;
    QLabel *label_6;
    QComboBox *comboBox_listeTags;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_extension;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QFrame *frame_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_12;
    QLineEdit *editNewTag;
    QPushButton *button_valider_Tag;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox_Tags;
    QVBoxLayout *verticalLayout_2;
    QPushButton *button_ajouterTag;
    QPushButton *button_retirerTag;
    QFrame *frame_4;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *edit_newTitre;
    QPushButton *button_validerTitre;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;

    void setupUi(QDialog *ModifInformations)
    {
        if (ModifInformations->objectName().isEmpty())
            ModifInformations->setObjectName(QString::fromUtf8("ModifInformations"));
        ModifInformations->resize(800, 550);
        frame = new QFrame(ModifInformations);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 20, 340, 191));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(130, 80, 63, 20));
        textEdit = new QTextEdit(ModifInformations);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 220, 340, 281));
        frame_2 = new QFrame(ModifInformations);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(370, 20, 421, 191));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayoutWidget = new QWidget(frame_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 401, 177));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(7);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_titre = new QLabel(gridLayoutWidget);
        label_titre->setObjectName(QString::fromUtf8("label_titre"));

        gridLayout->addWidget(label_titre, 0, 1, 1, 1);

        label_dimensions = new QLabel(gridLayoutWidget);
        label_dimensions->setObjectName(QString::fromUtf8("label_dimensions"));

        gridLayout->addWidget(label_dimensions, 2, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        comboBox_listeTags = new QComboBox(gridLayoutWidget);
        comboBox_listeTags->setObjectName(QString::fromUtf8("comboBox_listeTags"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox_listeTags->sizePolicy().hasHeightForWidth());
        comboBox_listeTags->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(comboBox_listeTags, 5, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        label_extension = new QLabel(gridLayoutWidget);
        label_extension->setObjectName(QString::fromUtf8("label_extension"));

        gridLayout->addWidget(label_extension, 1, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 3, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 4, 1, 1, 1);

        frame_3 = new QFrame(ModifInformations);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(370, 280, 421, 221));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 401, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_3->addWidget(label_12);

        editNewTag = new QLineEdit(layoutWidget);
        editNewTag->setObjectName(QString::fromUtf8("editNewTag"));

        horizontalLayout_3->addWidget(editNewTag);

        button_valider_Tag = new QPushButton(layoutWidget);
        button_valider_Tag->setObjectName(QString::fromUtf8("button_valider_Tag"));

        horizontalLayout_3->addWidget(button_valider_Tag);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMinimumSize(QSize(50, 50));
        label_3->setBaseSize(QSize(30, 20));

        horizontalLayout_2->addWidget(label_3);

        comboBox_Tags = new QComboBox(layoutWidget);
        comboBox_Tags->addItem(QString());
        comboBox_Tags->addItem(QString());
        comboBox_Tags->setObjectName(QString::fromUtf8("comboBox_Tags"));
        sizePolicy1.setHeightForWidth(comboBox_Tags->sizePolicy().hasHeightForWidth());
        comboBox_Tags->setSizePolicy(sizePolicy1);
        comboBox_Tags->setMinimumSize(QSize(60, 0));
        comboBox_Tags->setEditable(false);

        horizontalLayout_2->addWidget(comboBox_Tags);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        button_ajouterTag = new QPushButton(layoutWidget);
        button_ajouterTag->setObjectName(QString::fromUtf8("button_ajouterTag"));
        sizePolicy2.setHeightForWidth(button_ajouterTag->sizePolicy().hasHeightForWidth());
        button_ajouterTag->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(button_ajouterTag);

        button_retirerTag = new QPushButton(layoutWidget);
        button_retirerTag->setObjectName(QString::fromUtf8("button_retirerTag"));
        sizePolicy2.setHeightForWidth(button_retirerTag->sizePolicy().hasHeightForWidth());
        button_retirerTag->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(button_retirerTag);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        frame_4 = new QFrame(ModifInformations);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(370, 220, 421, 51));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        layoutWidget_3 = new QWidget(frame_4);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 10, 401, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        edit_newTitre = new QLineEdit(layoutWidget_3);
        edit_newTitre->setObjectName(QString::fromUtf8("edit_newTitre"));

        horizontalLayout->addWidget(edit_newTitre);

        button_validerTitre = new QPushButton(layoutWidget_3);
        button_validerTitre->setObjectName(QString::fromUtf8("button_validerTitre"));

        horizontalLayout->addWidget(button_validerTitre);

        layoutWidget1 = new QWidget(ModifInformations);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 510, 771, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(layoutWidget1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);

        QWidget::setTabOrder(comboBox_Tags, button_valider_Tag);
        QWidget::setTabOrder(button_valider_Tag, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);
        QWidget::setTabOrder(pushButton_4, edit_newTitre);
        QWidget::setTabOrder(edit_newTitre, textEdit);

        retranslateUi(ModifInformations);
        QObject::connect(pushButton_3, SIGNAL(clicked()), ModifInformations, SLOT(accept()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), ModifInformations, SLOT(reject()));

        QMetaObject::connectSlotsByName(ModifInformations);
    } // setupUi

    void retranslateUi(QDialog *ModifInformations)
    {
        ModifInformations->setWindowTitle(QCoreApplication::translate("ModifInformations", "Modifier informations", nullptr));
        label_4->setText(QCoreApplication::translate("ModifInformations", "image", nullptr));
        textEdit->setHtml(QCoreApplication::translate("ModifInformations", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Description blablabla</p></body></html>", nullptr));
        label_titre->setText(QCoreApplication::translate("ModifInformations", "Mon chat", nullptr));
        label_dimensions->setText(QCoreApplication::translate("ModifInformations", "1980x1080", nullptr));
        label_2->setText(QCoreApplication::translate("ModifInformations", "Titre :", nullptr));
        label_6->setText(QCoreApplication::translate("ModifInformations", "Etiquettes :", nullptr));
        label_8->setText(QCoreApplication::translate("ModifInformations", "Date de cr\303\251ation :", nullptr));
        label_5->setText(QCoreApplication::translate("ModifInformations", "Extension :", nullptr));
        label_7->setText(QCoreApplication::translate("ModifInformations", "Dimensions :", nullptr));
        label_extension->setText(QCoreApplication::translate("ModifInformations", "PNG", nullptr));
        label_9->setText(QCoreApplication::translate("ModifInformations", "Date de modification :", nullptr));
        label_10->setText(QCoreApplication::translate("ModifInformations", "23/01/22", nullptr));
        label_11->setText(QCoreApplication::translate("ModifInformations", "26/01/22", nullptr));
        label_12->setText(QCoreApplication::translate("ModifInformations", "Creer etiquette :", nullptr));
        editNewTag->setText(QCoreApplication::translate("ModifInformations", "nouveau tag", nullptr));
        button_valider_Tag->setText(QCoreApplication::translate("ModifInformations", "Valider", nullptr));
        label_3->setText(QCoreApplication::translate("ModifInformations", "Etiquettes :", nullptr));
        comboBox_Tags->setItemText(0, QCoreApplication::translate("ModifInformations", "chat", nullptr));
        comboBox_Tags->setItemText(1, QCoreApplication::translate("ModifInformations", "tigre", nullptr));

        button_ajouterTag->setText(QCoreApplication::translate("ModifInformations", "Ajouter", nullptr));
        button_retirerTag->setText(QCoreApplication::translate("ModifInformations", "Retirer", nullptr));
        label->setText(QCoreApplication::translate("ModifInformations", "Titre :", nullptr));
        edit_newTitre->setText(QCoreApplication::translate("ModifInformations", "Nouveau titre", nullptr));
        button_validerTitre->setText(QCoreApplication::translate("ModifInformations", "Valider", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ModifInformations", "Valider", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ModifInformations", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifInformations: public Ui_ModifInformations {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFINFORMATIONS_H
