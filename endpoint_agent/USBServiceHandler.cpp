#include "USBServiceHandler.h"
#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusArgument>
#include <QDBusMetaType>
//#include <qdbusinterface_interface.h>
//#include <qdbusinterface_adaptor.h>

USBServiceHandler::USBServiceHandler(QObject *parent) : QObject(parent)
{

    qDBusRegisterMetaType<QMap<QString,QString>>();


    ifaceUSBGuardRoot = new QDBusInterface("org.usbguard1", "/org/usbguard1", "org.usbguard1",
                                           QDBusConnection::systemBus(), this);
    ifaceUSBGuardDevices = new QDBusInterface("org.usbguard1", "/org/usbguard1/Devices", "org.usbguard.Devices1",
                                              QDBusConnection::systemBus(), this);
    ifaceUSBGuardPolicy = new QDBusInterface("org.usbguard1", "/org/usbguard1/Policy", "org.usbguard.Policy1",
                                             QDBusConnection::systemBus(), this);
    usbDevice = new org::usbguard::Devices1("org.usbguard1","/",
                                            QDBusConnection::systemBus(),this);
 auto result =   QDBusConnection::systemBus().connect(QString(), QString(), "org.usbguard.Devices1", "DevicePresenceChanged",
                                          this, SLOT(handlePresenceChanged(uint,uint,uint,QString,QMap<QString,QString>)));

    if (!ifaceUSBGuardDevices->isValid()) {
        fprintf(stderr, "%s\n",
                qPrintable(QDBusConnection::systemBus().lastError().message()));
        QCoreApplication::instance()->quit();
    }

  //  QDBusConnection system = QDBusConnection::systemBus();
//    auto result = system.connect("","","","DevicePresenceChanged",
//                   this,SLOT(handleDevicePresenceChanged(uint,uint,uint,QString,QMap<QString,QString>)));
//    auto result1 = system.connect("org.usbguard1","/org/usbguard1","org.usbguard1","ExceptionMessage",
//                   this,SLOT(handleExceptionMessage(QString,QString,QString)));
//    auto result2 = system.connect("","","","DevicePolicyChanged",
//                   this,SLOT(handleDevicePolicyChanged(uint,uint,uint,QString,uint,QMap<QString,QString>)));

//    auto result = connect(ifaceUSBGuardDevices,SIGNAL(DevicePresenceChanged(uint,uint,uint,QString,QMap<QString,QString>)),
   //                       this,SLOT(handleDevicePresenceChanged(uint,uint,uint,QString,QMap<QString,QString>)));
//    auto result1 = connect(ifaceUSBGuardRoot,SIGNAL(PropertyParameterChanged(QString,QString,QString)),
//                           this,SLOT(handlePropertyParameterChanged(QString,QString,QString)));
//    auto result2 = connect(ifaceUSBGuardRoot,SIGNAL(ExceptionMessage(QString,QString,QString)),
//                           this,SLOT(handleExceptionMessage(QString,QString,QString)));


    //   auto result = QDBusConnection::systemBus().connect("org.usbguard1","/org/usbguard1","org.usbguard1",
    //                             "DevicePresenceChanged",this,
    //                             SLOT(USBServiceHandler::handleDevicePresenceChanged(uint,uint,uint,QString,QList<QPair<QString,QString>>)));
    if(!result)
    {
        qDebug() << "connection0 failed";
        qPrintable(QDBusConnection::systemBus().lastError().message());
    }
//    if(!result1)
//    {
//        qDebug() << "connection1 failed";
//        qPrintable(QDBusConnection::systemBus().lastError().message());
//    }
//    if(!result2)
//    {
//        qDebug() << "connection2 failed";
//        qDebug() << QDBusConnection::systemBus().lastError().message();
//    }



//    QDBusMessage reply = ifaceUSBGuardPolicy->call("listRules","block");
 //   qDebug() << reply;
   // reply = ifaceUSBGuardPolicy->call("listRules","block");
   // qDebug() << reply;
 //   reply = ifaceUSBGuardRoot->call("getParameter","InsertedDevicePolicy");
 //   qDebug() << reply;

    // connect(iface, SIGNAL(DevicePolicyChanged(uint,uint,uint,QString,uint,)), QCoreApplication::instance(), SLOT(handle()));
}

void USBServiceHandler::handlePropertyParameterChanged(QString name, QString value_old, QString value_new)
{

    qDebug() << "property";
}

void USBServiceHandler::handleExceptionMessage(QString context, QString object, QString reason)
{

    qDebug() << "exception";
}

void USBServiceHandler::handleDevicePresenceChanged(uint id, uint event, uint target, QString device_rule, QMap<QString, QString>  attributes)
{
    qDebug() << "presence";
}

void USBServiceHandler::handleDevicePolicyChanged(uint id, uint target_old, uint target_new, QString device_rule, uint rule_id, QList<QMap<QString, QString> > attributes)
{

}

void USBServiceHandler::handleDevicePolicyApplied(uint id, uint target_new, uint device_rule, uint rule_id, QList<QPair<QString, QString> > attributes)
{

}
