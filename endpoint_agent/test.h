/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a test /home/bjorniv/arbeid/endpoint_agent/endpoint_agent/DBusInterface.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef TEST_H
#define TEST_H

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface org.usbguard.Policy1
 */
class Policy1Adaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.usbguard.Policy1")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"org.usbguard.Policy1\">\n"
"  </interface>\n"
        "")
public:
    Policy1Adaptor(QObject *parent);
    virtual ~Policy1Adaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
};

/*
 * Adaptor class for interface org.usbguard1
 */
class Usbguard1Adaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.usbguard1")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"org.usbguard1\">\n"
"    <method name=\"getParameter\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"name\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"value\"/>\n"
"    </method>\n"
"    <method name=\"setParameter\">\n"
"      <arg direction=\"in\" type=\"s\" name=\"name\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"value\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"previous_value\"/>\n"
"    </method>\n"
"    <signal name=\"PropertyParameterChanged\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"name\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"value_old\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"value_new\"/>\n"
"    </signal>\n"
"    <signal name=\"ExceptionMessage\">\n"
"      <arg direction=\"out\" type=\"s\" name=\"context\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"object\"/>\n"
"      <arg direction=\"out\" type=\"s\" name=\"reason\"/>\n"
"    </signal>\n"
"  </interface>\n"
        "")
public:
    Usbguard1Adaptor(QObject *parent);
    virtual ~Usbguard1Adaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    QString getParameter(const QString &name);
    QString setParameter(const QString &name, const QString &value);
Q_SIGNALS: // SIGNALS
    void ExceptionMessage(const QString &context, const QString &object, const QString &reason);
    void PropertyParameterChanged(const QString &name, const QString &value_old, const QString &value_new);
};

#endif
