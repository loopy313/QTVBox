#-------------------------------------------------
#
# Project created by QtCreator 2018-04-03T15:34:19
#
#-------------------------------------------------
QT       += core opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib

DEFINES += LIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
PROJECTDIR = $$PWD/..

include($${PROJECTDIR}/common.pri)


SOURCES += \
    AVInfo.cpp \
    AVPlay.cpp \
    AVDecoder.cpp \
    AVAudDecoder.cpp \
    AVVidDecoder.cpp \
    AVDemuxer.cpp \
    AVAudioOutput.cpp \
    AVPacketQueue.cpp \
    QAVPacket.cpp \
    QAVWorker.cpp \
    QAVThread.cpp

HEADERS += \
        lib_global.h \ 
    AVInfo.h \
    AVPlay.h \
    AVDecoder.h \
    AVAudDecoder.h \
    AVVidDecoder.h \
    AVDemuxer.h \
    AVAudioOutput.h \
    AVPacketQueue.h \
    QAVPacket.h \
    QAVWorker.h \
    QAVThread.h

unix { \
    target.path = /usr/lib
    INSTALLS += target
}
