// This program starts a capture from the default
// connected cam and shows it in a window. Stop
// pressing ESC.

// just compile and run:
//  qmake webcam.pro && make clean && make && ./webcam

// Render, Compile and run with:
// uic -o design.h DESIGN.ui && echo -e "SOURCES += WEBCAM.cpp\nHEADERS += design.h webcam.h\nCONFIG += c++11\nTARGET = webcam\nQT += widgets gui\nLIBS += \`pkg-config --cflags --libs opencv\`" > webcam.pro && qmake webcam.pro && make clean && make && ./webcam

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
#include "webcam.h"

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

  // // connect
  // QTimer timer;
  // QObject::connect(&timer, SIGNAL(timeout()), ui.checkBox, SLOT(ui.checkBox->toggle()));  timer.start(500);


  // run QTApp
  ui.label->setPixmap(ui.grabPixmap());





  window->show();
  return app.exec();
}
