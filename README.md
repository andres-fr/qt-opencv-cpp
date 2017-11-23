## STEPS TO FOLLOW TO COMPILE AND RUN A MINIMAL EXAMPLE:

References: `http://doc.qt.io/qt-5/designer-using-a-ui-file.html`, `https://doc.qt.io/archives/2.3/designer/chap2_3.html`

1. Run the QT designer (on debian `designer`), make your design and save it to `DESIGN.ui`
2. Convert the design to C++: `uic -o design.h DESIGN.ui`
3. Include it to other files like `<SOURCE>.cpp` with `#include "design.h"`. The minimal example would include such a main function:

```
int main(int argc, char** argv){
    QApplication app(argc, argv);
    QMainWindow* q = new QMainWindow;
    Ui::MainWindow ui;
    ui.setupUi(q);
    q->show();
    return app.exec();
}
```
4. QT projects are best compiled via `qmake`. Qmake requires a `<PROJECT>.pro` project file, which can look like this:

```
SOURCES += <SOURCE>.cpp
HEADERS += design.h
CONFIG += c++11
TARGET = <BINARY_NAME>
QT += widgets

```

5. Run `qmake <PROJECT>.pro && make && ./<BINARY_NAME>` to premake, make and run the GUI. It should open the designed window. Done!


For the webcam project, this can be compressed in the following actions:

1. run `designer DESIGN.ui` and make the desired changes
2. include `design.h` and a proper main function in `WEBCAM.cpp` with the desired functionality.
3. make all and run with: `uic -o design.h DESIGN.ui && echo -e "SOURCES += WEBCAM.cpp\nHEADERS += design.h\nCONFIG += c++11\nTARGET = webcam\nQT += widgets" > webcam.pro && qmake webcam.pro && make && ./webcam`

## FURTHER DO:

In a more complex setup, the generated source file doesn't need a main function since it is included to other sources which can also incorporate further libraries and interact with Qt. For example, interacting with OpenCV2  would look similar to this (TODO: test that it works with qt5):

```
#include <opencv2/opencv.hpp>
#include <QtCore/QtCore>
#include <QtGui/QtGui>

QImage Mat2QImage(cv::Mat const& cvmat){
  return QImage((uchar*)cvmat.data,
                         cvmat.cols, cvmat.rows, cvmat.step,
                         QImage::Format_RGB888);
}

int main(){

...

```

Compile with `g++ -std=c++11 -Wall -Wextra <SOURCES> `pkg-config --cflags --libs opencv QtCore QtGui`  -o test && ./test` (test that it works with qt5)



