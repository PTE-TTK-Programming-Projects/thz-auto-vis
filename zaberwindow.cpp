#include "./zaberwindow.h"

ZaberWindow::ZaberWindow(QWidget *parent) : QFrame(parent) {
  motor = new ZaberDevice();
  selectBox = new QComboBox();
  connectButton = new QPushButton("Connect");
  messageScrollback = new QListWidget();
  refreshComboBox();
  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(selectBox);
  layout->addWidget(connectButton);
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
