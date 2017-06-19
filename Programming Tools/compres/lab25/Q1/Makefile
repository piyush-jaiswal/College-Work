compiler = g++
executable_flag = -o
warning_flags = -Wall -Werror

compile:
	$(compiler) $(executable_flag) person person.cpp

run: compile person
	./person

clean:
	rm -rf *.o person
