compiler = gcc
warnFlags = -Wall -Werror
dependencies = linkedList.o

compile: $(dependencies)
	$(compiler) $(warnFlags) -g -o main main.c $(dependencies)

run: compile
	valgrind ./main
	
linkedList.o:
	$(compiler) -c linkedList.c
	
clean:
	rm -rf *.o main
