#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QSerialPortInfo>
#include <QDebug>
#include "serial.h"

class Handler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList portList READ portList WRITE setPortList NOTIFY portListChanged FINAL)
    Q_PROPERTY(bool led1 READ led1 WRITE setLed1 NOTIFY led1Changed FINAL)
    Q_PROPERTY(bool led2 READ led2 WRITE setLed2 NOTIFY led2Changed FINAL)
    Q_PROPERTY(bool led3 READ led3 WRITE setLed3 NOTIFY led3Changed FINAL)
    Q_PROPERTY(QString port READ port WRITE setPort NOTIFY portChanged FINAL)
public:
    explicit Handler(QObject *parent = nullptr);

    QStringList portList() const;
    void setPortList(const QStringList &newPortList);

    bool led1() const;
    Q_INVOKABLE void setLed1(bool newLed1);

    bool led2() const;
    Q_INVOKABLE void setLed2(bool newLed2);

    bool led3() const;
    Q_INVOKABLE void setLed3(bool newLed3);

    QString port() const;
    Q_INVOKABLE void setPort(const QString &newPort);

signals:
    void portListChanged();
    void led1Changed();

    void led2Changed();

    void led3Changed();

    void portChanged();

private:
    QStringList m_portList;
    bool m_led1;
    bool m_led2;
    bool m_led3;
    QString m_port;
};

#endif // HANDLER_H
