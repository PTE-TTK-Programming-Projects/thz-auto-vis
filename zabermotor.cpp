#include "./zabermotor.h"

ZaberDevice::ZaberDevice() : QSerialPort() {
  buffer = new std::string("");
  readTimer = new QTimer();
  readTimer->setInterval(50);
  this->setParity(QSerialPort::NoParity);
  this->setFlowControl(QSerialPort::NoFlowControl);
  this->setStopBits(QSerialPort::OneStop);
  this->setBaudRate(QSerialPort::Baud115200);
  connect(readTimer, &QTimer::timeout, this, &ZaberDevice::readSerial);
  connect(this, &ZaberDevice::readyRead, this, &ZaberDevice::startSerialTimer);
}

void ZaberDevice::connectName(std::string portName) {
  this->close();
  this->setPortName(portName.c_str());
  this->open(QSerialPort::ReadWrite);
}

void ZaberDevice::startSerialTimer() {
  *buffer = "";
  readTimer->start();
}

void ZaberDevice::readSerial() {
  *buffer += this->readAll().toStdString();
  if (buffer->end()[0] == '\n') {
    readTimer->stop();
    emit motorSent(buffer);
    if (buffer->find("READY")) {
      emit motorReady();
    } else if (buffer->find("BUSY")) {
      emit motorBusy();
    }
  }
}

void ZaberDevice::sendToMotor(std::string message) {
  this->waitForBytesWritten();
  this->write(message.c_str());
}
