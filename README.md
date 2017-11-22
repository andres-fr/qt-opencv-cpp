## STEPS TO FOLLOW TO COMPILE AND RUN A MINIMAL EXAMPLE:

1. Run the QT designer (on debian `designer`), make your design and save it to `<DESIGN>.ui`
2. Convert the design to C++: `uic -o <SOURCE>.cpp <DESIGN>.ui`
3. make it standalone as follows:
   1. Add a `#include<iostream>` declaration
   2. Add `int main(){std::cout << "hello qt!!" << std::endl;}` before `QT_END_NAMESPACE`
4. QT projects are best compiled via `qmake`. Qmake requires a `<PROJECT>.pro` file, which can look like this:

```

SOURCES += <SOURCE>.cpp
CONFIG += c++11
TARGET = <BINARY_NAME>

```

5. Run `qmake <PROJECT>.pro` to generate the `Makefile` in the same folder
6. Run `make` to compile the program
7. Run `./<BINARY_NAME>` should output `"hello qt!!` to the console. Done!


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



