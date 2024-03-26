#ifndef HOST_WINDOW
#define HOST_WINDOW

#include "./scope.h"
#include <QtWidgets>
#include <string>

class HostWindow : public QWidget {
  Q_OBJECT;

public:
  HostWindow(QWidget *parent = nullptr);
private slots:
  void showStatus(std::string status);

private:
  QPushButton *button;
  QLineEdit *status;
  PicoScope *scope;
};

#endif // HOST_WINDOW
