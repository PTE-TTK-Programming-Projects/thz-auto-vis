#ifndef HOST_WIN
#define HOST_WIN

#include "./scopewindow.h"
#include "./zaberwindow.h"
#include "./meascontrolwidget.h"

class HostWindow : public QWidget {
  Q_OBJECT

public:
  HostWindow(QWidget *parent = nullptr);

private:
  ScopeWindow *scopeWin;
  ZaberWindow *zaberWin;
  MeasureControlWindow *conWin;
};

#endif // HOST_WIN
