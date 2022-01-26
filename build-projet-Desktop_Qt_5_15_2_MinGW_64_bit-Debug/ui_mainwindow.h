/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QAction *actionRogner;
    QAction *actionOrdonner;
    QAction *action100;
    QAction *action75;
    QAction *action50;
    QAction *action25;
    QAction *actionS_lectionner;
    QAction *actionAjouter_Fichier;
    QAction *actionOuvrir_un_album;
    QAction *actionCr_er_un_album;
    QAction *actionEditer_les_informations;
    QAction *actionEditer_l_image;
    QAction *action;
    QWidget *centralwidget;
    QTreeView *treeView;
    QTreeWidget *treeWidget;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuOption;
    QMenu *menuAide;
    QMenu *menuAlbum;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName(QString::fromUtf8("actionFile"));
        actionRogner = new QAction(MainWindow);
        actionRogner->setObjectName(QString::fromUtf8("actionRogner"));
        actionOrdonner = new QAction(MainWindow);
        actionOrdonner->setObjectName(QString::fromUtf8("actionOrdonner"));
        action100 = new QAction(MainWindow);
        action100->setObjectName(QString::fromUtf8("action100"));
        action75 = new QAction(MainWindow);
        action75->setObjectName(QString::fromUtf8("action75"));
        action50 = new QAction(MainWindow);
        action50->setObjectName(QString::fromUtf8("action50"));
        action25 = new QAction(MainWindow);
        action25->setObjectName(QString::fromUtf8("action25"));
        actionS_lectionner = new QAction(MainWindow);
        actionS_lectionner->setObjectName(QString::fromUtf8("actionS_lectionner"));
        actionAjouter_Fichier = new QAction(MainWindow);
        actionAjouter_Fichier->setObjectName(QString::fromUtf8("actionAjouter_Fichier"));
        actionOuvrir_un_album = new QAction(MainWindow);
        actionOuvrir_un_album->setObjectName(QString::fromUtf8("actionOuvrir_un_album"));
        actionCr_er_un_album = new QAction(MainWindow);
        actionCr_er_un_album->setObjectName(QString::fromUtf8("actionCr_er_un_album"));
        actionEditer_les_informations = new QAction(MainWindow);
        actionEditer_les_informations->setObjectName(QString::fromUtf8("actionEditer_les_informations"));
        actionEditer_l_image = new QAction(MainWindow);
        actionEditer_l_image->setObjectName(QString::fromUtf8("actionEditer_l_image"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 10, 191, 561));
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(995, 10, 271, 371));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 25));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuOption = new QMenu(menubar);
        menuOption->setObjectName(QString::fromUtf8("menuOption"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        menuAlbum = new QMenu(menubar);
        menuAlbum->setObjectName(QString::fromUtf8("menuAlbum"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuAlbum->menuAction());
        menubar->addAction(menuOption->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionAjouter_Fichier);
        menuOption->addSeparator();
        menuOption->addSeparator();
        menuOption->addSeparator();
        menuOption->addSeparator();
        menuOption->addAction(actionEditer_les_informations);
        menuOption->addAction(actionEditer_l_image);
        menuAide->addAction(action);
        menuAlbum->addAction(actionOuvrir_un_album);
        menuAlbum->addAction(actionCr_er_un_album);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionFile->setText(QCoreApplication::translate("MainWindow", "File", nullptr));
        actionRogner->setText(QCoreApplication::translate("MainWindow", "Rogner", nullptr));
        actionOrdonner->setText(QCoreApplication::translate("MainWindow", "Ordonner", nullptr));
        action100->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
        action75->setText(QCoreApplication::translate("MainWindow", "75%", nullptr));
        action50->setText(QCoreApplication::translate("MainWindow", "50%", nullptr));
        action25->setText(QCoreApplication::translate("MainWindow", "25%", nullptr));
        actionS_lectionner->setText(QCoreApplication::translate("MainWindow", "S\303\251lectionner", nullptr));
        actionAjouter_Fichier->setText(QCoreApplication::translate("MainWindow", "Ajouter Fichier", nullptr));
        actionOuvrir_un_album->setText(QCoreApplication::translate("MainWindow", "Ouvrir un album", nullptr));
        actionCr_er_un_album->setText(QCoreApplication::translate("MainWindow", "Cr\303\251er un album", nullptr));
        actionEditer_les_informations->setText(QCoreApplication::translate("MainWindow", "Editer les informations", nullptr));
        actionEditer_l_image->setText(QCoreApplication::translate("MainWindow", "Editer l'image", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "?", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "Fichier", nullptr));
        menuOption->setTitle(QCoreApplication::translate("MainWindow", "Option", nullptr));
        menuAide->setTitle(QCoreApplication::translate("MainWindow", "Aide", nullptr));
        menuAlbum->setTitle(QCoreApplication::translate("MainWindow", "Album", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
