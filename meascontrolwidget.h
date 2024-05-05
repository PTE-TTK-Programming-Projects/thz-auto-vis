#pragma once
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
  QPushButton *showInstrumentControls;
private slots:
  void sendCurrentIndex(int index);
  void showClicked();

public slots:
  void recUnitIndex(int index);

signals:
  void unitSelectorIndex(int index);
  void instrumentVisibility(bool isChecked);
};
