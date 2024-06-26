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
  void sendSetup();
  void sendTime();
  void sendRatio();

  signals:
  void chartingFinished();
  void setScopeChannel(int couplingIDX, int sensIDX);
  void setTriggerThreshold(int16_t divisor);
  void setTimeBase(uint32_t timeBase);

private:
  QPushButton *button, *measurebutton, *liveButton, *homeButton;
  QLineEdit *status, *avgRequest;
  QLabel *avgRequestLabel;
  PicoScope *scope;
  QChartView *chartView;
  QChart *chart;
  ScopeDataLine *avgLine, *ptpLine;
  QComboBox *coupling, *sens;
  QComboBox *windowLength, *triggerRatio;
  double *timeWindow, *sensitivity;
};


#endif // HOST_WINDOW
