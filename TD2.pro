# configuration Qt
QT       += core gui opengl widgets openglwidgets
TEMPLATE  = app
CONFIG += c++17

QMAKE_MACOSX_DEPLOYMENT_TARGET = 11.6.1

INCLUDEPATH += /usr/local/include/opencv4

# ajout des libs au linker
win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib\
                    -L/usr/local/lib \
                    -lopencv_core \
                    -lopencv_highgui \
                    -lopencv_imgproc \
                    -lopencv_imgcodecs \
                    -lopencv_videoio \
                    -lopencv_features2d \
                    -lopencv_calib3d \
                    -lopencv_objdetect
    } else {
        LIBS     += -lopengl32 -lglu32\
                    -L/usr/local/lib \
                    -lopencv_core \
                    -lopencv_highgui \
                    -lopencv_imgproc \
                    -lopencv_imgcodecs \
                    -lopencv_videoio \
                    -lopencv_features2d \
                    -lopencv_calib3d \
                     -lopencv_objdetect
    }
}
else {
        LIBS     += -framework OpenGL \
                    -L/usr/local/lib \
                    -lopencv_core \
                    -lopencv_highgui \
                    -lopencv_imgproc \
                    -lopencv_imgcodecs \
                    -lopencv_videoio \
                    -lopencv_features2d \
                    -lopencv_calib3d \
                    -lopencv_objdetect

}

# nom de l'exe genere
TARGET 	  = TD2

# fichiers sources/headers/ressources
SOURCES += main.cpp \
    Asteroids.cpp \
    MySpace.cpp \
    collision.cpp \
    detectfist.cpp \
    iss.cpp \
    mainwindow.cpp \
    spaceship.cpp
HEADERS += \
    Asteroids.h \
    MySpace.h \
    collision.h \
    detectfist.h \
    iss.h \
    mainwindow.h \
    spaceship.h

RESOURCES += \
    res/textures.qrc

DISTFILES += \
    Test.qml \
    TestForm.ui.qml \
    closed_frontal_palm.xml \
    fist.xml \
    palm.xml
