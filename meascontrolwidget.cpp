#include "./meascontrolwidget.h"

MeasureControlWindow::MeasureControlWindow(QWidget *parent) : QFrame(parent) {
  initDefaultValues();

  motor = new ZaberDevice();
  motorWin = new ZaberWindow();




  QHBoxLayout *layout = new QHBoxLayout();
  layout->addWidget(start);
  layout->addWidget(startpos);
  layout->addWidget(step);
  layout->addWidget(stepsize);
  layout->addWidget(end);
  layout->addWidget(endpos);
  layout->addWidget(unitSelector);
  layout->addWidget(measure);
  setupConnections();
  setLayout(layout);

  //connect(motorWin, &ZaberWindow::motorReady,this, &MeasureControlWindow::enableMeasure);
}

void MeasureControlWindow::initDefaultValues() {
  startpos = new QLineEdit();
  start = new QLabel("Absolute starting position: ");
  endpos = new QLineEdit();
  end = new QLabel("Absolute finish position: ");
  stepsize = new QLineEdit();
  step = new QLabel("Stepsize: ");
  unitSelector = new QComboBox();
  unitSelector->addItems(QList<QString>({QString("mm"), QString("um")}));
  measure = new QPushButton("Start procedure");
  measure->setEnabled(false);

  
}

void MeasureControlWindow::setupConnections() {
  connect(unitSelector, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &MeasureControlWindow::sendCurrentIndex);
}

void MeasureControlWindow::sendCurrentIndex(int index) {
  emit unitSelectorIndex(index);
}

void MeasureControlWindow::recUnitIndex(int index) {
  unitSelector->setCurrentIndex(index);
}

void MeasureControlWindow::enableMeasure() { measure->setEnabled(true); }

