#!/bin/sh -x
#cd ~/problem1
make
./main < testfile.txt >& output.txt
diff output.txt correctOutput.txt > diffs.txt
