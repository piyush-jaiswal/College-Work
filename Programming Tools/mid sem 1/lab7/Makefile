g=g++
obj=-o
com=-c
objects= check.o armstrong.o first.o

all: compile main
	./main
	
compile: $(objects)
	g++ $(objects) $(obj) main main.cpp
	
check.o: check.cpp
	$(g) $(com) check.cpp
	
armstrong.o: armstrong.cpp
	$(g) $(com) armstrong.cpp
	
first.o: first.cpp
	$(g) $(com) first.cpp
	
clean:
	rm -rf *.o main
