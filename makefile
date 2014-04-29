all: main

main: main.o Menu.o
	g++ main.o Menu.o -o main -lSDL -lSDL_image

main.o: main.cpp Timer.h Character.h CharlesBarkley.h Conan.h Lebron.h Leprechaun.h LadyGaga.h Miley.h
	g++ -c main.cpp 

Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp

clean:
	rm -f *.o main
