#include "./hostwindow.h"

HostWindow::HostWindow(QWidget *parent) : QWidget(parent) {
  scopeWin = new ScopeWindow();
  zaberWin = new ZaberWindow();
  conWin = new MeasureControlWindow();
  QGridLayout *layout = new QGridLayout();
  layout->addWidget(conWin, 0, 0, 1, 2);
  layout->addWidget(scopeWin, 1, 0);
  layout->addWidget(zaberWin, 1, 1);
  setLayout(layout);
  connect(conWin, &MeasureControlWindow::unitSelectorIndex, zaberWin,
          &ZaberWindow::externalUnitChange);
  connect(zaberWin, &ZaberWindow::sendUnitIndex, conWin,
          &MeasureControlWindow::recUnitIndex);
  connect(zaberWin, &ZaberWindow::connectToPort, conWin,
          &MeasureControlWindow::enableMeasure);
  connect(conWin, &MeasureControlWindow::getMotorValues, zaberWin,
          &ZaberWindow::sendMotorValues);
  connect(zaberWin, &ZaberWindow::giveMotorValues, conWin,
          &MeasureControlWindow::claimMotorValues);
  connect(conWin, QOverload<double>::of(&MeasureControlWindow::stepMotor),
          zaberWin, QOverload<double>::of(&ZaberWindow::moveToPos));
  connect(conWin, &MeasureControlWindow::startProc, this,
          &HostWindow::startMeas);
  connect(conWin, &MeasureControlWindow::stopProc, this,
          &HostWindow::stopMeas);
}

void HostWindow::startMeas() {
  connect(zaberWin, &ZaberWindow::motorReady, conWin,
          &MeasureControlWindow::stepNext);
}
void HostWindow::stopMeas() {
  disconnect(zaberWin, &ZaberWindow::motorReady, conWin,
          &MeasureControlWindow::stepNext);
}
