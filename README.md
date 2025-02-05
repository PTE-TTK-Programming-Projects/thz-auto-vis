# THz auto visualizer, beam profilem measurement software
This software was produced as an educational project. It is free to use and modify for anyone.

## Installation
In order to compile the program one has to have a C++ compiler, the Qt modules specified in the ```.pro``` file, the libpico5000a and libpicoipp libraries which are freely available from Pico Technology.
After all dependencies have been fulfilled one has to issue the following commands:
```
qmake thz-auto-vis.pro
make
```
or in the case of Qt 6
```
qmake6 thz-auto-vis.pro
make
```
