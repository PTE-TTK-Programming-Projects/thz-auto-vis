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
  instrumentPanel->setWindowFlags(Qt::Window | Qt::WindowMaximizeButtonHint);
  this->setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
  setLayout(layout);
  connect(conWin, &MeasureControlWindow::unitSelectorIndex, zaberWin,
          &ZaberWindow::externalUnitChange);
  connect(zaberWin, &ZaberWindow::sendUnitIndex, conWin,
          &MeasureControlWindow::recUnitIndex);
  connect(conWin, &MeasureControlWindow::instrumentVisibility, this,
          &HostWindow::visChanged);
  connect(conWin, &MeasureControlWindow::controlsHidden, this,
          &HostWindow::controlHidden);
  connect(conWin, &MeasureControlWindow::requestStart, this,
          &HostWindow::start);
  connect(conWin, &MeasureControlWindow::requestStop, this, &HostWindow::stop);
  this->setWindowTitle("THz auto visualizer by Gergő Illés");
  instrumentPanel->setWindowTitle(
      "Advanced Instrument Controls by Gergő Illés");
}

void HostWindow::visChanged(bool isChecked) {
  if (isChecked) {
    instrumentPanel->show();
  } else {
    instrumentPanel->hide();
  }
}

void HostWindow::controlHidden() { QCoreApplication::exit(); }

void HostWindow::start(double pos) {
  connect(zaberWin, &ZaberWindow::motorReady, scopeWin,
          &ScopeWindow::extMeasure);
  connect(scopeWin, &ScopeWindow::MEASUREMENT_TYPE, conWin,
          &MeasureControlWindow::recMeasPoint);
  connect(conWin, &MeasureControlWindow::requestNextStep, zaberWin,
          &ZaberWindow::moveToUnitPos);
  zaberWin->moveToUnitPos(pos);
}

void HostWindow::stop() {
  disconnect(zaberWin, &ZaberWindow::motorReady, scopeWin,
             &ScopeWindow::extMeasure);
  disconnect(scopeWin, &ScopeWindow::MEASUREMENT_TYPE, conWin,
             &MeasureControlWindow::recMeasPoint);
  disconnect(conWin, &MeasureControlWindow::requestNextStep, zaberWin,
             &ZaberWindow::moveToUnitPos);
}
