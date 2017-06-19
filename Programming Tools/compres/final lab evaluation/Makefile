compiler = g++
debug_flag = -g
warning_flags = -Wall -Werror
executable_flag = -o

compile:
		$(compiler) $(debug_flag) $(warning_flags) $(executable_flag) exam exam.cpp

run:	compile
		./exam

debug:	compile
		gdb exam
		
clean:
		rm -rf *.o exam
