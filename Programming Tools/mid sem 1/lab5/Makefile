all: compile main
	./main

compile: lexi.o up.o hello.o
	g++ -o main main.cpp lexi.o up.o hello.o

lexi.o:
	g++ -c lexi.cpp
	
up.o:
	g++ -c up.cpp
	
hello.o:
	g++ -c hello.cpp

clean:
	rm -rf *.o main
