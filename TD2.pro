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
    collision.cpp \
    coordinates.cpp \
    detectfist.cpp \
    iss.cpp \
    mainwindow.cpp \
    spaceship.cpp
HEADERS += \
    Asteroids.h \
    MySpace.h \
    collision.h \
    coordinates.h \
    detectfist.h \
    iss.h \
    mainwindow.h \
    spaceship.h

RESOURCES += \
    res/textures.qrc

INCLUDEPATH +=$$(OPENCV_DIR)\..\..\include

LIBS += -L$$(OPENCV_DIR)\lib \
    -lopencv_core455 \
    -lopencv_highgui455 \
    -lopencv_imgproc455 \
    -lopencv_imgcodecs455 \
    -lopencv_videoio455 \
    -lopencv_features2d455 \
    -lopencv_calib3d455 \
    -lopencv_objdetect455
