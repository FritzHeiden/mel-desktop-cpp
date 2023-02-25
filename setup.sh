#!/bin/bash

which g++ > /dev/null || exit
which bear > /dev/null || exit
which make > /dev/null || exit
make clean
bear -- make