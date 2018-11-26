#-------------------------------------------------
#
# Project created by QtCreator 2015-08-18T14:13:28
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtGuider

TEMPLATE = app

#QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++

SOURCES += \
    ./main.cpp \
    ./QtGuider.cpp

HEADERS  += \
    ./QtGuider.h

FORMS    += \
    ./QtGuider.ui

RESOURCES += \
    ./QtGuider.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$_PRO_FILE_PWD_/../bin/ -lqtdock
else:win32:CONFIG(debug, debug|release): LIBS += -L$$_PRO_FILE_PWD_/../bin/ -lqtdockd

CONFIG(debug, debug|release) {
    TARGET = $$member(TARGET, 0)d
    DESTDIR = $$_PRO_FILE_PWD_/../bin
} else {
    DESTDIR = $$_PRO_FILE_PWD_/../bin
}

INCLUDEPATH += $$PWD/../qtdock
DEPENDPATH += $$PWD/../qtdock
