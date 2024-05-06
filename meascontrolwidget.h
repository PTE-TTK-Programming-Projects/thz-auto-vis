#pragma once
#include <QtWidgets>
#include <iostream>
#include <QtCharts>

class MeasureControlWindow : public QFrame {
  Q_OBJECT;

public:
  MeasureControlWindow(QWidget *parent = nullptr);

private:
  void initDefaultValues();
  void setupConnections();
  void hideEvent(QHideEvent *event);
  void closeEvent(QCloseEvent *event);
  QLineEdit *startpos, *endpos, *stepsize;
  QComboBox *unitSelector;
  QPushButton *showInstrumentControls;
  QLabel *start, *step, *stop;
  QFrame *parameterFrame, *visualizationFrame;
  QChart *chart;
  QChartView *chartView;
private slots:
  void sendCurrentIndex(int index);
  void showClicked();

public slots:
  void recUnitIndex(int index);

signals:
  void unitSelectorIndex(int index);
  void instrumentVisibility(bool isChecked);
  void controlsHidden();
};
