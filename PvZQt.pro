QT       += core gui multimediawidgets
QT+=multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

OBJECTS_DIR  = tmp
MOC_DIR      = tmp

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Config.cpp \
    bullet.cpp \
    card.cpp \
    chessboard.cpp \
    main.cpp \
    mainwindow.cpp \
    object.cpp \
    plant.cpp \
    shop.cpp \
    shovel.cpp \
    sun.cpp \
    timectrl.cpp \
    zombie.cpp

HEADERS += \
    Config.h \
    bullet.h \
    card.h \
    chessboard.h \
    mainwindow.h \
    object.h \
    plant.h \
    shop.h \
    shovel.h \
    sun.h \
    timectrl.h \
    zombie.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
