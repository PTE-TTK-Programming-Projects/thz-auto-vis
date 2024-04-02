#include "./zaberwindow.h"

ZaberWindow::ZaberWindow(QWidget *parent) : QFrame(parent) {
  motor = new ZaberDevice();
  selectBox = new QComboBox();
  connectButton = new QPushButton("Connect");
  moveButton = new QPushButton("Move motor");
  moveButton->setDisabled(true);
  homeButton = new QPushButton("Home motor");
  homeButton->setDisabled(true);
  manualMsg = new QLineEdit();
  manualMsg->setDisabled(true);
  messageScrollback = new QListWidget();
  microstepSize = new double(1);
  maxDistance = new double(1);
  refreshComboBox();
  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(selectBox);
  layout->addWidget(connectButton);
  layout->addWidget(manualMsg);
  layout->addWidget(homeButton);
  layout->addWidget(messageScrollback);

  layout->setAlignment(Qt::AlignmentFlag::AlignTop);
  this->setLayout(layout);

  setFrameShape(QFrame::StyledPanel);
  setFrameShadow(QFrame::Raised);
  setLineWidth(3);
  setMidLineWidth(3);
  selectBox->setMinimumWidth(200);
  connect(connectButton, &QPushButton::clicked, this, &ZaberWindow::selectPort);
  connect(this, &ZaberWindow::connectToPort, motor, &ZaberDevice::connectName);
  connect(motor, &ZaberDevice::motorSent, this, &ZaberWindow::motorMsg);
  connect(motor, &ZaberDevice::motorIDed, this, &ZaberWindow::motorID);
  connect(manualMsg, &QLineEdit::returnPressed, this, &ZaberWindow::prepManMsg);
  connect(this, &ZaberWindow::sendManualMsg, motor, &ZaberDevice::sendToMotor);
  connect(homeButton, &QPushButton::clicked, this, &ZaberWindow::buttonHome);
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
  messageScrollback->addItem(message->substr(0, message->size() - 2).c_str());
}

void ZaberWindow::motorID(int ID) {
  switch (ID) {
  case 50105:
    manualMsg->setDisabled(false);
    homeButton->setDisabled(false);
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

void ZaberWindow::buttonHome() {
  emit sendManualMsg("/home");
}
