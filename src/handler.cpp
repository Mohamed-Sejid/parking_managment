#include "handler.h"


Handler::Handler(QObject *parent)
    : QObject{parent}
{
    foreach(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        m_portList.append(port.portName());
    }
    m_led1=true;
    m_led2=false;
    m_led3=false;
}

QStringList Handler::portList() const
{
    return m_portList;
}

void Handler::setPortList(const QStringList &newPortList)
{
    if (m_portList == newPortList)
        return;
    m_portList = newPortList;
    emit portListChanged();
}

bool Handler::led1() const
{
    return m_led1;
}

void Handler::setLed1(bool newLed1)
{
    if (m_led1 == newLed1)
        return;
    m_led1 = newLed1;
    emit led1Changed();
}

bool Handler::led2() const
{
    return m_led2;
}

void Handler::setLed2(bool newLed2)
{
    if (m_led2 == newLed2)
        return;
    m_led2 = newLed2;
    emit led2Changed();
}

bool Handler::led3() const
{
    return m_led3;
}

void Handler::setLed3(bool newLed3)
{
    if (m_led3 == newLed3)
        return;
    m_led3 = newLed3;
    emit led3Changed();
}

QString Handler::port() const
{
    return m_port;
}

void Handler::setPort(const QString &newPort)
{
    if (m_port == newPort)
        return;
    m_port = newPort;
    emit portChanged();
    qDebug()<< m_port;
}
