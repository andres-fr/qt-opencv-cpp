## TO RUN THIS REPO:

1. make sure you have Qt5 and OpenCV(??) installed
2. clone this repo into `<REPO>`
3. open a `bash` in `<REPO>` and execute the following commands:

```
mkdir -p build
uic -o build/design.h DESIGN.ui
echo -e "VPATH += VPATH += ../\nSOURCES += MAIN.cpp\nHEADERS += build/design.h include/webcam.hpp include/barchart.hpp include/integrated_gui.hpp\nCONFIG += c++11\nTARGET = bin/main\nQT += widgets gui\nLIBS += \`pkg-config --cflags --libs opencv\`" > build/main.pro
qmake build/main.pro -o build/Makefile
make -C build/ clean
make -C build/
build/bin/main
```
 Or alternatively, cross your fingers and do it all in one line! ``mkdir -p build && uic -o build/design.h DESIGN.ui && echo -e "VPATH += VPATH += ../\nSOURCES += MAIN.cpp\nHEADERS += build/design.h include/webcam.hpp include/barchart.hpp include/integrated_gui.hpp\nCONFIG += c++11\nTARGET = bin/main\nQT += widgets gui\nLIBS += \`pkg-config --cflags --libs opencv\`" > build/main.pro && qmake build/main.pro -o build/Makefile && make -C build/ clean && make -C build/ && build/bin/main``
 
 ## EXPLANATION:
 
 This is an example on how to "marry" a simple OpenCV program that grabs video from a webcam, and a QT gui made with the `designer`.
 
 1. Editing any GUI with the designer will generate an XML file with the `.ui` extension (in this case, [DESIGN.ui](DESIGN.ui)).
 2. The work with the designer is fairly intuitive, but the XML has to be converted to C++ compatible code. This is done with the `uic` command
 3. The typical C++ program is then compiled and linked, but C++ code that incorporates QT has some extra requirements. See for instance the [webcam.h](include/webcam.h) file:
    1. The window header generated by `uic` has to be be included
    2. The class inheriting from `MainWindow` has to inherit from `QObject` first, and include the `Q_OBJECT` macro. The class needs to be in its own header file, since the Q_OBJECT macro is needed and the file has to be added as HEADERS in the project (having the class in the same file as MAIN could spoil the process with some [undefined reference to vtable](https://stackoverflow.com/questions/2555816/qt-linker-error-undefined-reference-to-vtable)).
    3. The last point is needed to connect the "slots" to other objects of the GUI, with, f.e., the `public slots:` qualifier. See the usage of `QTimer` and `QObject::connect` in the example file.
    4. All the extra QT widgets that weren't included by the `uic` header have to be included too.
    5. With this requirements, the program is ready to be included in arbitrary C++ code and further built as explained in the following points.
4. Due to some specialities like the `Q_OBJECT` marcro, the C++ program is best built with `qmake`. `qmake` needs a `.pro` "project" file, which in the case of this repo is automatically generated with the `echo` command. Note that, among other things, the reference to the `HEADERS` files and to `LIBS += widgets gui`. Note also the following line, since we are using OpenCV: `` LIBS += `pkg-config --cflags --libs opencv ` ``
5. `qmake` can now be called to create the `Makefile` based on the `.pro` file.
6. The program can be then compiled and run with the last three lines. The binary can be found at `<REPO>/build/bin/main`

#### REFERENCES:

`http://doc.qt.io/qt-5/designer-using-a-ui-file.html`
`https://doc.qt.io/archives/2.3/designer/chap2_3.html`

