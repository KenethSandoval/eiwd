#!/bin/bash

CC=g++

LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

$CC window.cpp $LDFLAGS -o main.o
