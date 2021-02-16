#!/bin/bash

for f in ./*.c; do
    gcc -lm -o ${f::-2} $f
done
rm t0