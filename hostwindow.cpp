#include "./hostwindow.h"

HostWindow::HostWindow(QWidget *parent) : QWidget(parent){
  scopeWin = new ScopeWindow();
  QGridLayout *layout = new QGridLayout();
  layout->addWidget(scopeWin);
  setLayout(layout);
}
