#pragma once
#include <QtWidgets>
#include <QLabel>
#include <QPushButton>
#include "./zaberwindow.h"
#include "./zabermotor.h"

class MeasureControlWindow : public QFrame {
  Q_OBJECT;

public:
  MeasureControlWindow(QWidget *parent = nullptr);

private:
  ZaberWindow *motorWin;
  ZaberDevice *motor;

  void initDefaultValues();
  void setupConnections();
  QLineEdit *startpos, *endpos, *stepsize;
  QComboBox *unitSelector;
  QLabel *start, *step, *end;
  QPushButton *measure;
private slots:
  void sendCurrentIndex(int index);
  void enableMeasure();

public slots:
  void recUnitIndex(int index);

signals:
  void unitSelectorIndex(int index);
};
