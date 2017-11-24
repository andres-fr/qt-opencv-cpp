// This file contains two classes:
// - QtWebCam: grabs video from a webcam via OpenCV and shows it on a Qt GUI
// - CvWebCam: minimal class that grabs and shows webcam using just OpenCV
// And can be run with the following main.cpp:
//
// #include "include/webcam.h"
// int main(int argc, char** argv){
//   const bool kWithCV = true;
//   if(kWithCV)
//     { // The plain OpenCV version (test/debug)
//       CvWebCam cam;
//       cam.start();
//       return 0;
//     }
//   else
//     { // The OpenCV+Qt integrated version
//       // instantiate QT application and main window
//       QApplication app(argc, argv);
//       QMainWindow* window = new QMainWindow;
//       // assign our QtWebCam to the main window
//       QtWebCam cam(window);
//       // show the window and start main loop!
//       window->show();
//       return app.exec();
//     }
// }

#ifndef WEBCAM_H
#define WEBCAM_H

// STL INCLUDES
#include <iostream>
#include <stdexcept>
// LOCAL INCLUDES
#include "design.h"
// LIBRARY INCLUDES
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
//
#include <QtGui/QPixmap>
#include <QtCore/QTimer>



// This is a basic working example for showing a cam in a QT gui:
// It inherites from QObject to provide connections to other widgets,
// And from the MainWindow generated by the uic program from the
// designed GUI, to populate any given QT window with the desired widgets.
class QtWebCam : public QObject, public Ui::MainWindow{

  Q_OBJECT // needed by every QObject that uses slots

private slots: // this slot can be used in the QObject::connect method
  void update(){this->label->setPixmap(grabPixmap());}

private:
  QMainWindow* window_;
  cv::VideoCapture cv_cam_;
  cv::Mat cv_mat_;
  QTimer timer_;

public:
  // Constructor: given a reference to a QT window, an index for OpenCV to
  // access a cam, and a refresh rate in miliseconds, this method:
  // 1) opens a stream from the given camera, or throws an exception else
  // 2) populates the window with the widgets inherited from MainWindow
  // 3) sets a trigger that refreshes the "label" widget with the cam contents
  //    at the given rate in miliseconds (0 means as fast as possible).
  QtWebCam(QMainWindow* w, const size_t cam_idx=0, const size_t refresh_ms=0)
    : window_(w), cv_cam_(cam_idx){ // init list tries to open cam stream
    if (!cv_cam_.isOpened()) {      // an error will be thrown else
      throw std::runtime_error("[ERROR] QtWebCam: CV can't open camera");
    }
    // the inherited setup method populates the window with the widgets
    this->setupUi(w);
    // This connection+timer is responsible for refreshing the cam
    QObject::connect(&timer_, SIGNAL(timeout()), this, SLOT(update()));
    timer_.start(refresh_ms);
    // This line makes the app start much faster (no idea why)
    this->label->setPixmap(grabPixmap());
  }

  // This method grabs a single, current frame from the cam stream opened
  // by the constructor and returns it as a QPixmap, the preferred way
  // for feeding QT widgets.
  QPixmap grabPixmap(){
    cv_cam_.read(cv_mat_);
    cv::cvtColor(cv_mat_, cv_mat_, cv::COLOR_BGR2RGB);
    return QPixmap::fromImage(QImage((uchar*)cv_mat_.data,
                                     cv_mat_.cols, cv_mat_.rows, cv_mat_.step,
                                     QImage::Format_RGB888));
  }
};

////////////////////////////////////////////////////////////////////////////////

// This is a minimal working example for showing a cam in OpenCV.
// Kept for doc/debugging purposes
struct CvWebCam{
  cv::VideoCapture cam_stream_;
  cv::Mat frame_;
  // Constructor: given a cam idx opens the stream to that cam or error else
  CvWebCam(const size_t cam_idx=0)
    : cam_stream_(cam_idx){
    if (!cam_stream_.isOpened()){std::cout << "can't open camera" << std::endl;}
  }
  // Start: infinite loop that grabs frames from the cam as fast as possible
  // and plots them to a window. Can be interrupted pressing ESC.
  void start(){
    while (true) {
      cam_stream_.read(frame_);
      imshow("cam", frame_);
      if (cv::waitKey(30) >= 0){break;}}
  }
};



#endif // WEBCAM_H
