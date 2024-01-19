#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QDebug>

class Serial : public QObject
{
    Q_OBJECT
public:
    explicit Serial(QObject *parent = nullptr);
    ~Serial();
    void openConnection();
    void closeConnection();
    void serialWrite(const char* msg);
    bool isOpen();
    bool isWritable();
    void receivedSerial(QString data);


private slots:
    void newData();
signals:
    void gotNewData(QString dataMsg);
private:
    QSerialPort _link;
    int i;
};

#endif // SERIAL_H
