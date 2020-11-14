QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    converter.cpp \
    main.cpp \
    requester.cpp \
    requests.cpp \
    responses.cpp \
    rest_request.cpp \
    session.cpp \
    session_manager.cpp

HEADERS += \
    converter.h \
    converter_handler.h \
    request_handler.h \
    requester.h \
    requests.h \
    responses.h \
    rest_request.h \
    session.h \
    session_manager.h

FORMS +=

TRANSLATIONS += \
    plutus-atm_uk_UA.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
