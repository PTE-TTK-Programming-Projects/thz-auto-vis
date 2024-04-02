#pragma once
#include "./zabermotor.h"
#include <QSerialPortInfo>
#include <QtWidgets>
#include <string>

class ZaberWindow : public QFrame {
  Q_OBJECT;

public:
  ZaberWindow(QWidget *parent = nullptr);

private:
  ZaberDevice *motor;
  QPushButton *connectButton;
  QComboBox *selectBox;
  void refreshComboBox();
  private slots:
  void selectPort();

signals:
  void connectToPort(std::string portName);
};
