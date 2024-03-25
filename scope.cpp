#include "./scope.h"

PicoScope::PicoScope() : QObject() {
  handle = new int16_t;
  status = new PICO_STATUS;
  *status = ps5000aOpenUnit(handle,nullptr,PS5000A_DR_12BIT);
  if (*status == PICO_POWER_SUPPLY_NOT_CONNECTED){
    ps5000aChangePowerSource(*handle,*status);
  }

}

void PicoScope::getStatus(){
  std::cout << "Status fetching reached" << std::endl;
}
