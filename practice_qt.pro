QT       += core gui
QT       += core gui svg
QT       += xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ellipse.cpp \
    figure.cpp \
    line.cpp \
    main.cpp \
    mainwindow.cpp \
    paintscene.cpp \
    rectangle.cpp \
    svgreader.cpp \
    triangle.cpp

HEADERS += \
    ellipse.h \
    figure.h \
    line.h \
    mainwindow.h \
    paintscene.h \
    rectangle.h \
    svgreader.h \
    triangle.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
