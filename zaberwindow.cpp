#include "./zaberwindow.h"

ZaberWindow::ZaberWindow(QWidget *parent) : QFrame(parent) {
  unitMultiplier = new double(1e-3);
  motor = new ZaberDevice();
  selectBox = new QComboBox();
  connectButton = new QPushButton("Connect");
  moveButton = new QPushButton("Move motor");
  unitbox = new QComboBox;
  unitbox->addItems(
      QStringList(QList<QString>({QString("mm"), QString("um")})));
  movePos = new QLineEdit();
  moveButton->setDisabled(true);
  homeButton = new QPushButton("Home motor");
  homeButton->setDisabled(true);
  manualMsg = new QLineEdit();
  manualMsg->setDisabled(true);
  messageScrollback = new QListWidget();
  microstepSize = new double(1);
  maxDistance = new double(1);
  movePos->setDisabled(true);
  unitbox->setDisabled(true);
  refreshComboBox();
  QVBoxLayout *layout = new QVBoxLayout();
  QHBoxLayout *movebox = new QHBoxLayout();
  movebox->addWidget(movePos);
  movebox->addWidget(unitbox);
  layout->addWidget(selectBox);
  layout->addWidget(connectButton);
  layout->addLayout(movebox);
  layout->addWidget(moveButton);
  layout->addWidget(manualMsg);
  layout->addWidget(homeButton);
  layout->addWidget(messageScrollback);

  layout->setAlignment(Qt::AlignmentFlag::AlignTop);
  this->setLayout(layout);

  setFrameShape(QFrame::StyledPanel);
  setFrameShadow(QFrame::Raised);
  setLineWidth(3);
  setMidLineWidth(3);
  selectBox->setMinimumWidth(150);
  connect(connectButton, &QPushButton::clicked, this, &ZaberWindow::selectPort);
  connect(this, &ZaberWindow::connectToPort, motor, &ZaberDevice::connectName);
  connect(motor, &ZaberDevice::motorSent, this, &ZaberWindow::motorMsg);
  connect(motor, &ZaberDevice::motorIDed, this, &ZaberWindow::motorID);
  connect(manualMsg, &QLineEdit::returnPressed, this, &ZaberWindow::prepManMsg);
  connect(this, &ZaberWindow::sendManualMsg, motor, &ZaberDevice::sendToMotor);
  connect(homeButton, &QPushButton::clicked, this, &ZaberWindow::buttonHome);
  connect(moveButton, &QPushButton::clicked, this, &ZaberWindow::moveToPos);
  connect(unitbox, &QComboBox::currentTextChanged, this,
          &ZaberWindow::unitSelChd);
  connect(unitbox, QOverload<int>::of(&QComboBox::currentIndexChanged), this,
          &ZaberWindow::unitSend);
}

void ZaberWindow::refreshComboBox() {
  QList<QSerialPortInfo> portInfo = QSerialPortInfo::availablePorts();
  selectBox->clear();
  for (int i = 0; i < portInfo.size(); i++) {
    if (portInfo.at(i).portName().contains("USB")) {
      selectBox->addItem(portInfo.at(i).portName());
    }
  }
}

void ZaberWindow::selectPort() {
  emit connectToPort(selectBox->currentText().toStdString());
}

void ZaberWindow::motorMsg(std::string *message) {
  messageScrollback->insertItem(
      0, message->substr(0, message->size() - 2).c_str());
}

void ZaberWindow::motorID(int ID) {
  switch (ID) {
  case 50105:
    manualMsg->setDisabled(false);
    homeButton->setDisabled(false);
    unitbox->setDisabled(false);
    movePos->setDisabled(false);
    moveButton->setDisabled(false);
    *microstepSize = 0.09921875e-6;
    *maxDistance = 150e-3;
    break;
  default:
    QErrorMessage *errormsg = new QErrorMessage();
    errormsg->showMessage("Error! Motor could not be identified!");
    break;
  }
}

void ZaberWindow::prepManMsg() {
  emit sendManualMsg(manualMsg->text().toStdString());
}

void ZaberWindow::buttonHome() { emit sendManualMsg("/home"); }

void ZaberWindow::moveToPos() {
  int microstep;
  double selectedPos =
      movePos->text().toDouble() * (*unitMultiplier) / (*microstepSize);
  microstep = static_cast<int>(round(selectedPos));
  emit sendManualMsg("/move abs " + std::to_string(microstep));
}

void ZaberWindow::unitSelChd(QString unit) {
  if (unit == QString("mm")) {
    *unitMultiplier = 1e-3;
  } else if (unit == QString("um")) {
    *unitMultiplier = 1e-6;
  }
}

void ZaberWindow::externalUnitChange(int index) {
  unitbox->setCurrentIndex(index);
}

void ZaberWindow::unitSend(int index) {
  emit sendUnitIndex(index);
}
