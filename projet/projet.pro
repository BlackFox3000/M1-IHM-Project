TARGET = your_app
TEMPLATE = app
QT += widgets
RESOURCES += ressources.qrc
QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    album.cpp \
    creationalbumwindow.cpp \
    editionimagewindow.cpp \
    WindowFiles.cpp \
    image.cpp \
    main.cpp \
    mainwindow.cpp \
    navigation.cpp \
    ouvriralbum.cpp \
    resizewindow.cpp \
    modifinformations.cpp \
    database.cpp \
    tag.cpp

HEADERS += \
    album.h \
    creationalbumwindow.h \
    editionimagewindow.h \
    WindowFiles.h \
    image.h \
    mainwindow.h \
    navigation.h \
    ouvriralbum.h \
    resizewindow.h \
    modifinformations.h \
    database.h \
    tag.h


FORMS += \
    creationalbumwindow.ui \
    editionimagewindow.ui \
    WindowFiles.ui \
    mainwindow.ui \
    navigation.ui \
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
