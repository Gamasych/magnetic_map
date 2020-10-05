TEMPLATE = app
QT       += core gui
QT += datavisualization
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

SOURCES += \
    axesinputhandler.cpp \
    data.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    axesinputhandler.h \
    data.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target






LIBS += -L'C:/Program Files/MATLAB/R2020a/extern/lib/win64/microsoft/' -llibmat

INCLUDEPATH += 'C:/Program Files/MATLAB/R2020a/extern/include'
DEPENDPATH += 'C:/Program Files/MATLAB/R2020a/extern/include'

PRE_TARGETDEPS += 'C:/Program Files/MATLAB/R2020a/extern/lib/win64/microsoft/libmat.lib'

LIBS += -L'C:/Program Files/MATLAB/R2020a/extern/lib/win64/microsoft/' -llibmx

PRE_TARGETDEPS += 'C:/Program Files/MATLAB/R2020a/extern/lib/win64/microsoft/libmx.lib'

