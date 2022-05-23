# configuration Qt
QT       += core gui opengl widgets openglwidgets
TEMPLATE  = app
CONFIG += c++17

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -framework OpenGL
}

# nom de l'exe genere
TARGET 	  = TD2

# fichiers sources/headers/ressources
SOURCES += main.cpp \
    Asteroids.cpp \
    MySpace.cpp \
    coordinates.cpp \
    iss.cpp \
    mainwindow.cpp \
    spaceship.cpp
HEADERS += \
    Asteroids.h \
    MySpace.h \
    coordinates.h \
    iss.h \
    mainwindow.h \
    spaceship.h

RESOURCES += \
    res/textures.qrc

DISTFILES += \
    Test.qml \
    TestForm.ui.qml
