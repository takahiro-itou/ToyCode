#! /bin/bash -x

CC=g++
AR=ar

cd  lib
cd  sub1
${CC}  -c  -o  sub1.o  sub1.cpp
${AR}  rcs  libsub1.a  sub1.o
cd  ..

cd  sub2
${CC}  -c  -o  sub2.o  sub2.cpp
${AR}  rcs  libsub2.a  sub2.o
cd  ..

cd  ..

cd  bin
${CC}  -c  -o  main1.o  main1.cpp
${CC}  -o  bin_main1  main1.o  -L ../lib  -lsub1
cd  ..

