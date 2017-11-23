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


// This is a minimal working example for showing a cam in a QT gui.
class WebCam : public QObject, public Ui::MainWindow{ //  public QObject,
  Q_OBJECT // if this
public slots:
  void update(){this->label->setPixmap(grabPixmap());}
private:
  QMainWindow* window_;
  cv::VideoCapture cv_cam_;
  cv::Mat cv_mat_;
  QTimer timer_;
public:
  QPixmap qp;
  WebCam(QMainWindow* w, const size_t cam_idx=0, const size_t refresh_ms=0)
    : window_(w), cv_cam_(cam_idx){ // init list tries to open cam stream
    if (!cv_cam_.isOpened()) {
      throw std::runtime_error("[ERROR] WebCam: CV can't open camera");
    }
    // the inherited setup method populates the window with the widgets
    this->setupUi(w);
    //
    QObject::connect(&timer_, SIGNAL(timeout()), this, SLOT(update()));
    timer_.start(refresh_ms);
  }
  QPixmap grabPixmap(){
    cv_cam_.read(cv_mat_);
    cv::cvtColor(cv_mat_, cv_mat_, cv::COLOR_BGR2RGB);
    return QPixmap::fromImage(QImage((uchar*)cv_mat_.data,
                                     cv_mat_.cols, cv_mat_.rows, cv_mat_.step,
                                     QImage::Format_RGB888));
  }

};



#endif // WEBCAM_H
