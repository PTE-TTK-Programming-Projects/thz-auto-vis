#include "./scope.h"

PicoScope::PicoScope() : QObject() {
  statusTimer = new QTimer;
  statusTimer->setInterval(100);
  ready = new int16_t;
  handle = new int16_t;
  status = new PICO_STATUS;
  timeTookMS = new int32_t;
  bufferLength = new int32_t(2001);
  noOfSamples = new uint32_t(2001);
  bufferArray = new int16_t[2001];
  *status = ps5000aOpenUnit(handle, nullptr, PS5000A_DR_12BIT);
  if (*status == PICO_POWER_SUPPLY_NOT_CONNECTED) {
    ps5000aChangePowerSource(*handle, *status);
  }
  maxValue = new int16_t;
  ps5000aMaximumValue(*handle, maxValue);
  ps5000aSetChannel(*handle, PS5000A_CHANNEL_A, 1, PS5000A_AC, PS5000A_5V, 0);
  ps5000aSetSimpleTrigger(
      *handle, 1, PS5000A_CHANNEL::PS5000A_CHANNEL_A, *maxValue / 10,
      PS5000A_THRESHOLD_DIRECTION::PS5000A_FALLING, 0, 1000);
  ps5000aSetDataBuffer(*handle, PS5000A_CHANNEL_A, bufferArray, *bufferLength,
                       0, PS5000A_RATIO_MODE_NONE);
  connect(this, &PicoScope::finishSignal, this, &PicoScope::retrieveData);
  connect(statusTimer, &QTimer::timeout, this, &PicoScope::getStatus);
  statusTimer->start();
}

void PicoScope::measure() {
  ps5000aRunBlock(*handle, 1000, 1001, 128, timeTookMS, 0, PicoScope::readReady,
                  static_cast<void*>(this));
}

void PicoScope::getStatus() {
  // std::cout << "Status fetching reached" << std::endl;
  *status = ps5000aPingUnit(*handle);
  switch (*status) {
  case PICO_OK:
    emit sendStatus("PICO_OK");
    break;
  case PICO_BUSY:
    emit sendStatus("PICO_BUSY");
    break;
  case PICO_MEMORY:
    emit sendStatus("PICO_MEMORY");
    break;

  default:
    emit sendStatus("PICO_ERROR");
    break;
  }
}

void PicoScope::retrieveData() {
  std::cout << "Retrieving data" << std::endl;
  *noOfSamples = 2001;
  ps5000aGetValues(*handle, 0, noOfSamples, 1, PS5000A_RATIO_MODE_NONE, 0,
                   nullptr);
  emit sendMeasurement(bufferLength, bufferArray);
}

void PicoScope::readReady(int16_t handle, PICO_STATUS status,
                                       void *pParameter) {
  static_cast<PicoScope*>(pParameter)->finishSignal();
}
