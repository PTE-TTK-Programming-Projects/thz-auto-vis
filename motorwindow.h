#ifndef MOTORWINDOW
#define MOTORWINDOW

#include <QWidgets>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>



class MotorWindow : public QWidget {
  Q_OBJECT;

public:
  MotorWindow(QWidget *parent = nullptr);

private:
  QGridLayout *grid;

  QPushButton *btn1;
  QLabel *lb1;
  QLineEdit *edit1;
};
#endif
