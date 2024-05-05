#include "./zabermotor.h"

ZaberDevice::ZaberDevice() : QSerialPort() {
  buffer = new std::string("");
  readTimer = new QTimer();
  readTimer->setInterval(50);
  this->setParity(QSerialPort::NoParity);
  this->setFlowControl(QSerialPort::NoFlowControl);
  this->setStopBits(QSerialPort::OneStop);
  this->setBaudRate(QSerialPort::Baud115200);
  this->setDataBits(QSerialPort::Data8);
  connect(readTimer, &QTimer::timeout, this, &ZaberDevice::readSerial);
  connect(this, &ZaberDevice::readyRead, this, &ZaberDevice::startSerialTimer);
}

void ZaberDevice::connectName(std::string portName) {
  this->close();
  this->setPortName(portName.c_str());
  this->open(QSerialPort::ReadWrite);
  this->sendToMotor("/get device.id");
}

void ZaberDevice::startSerialTimer() {
  *buffer = "";
  readTimer->start();
}

void ZaberDevice::readSerial() {
  *buffer += this->readAll().toStdString();
  if (*buffer->end() == 10 || *buffer->end() == 0) {
    readTimer->stop();
    emit motorSent(buffer);
    if (buffer->find("IDLE") != std::string::npos) {
      emit motorReady();
    } else if (buffer->find("BUSY") != std::string::npos) {
      emit motorBusy();
    }

    if (buffer->find("50105") != std::string::npos) {
      emit motorIDed(50105);
    }
  }
}

void ZaberDevice::sendToMotor(std::string message) {
  this->waitForBytesWritten();
  this->write((message + "\r\n").c_str());
}
