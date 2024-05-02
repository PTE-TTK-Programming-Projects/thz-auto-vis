#pragma once
#include "./zaberwindow.h"
#include <QtWidgets>

class MeasureControlWindow : public QFrame {
  Q_OBJECT;

public:
  MeasureControlWindow(QWidget *parent = nullptr);

private:

  void initDefaultValues();
  void setupConnections();
  QLineEdit *startpos, *endpos, *stepsize;
  QComboBox *unitSelector;
  QLabel *start, *step, *end, *stepNumber;
  QPushButton *measure;
  double *microstepSize, *maxDistance, *unitMultiplier; 
  u_int *stepCounter, *lastStep;
  std::vector<double> *positions;
  bool *stepping;
private slots:
  void sendCurrentIndex(int index);
  void startProcedure();

  void setUnits(QString unit);

public slots:
  void recUnitIndex(int index);
  void enableMeasure();
  void claimMotorValues(double stepSize, double maxDist);
  void stepNext();
  void scopeNext();

signals:
  void unitSelectorIndex(int index);
  void getMotorValues();
  void stepMotor(std::string stepMsg);
  void stepMotor(double selectedPos);
  void startProc();
  void stopProc();
  void takeSample();
};
