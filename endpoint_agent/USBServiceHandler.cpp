#include "USBServiceHandler.h"
#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusConnection>

USBServiceHandler::USBServiceHandler(QObject *parent) : QObject(parent)
{

    ifaceUSBGuardRoot = new QDBusInterface("org.usbguard1", "/org/usbguard1", "org.usbguard1",
                               QDBusConnection::systemBus(), this);
    ifaceUSBGuardDevices = new QDBusInterface("org.usbguard1", "/org/usbguard1/Devices", "org.usbguard.Devices1",
                               QDBusConnection::systemBus(), this);
    ifaceUSBGuardPolicy = new QDBusInterface("org.usbguard1", "/org/usbguard1/Policy", "org.usbguard.Policy1",
                               QDBusConnection::systemBus(), this);

    if (!ifaceUSBGuardDevices->isValid()) {
        fprintf(stderr, "%s\n",
                qPrintable(QDBusConnection::systemBus().lastError().message()));
        QCoreApplication::instance()->quit();
    }


//   auto result = QDBusConnection::systemBus().connect("org.usbguard1","/org/usbguard1","org.usbguard1",
//                             "DevicePresenceChanged",this, SLOT(USBServiceHandler::handleDevicePresenceChanged()));
//   if(!result)
//   {
//    qDebug() << "connection failed";
//   }


    QDBusMessage reply = ifaceUSBGuardDevices->call("listDevices","allow");
   // qDebug() << reply;
    reply = ifaceUSBGuardPolicy->call("listRules","block");
    qDebug() << reply;
    reply = ifaceUSBGuardRoot->call("getParameter","InsertedDevicePolicy");
    qDebug() << reply;

    // connect(iface, SIGNAL(DevicePolicyChanged(uint,uint,uint,QString,uint,)), QCoreApplication::instance(), SLOT(handle()));
}

void USBServiceHandler::handlePropertyParameterChanged(QString name, QString value_old, QString value_new)
{

}

void USBServiceHandler::handleExceptionMessage(QString context, QString object, QString reason)
{

}

void USBServiceHandler::handleDevicePresenceChanged(uint id, uint event, uint target, QString device_rule, QList<QMap<QString, QString> > attributes)
{

}

void USBServiceHandler::handleDevicePolicyChanged(uint id, uint target_old, uint target_new, QString device_rule, uint rule_id, QList<QMap<QString, QString> > attributes)
{

}

void USBServiceHandler::handleDevicePolicyApplied(uint id, uint target_new, uint device_rule, uint rule_id, QList<QMap<QString, QString> > attributes)
{

}
