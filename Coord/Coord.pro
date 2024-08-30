QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TRANSLATIONS += \
    translate/Language_CN.ts \
    translate/Language_EN.ts \
    translate/Language_JA.ts

SOURCES += \
    ButtonEffect/coordbtnbase.cpp \
    ButtonEffect/glimmerbutton.cpp \
    ButtonEffect/glowbutton.cpp \
    ButtonEffect/normalbutton.cpp \
    Chart/coordchartgenerate.cpp \
    Chart/qcustomplot.cpp \
    CoordData/chartfunctionframe.cpp \
    CoordData/coordtreewidget.cpp \
    CoordData/fileframe.cpp \
    CoordData/functionbar.cpp \
    CoordTab/MyTabWidget.cpp \
    FlickWindow/flickwindow.cpp \
    MaskForm/maskform.cpp \
    collapseanimation.cpp \
    collapsewidget.cpp \
    main.cpp \
    cood.cpp \
    mainobject.cpp \
    maintitlebar.cpp \
    numberanimation.cpp \
    render/bannacontrol.cpp \
    render/globalapplication.cpp \
    render/languageswitch.cpp \
    splashscreen.cpp \
    systemtray.cpp \
    titlebar.cpp

HEADERS += \
    ButtonEffect/coordbtnbase.h \
    ButtonEffect/glimmerbutton.h \
    ButtonEffect/glowbutton.h \
    ButtonEffect/normalbutton.h \
    Chart/ChartDateBase.h \
    Chart/coordchartgenerate.h \
    Chart/qcustomplot.h \
    CoordData/chartfunctionframe.h \
    CoordData/coordtreenode.h \
    CoordData/coordtreewidget.h \
    CoordData/fileframe.h \
    CoordData/functionbar.h \
    CoordTab/MyTabWidget.h \
    FlickWindow/flickwindow.h \
    MaskForm/maskform.h \
    collapseanimation.h \
    collapsewidget.h \
    cood.h \
    globaldef.hpp \
    mainobject.h \
    maintitlebar.h \
    numberanimation.h \
    render/bannacontrol.h \
    render/globalapplication.h \
    render/languageswitch.h \
    splashscreen.h \
    systemtray.h \
    titlebar.h

FORMS += \
    CoordData/chartfunctionframe.ui \
    CoordData/fileframe.ui \
    CoordData/functionbar.ui \
    FlickWindow/flickwindow.ui \
    collapseanimation.ui \
    collapsewidget.ui \
    cood.ui \
    maintitlebar.ui \
    render/bannacontrol.ui \
    render/languageswitch.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QXLSX_PARENTPATH=./QXlsx         # QXlsx path is ./QXlsx
QXLSX_HEADERPATH=./QXlsx/header/  # QXlsx header path is ./QXlsx/header/
QXLSX_SOURCEPATH=./QXlsx/source/  # QXlsx s`ource path is ./QXlsx/source/
include(./QXlsx/QXlsx.pri)

RESOURCES += \
    res.qrc

TRANSLATIONS +=
