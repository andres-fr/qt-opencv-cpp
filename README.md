## STEPS TO FOLLOW TO COMPILE AND RUN A MINIMAL EXAMPLE:

This is somewhat an excerpt of this webpage: `http://doc.qt.io/qt-5/designer-using-a-ui-file.html`

1. Run the QT designer (on debian `designer`), make your design and save it to `<DESIGN>.ui`
2. Convert the design to C++: `uic -o <SOURCE>.h <DESIGN>.ui`
3. Include it to other files as `#include "<SOURCE>.h"`, or make it standalone adding a main function to it before `QT_END_NAMESPACE`:

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

4. QT projects are best compiled via `qmake`. Qmake requires a `<PROJECT>.pro` file, which can look like this:

```
SOURCES += <SOURCE>.cpp
CONFIG += c++11
TARGET = <BINARY_NAME>
QT += widgets
```

5. Run `qmake project.pro && make && ./<BINARY_NAME>` to premake, make and run the GUI. It should open the designed window. Done!

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



