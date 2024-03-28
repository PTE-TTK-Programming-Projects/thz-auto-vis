#ifndef HOST_WIN
#define HOST_WIN

#include "./scopewindow.h"

class HostWindow : public QWidget {
  Q_OBJECT

public:
  HostWindow(QWidget *parent = nullptr);

private:
  ScopeWindow *scopeWin;
};

#endif // HOST_WIN
