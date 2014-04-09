all: main

main: main.o 
	g++ main.o -o main -lSDL -lSDL_image

main.o: main.cpp blob.h
	g++ -c main.cpp

clean:
	rm -f *.o main
