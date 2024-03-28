#include "./scope.h"

PicoScope::PicoScope() : QObject() {
  ready = new int16_t;
  polltimer = new QTimer;
  polltimer->setInterval(100);
  handle = new int16_t;
  status = new PICO_STATUS;
  timeTookMS = new int32_t;
  bufferLength = new int32_t(2000);
  noOfSamples = new uint32_t(2000);
  bufferArray = new int16_t[2000];
  *status = ps5000aOpenUnit(handle, nullptr, PS5000A_DR_12BIT);
  if (*status == PICO_POWER_SUPPLY_NOT_CONNECTED) {
    ps5000aChangePowerSource(*handle, *status);
  }
  maxValue = new int16_t;
  ps5000aMaximumValue(*handle, maxValue);
  ps5000aSetChannel(*handle, PS5000A_CHANNEL_A, 1, PS5000A_AC, PS5000A_10MV, 0);
  ps5000aSetSimpleTrigger(
      *handle, 1, PS5000A_CHANNEL::PS5000A_CHANNEL_A, *maxValue / 10,
      PS5000A_THRESHOLD_DIRECTION::PS5000A_FALLING, 0, 1000);
  ps5000aSetDataBuffer(*handle, PS5000A_CHANNEL_A, bufferArray, *bufferLength,
                       0, PS5000A_RATIO_MODE_NONE);
  connect(polltimer, &QTimer::timeout, this, &PicoScope::pollMeasurement);
  connect(this, &PicoScope::finishSignal, this, &PicoScope::retrieveData);
}

void PicoScope::measure() {
  ps5000aRunBlock(*handle, 1000, 1000, 32, timeTookMS, 0, nullptr, nullptr);
  polltimer->start();
}

void PicoScope::getStatus() {
  std::cout << "Status fetching reached" << std::endl;
  *status = ps5000aPingUnit(*handle);
  switch (*status) {
  case 0:
    emit sendStatus("PICO_OK");
    break;

  default:
    emit sendStatus("PICO_NOT_OK");
    break;
  }
}

void PicoScope::pollMeasurement() {
  ps5000aIsReady(*handle, ready);
  if (*ready != 0) {
    polltimer->stop();
    emit finishSignal();
  }
}

void PicoScope::retrieveData() {
  std::cout << "Retrieving data" << std::endl;
  *noOfSamples = 2000;
  ps5000aGetValues(*handle, 0, noOfSamples, 1, PS5000A_RATIO_MODE_NONE, 0,
                   nullptr);
  emit sendStatus("Measurement data recieved");
  emit sendMeasurement(bufferLength, bufferArray);
}
