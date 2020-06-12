QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

REV_MAJOR_CODE = 0
REV_MINOR_CODE = 5
REV_PATCH_CODE = 0
PROJECT_DIR=$$PWD
include (../QtBaseGeral/base_geral.pri)


SOURCES += \
	main.cpp \
	QtRandomKeyboard.cpp \
	random_keyboard.cpp \
	random_keyboard_display.cpp

HEADERS += \
	QtRandomKeyboard.h \
	random_keyboard.h \
	random_keyboard_display.h

FORMS += \
	QtRandomKeyboard.ui \
	random_keyboard.ui \
	random_keyboard_display.ui

TRANSLATIONS += \
	en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
	random_keyboard.qrc
