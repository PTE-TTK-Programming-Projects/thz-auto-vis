#pragma once
#include <QtWidgets>
#include <iostream>

class ScopeDataLine : public QWidget{
  Q_OBJECT;

public:
  ScopeDataLine(std::string dataName = "Data", double value = 0, QWidget *parent = nullptr);
  double readData();

public slots:
void newData(double value);

private:
  QLabel *dataName;
  QLineEdit *dataValue;
  double *data;
};

