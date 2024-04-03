#include "./meascontrolwidget.h";

MeasureControlWindow::MeasureControlWindow(QWidget *parent) : QFrame(parent) {
  initDefaultValues();
  QHBoxLayout *layout = new QHBoxLayout();
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
}

void MeasureControlWindow::setupConnections() {
  connect(unitSelector, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &MeasureControlWindow::sendCurrentIndex);
}

void MeasureControlWindow::sendCurrentIndex(int index) {
  emit unitSelectorIndex(index);
}

void MeasureControlWindow::recUnitIndex(int index){
  unitSelector->setCurrentIndex(index);
}
