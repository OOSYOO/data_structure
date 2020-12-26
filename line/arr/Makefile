# CPP_FLAGS='-std=c++11'

CXX := /usr/bin/clang++

all:main

main:main.o	sqlist.o
	$(CXX)	$^	-o	$@

.PHONY:clean
clean:
	rm -rf *.o	main