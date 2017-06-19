compiler = gcc
warnFlags = -Wall -Werror
debugFlag = -g

compile:
	$(compiler) $(warnFlags) $(debugFlag) -o valgrind valgrind.c

run: compile
	valgrind ./valgrind

clean:
	rm -rf .*o valgrind
