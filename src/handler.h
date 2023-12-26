#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QSerialPortInfo>

class Handler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList portList READ portList WRITE setPortList NOTIFY portListChanged FINAL)
public:
    explicit Handler(QObject *parent = nullptr);

    QStringList portList() const;
    void setPortList(const QStringList &newPortList);

signals:
    void portListChanged();
private:
    QStringList m_portList;
};

#endif // HANDLER_H
