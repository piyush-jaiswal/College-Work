compiler = gcc
warnFlags = -Wall -Werror
debugFlag = -g
noLinkFlag = -c
dependencies = getWords.o printWords.o

compile: $(dependencies)
	$(compiler) $(warnFlags) $(debugFlag) -o main main.c $(dependencies)

getWords.o:
	$(compiler) $(noLinkFlag) getWords.c

printWords.o:
	$(compiler) $(noLinkFlag) printWords.c 

run: compile
	valgrind ./main

clean:
	rm -rf *.o main
