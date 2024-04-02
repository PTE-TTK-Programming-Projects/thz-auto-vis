#include "./hostwindow.h"

HostWindow::HostWindow(QWidget *parent) : QWidget(parent) {
  scopeWin = new ScopeWindow();
  zaberWin = new ZaberWindow();
  QGridLayout *layout = new QGridLayout();
  layout->addWidget(scopeWin, 0, 0);
  layout->addWidget(zaberWin, 0, 1);
  setLayout(layout);
}
