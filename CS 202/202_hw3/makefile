# Make file to compile source code

CC=g++

CFLAGS=-c -Wall


target: heapsort


heapsort: heapsort.o heap.o
	$(CC) heapsort.o heap.o -o heapsort


heapsort.o: heapsort.cpp
	$(CC) $(CFLAGS) heapsort.cpp


heap.o: heap.cpp
	$(CC) $(CFLAGS) heap.cpp

clean:
	rm *o heapsort