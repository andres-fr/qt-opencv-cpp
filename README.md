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
3. make all and run with: `uic -o design.h design.ui && echo -e "SOURCES += webcam.cpp\nHEADERS += design.h\nCONFIG += c++11\nTARGET = build/webcam\nQT += widgets" > build/webcam.pro && qmake build/webcam.pro && make && ./build/webcam`

## FURTHER DO:

In a more complex setup, the generated source file doesn't need a main function since it is included to other sources which can also incorporate further libraries and interact with Qt. For example, interacting with OpenCV2  would need the following line in the project file:

```
LIBS += `pkg-config --cflags --libs opencv`
```

1. The `cv::Mat` returned by CV's `read` method has to be converted to QT's `QPixmap`. For that,
   1. `#include <QtGui/QPixmap>` where needed
   2. add `QT += gui` to the project file
2. The pixmap can be set to a QLabel like this: `MainWindow.label->setPixmap(<PIXMAP_OBJECT>)`

3. To make QT refresh the pixmap automatically, several things are needed:
   1. Make a class that inherits from QObject and from the designed window, both public.
   3. Add the `Q_OBJECT` macro to the class, and the refreshing method as `public slots:`
   4. Put the class in a separate header and include the header into the project file
   5. Add a QTimer to the constructor, and connect it to the refreshing method like this: `QObject

The class needs to be in its own header, since the Q_OBJECT macro is needed and the file has to be added as HEADERS in the project.


Compile with ``uic -o design.h DESIGN.ui && echo -e "SOURCES += MAIN.cpp\nHEADERS += design.h webcam.h\nCONFIG += c++11\nTARGET = main\nQT += widgets gui\nLIBS += \`pkg-config --cflags --libs opencv\`" > webcam.pro && qmake webcam.pro && make clean && make && ./main``



