#!/bin/sh
rm ./debug/meshgen
mkdir debug
cd debug/
cmake -DCGAL_DIR=$HOME/CGAL-4.13 -DCMAKE_BUILD_TYPE=Debug ..
make 
cd ..
echo ; echo ; echo
echo "Running meshgen ..."
echo
./debug/meshgen
