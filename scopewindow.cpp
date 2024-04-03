#include "./scopewindow.h"

ScopeWindow::ScopeWindow(QWidget *parent) : QFrame(parent) {
  button = new QPushButton("Status");
  measurebutton = new QPushButton("Capture Single");
  liveButton = new QPushButton("Live view");
  liveButton->setCheckable(true);
  homeButton = new QPushButton("Reset Zoom");
  status = new QLineEdit("");
  status->setReadOnly(true);
  status->setMinimumWidth(200);
  scope = new PicoScope();
  chart = new QChart();
  chartView = new QChartView(chart);
  chartView->setRubberBand(QChartView::RectangleRubberBand);
  chartView->setRenderHint(QPainter::Antialiasing, true);
  avgLine = new ScopeDataLine("Average: ", 0);
  ptpLine = new ScopeDataLine("Peak to peak: ", 0);

  QVBoxLayout *Llayout = new QVBoxLayout();
  QVBoxLayout *Rlayout = new QVBoxLayout();
  QHBoxLayout *glued = new QHBoxLayout();
  Rlayout->addWidget(homeButton);
  Rlayout->addWidget(measurebutton);
  Rlayout->addWidget(liveButton);
  Rlayout->addWidget(button);
  Rlayout->addWidget(status);
  Rlayout->addWidget(avgLine);
  Rlayout->addWidget(ptpLine);
  Llayout->addWidget(chartView);
  Rlayout->setAlignment(Qt::AlignmentFlag::AlignTop);
  glued->addLayout(Llayout);
  glued->addLayout(Rlayout);
  setLayout(glued);
  chart->layout()->setContentsMargins(0, 0, 0, 0);
  chart->resize(640, 480);
  chart->createDefaultAxes();
  connect(button, &QPushButton::clicked, scope, &PicoScope::getStatus);
  connect(measurebutton, &QPushButton::clicked, scope, &PicoScope::measure);
  connect(scope, &PicoScope::sendStatus, this, &ScopeWindow::showStatus);
  connect(scope, &PicoScope::sendMeasurement, this,
          &ScopeWindow::showMeasurementData);
  connect(homeButton, &QPushButton::clicked, this, &ScopeWindow::resetZoom);
  connect(liveButton, &QPushButton::toggled, this, &ScopeWindow::liveRequest);
  setFrameShape(QFrame::StyledPanel);
  setFrameShadow(QFrame::Raised);
  setLineWidth(3);
  setMidLineWidth(3);
}

void ScopeWindow::showStatus(std::string status) {
  this->status->setText(status.c_str());
}

void ScopeWindow::resetZoom() { chart->zoomReset(); }

void ScopeWindow::showMeasurementData(int32_t *bufferSize, int16_t *buffer) {
  std::cout << *bufferSize << " data points recieved for plotting" << std::endl;
  double sum = 0;
  int16_t min = buffer[0], max = buffer[0];
  chart->removeAllSeries();
  QLineSeries *line = new QLineSeries;
  for (int32_t i = 0; i < *bufferSize; i++) {
    line->append(i - 1000, buffer[i]);
    sum += static_cast<double>(buffer[i]);
    if (buffer[i] > max) {
      max = buffer[i];
    }
    if (buffer[i] < min) {
      min = buffer[i];
    }
  }
  avgLine->newData(sum / static_cast<double>(*bufferSize));
  ptpLine->newData(static_cast<double>(max - min));
  chart->addSeries(line);
  chart->createDefaultAxes();
  chart->legend()->hide();
  chart->update();
  emit chartingFinished();
}

void ScopeWindow::liveRequest(bool isLive) {
  if (isLive) {
    measurebutton->setDisabled(true);
    connect(this, &ScopeWindow::chartingFinished, scope, &PicoScope::measure);
    scope->measure();
  } else {
    measurebutton->setDisabled(false);
    disconnect(this, &ScopeWindow::chartingFinished, scope,
               &PicoScope::measure);
  }
}
