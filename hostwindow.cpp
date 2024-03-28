#include "./hostwindow.h"

HostWindow::HostWindow(QWidget *parent) : QWidget(parent) {
  button = new QPushButton("Status");
  measurebutton = new QPushButton("Measure");
  status = new QLineEdit("");
  scope = new PicoScope();
  chart = new QChart();
  chartView = new QChartView(chart);
  QVBoxLayout *Llayout = new QVBoxLayout();
  QVBoxLayout *Rlayout = new QVBoxLayout();
  QHBoxLayout *glued = new QHBoxLayout();
  Rlayout->addWidget(button);
  Rlayout->addWidget(measurebutton);
  Rlayout->addWidget(status);
  Llayout->addWidget(chartView);
  glued->addLayout(Llayout);
  glued->addLayout(Rlayout);
  setLayout(glued);
  chart->resize(640, 480);
  chart->createDefaultAxes();
  connect(button, &QPushButton::clicked, scope, &PicoScope::getStatus);
  connect(measurebutton, &QPushButton::clicked, scope, &PicoScope::measure);
  connect(scope, &PicoScope::sendStatus, this, &HostWindow::showStatus);
  connect(scope, &PicoScope::sendMeasurement, this,
          &HostWindow::showMeasurementData);
}

void HostWindow::showStatus(std::string status) {
  this->status->setText(status.c_str());
}

void HostWindow::showMeasurementData(int32_t *bufferSize, int16_t *buffer) {
  std::cout << *bufferSize << " data points recieved for plotting" << std::endl;
  chart->removeAllSeries();
  QLineSeries *line = new QLineSeries;
  for (int32_t i = 0; i < *bufferSize; i++) {
    line->append(i-1000, buffer[i]);
  }
  chart->addSeries(line);
  chart->update();
  chart->createDefaultAxes();
}
