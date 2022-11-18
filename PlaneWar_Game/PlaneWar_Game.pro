QT += core gui opengl multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17 exceptions

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
    enemybullet.cpp \
    enemyplane.cpp \
    gameobject.cpp \
    main.cpp \
    particlegenerator.cpp \
    planewar.cpp \
    playerbullet.cpp \
    playerplane.cpp \
    rng.cpp \
    skill.cpp \
    soundengine.cpp

HEADERS += \
    enemybullet.h \
    enemyplane.h \
    gameobject.h \
    particlegenerator.h \
    planewar.h \
    playerbullet.h \
    playerplane.h \
    rng.h \
    skill.h \
    soundengine.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
DISTFILES += \
#    ../build-PlaneWar_Game-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug/planewar.db3 \
    shaders/particle.frag \
    shaders/particle.vert \
    shaders/player.fs \
    shaders/player.vs \

QMAKE_LFLAGS += -Wl,--stack,64000000
QMAKE_LFLAGS += -Wl,--heap,64000000
