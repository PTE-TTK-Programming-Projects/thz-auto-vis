#include "./hostwindow.h"

HostWindow::HostWindow(QWidget *parent) : QWidget(parent) {
  button = new QPushButton("Status");
  measurebutton = new QPushButton("Measure");
  status = new QLineEdit("");
  scope = new PicoScope();
  QGridLayout *layout = new QGridLayout();
  layout->addWidget(button);
  layout->addWidget(measurebutton);
  layout->addWidget(status);
  setLayout(layout);
  connect(button, &QPushButton::clicked, scope, &PicoScope::getStatus);
  connect(measurebutton, &QPushButton::clicked, scope, &PicoScope::measure);
  connect(scope, &PicoScope::sendStatus, this, &HostWindow::showStatus);
}

void HostWindow::showStatus(std::string status) {
  this->status->setText(status.c_str());
}
