// This program starts a capture from the default
// connected cam and shows it in a window. Stop
// pressing ESC.


// PIPELINE:
// mkdir -p build && uic -o build/design.h DESIGN.ui && echo -e "VPATH += VPATH += ../\nSOURCES += MAIN.cpp\nHEADERS += build/design.h include/webcam.h\nCONFIG += c++11\nTARGET = bin/main\nQT += widgets gui\nLIBS += \`pkg-config --cflags --libs opencv\`" > build/main.pro && qmake build/main.pro -o build/Makefile && make -C build/ && build/bin/main


// STL INCLUDES
#include <iostream>
#include <stdexcept>
// LIBRARY INCLUDES
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
// #include <opencv2/opencv.hpp>
// #include "design.h"
// #include <QtGui/QPixmap>
// #include <QtCore/QTimer>
#include "include/webcam.h"

////////////////////////////////////////////////////////////////////////////////

// This is a minimal working example for showing a cam in opencv.
// Run with:     int main(){CvCamTest x; x.start(); return 0;}
struct CvCamTest{
  cv::VideoCapture cam_stream_;
  cv::Mat frame_;
  CvCamTest(const size_t cam_idx=0)
    : cam_stream_(cam_idx){
    if (!cam_stream_.isOpened()){std::cout << "can't open camera" << std::endl;}
  }
  QImage mat2QImage(cv::Mat const& cvmat){
    return QImage((uchar*)cvmat.data, cvmat.cols, cvmat.rows, cvmat.step,
                  QImage::Format_RGB888);
  }
  void start(){
    while (true) {
      cam_stream_.read(frame_);
      imshow("cam", frame_);
      if (cv::waitKey(30) >= 0){break;}}
  }
};

////////////////////////////////////////////////////////////////////////////////
/// MAIN ROUTINE
// int main(){CvCamTest x; x.start(); return 0;}
////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv){

  // instantiate QT application and main window
  QApplication app(argc, argv);
  QMainWindow* window = new QMainWindow;

  // start the webcam QT app on the main window
  WebCam ui(window);//, cam_stream);

  // run QTApp
  ui.label->setPixmap(ui.grabPixmap());





  window->show();
  return app.exec();
}
