#!/bin/bash

# Count files in current directory
count=$(ls -1 *.txt 2>/dev/null | wc -l)
# print
echo "Number of .txt files: $count"
