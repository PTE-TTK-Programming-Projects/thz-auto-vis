#include "./scopewindow.h"

ScopeWindow::ScopeWindow(QWidget *parent) : QFrame(parent) {
  timeWindow = new double(1e-3);
  sensitivity = new double(5);
  avgRequest = new QLineEdit("0");
  avgRequestLabel = new QLabel("Averaging count: ");
  button = new QPushButton("Status");
  measurebutton = new QPushButton("Capture Single");
  liveButton = new QPushButton("Live view");
  liveButton->setCheckable(true);
  homeButton = new QPushButton("Reset Zoom");
  status = new QLineEdit("");
  status->setReadOnly(true);
  status->setMinimumWidth(200);
  status->setMaximumWidth(200);
  scope = new PicoScope();
  chart = new QChart();
  chartView = new QChartView(chart);
  chartView->setRubberBand(QChartView::RectangleRubberBand);
  chartView->setRenderHint(QPainter::Antialiasing, true);
  avgLine = new ScopeDataLine("Average: ", 0);
  ptpLine = new ScopeDataLine("Peak to peak: ", 0);
  coupling = new QComboBox();
  coupling->addItems(QStringList(QList<QString>({"AC", "DC"})));
  sens = new QComboBox();
  sens->addItems(QStringList(QList<QString>(
      {"10 mV", "50 mV", "100 mV", "500 mV", "1 V", "2 V", "5 V"})));
  sens->setCurrentIndex(6);
  windowLength = new QComboBox();
  windowLength->addItems(QStringList(QList<QString>(
      {"1 ms", "5 ms", "10 ms", "100 ms", "500 ms", "1000 ms"})));
  triggerRatio = new QComboBox();
  triggerRatio->addItems(
      QStringList(QList<QString>({"1%", "5%", "10%", "External"})));
  QVBoxLayout *Llayout = new QVBoxLayout();
  QVBoxLayout *Rlayout = new QVBoxLayout();
  QHBoxLayout *setupBox = new QHBoxLayout();
  QHBoxLayout *setupBox2 = new QHBoxLayout();
  QHBoxLayout *avgBox = new QHBoxLayout();
  QHBoxLayout *glued = new QHBoxLayout();
  Rlayout->addWidget(homeButton);
  Rlayout->addWidget(measurebutton);
  Rlayout->addWidget(liveButton);
  setupBox->addWidget(coupling);
  setupBox->addWidget(sens);
  setupBox2->addWidget(windowLength);
  setupBox2->addWidget(triggerRatio);
  avgBox->addWidget(avgRequestLabel);
  avgBox->addWidget(avgRequest);
  Rlayout->addLayout(setupBox);
  Rlayout->addLayout(setupBox2);
  Rlayout->addLayout(avgBox);
  Rlayout->addWidget(button);
  Rlayout->addWidget(status);
  Rlayout->addWidget(avgLine);
  Rlayout->addWidget(ptpLine);
  Llayout->addWidget(chartView);
  Rlayout->setAlignment(Qt::AlignmentFlag::AlignTop);
  QWidget *RWidget = new QWidget();
  RWidget->setLayout(Rlayout);
  RWidget->setFixedWidth(250);
  glued->addLayout(Llayout);
  glued->addWidget(RWidget);
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
  connect(coupling, QOverload<int>::of(&QComboBox::currentIndexChanged), this,
          &ScopeWindow::sendSetup);
  connect(sens, QOverload<int>::of(&QComboBox::currentIndexChanged), this,
          &ScopeWindow::sendSetup);
  connect(this, &ScopeWindow::setScopeChannel, scope,
          &PicoScope::setScopeChannel);
  connect(windowLength, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &ScopeWindow::sendTime);
  connect(triggerRatio, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &ScopeWindow::sendRatio);
  connect(this, &ScopeWindow::setTriggerThreshold, scope,
          &PicoScope::setTriggerRatio);
  connect(this, &ScopeWindow::setTimeBase, scope, &PicoScope::setTimeWindow);
  connect(avgRequest, &QLineEdit::textChanged, scope, &PicoScope::setAvgRqst);
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
  // std::cout << *bufferSize << " data points recieved for plotting" <<
  // std::endl;
  double sum = 0;
  int16_t min = buffer[0], max = buffer[0];
  chart->removeAllSeries();
  QLineSeries *line = new QLineSeries;
  for (int32_t i = 0; i < *bufferSize; i++) {
    line->append(static_cast<double>(i - 1000) / 2001 * *timeWindow,
                 static_cast<double>(buffer[i]) / 32767 * *sensitivity);
    sum += static_cast<double>(buffer[i]);
    if (buffer[i] > max) {
      max = buffer[i];
    }
    if (buffer[i] < min) {
      min = buffer[i];
    }
  }
  avgLine->newData(sum / static_cast<double>(*bufferSize) / 32767 *
                   *sensitivity);
  emit sendAvg(avgLine->readData());
  ptpLine->newData(static_cast<double>(max - min) / 32767 * *sensitivity);
  emit sendPtp(ptpLine->readData());
  chart->addSeries(line);
  chart->createDefaultAxes();
  chart->axisX()->setTitleText("Time (s)");
  chart->axisY()->setTitleText("Voltage (V)");
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

void ScopeWindow::sendSetup() {
  emit setScopeChannel(coupling->currentIndex(), sens->currentIndex());
  switch (sens->currentIndex()) {
  case 0:
    *sensitivity = 10e-3;
    break;
  case 1:
    *sensitivity = 50e-3;
    break;
  case 2:
    *sensitivity = 100e-3;
    break;
  case 3:
    *sensitivity = 500e-3;
    break;
  case 4:
    *sensitivity = 1000e-3;
    break;
  case 5:
    *sensitivity = 2000e-3;
    break;
  case 6:
    *sensitivity = 5000e-3;
    break;
  }
}

void ScopeWindow::sendTime() {
  switch (windowLength->currentIndex()) {
  case 0:
    emit setTimeBase(34);
    *timeWindow = 1e-3;
    break;
  case 1:
    emit setTimeBase(159);
    *timeWindow = 5e-3;
    break;
  case 2:
    emit setTimeBase(315);
    *timeWindow = 10e-3;
    break;
  case 3:
    emit setTimeBase(2979);
    *timeWindow = 100e-3;
    break;
  case 4:
    emit setTimeBase(14884);
    *timeWindow = 500e-3;
    break;
  case 5:
    emit setTimeBase(29765);
    *timeWindow = 1000e-3;
    break;
  }
}

void ScopeWindow::sendRatio() {
  switch (triggerRatio->currentIndex()) {
  case 0:
    emit setTriggerThreshold(100);
    break;
  case 1:
    emit setTriggerThreshold(20);
    break;
  case 2:
    emit setTriggerThreshold(10);
    break;
  case 3:
    setTriggerThreshold(-1);
    break;
  }
}

void ScopeWindow::extMeasure(){
  scope->measure();
}
