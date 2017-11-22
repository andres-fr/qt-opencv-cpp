// This program starts a capture from the default
// connected cam and shows it in a window. Stop
// pressing ESC.



// TUTORIAL QT DESIGN WITH C++
// https://doc.qt.io/archives/2.3/designer/chap2_3.html

// 1. MAKE SOME NICE GUI WITH THE `designer` PROGRAM AND SAVE THE test.ui FILE
// 2. MAKE THE CORRESPONDING C++ FILE: uic -o test.cpp test.ui
// 3. add #include<iostream> at the top of test.cpp
// 4. add int main(){std::cout << "hello qt!!" << std::endl;} before QT_END_NAMESPACE
// 5. MAKE THE Q PROJECT FILE WITH THE FOLLOWING THREE LINES:
//        SOURCES += test.cpp
//        CONFIG += c++11
//        TARGET = test
// 6. PREMAKE: qmake test.pro
// 7. make
// 8. ./test


// Compile with:
// g++ -std=c++11 -Wall -Wextra webcam.cpp `pkg-config --cflags --libs opencv QtCore QtGui`  -o test && ./test


// STL INCLUDES
#include <iostream>
// LIBRARY INCLUDES
#include <opencv2/opencv.hpp>
#include <QtCore/QtCore>
#include <QtGui/QtGui>
// NAMESPACING
// using namespace cv;
// using namespace std;




QImage Mat2QImage(cv::Mat const& cvmat){
  return QImage((uchar*)cvmat.data,
                         cvmat.cols, cvmat.rows, cvmat.step,
                         QImage::Format_RGB888);
}


int main() {

  //device ID is 0 if you have only one camera.
  cv::VideoCapture stream1(0);
 
  if (!stream1.isOpened()) {
    std::cout << "cannot open camera" << std::endl;
  }
 
  while (true) {
    cv::Mat cameraFrame;
    stream1.read(cameraFrame);
    QImage x = Mat2QImage(cameraFrame);

    imshow("cam", cameraFrame);
    if (cv::waitKey(30) >= 0)
      break;
  }
  return 0;
}
