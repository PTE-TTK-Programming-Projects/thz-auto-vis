#ifndef HOST_WINDOW
#define HOST_WINDOW

#include "./scope.h"
#include <QtCharts>
#include <QtWidgets>
#include <string>

class HostWindow : public QWidget {
  Q_OBJECT;

public:
  HostWindow(QWidget *parent = nullptr);
private slots:
  void showStatus(std::string status);
  void showMeasurementData(int32_t *bufferSize, int16_t *buffer);
  void resetZoom();

private:
  QPushButton *button, *measurebutton, *homeButton;
  QLineEdit *status;
  PicoScope *scope;
  QChartView *chartView;
  QChart *chart;
};

#endif // HOST_WINDOW
