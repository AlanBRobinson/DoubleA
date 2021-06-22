#!/bin/bash
g++  -W -Wall -include ./src/Vector.cc -o main ./src/main.cc -lSDL2 -lSDL2main && ./main 