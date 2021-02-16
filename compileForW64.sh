#!/bin/bash

for f in ./*.c; do
    x86_64-w64-mingw32-gcc -lm -o ${f::-2} $f
done
rm t0.exe