#ifndef SCOPE_QT
#define SCOPE_QT
#include <QtWidgets>
#include <iostream>
#include <ps5000aApi.h>
#include <string>

class PicoScope : public QObject {
  Q_OBJECT;

public:
  PicoScope();

private:
  int16_t *handle;
  PICO_STATUS *status;
  int16_t *maxValue, *ready, *divisor;
  uint32_t *timeBase;
  int32_t *timeTookMS;
  int16_t *bufferArray;
  int32_t *bufferLength;
  uint32_t *noOfSamples;
  static void readReady(int16_t handle, PICO_STATUS status,
                            void *pParameter);
  QTimer *statusTimer;
private slots:
  void retrieveData();

public slots:
  void getStatus();
  void measure();
  void setScopeChannel(int couplingIDX, int sensIDX);
  void setTimeWindow(uint32_t timeBase);
  void setTriggerRatio(int16_t divisor);
signals:
  void sendStatus(std::string status);
  void finishSignal();
  void sendMeasurement(int32_t *bufferLength, int16_t *buffer);
};

#endif // SCOPE_QT
