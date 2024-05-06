#ifndef DATA_LINE
#define DATA_LINE

#include <QtWidgets>

class ScopeDataLine : public QWidget{
  Q_OBJECT;

public:
  ScopeDataLine(std::string dataName = "Data", double value = 0, QWidget *parent = nullptr);
  double readData();

public slots:
void newData(double value);

private:
  QLabel *dataName;
  QLineEdit *dataValue;
  double *data;
};

#endif
