compiler = g++
objects = insertionSort.o

compile: $(objects)
	$(compiler) main.cpp $(objects) -o main

run: compile main
	./main

insertionSort.o:
	$(compiler) -c insertionSort.cpp

clean:
	rm -rf *.o main
