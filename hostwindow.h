#ifndef HOST_WINDOW
#define HOST_WINDOW

#include <QtWidgets>
#include "./scope.h"

class HostWindow : public QWidget {
  Q_OBJECT;

public:
  HostWindow(QWidget *parent = nullptr);
private:
  QPushButton *button;
  QLineEdit *status;
  PicoScope *scope;
};

#endif // HOST_WINDOW
