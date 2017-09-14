TEMPLATE = app
CONFIG += qt warn_on
TARGET = PointPlotter
DESTDIR = bin
MOC_DIR = tmp
OBJECTS_DIR = obj
RES_DIR = resource
DEPENDPATH  += src include
INCLUDEPATH += include

HEADERS += include/point_plotter_window.h \
           include/point_plotter_frame.h  \
           include/findline.h \
           include/fast.h \
           include/brute.h \
           include/point.h
SOURCES += src/PointPlotter.cpp \
           src/point_plotter_window.cpp \
           src/point_plotter_frame.cpp \
           src/findline.cpp \
           src/fast.cpp \
           src/brute.cpp \
           src/point.cpp

QMAKE_POST_LINK= cp -r $${RES_DIR}/* $${DESTDIR}