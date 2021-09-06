#pragma once

#include <QObject>
#include <QtDBus>


class USBServiceHandler : public QObject
{
    Q_OBJECT
public:
    explicit USBServiceHandler(QObject *parent = nullptr);

private:
    QDBusInterface *ifaceUSBGuardRoot;
    QDBusInterface *ifaceUSBGuardDevices;
    QDBusInterface *ifaceUSBGuardPolicy;
signals:
    //USBGUARD_ROOT
    void getParameter(QString name); // out s value
    void setParameter(QString name); // out s previous_value
    //USBGUARD_POLICY
    void listRules(QString label); // out a(us) ruleset
    void appendRule(QString rule, uint parent_id, bool temporary); // out u id
    void removeRule(uint id); // out
    //USBGUARD_DEVICE
    void listDevices(QString query); // out a(us) devices
    void applyDevicePolicy(uint id, uint target, bool permanent);


public slots:
    //USBGUARD_ROOT
    void handlePropertyParameterChanged(QString name, QString value_old, QString value_new);
    void handleExceptionMessage(QString context, QString object, QString reason);
    //USBGUARD_POLICY


    //USBGUARD_DEVICE
    void handleDevicePresenceChanged(uint id, uint event, uint target, QString device_rule,
                               QList< QMap < QString , QString > > attributes);
    void handleDevicePolicyChanged(uint id, uint target_old, uint target_new, QString device_rule, uint rule_id,
                             QList< QMap < QString, QString > > attributes);
    void handleDevicePolicyApplied(uint id, uint target_new, uint device_rule, uint rule_id,
                             QList< QMap < QString, QString > > attributes);




};

