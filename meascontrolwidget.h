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
private slots:
  void sendCurrentIndex(int index);

public slots:
  void recUnitIndex(int index);

signals:
  void unitSelectorIndex(int index);
};
