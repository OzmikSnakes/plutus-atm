QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    automatictransfer.cpp \
    cashcontroller.cpp \
    cashwithdrawal.cpp \
    chargeaccount.cpp \
    creditlimit.cpp \
    login.cpp \
    main.cpp \
    menu.cpp \
    transfer.cpp

HEADERS += \
    automatictransfer.h \
    cashcontroller.h \
    cashwithdrawal.h \
    chargeaccount.h \
    creditlimit.h \
    login.h \
    menu.h \
    nominal.h \
    transfer.h

FORMS += \
    automatictransfer.ui \
    cashwithdrawal.ui \
    chargeaccount.ui \
    creditlimit.ui \
    login.ui \
    menu.ui \
    transfer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
