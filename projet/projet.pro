QT       += core gui

QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creationalbumwindow.cpp \
    database.cpp \
    editionimagewindow.cpp \
    WindowFiles.cpp \
    main.cpp \
    mainwindow.cpp \
    ouvriralbum.cpp \
    resizewindow.cpp \
    modifinformations.cpp

HEADERS += \
    creationalbumwindow.h \
    database.h \
    editionimagewindow.h \
    WindowFiles.h \
    mainwindow.h \
    ouvriralbum.h \
    resizewindow.h \
    modifinformations.h

FORMS += \
    creationalbumwindow.ui \
    editionimagewindow.ui \
    WindowFiles.ui \
    mainwindow.ui \
    ouvriralbum.ui \
    resizewindow.ui \
    modifinformations.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icon/icon_file.ico \
    icon/icon_folder.ico
