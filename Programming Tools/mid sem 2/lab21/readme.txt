Enrollment no. = U101114FCS203

Time output

real	0m6.211s
user	0m0.000s
sys		0m0.000s

Here the real time indicates the time taken by the program to execute in real time. This time includes the time taken by the user to enter the input, the time taken by the user code and the time taken by the system calls. In this output the time taken by the user to input is 6.211s as it is user and sys time are 0 indicating the time taken to execute the program is negligible.

------------------------------------------------------------------------------------------------------------------------------------

Time output after reading from file

real	0m0.007s
user	0m0.004s
sys		0m0.000s

Now, the time taken is lesser and some amount of time is taken by the user because of reading from the file which takes some time. The rest 0.003 might be the time taken by the terminal to print the result.

------------------------------------------------------------------------------------------------------------------------------------

Input 1000 1500 2000 2500 0

Time output after reading from file

real	0m0.370s
user	0m0.360s
sys		0m0.000s


Time output after reading from file using O1

real	0m0.351s
user	0m0.352s
sys		0m0.000s


Time output after reading from file using O2

real	0m0.339s
user	0m0.336s
sys		0m0.000s


Time output after reading from file using O3

real	0m0.339s
user	0m0.336s
sys		0m0.000s

So we can see that as we increase the optimization, the code takes lesser time to execute.

-------------------------------------------------------------------------------------------------------------------------------------

Ouput by my program of no of function calls

No of function calls:

initialize_function_counters: 1853189988
make_empty: 6
make_nonempty: 5768000
is_empty: 5782007
make_list_helper: 7000
make_list: 4
append_lists: 8004
get_num: 5
get_data: 1
insert_list: 5753000
sort_list: 7001
sort_data: 1
print_list: 14002
print_data: 2
show_function_countess: 29555
main: 1



Output of gprof of no of function calls

granularity: each sample hit covers 4 byte(s) for 5.56% of 0.18 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]    100.0    0.00    0.18                 main [1]
                0.00    0.18       1/1           sort_data [2]
                0.00    0.00       1/1           get_data [7]
                0.00    0.00       2/2           print_data [11]
                0.00    0.00       1/1           initialize_function_counters [15]
                0.00    0.00       1/1           show_function_counters [16]
-----------------------------------------------
                0.00    0.18       1/1           main [1]
[2]     99.9    0.00    0.18       1         sort_data [2]
                0.00    0.18       1/1           sort_list [3]
-----------------------------------------------
                                7000             sort_list [3]
                0.00    0.18       1/1           sort_data [2]
[3]     99.9    0.00    0.18       1+7000    sort_list [3]
                0.10    0.08    7000/7000        insert_list [4]
                0.00    0.00    7001/5782007     is_empty [6]
                                7000             sort_list [3]
-----------------------------------------------
                             5746000             insert_list [4]
                0.10    0.08    7000/7000        sort_list [3]
[4]     99.9    0.10    0.08    7000+5746000 insert_list [4]
                0.06    0.00 5753000/5768000     make_nonempty [5]
                0.01    0.00 5753000/5782007     is_empty [6]
                0.00    0.00       1/6           make_empty [13]
                             5746000             insert_list [4]
-----------------------------------------------
                0.00    0.00    7000/5768000     make_list_helper [10]
                0.00    0.00    8000/5768000     append_lists [8]
                0.06    0.00 5753000/5768000     insert_list [4]
[5]     36.1    0.07    0.00 5768000         make_nonempty [5]
-----------------------------------------------
                0.00    0.00    7001/5782007     sort_list [3]
                0.00    0.00    8004/5782007     append_lists [8]
                0.00    0.00   14002/5782007     print_list [12]
                0.01    0.00 5753000/5782007     insert_list [4]
[6]      8.3    0.01    0.00 5782007         is_empty [6]
-----------------------------------------------
                0.00    0.00       1/1           main [1]
[7]      0.1    0.00    0.00       1         get_data [7]
                0.00    0.00       4/4           append_lists [8]
                0.00    0.00       4/4           make_list [9]
                0.00    0.00       5/5           get_num [14]
                0.00    0.00       1/6           make_empty [13]
-----------------------------------------------
                                8000             append_lists [8]
                0.00    0.00       4/4           get_data [7]
[8]      0.1    0.00    0.00       4+8000    append_lists [8]
                0.00    0.00    8000/5768000     make_nonempty [5]
                0.00    0.00    8004/5782007     is_empty [6]
                                8000             append_lists [8]
-----------------------------------------------
                0.00    0.00       4/4           get_data [7]
[9]      0.0    0.00    0.00       4         make_list [9]
                0.00    0.00       4/4           make_list_helper [10]
                0.00    0.00       4/6           make_empty [13]
-----------------------------------------------
                                6996             make_list_helper [10]
                0.00    0.00       4/4           make_list [9]
[10]     0.0    0.00    0.00       4+6996    make_list_helper [10]
                0.00    0.00    7000/5768000     make_nonempty [5]
                                6996             make_list_helper [10]
-----------------------------------------------
                0.00    0.00       2/2           main [1]
[11]     0.0    0.00    0.00       2         print_data [11]
                0.00    0.00       2/2           print_list [12]
-----------------------------------------------
                               14000             print_list [12]
                0.00    0.00       2/2           print_data [11]
[12]     0.0    0.00    0.00       2+14000   print_list [12]
                0.00    0.00   14002/5782007     is_empty [6]
                               14000             print_list [12]
-----------------------------------------------
                0.00    0.00       1/6           get_data [7]
                0.00    0.00       1/6           insert_list [4]
                0.00    0.00       4/6           make_list [9]
[13]     0.0    0.00    0.00       6         make_empty [13]
-----------------------------------------------
                0.00    0.00       5/5           get_data [7]
[14]     0.0    0.00    0.00       5         get_num [14]
-----------------------------------------------
                0.00    0.00       1/1           main [1]
[15]     0.0    0.00    0.00       1         initialize_function_counters [15]
-----------------------------------------------
                0.00    0.00       1/1           main [1]
[16]     0.0    0.00    0.00       1         show_function_counters [16]
-----------------------------------------------



-------------------------------------------------------------------------------------------------------------------------------------


File 'sample.c'
Lines executed:98.44% of 192
sample.c:creating 'sample.c.gcov'

Line 192 is executed the most 98.44%



File 'sample.c'
Lines executed:98.44% of 192
Branches executed:100.00% of 28
Taken at least once:85.71% of 28
Calls executed:97.32% of 112
sample.c:creating 'sample.c.gcov'

-------------------------------------------------------------------------------------------------------------------------------------













