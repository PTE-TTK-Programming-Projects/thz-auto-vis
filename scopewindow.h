#ifndef HOST_WINDOW
#define HOST_WINDOW

#include "./scope_data_line.h"
#include "./scope.h"
#include <QtCharts>
#include <QtWidgets>
#include <string>

class ScopeWindow : public QFrame {
  Q_OBJECT;

public:
  ScopeWindow(QWidget *parent = nullptr);
private slots:
  void showStatus(std::string status);
  void showMeasurementData(int32_t *bufferSize, int16_t *buffer);
  void resetZoom();
  void liveRequest(bool isLive);

  signals:
  void chartingFinished();

private:
  QPushButton *button, *measurebutton, *liveButton, *homeButton;
  QLineEdit *status;
  PicoScope *scope;
  QChartView *chartView;
  QChart *chart;
  ScopeDataLine *avgLine, *ptpLine;
};


#endif // HOST_WINDOW
