#include "./hostwindow.h"

HostWindow::HostWindow(QWidget *parent) : QWidget(parent) {
  button = new QPushButton("Status");
  status = new QLineEdit("");
  scope = new PicoScope();
  QGridLayout *layout = new QGridLayout(); 
  layout->addWidget(button);
  layout->addWidget(status);
  setLayout(layout);
  connect(button,&QPushButton::clicked, scope, &PicoScope::getStatus);
}
