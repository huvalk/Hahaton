#!/bin/bash

# originally from  Michael de Gans 2019

# changes by DK  September 2020

### !!!  Raspberry Pi 4 version !!!


set -e     # exit script immediately upon any error

cd ~

echo "DK-INFO: Download OpenCV from Github archive"

wget -O opencv.zip https://github.com/opencv/opencv/archive/4.4.0.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.4.0.zip

unzip opencv.zip
unzip opencv_contrib.zip

mv opencv-4.4.0 opencv
mv opencv_contrib-4.4.0 opencv_contrib

echo "DK-INFO: Install OpenCV build dependencies"

CMAKEFLAGS="
    -D CMAKE_BUILD_TYPE=RELEASE
    -D CMAKE_INSTALL_PREFIX=/usr/local
    -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules
    -D BUILD_EXAMPLES=OFF
    -D WITH_QT=OFF
    -D BUILD_TESTS=OFF
    -D BUILD_PERF_TESTS=OFF
    -D INSTALL_PYTHON_EXAMPLES=OFF
    -D INSTALL_C_EXAMPLES=OFF
    -D WITH_OPENGL=ON
    -D FORCE_VTK=ON
    -D WITH_TBB=ON
    -D WITH_GDAL=ON
    -D WITH_XINE=ON"


echo "DK-INFO>cmake flags: ${CMAKEFLAGS}"
cd ~/opencv
mkdir build
cd build
cmake ${CMAKEFLAGS} ..

echo "DK-INFO>Make"
make -j4

echo "DK-INFO>Make Install"
make install


echo "DK-INFO>Done! Now do this command to finish installion = sudo ldconfig"