#include "./hostwindow.h"
#include "./scope.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  HostWindow w;
  w.show();
  return app.exec();
}
