QT       += core gui sql multimedia multimediawidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    camera.cpp \
    gpedido.cpp \
    main.cpp \
    mainwindow.cpp \
    producto.cpp \
    recibir.cpp \
    recolector.cpp \
    registar.cpp \
    usuario.cpp

HEADERS += \
    camera.h \
    gpedido.h \
    mainwindow.h \
    producto.h \
    recibir.h \
    recolector.h \
    registar.h \
    usuario.h

FORMS += \
    camera.ui \
    gpedido.ui \
    mainwindow.ui \
    producto.ui \
    recibir.ui \
    recolector.ui \
    registar.ui \
    usuario.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc

QMAKE_CXXFLAGS += -std=gnu++14

DISTFILES +=
