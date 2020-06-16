QT += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    blinky.cpp \
    board.cpp \
    character.cpp \
    clyde.cpp \
    game.cpp \
    ghost.cpp \
    inky.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    pinky.cpp \
    player.cpp \
    scoremanager.cpp \
    edible.cpp \
    gums.cpp \
    gum.cpp \
    superGum.cpp

HEADERS += \
    blinky.h \
    board.h \
    character.h \
    clyde.h \
    direction.h \
    game.h \
    ghost.h \
    ghostmode.h \
    inky.h \
    mainwindow.h \
    menu.h \
    pinky.h \
    player.h \
    scoremanager.h \
    edible.h \
    gums.h \
    gum.h \
    superGum.h
	
FORMS += \
    game.ui \
    mainwindow.ui \
    menu.ui

RESOURCES += \
    resources.qrc

RC_ICONS = icon.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icon.ico
