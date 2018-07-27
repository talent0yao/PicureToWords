#-------------------------------------------------
#
# Project created by QtCreator 2018-07-10T18:38:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PTW
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


#LIBS+= -L./https/lib/curl/libcurl.lib
#INCLUDEPATH +=

#LIBS += -L./https/lib/openssl/openssl.lib
#LIBS += -L./https/lib/openssl/libcrypto.lib
#LIBS += -L./https/lib/openssl/libssl.lib
#INCLUDEPATH +=$$quote(./https/include)


win32:CONFIG(debug) {
    LIBS += -L../build-PTW-Desktop_Qt_5_10_1_MSVC2015_32bit-Debug/debug/lib \
            -llibcurl \
            -lopenssl \
            -llibcrypto \
            -llibssl
}

INCLUDEPATH +=./https/include







SOURCES += \
        main.cpp \
        widget.cpp \
    json/json_reader.cpp \
    json/json_value.cpp \
    json/json_writer.cpp \
    mygraphicsview.cpp

HEADERS += \
        widget.h \
    base/base.h \
    base/base64.h \
    base/http.h \
    base/utils.h \
    ocr.h \
    json/json_tool.h \
    mygraphicsview.h

FORMS += \
        widget.ui


RESOURCES += \
    logo.qrc

RC_ICONS = transfer.ico
