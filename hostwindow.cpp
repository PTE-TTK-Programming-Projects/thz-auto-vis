#include "./hostwindow.h"

HostWindow::HostWindow(QWidget *parent) : QWidget(parent) {
  scopeWin = new ScopeWindow();
  zaberWin = new ZaberWindow();
  conWin = new MeasureControlWindow();
  instrumentPanel = new QFrame();
  QHBoxLayout *instLayout = new QHBoxLayout();
  instLayout->addWidget(scopeWin);
  instLayout->addWidget(zaberWin);
  instrumentPanel->setLayout(instLayout);
  QGridLayout *layout = new QGridLayout();
  layout->addWidget(conWin);
  setLayout(layout);
  connect(conWin, &MeasureControlWindow::unitSelectorIndex, zaberWin,
          &ZaberWindow::externalUnitChange);
  connect(zaberWin, &ZaberWindow::sendUnitIndex, conWin,
          &MeasureControlWindow::recUnitIndex);
  connect(conWin, &MeasureControlWindow::instrumentVisibility, this,
          &HostWindow::visChanged);
}

void HostWindow::visChanged(bool isChecked) {
  if (isChecked) {
    instrumentPanel->show();
  } else {
    instrumentPanel->hide();
  }
}
