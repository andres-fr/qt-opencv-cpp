// This program starts a capture from the default
// connected cam and shows it in a QT window. Stop
// pressing ESC.


// PIPELINE:
// mkdir -p build && uic -o build/design.h DESIGN.ui && echo -e "VPATH += VPATH += ../\nSOURCES += MAIN.cpp\nHEADERS += build/design.h include/webcam.h\nCONFIG += c++11\nTARGET = bin/main\nQT += widgets gui\nLIBS += \`pkg-config --cflags --libs opencv\`" > build/main.pro && qmake build/main.pro -o build/Makefile && make -C build/ clean && make -C build/ && build/bin/main



#include "include/webcam.h"

int main(int argc, char** argv){
  // lets add some barcharts!


  // The OpenCV+Qt integrated version
  // instantiate QT application and main window
  QApplication app(argc, argv);
  QMainWindow* window = new QMainWindow;
  // assign our QtWebCam to the main window
  QtWebCam cam(window);
  // show the window and start main loop!
  window->show();
  return app.exec();
}
