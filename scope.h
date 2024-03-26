#ifndef SCOPE_QT
#define SCOPE_QT
#include <QtWidgets>
#include <iostream>
#include <string>
#include <ps5000aWrap.h>

class PicoScope : public QObject {
  Q_OBJECT;

public:
  PicoScope();
private:
  int16_t *handle;
  PICO_STATUS *status;
private slots:

public slots:
  void getStatus();
signals:
  void sendStatus(std::string status);
};

#endif // SCOPE_QT
