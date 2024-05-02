#include "./meascontrolwidget.h"

MeasureControlWindow::MeasureControlWindow(QWidget *parent) : QFrame(parent) {
  initDefaultValues();

  QHBoxLayout *layout = new QHBoxLayout();
  layout->addWidget(start);
  layout->addWidget(startpos);
  layout->addWidget(step);
  layout->addWidget(stepsize);
  layout->addWidget(end);
  layout->addWidget(endpos);
  layout->addWidget(unitSelector);
  layout->addWidget(stepNumber);
  layout->addWidget(measure);
  setupConnections();
  setLayout(layout);

  connect(unitSelector, &QComboBox::currentTextChanged, this,
          &MeasureControlWindow::setUnits);
  connect(measure, &QPushButton::clicked, this,
          &MeasureControlWindow::startProcedure);
   
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
  stepNumber = new QLabel("Number of steps: 0");

  unitMultiplier = new double(1e-3);
  microstepSize = new double(0.09921875e-6);
  maxDistance = new double(150e-3);

  positions = new std::vector<double>();
  stepCounter = new u_int(0);
  lastStep = new u_int(0);
  stepping = new bool();
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

void MeasureControlWindow::enableMeasure() {
  // startpos->setText("Lefut");
  measure->setEnabled(true);
  emit getMotorValues();
}

void MeasureControlWindow::claimMotorValues(double stepSize, double maxDist) {
  *microstepSize = stepSize;
  *maxDistance = maxDist;
}

void MeasureControlWindow::startProcedure() {

  /*if (endpos->text().toDouble() > *maxDistance*1e3 ||
  startpos->text().toDouble() > *maxDistance*1e3){ QErrorMessage *errormsg = new
  QErrorMessage(); errormsg->showMessage("Move interval reaches out of limit!");
  } else {*/
  int microstep;

  double selectedPos = startpos->text().toDouble();
  // double selectedPos = startpos->text().toDouble() * (*unitMultiplier) /
  // (*microstepSize);
  microstep = static_cast<int>(round(selectedPos));

  emit stepMotor(selectedPos);
  // várakozás kell

  double stepDistance = endpos->text().toDouble() - startpos->text().toDouble();

  int numberOfSteps = round(stepDistance / stepsize->text().toDouble());
  // QString steps = "Number of steps: " + QString::number(numberOfSteps);
  stepNumber->setText("Number of steps: " + QString::number(numberOfSteps));

  double length =
      stepDistance / numberOfSteps; //* (*unitMultiplier) / (*microstepSize);
  microstep = static_cast<int>(round(length));
  positions->clear();
  *stepCounter = 0;
  *stepping = true;

  for (int i = 0; i < numberOfSteps+1; i++) {
    // emit stepMotor("/move rel +" + std::to_string(microstep));
    //  várakozás kell
    positions->push_back(startpos->text().toDouble() + i * length);
    //std::cout << i << ". position is calculated and stored" << std::endl;
  }

  //emit stepMotor("/home");
  emit startProc();

  //}
}

void MeasureControlWindow::setUnits(QString unit) {
  if (unit == QString("mm")) {
    *unitMultiplier = 1e-3;
  } else if (unit == QString("um")) {
    *unitMultiplier = 1e-6;
  }
}

void MeasureControlWindow::stepNext() {
  //std::cout << "Current position is: "<< *stepCounter << std::endl;
  //std::cout << "Last position is: " << positions->size() << std::endl;
  if (*stepCounter < positions->size() && *stepping) {
    emit stepMotor(positions->at(*stepCounter));
    //emit takeSample();
    *stepCounter += 1;
    *stepping = false;
  } else if(*stepCounter < positions->size()){
    // rest in place until the local measurement finished
  }else {
    //std::cout << "please let me die" << std::endl;
    emit stopProc();
  }
}

void MeasureControlWindow::scopeNext(){
  std::cout << "Mérek" << std::endl;
  emit takeSample();
  *stepping = true;
}

/*void valami(){
  // lépé#include <iostream>
    emit stepMotor() 

  // mérés
  emit takeSample();
}*/
