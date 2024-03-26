#include "./scope.h"

PicoScope::PicoScope() : QObject() {
  handle = new int16_t;
  status = new PICO_STATUS;
  *status = ps5000aOpenUnit(handle, nullptr, PS5000A_DR_12BIT);
  if (*status == PICO_POWER_SUPPLY_NOT_CONNECTED) {
    ps5000aChangePowerSource(*handle, *status);
  }
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
