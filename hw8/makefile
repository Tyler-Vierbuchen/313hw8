CXX = g++
CC = gcc
CXXFLAGS = -Wall
CFLAGS = -std=c99 -m32 -O0 Matrixc.c Matrixc.h -Wall

all: homeWork8cpp homeWork8c

homeWork8cpp: driver.cpp Matrixcpp.o
	$(CXX) $(CXXFLAGS) driver.cpp Matrixcpp.o -o homeWork8cpp

homeWork8c: driver.c Matrixc.o
	$(CC) $(CFLAGS) driver.c Matrixc.o -o homeWork8c

Matrixcpp.o: Matrixcpp.h Matrixcpp.cpp
	$(CXX) $(CXXFLAGS) -c Matrixcpp.cpp

Matrixc.o: Matrixc.h Matrixc.c
	$(CC) $(CFLAGS) -c Matrixc.c

val1:
	valgrind ./homeWork8cpp

val2:
	valgrind ./homeWork8c

run1:
	./homeWork8cpp

run2:
	./homeWork8c

clean:
	rm *~
