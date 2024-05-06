#include "./meascontrolwidget.h"

MeasureControlWindow::MeasureControlWindow(QWidget *parent) : QFrame(parent) {
  initDefaultValues();
  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(showInstrumentControls);
  layout->addWidget(start);
  layout->addWidget(startpos);
  layout->addWidget(step);
  layout->addWidget(stepsize);
  layout->addWidget(stop);
  layout->addWidget(endpos);
  layout->addWidget(unitSelector);
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
  step = new QLabel("Stepping distance");
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
}

void MeasureControlWindow::setupConnections() {
  connect(unitSelector, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &MeasureControlWindow::sendCurrentIndex);
  connect(showInstrumentControls, &QPushButton::clicked, this,
          &MeasureControlWindow::showClicked);
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
