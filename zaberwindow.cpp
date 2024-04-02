#include "./zaberwindow.h"

ZaberWindow::ZaberWindow(QWidget *parent) : QFrame(parent) {
  motor = new ZaberDevice();
  selectBox = new QComboBox();
  connectButton = new QPushButton("Connect");
  refreshComboBox();
  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(selectBox);
  layout->addWidget(connectButton);

  layout->setAlignment(Qt::AlignmentFlag::AlignTop);
  this->setLayout(layout);

  setFrameShape(QFrame::StyledPanel);
  setFrameShadow(QFrame::Raised);
  setLineWidth(3);
  setMidLineWidth(3);
  this->resize(350, 480);
  connect(connectButton, &QPushButton::clicked, this,
          &ZaberWindow::selectPort);
  connect(this, &ZaberWindow::connectToPort, motor, &ZaberDevice::connectName);
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
