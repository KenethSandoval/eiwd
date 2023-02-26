CC = g++
FLAGS = -std=c99 -pedantic -g
FLAGS+= -Wall -Wno-unused-parameter -Wextra -Werror=vla -Werror


.PHONY: __all
__all: ogdev_util.a

ogdev_util.a: ogdev_util.o
	ar rcs $@ $^

ogdev_util.o: ogdev_util.cc ogdev_util.h
	$(CC) -c -o $@ $<

install:
	mkdir -p /usr/include/GL/ogdev_util && cp -r ogdev_util.* /usr/include/GL/ogdev_util

clean:
	rm -rf *.o *.a
