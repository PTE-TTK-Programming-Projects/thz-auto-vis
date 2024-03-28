#ifndef SCOPE_QT
#define SCOPE_QT
#include <QtWidgets>
#include <iostream>
#include <ps5000aWrap.h>
#include <string>

class PicoScope : public QObject {
  Q_OBJECT;

public:
  PicoScope();

private:
  int16_t *handle;
  PICO_STATUS *status;
  int16_t *maxValue, *ready;
  int32_t *timeTookMS;
  int16_t *bufferArray;
  int32_t *bufferLength;
  uint32_t *noOfSamples;
  QTimer *polltimer, *statusTimer;
private slots:
  void retrieveData();

public slots:
  void getStatus();
  void pollMeasurement();
  void measure();
signals:
  void sendStatus(std::string status);
  void finishSignal();
  void sendMeasurement(int32_t *bufferLength, int16_t *buffer);
};

#endif // SCOPE_QT
