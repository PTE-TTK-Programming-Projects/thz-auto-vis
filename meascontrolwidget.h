#pragma once
#include <QtCharts>
#include <QtWidgets>
#include <iostream>
#include <fstream>

class MeasureControlWindow : public QFrame {
  Q_OBJECT;

public:
  MeasureControlWindow(QWidget *parent = nullptr);

private:
  void initDefaultValues();
  void setupConnections();
  void hideEvent(QHideEvent *event);
  void closeEvent(QCloseEvent *event);
  QLineEdit *startpos, *endpos, *stepsize, *saveName;
  QComboBox *unitSelector;
  QPushButton *showInstrumentControls, *startMeasure, *stopButton, *resetZoom, *saveButton;
  QLabel *start, *step, *stop;
  QFrame *parameterFrame, *visualizationFrame;
  QChart *chart;
  QChartView *chartView;
  std::vector<double> *coords, *measVals;
  void plotResults();
private slots:
  void sendCurrentIndex(int index);
  void showClicked();
  void startMeasProc();
  void stopMeasProc();
  void resetZoomSlot();
  void saveDataSlot();

public slots:
  void recUnitIndex(int index);
  void recMeasPoint(double value);

signals:
  void unitSelectorIndex(int index);
  void instrumentVisibility(bool isChecked);
  void controlsHidden();
  void requestStart(double pos);
  void requestNextStep(double pos);
  void requestStop();
};
