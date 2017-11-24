#ifndef INTEGRATED_GUI_H
#define INTEGRATED_GUI_H

// STL INCLUDES
#include <iostream>
#include <stdexcept>
// LIBRARY INCLUDES
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
//
#include <QtGui/QPixmap>
// LOCAL INCLUDES
#include "barchart.hpp"
#include "webcam.hpp"

class IntegratedGui : public QtWebCam {
  Q_OBJECT
protected slots:
  void updateRgbChart() {
    xxx = (xxx+1)%100;
    setPixmapScaled(this->label_2, chart_.getChart(xxx, 110, 90));
  }
protected:
  QtRgbChart chart_;
  size_t xxx;
public:
  IntegratedGui(QMainWindow* w, const size_t cam_idx=0)
    : QtWebCam(w, cam_idx),
      chart_(400, 170, 3, Qt::black, QColor(200,200,200), 30, 0.8, 50, -10){
    xxx = 0;
    QObject::connect(&timer_, SIGNAL(timeout()), this, SLOT(updateRgbChart()));
    updateRgbChart();
  }
};

#endif // INTEGRATED_GUI_H
