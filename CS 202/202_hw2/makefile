# Make file to compile source code

CC=g++

CFLAGS=-c -Wall


target: hw2


hw2: hw2.o NgramTree.o Node.o
	$(CC) hw2.o NgramTree.o Node.o -o hw2


hw2.o: hw2.cpp
	$(CC) $(CFLAGS) hw2.cpp


NgramTree.o: NgramTree.cpp
	$(CC) $(CFLAGS) NgramTree.cpp


Node.o: Node.cpp
	$(CC) $(CFLAGS) Node.cpp


clean:
	rm *o hw2