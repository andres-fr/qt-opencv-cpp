// This program starts a capture from the default
// connected cam and shows it in a window. Stop
// pressing ESC.

// just compile and run:
//  qmake webcam.pro && make clean && make && ./webcam

// Render, Compile and run with:
// uic -o design.h DESIGN.ui && echo -e "SOURCES += WEBCAM.cpp\nHEADERS += design.h\nCONFIG += c++11\nTARGET = webcam\nQT += widgets gui\nLIBS += \`pkg-config --cflags --libs opencv\`" > webcam.pro && qmake webcam.pro && make clean && make && ./webcam

// STL INCLUDES
#include <stdexcept>
// LIBRARY INCLUDES
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
// #include <opencv2/opencv.hpp>
#include "design.h"
#include <QtGui/QPixmap>
#include <QtCore/QTimer>

QPixmap Cam2Pixmap(cv::VideoCapture cam_stream){
  cv::Mat m;
  cam_stream.read(m);
  QImage qi((uchar*)m.data, m.cols, m.rows, m.step,
            QImage::Format_RGB888);
  return QPixmap::fromImage(qi);
}



class WebCam : public Ui::MainWindow{
public:
  QPixmap qp;
  cv::VideoCapture cam_;
  WebCam(cv::VideoCapture const& cam)
    : cam_(cam){
  }
  void test(){

  }
};


int main(int argc, char** argv){

  //device ID is 0 if you have only one camera.
  cv::VideoCapture cam_stream(0);
  if (!cam_stream.isOpened()) {
    throw std::runtime_error("[ERROR]: CV can't open camera");
  }

  // instantiate QT application and main window
  QApplication app(argc, argv);
  QMainWindow* q = new QMainWindow;
  //Ui::MainWindow ui;
  WebCam ui(cam_stream);

  // // fill main window with desired data
  // QPixmap qp = Cam2Pixmap(cam_stream);
  // ui.label->setPixmap(qp);

  cv::Mat m;
  cam_stream.read(m);
  cv::cvtColor(m, m, cv::COLOR_BGR2RGB);
  QImage qi((uchar*)m.data, m.cols, m.rows, m.step,
            QImage::Format_RGB888);
  ui.qp = QPixmap::fromImage(qi);
  // run QTapp
  ui.setupUi(q);

  ui.label->setPixmap(ui.qp);

  q->show();
  return app.exec();
}


// refresh: qtimer


// int main() {

//   //device ID is 0 if you have only one camera.
//   cv::VideoCapture stream1(0);

//   if (!stream1.isOpened()) {
//     std::cout << "cannot open camera" << std::endl;
//   }

//   while (true) {
//     cv::Mat cameraFrame;
//     stream1.read(cameraFrame);
//     QImage x = Mat2QImage(cameraFrame);

//     imshow("cam", cameraFrame);
//     if (cv::waitKey(30) >= 0)
//       break;
//   }
//   return 0;
// }
