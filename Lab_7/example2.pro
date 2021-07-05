QT       += core gui
QT += opengl
LIBS += -lOpengl32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    applogic.cpp \
    gl_view.cpp \
    main.cpp \
    mainwindow.cpp \
    entry_point.cpp \
    file_reader_implementation.cpp \
    facade_factory.cpp \
    scene_drawer_implementation.cpp \
    scene_implementation.cpp \
    facade_operation_result.cpp \
    facade_implementation.cpp

HEADERS += \
    applogic.h \
    gl_view.h \
    mainwindow.h \
    entry_point.h \
    file_reader_implementation.h \
    file_reader_interface.h \
    base_scene_interface.h \
    scene_drawer_interface.h \
    scene_drawer_implementation.h \
    scene_implementation.h \
    figure.h \
    vertex.h \
    point3d.h \
    facet.h \
    transform_information.h \
    facade_implementation.h \
    facade_interface.h \
    facade_operation_result.h \
    facade_factory.h \
    normalization_parameters.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    example2_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
