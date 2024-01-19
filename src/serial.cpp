#include "serial.h"
#include <QDebug>
#include "handler.h"
Serial::Serial(QObject *parent)
    : QObject{parent}
{
    _link.setPortName("COM36");
    _link.setBaudRate(QSerialPort::Baud115200);
    _link.setDataBits(QSerialPort::Data8);
    _link.setParity(QSerialPort::NoParity);
    _link.setStopBits(QSerialPort::OneStop);
    _link.setFlowControl(QSerialPort::NoFlowControl);
    connect(&_link, &QSerialPort::readyRead, this, &Serial::newData);
    qDebug()<<"Serial Object created";
    connect(this,&Serial::gotNewData,this,&Serial::receivedSerial);

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

void Serial::receivedSerial(QString data)
{
    /*if(data[0].digitValue()==0){
        Handler::.setLed1(0);
    }
    else{
        Handler::setLed1(1);
    }

    if(data[1].digitValue()==0){
        Handler::setLed2(0);
    }
    else{
        Handler::setLed2(1);
    }

    if(data[2].digitValue()==0){
        Handler::setLed3(0);
    }
    else{
        Handler::setLed3(1);
    }*/
    qDebug()<<data;

}
void Serial::newData(){

    emit gotNewData(_link.readAll());
}

