#include "./scopewindow.h"
#include "./scope.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  ScopeWindow w;
  w.show();
  return app.exec();
}
