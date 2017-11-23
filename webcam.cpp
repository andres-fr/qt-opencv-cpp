// This program starts a capture from the default
// connected cam and shows it in a window. Stop
// pressing ESC.


// make all and run with:
// uic -o design.h DESIGN.ui && echo -e "SOURCES += WEBCAM.cpp\nHEADERS += design.h\nCONFIG += c++11\nTARGET = webcam\nQT += widgets" > webcam.pro && qmake webcam.pro && make && ./webcam

// LIBRARY INCLUDES
#include <opencv2/opencv.hpp>
#include "design.h"


QImage Mat2QImage(cv::Mat const& cvmat){
  return QImage((uchar*)cvmat.data,
                         cvmat.cols, cvmat.rows, cvmat.step,
                         QImage::Format_RGB888);
}


int main(int argc, char** argv){

  QApplication app(argc, argv);
  QMainWindow* q = new QMainWindow;
  Ui::MainWindow ui;
  ui.setupUi(q);
  q->show();
  return app.exec();
}



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
