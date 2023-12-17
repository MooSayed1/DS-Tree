#!/bin/sh

# rm -rf .build
mkdir .build -p
cd .build

#Genrate build folder
cmake ../.
#make, execute compile command
make

mv ./main ..
cd ..
#run
./main

