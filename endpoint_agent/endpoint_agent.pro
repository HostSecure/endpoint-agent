QT -= gui
QT += dbus

CONFIG += c++17 console
CONFIG -= app_bundle

#DBUS_ADAPTORS += DBusInterface.xml
DBUS_INTERFACES += DBusInterface.xml
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        USBServiceHandler.cpp \
        detector.cpp \
        main.cpp \
        parser.cpp \
        rulehandler.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    USBServiceHandler.h \
    detector.h \
    parser.h \
    rulehandler.h

DISTFILES += \
    ../../../usbguard/src/DBus/DBusInterface.xml \
    DBusInterface.xml
