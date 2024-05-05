#ifndef HOST_WIN
#define HOST_WIN

#include "./meascontrolwidget.h"
#include "./scopewindow.h"
#include "./zaberwindow.h"

class HostWindow : public QWidget {
  Q_OBJECT

public:
  HostWindow(QWidget *parent = nullptr);

private:
  ScopeWindow *scopeWin;
  ZaberWindow *zaberWin;
  MeasureControlWindow *conWin;
  QFrame *instrumentPanel;

private slots:
  void visChanged(bool isChecked);
  void controlHidden();
};

#endif // HOST_WIN
