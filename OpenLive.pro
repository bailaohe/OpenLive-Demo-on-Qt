#-------------------------------------------------
#
# Project created by QtCreator 2019-09-04T11:52:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenLive
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    agoraconfig.cpp \
    roomsettings.cpp \
    agoraobject.cpp \
    enterroom.cpp \
    inroom.cpp

HEADERS  += mainwindow.h \
    stdafx.h \
    agoraconfig.h \
    roomsettings.h \
    agoraobject.h \
    enterroom.h \
    inroom.h

FORMS    += mainwindow.ui \
    roomsettings.ui \
    enterroom.ui \
    inroom.ui

RC_FILE = openlive.rc

RESOURCES += \
    openlive.qrc

DISTFILES += \
    openlive.rc \
    sdk/dll/agora_rtc_sdk.dll \
    sdk/lib/agora_rtc_sdk.lib

win32: {
INCLUDEPATH += $$PWD/sdk/include
LIBS += -L$$PWD/sdk/lib/ -lagora_rtc_sdk
LIBS += User32.LIB
}
macx: {
INCLUDEPATH += $$PWD/sdk/macos/AgoraRtcEngineKit.framework/Headers
LIBS += -F$$PWD/sdk/macos/ -framework AgoraRtcEngineKit
LIBS += -F/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/ \
        # SCNetworkReachabilityCreateWithAddress
        -framework SystemConfiguration \
        # vDSP_DFT_DestroySetup
        -framework Accelerate \
        # CWWiFiClient
        -framework CoreWLAN \
        -framework AVFoundation -framework CoreAudio -framework AudioToolbox \
        -framework CoreMedia -framework CoreVideo -framework VideoToolbox
LIBS += -lresolv.9
LIBS += -lresolv
}

