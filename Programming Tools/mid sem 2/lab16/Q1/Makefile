compiler = gcc
warnFlags = -Wall -Werror
debugFlag = -g

compile:
	$(compiler) $(warnFlags) $(debugFlag) -o swap swap.c

run: compile
	valgrind ./swap

clean:
	rm -rf .*o swap
