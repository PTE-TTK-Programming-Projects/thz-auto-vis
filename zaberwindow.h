#pragma once
#include "./zabermotor.h"
#include <QSerialPortInfo>
#include <QtWidgets>
#include <string>
#include <QErrorMessage>

class ZaberWindow : public QFrame {
  Q_OBJECT;

public:
  ZaberWindow(QWidget *parent = nullptr);

private:
  ZaberDevice *motor;
  QPushButton *connectButton, *homeButton, *moveButton;
  QComboBox *selectBox, *unitbox;
  QLineEdit *manualMsg, *movePos;
  QListWidget *messageScrollback;
  void refreshComboBox();
  double *microstepSize, *maxDistance, *unitMultiplier;
  private slots:
  void selectPort();
  void motorMsg(std::string *message);
  void motorID(int ID);
  void prepManMsg();
  void buttonHome();
  void moveToPos();
  void unitSelChd(QString unit);

signals:
  void connectToPort(std::string portName);
  void sendManualMsg(std::string manMsg);
};
