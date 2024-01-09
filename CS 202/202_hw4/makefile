# Make file to compile source code

CC=g++

CFLAGS=-c -Wall


target: avlfreq


avlfreq: main.o AVLTree.o Node.o
	$(CC) main.o AVLTree.o Node.o -o avlfreq


main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp


AVLTree.o: AVLTree.cpp
	$(CC) $(CFLAGS) AVLTree.cpp


Node.o: Node.cpp
	$(CC) $(CFLAGS) Node.cpp


clean:
	rm *o avlfreq