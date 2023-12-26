#include "handler.h"


Handler::Handler(QObject *parent)
    : QObject{parent}
{
    foreach(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
        m_portList.append(port.portName());
    }
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
