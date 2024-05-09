#include "./meascontrolwidget.h"

MeasureControlWindow::MeasureControlWindow(QWidget *parent) : QFrame(parent) {
  initDefaultValues();
  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(resetZoom);
  layout->addWidget(showInstrumentControls);
  layout->addWidget(start);
  layout->addWidget(startpos);
  layout->addWidget(step);
  layout->addWidget(stepsize);
  layout->addWidget(stop);
  layout->addWidget(endpos);
  layout->addWidget(unitSelector);
  layout->addWidget(startMeasure);
  layout->addWidget(stopButton);
  layout->addWidget(saveName);
  layout->addWidget(saveButton);
  layout->setAlignment(Qt::AlignmentFlag::AlignTop);
  setupConnections();
  parameterFrame->setLayout(layout);
  QGridLayout *visLayout = new QGridLayout();
  visLayout->addWidget(chartView);
  visualizationFrame->setLayout(visLayout);
  QHBoxLayout *measureLayout = new QHBoxLayout();
  measureLayout->addWidget(visualizationFrame);
  measureLayout->addWidget(parameterFrame);
  setLayout(measureLayout);
}

void MeasureControlWindow::initDefaultValues() {
  startpos = new QLineEdit();
  endpos = new QLineEdit();
  stepsize = new QLineEdit();
  unitSelector = new QComboBox();
  unitSelector->addItems(QList<QString>({QString("mm"), QString("um")}));
  showInstrumentControls = new QPushButton("Show instrument controls");
  showInstrumentControls->setCheckable(true);
  start = new QLabel("Start Position");
  step = new QLabel("Step size");
  stop = new QLabel("End postition");
  parameterFrame = new QFrame();
  visualizationFrame = new QFrame();
  chart = new QChart();
  chartView = new QChartView(chart);
  chart->layout()->setContentsMargins(0, 0, 0, 0);
  chart->resize(640, 480);
  chartView->setRubberBand(QChartView::RectangleRubberBand);
  chartView->setRenderHint(QPainter::Antialiasing, true);
  parameterFrame->setFrameShape(QFrame::StyledPanel);
  parameterFrame->setFrameShadow(QFrame::Raised);
  parameterFrame->setLineWidth(3);
  parameterFrame->setMidLineWidth(3);
  parameterFrame->setFixedWidth(200);
  visualizationFrame->setFrameShape(QFrame::StyledPanel);
  visualizationFrame->setFrameShadow(QFrame::Raised);
  visualizationFrame->setLineWidth(3);
  visualizationFrame->setMidLineWidth(3);
  startMeasure = new QPushButton("Start measurement");
  coords = new std::vector<double>();
  measVals = new std::vector<double>();
  stopButton = new QPushButton("Stop and Reset");
  resetZoom = new QPushButton("Reset Zoom");
  saveButton = new QPushButton("Save data");
  saveName = new QLineEdit();
}

void MeasureControlWindow::setupConnections() {
  connect(unitSelector, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &MeasureControlWindow::sendCurrentIndex);
  connect(showInstrumentControls, &QPushButton::clicked, this,
          &MeasureControlWindow::showClicked);
  connect(startMeasure, &QPushButton::clicked, this,
          &MeasureControlWindow::startMeasProc);
  connect(stopButton, &QPushButton::clicked, this,
          &MeasureControlWindow::stopMeasProc);
  connect(resetZoom, &QPushButton::clicked, this,
          &MeasureControlWindow::resetZoomSlot);
  connect(saveButton, &QPushButton::clicked, this,
          &MeasureControlWindow::saveDataSlot);
}

void MeasureControlWindow::sendCurrentIndex(int index) {
  emit unitSelectorIndex(index);
}

void MeasureControlWindow::recUnitIndex(int index) {
  unitSelector->setCurrentIndex(index);
}
void MeasureControlWindow::showClicked() {
  emit instrumentVisibility(showInstrumentControls->isChecked());
}

void MeasureControlWindow::hideEvent(QHideEvent *event) { event->ignore(); }
void MeasureControlWindow::closeEvent(QCloseEvent *event) { event->ignore(); }

void MeasureControlWindow::startMeasProc() {
  double start, step, end, currentCoord;
  start = startpos->text().toDouble();
  step = stepsize->text().toDouble();
  end = endpos->text().toDouble();
  coords->clear();
  measVals->clear();
  currentCoord = start;
  while (currentCoord < end) {
    coords->push_back(currentCoord);
    currentCoord += step;
  }
  coords->push_back(end);
  emit requestStart(coords->at(0));
}

void MeasureControlWindow::recMeasPoint(double value) {
  measVals->push_back(value);
  plotResults();
  if (coords->size() > measVals->size()) {
    emit requestNextStep(coords->at(measVals->size()));
  } else {
    emit requestStop();
  }
}

void MeasureControlWindow::plotResults() {
  chart->removeAllSeries();
  QLineSeries *line = new QLineSeries();
  for (size_t i = 0; i < measVals->size(); i++) {
    line->append(coords->at(i), measVals->at(i));
  }
  chart->addSeries(line);
  chart->createDefaultAxes();
  chart->axisX()->setTitleText("Position (m)");
  chart->axisY()->setTitleText("Voltage (V)");
  chart->legend()->hide();
  chart->update();
}

void MeasureControlWindow::stopMeasProc() { emit requestStop(); }

void MeasureControlWindow::resetZoomSlot() { chart->zoomReset(); }

void MeasureControlWindow::saveDataSlot() {
  if (chart->series().isEmpty()) {
    return;
  } else {
    std::ofstream dataFile;
    dataFile.open(saveName->text().toStdString().c_str());
    QLineSeries *series = qobject_cast<QLineSeries *>(chart->series().last());
    QVector<QPointF> points = series->pointsVector();
    for (int i = 0; i < points.size(); i++) {
      dataFile << points.at(i).x() << ",\t" << points.at(i).y() << "\n";
    }
    dataFile.close();
  }
}
