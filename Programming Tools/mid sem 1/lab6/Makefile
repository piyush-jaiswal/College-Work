all: compile main1
	./main1

compile: bub.o bin.o ins.o del.o
	g++ -o main1 main1.cpp bub.o bin.o ins.o del.o

bub.o:
	g++ -c bub.cpp

bin.o:
	g++ -c bin.cpp

ins.o:
	g++ -c ins.cpp

del.o:
	g++ -c del.cpp

clean:
	rm *.o main1
