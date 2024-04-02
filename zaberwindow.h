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
  QListWidget *messageScrollback;
  void refreshComboBox();
  private slots:
  void selectPort();
  void motorMsg(std::string *message);

signals:
  void connectToPort(std::string portName);
};
