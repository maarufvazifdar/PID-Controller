# PID_Controller
[![Build Status](https://app.travis-ci.com/maarufvazifdar/PID-Controller.svg?branch=development)](https://app.travis-ci.com/maarufvazifdar/PID-Controller)
[![Coverage Status](https://coveralls.io/repos/github/maarufvazifdar/PID-Controller/badge.svg?branch=development)](https://coveralls.io/github/maarufvazifdar/PID-Controller?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
---

## Authors
Part B: 
- Maaruf - Driver
- Rishabh - Navigator
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
```
git clone https://github.com/maarufvazifdar/PID-Controller
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

