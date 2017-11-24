#ifndef BARCHART_H
#define BARCHART_H

#include <QtGui/QImage>
#include <QtGui/QPixmap>
#include <QtGui/QColor>
#include <QtGui/QPainter>
#include <QtGui/QPainterPath>
#include <QtGui/QPen>
#include <QtCore/QRect>


class QtRgbChart : public QObject {
  Q_OBJECT
private:
  size_t w_;
  size_t h_;
  size_t bar_size_;
  size_t gap_size_;
  QImage img_;
  QPainter painter_;
  QColor border_color_;
  QColor background_color_;
  QPen pen_;
  size_t font_size_;
  size_t bar_horiz_offset_;
  size_t label_vert_offset_;
public:
  QtRgbChart(const size_t w, const size_t h,
             const size_t border_width=1,
             const QColor border_color=Qt::black,
             const QColor background_color=QColor(0,0,0,255),
             const size_t font_size=20,
             const float  bar_thickness=0.9,
             const size_t bar_horiz_offset=50,
             const size_t label_vert_offset=0)
    : w_(w), h_(h),
      bar_size_(h*bar_thickness/3),
      gap_size_((h-3*bar_size_)/4),
      img_(w, h, QImage::Format_RGBA8888),
      painter_(&img_),
      border_color_(border_color),
      background_color_(background_color),
      pen_(border_color),
      font_size_(font_size),
      bar_horiz_offset_(bar_horiz_offset),
      label_vert_offset_(label_vert_offset){
    painter_.setRenderHint(QPainter::Antialiasing);
    painter_.setFont(QFont("arial", font_size));
    pen_.setWidth(border_width);
    painter_.setPen(pen_);
  }
  QPixmap getChart(size_t const r, size_t const g, size_t const b){
    img_.fill(background_color_);
    const size_t kLabelPos = bar_size_ + gap_size_;
    painter_.drawText(10, kLabelPos+label_vert_offset_, "R");
    painter_.drawText(10, 2*kLabelPos+label_vert_offset_, "G");
    painter_.drawText(10, 3*kLabelPos+label_vert_offset_, "B");
    // paint and fill three rounded rectangles
    QPainterPath path;
    path.addRoundedRect(QRect(bar_horiz_offset_, gap_size_, r, bar_size_),
                        2, 2, Qt::AbsoluteSize);
    painter_.fillPath(path, Qt::red);
    painter_.drawPath(path);
    path = QPainterPath();
    path.addRoundedRect(QRect(bar_horiz_offset_, bar_size_+2*gap_size_, g, bar_size_),
                        2, 2, Qt::AbsoluteSize);
    painter_.fillPath(path, Qt::green);
    painter_.drawPath(path);
    path = QPainterPath();
    path.addRoundedRect(QRect(bar_horiz_offset_, 2*kLabelPos+gap_size_, b, bar_size_),
                        2, 2, Qt::AbsoluteSize);
    painter_.fillPath(path, Qt::blue);
    painter_.drawPath(path);
    // return painted result, converted as pixmal
    return QPixmap::fromImage(img_);
  }
};

#endif // BARCHART_H
