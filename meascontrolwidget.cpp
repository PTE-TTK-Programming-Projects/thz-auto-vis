#include "./meascontrolwidget.h"

MeasureControlWindow::MeasureControlWindow(QWidget *parent) : QFrame(parent) {
  initDefaultValues();
  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(showInstrumentControls);
  layout->addWidget(startpos);
  layout->addWidget(stepsize);
  layout->addWidget(endpos);
  layout->addWidget(unitSelector);
  setupConnections();
  setLayout(layout);
}

void MeasureControlWindow::initDefaultValues() {
  startpos = new QLineEdit();
  endpos = new QLineEdit();
  stepsize = new QLineEdit();
  unitSelector = new QComboBox();
  unitSelector->addItems(QList<QString>({QString("mm"), QString("um")}));
  showInstrumentControls = new QPushButton("Show instrument controls");
  showInstrumentControls->setCheckable(true);
}

void MeasureControlWindow::setupConnections() {
  connect(unitSelector, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &MeasureControlWindow::sendCurrentIndex);
  connect(showInstrumentControls, &QPushButton::clicked, this,
          &MeasureControlWindow::showClicked);
}

void MeasureControlWindow::sendCurrentIndex(int index) {
  emit unitSelectorIndex(index);
}

void MeasureControlWindow::recUnitIndex(int index) {
  unitSelector->setCurrentIndex(index);
}
void MeasureControlWindow::showClicked() {
  emit instrumentVisibility(showInstrumentControls->isChecked());
}
