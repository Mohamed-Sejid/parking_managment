#include "serial.h"
#include <QDebug>

Serial::Serial(QObject *parent)
    : QObject{parent}
{
    _link.setPortName("COM1");
    _link.setBaudRate(QSerialPort::Baud9600);
    _link.setDataBits(QSerialPort::Data8);
    _link.setParity(QSerialPort::NoParity);
    _link.setStopBits(QSerialPort::OneStop);
    _link.setFlowControl(QSerialPort::NoFlowControl);
    connect(&_link, &QSerialPort::readyRead, this, &Serial::newData);
    qDebug()<<"Serial Object created";

}

Serial::~Serial()
{
    closeConnection();
}

void Serial::openConnection()
{
    if(!_link.open(QIODevice::ReadWrite)){
        qDebug()<<"Impossible connection";
    }
    else qDebug()<<"Connected";
}

void Serial::closeConnection()
{
    _link.close();
}

void Serial::serialWrite(const char *msg)
{
    if(this->isWritable()){
        _link.write(msg);
        qDebug()<<"QDebug: message sent \n";
    }
    else{
        qDebug()<<"QDebug: port is not writable";
    }
}

bool Serial::isOpen()
{
    return _link.isOpen();
}

bool Serial::isWritable()
{
    return _link.isWritable();
}
void Serial::newData(){
    emit gotNewData(_link.readAll());
}
