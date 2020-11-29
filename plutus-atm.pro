QT       += core gui \
            core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controllers/automatic_transfer.cpp \
    controllers/cash_withdrawal.cpp \
    controllers/charge_account.cpp \
    controllers/login.cpp \
    controllers/menu.cpp \
    controllers/transfer.cpp \
    dto/requests.cpp \
    dto/responses.cpp \
    rest_communication/rest_request.cpp \
    rest_communication/session_manager.cpp \
    rest_communication/response_handler.cpp \
    rest_communication/converter.cpp \
    rest_communication/requester.cpp \
    cashcontroller.cpp \
    main.cpp

HEADERS += \
    controllers/automatic_transfer.h \
    controllers/cash_withdrawal.h \
    controllers/charge_account.h \
    controllers/login.h \
    controllers/menu.h \
    controllers/transfer.h \
    dto/requests.h \
    dto/responses.h \
    rest_communication/rest_request.h \
    rest_communication/session_manager.h \
    rest_communication/response_handler.h \
    rest_communication/converter.h \
    rest_communication/converter_handler.h \
    rest_communication/requester.h \
    cashcontroller.h \
    nominal.h \

FORMS += \
    ui/automatic_transfer.ui \
    ui/cash_withdrawal.ui \
    ui/charge_account.ui \
    ui/login.ui \
    ui/menu.ui \
    ui/transfer.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
