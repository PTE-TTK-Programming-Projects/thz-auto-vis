#pragma once
#include <QtWidgets>
#include <iostream>

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
