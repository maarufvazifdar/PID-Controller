# PID_Controller

[![Build Status](https://app.travis-ci.com/maarufvazifdar/PID-Controller.svg?branch=develpoment)](https://app.travis-ci.com/maarufvazifdar/PID-Controller)
[![Coverage Status](https://coveralls.io/repos/github/maarufvazifdar/PID-Controller/badge.svg?branch=develpoment)](https://coveralls.io/github/maarufvazifdar/PID-Controller?branch=develpoment)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
---`

## Authors
Pair B: 
- Maaruf - Driver
- Rishabh - Navigator

Pair A:
- Dani - Driver
- Siddharth - Navigator
## Overview

A program to compute PID values for a system.
Refer the UML diagram and the activity diagrams for a basic overview of the programm flow.

## Tools used:

- cmake
- googletest
- travis
- coveralls
- cpplint
- cppcheck
- git version control

## Standard install via command-line
```bash
git clone -b development https://github.com/maarufvazifdar/PID-Controller
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

To Run cppcheck and cpplint
```bash
cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" )
cpplint $( find . -name *.cpp -or -name *.hpp | grep -vE -e "^./build/" -e "^./vendor/" )
```