#include "./scope_data_line.h"

ScopeDataLine::ScopeDataLine(std::string dataName, double value,
                             QWidget *parent)
    : QWidget(parent) {
  this->dataName = new QLabel(dataName.c_str());
  this->dataValue = new QLineEdit(QString::number(value));
  this->dataValue->setReadOnly(true);
  this->data = new double;
  *this->data = value;
  QHBoxLayout *layout = new QHBoxLayout();
  layout->addWidget(this->dataName);
  layout->addWidget(this->dataValue);
  layout->setAlignment(Qt::AlignmentFlag::AlignLeft);
  setLayout(layout);
}

void ScopeDataLine::newData(double value) {
  this->dataValue->setText(QString::number(value));
}

double ScopeDataLine::readData() { return *this->data; }
