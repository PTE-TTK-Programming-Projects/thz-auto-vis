######################################################################
# Automatically generated by qmake (3.1) Mon Mar 25 17:19:56 2024
######################################################################

TEMPLATE = app
TARGET = thz-auto-vis
INCLUDEPATH += . /opt/picoscope/include
QT += widgets charts
LIBS += -L/opt/picoscope/lib -lps5000a -lps5000aWrap

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += hostwindow.h scope.h
SOURCES += hostwindow.cpp main.cpp scope.cpp
