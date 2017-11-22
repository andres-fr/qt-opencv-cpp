## STEPS TO FOLLOW TO COMPILE AND RUN A MINIMAL EXAMPLE:

1. Run the QT designer (on debian `designer`), make your design and save it to `<DESIGN>.ui`
2. Convert the design to C++: `uic -o <SOURCE>.cpp <DESIGN>.ui`
3. make it standalone as follows: (in more complex setups the file should be a `.hpp` header included to other files
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
