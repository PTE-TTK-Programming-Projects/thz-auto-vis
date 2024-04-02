#ifndef HOST_WIN
#define HOST_WIN

#include "./scopewindow.h"
#include "./zaberwindow.h"

class HostWindow : public QWidget {
  Q_OBJECT

public:
  HostWindow(QWidget *parent = nullptr);

private:
  ScopeWindow *scopeWin;
  ZaberWindow *zaberWin;
};

#endif // HOST_WIN
