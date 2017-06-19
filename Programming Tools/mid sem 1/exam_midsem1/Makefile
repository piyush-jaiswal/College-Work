c = g++
objects = trip.o

compile: $(objects)
	$(c) $(objects) main.cpp -o main

run: compile main
	./main
    
trip.o:
	 $(c) -c trip.cpp

clean:
	 rm -rf *.o main
