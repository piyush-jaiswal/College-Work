Time

Non-optimized
time ./nth_fibo_recursion 27 0
Nth fibo = 196418

real	0m0.021s
user	0m0.020s
sys		0m0.000s



Optimized
on 31 1
Nth fibo = 1346269

real	0m0.003s
user	0m0.000s
sys		0m0.000s

------------------------------------------------------------------------------------------------------------------------------------

Cachegrind

Non-optimized

valgrind --tool=cachegrind ./nth_fibo_recursion 27 0
==4592== Cachegrind, a cache and branch-prediction profiler
==4592== Copyright (C) 2002-2011, and GNU GPL'd, by Nicholas Nethercote et al.
==4592== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==4592== Command: ./nth_fibo_recursion 27 0
==4592== 
Nth fibo = 196418
==4592== 
==4592== I   refs:      49,915,477
==4592== I1  misses:           950
==4592== LLi misses:           937
==4592== I1  miss rate:       0.00%
==4592== LLi miss rate:       0.00%
==4592== 
==4592== D   refs:      30,978,572  (20,052,278 rd   + 10,926,294 wr)
==4592== D1  misses:         8,485  (     1,995 rd   +      6,490 wr)
==4592== LLd misses:         7,941  (     1,508 rd   +      6,433 wr)
==4592== D1  miss rate:        0.0% (       0.0%     +        0.0%  )
==4592== LLd miss rate:        0.0% (       0.0%     +        0.0%  )
==4592== 
==4592== LL refs:            9,435  (     2,945 rd   +      6,490 wr)
==4592== LL misses:          8,878  (     2,445 rd   +      6,433 wr)
==4592== LL miss rate:         0.0% (       0.0%     +        0.0%  )
Profiling timer expired



Optimized

valgrind --tool=cachegrind ./nth_fibo_recursion 31 1
==4604== Cachegrind, a cache and branch-prediction profiler
==4604== Copyright (C) 2002-2011, and GNU GPL'd, by Nicholas Nethercote et al.
==4604== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==4604== Command: ./nth_fibo_recursion 31 1
==4604== 
Nth fibo = 1346269
==4604== 
==4604== I   refs:      901,552
==4604== I1  misses:        948
==4604== LLi misses:        935
==4604== I1  miss rate:    0.10%
==4604== LLi miss rate:    0.10%
==4604== 
==4604== D   refs:      592,992  (471,199 rd   + 121,793 wr)
==4604== D1  misses:      8,481  (  1,990 rd   +   6,491 wr)
==4604== LLd misses:      7,935  (  1,505 rd   +   6,430 wr)
==4604== D1  miss rate:     1.4% (    0.4%     +     5.3%  )
==4604== LLd miss rate:     1.3% (    0.3%     +     5.2%  )
==4604== 
==4604== LL refs:         9,429  (  2,938 rd   +   6,491 wr)
==4604== LL misses:       8,870  (  2,440 rd   +   6,430 wr)
==4604== LL miss rate:      0.5% (    0.1%     +     5.2%  )
Profiling timer expired

--------------------------------------------------------------------------------------------------------------------------------------

Gprof

Non-optimized

./nth_fibo_recursion 42 0

Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls   s/call   s/call  name    
 97.83      7.66     7.66        1     7.66     7.66  get_nth_fibo
  2.17      7.83     0.17                             main



			Call graph (explanation follows)


granularity: each sample hit covers 4 byte(s) for 0.13% of 7.83 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]    100.0    0.17    7.66                 main [1]
                7.66    0.00       1/1           get_nth_fibo [2]
-----------------------------------------------
                             866988872             get_nth_fibo [2]
                7.66    0.00       1/1           main [1]
[2]     97.8    7.66    0.00       1+866988872 get_nth_fibo [2]
                             866988872             get_nth_fibo [2]
-----------------------------------------------






Optimized

./nth_fibo_recursion 50 1

  %   cumulative   self              self     total           
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
  0.00      0.00     0.00        1     0.00     0.00  get_nth_fibo_dprog

		     
		     
		     Call graph (explanation follows)


granularity: each sample hit covers 4 byte(s) no time propagated

index % time    self  children    called     name
                                  98             get_nth_fibo_dprog [1]
                0.00    0.00       1/1           main [6]
[1]      0.0    0.00    0.00       1+98      get_nth_fibo_dprog [1]
                                  98             get_nth_fibo_dprog [1]
-----------------------------------------------


-------------------------------------------------------------------------------------------------------------------------------------

Massif

Non-optimized

valgrind --tool=massif --stacks=yes ./nth_fibo_recursion 10 0

--------------------------------------------------------------------------------
Command:            ./nth_fibo_recursion 10 0
Massif arguments:   --stacks=yes
ms_print arguments: massif.out.4793
--------------------------------------------------------------------------------


    KB
2.379^           #                                                            
     |           #                                                            
     |         : #                                                            
     |       ::: #                                                            
     |       ::: #                                                            
     |       ::::#                                                      :     
     |       ::::#                                                      :@    
     |    : :::::#                                                      :@    
     |    : :::::#                                                      :@    
     |    : :::::#:           :       :         :     :  :     ::       :@    
     |    : :::::#::          : ::::::: ::::::  ::: : :: :    :::       :@    
     |    : :::::#::        :@: ::::::: ::::::@ :::::::@::::: :::       :@    
     |    : :::::#::        :@: ::::::: ::::::@ :::::::@::::: :::       :@    
     |    : :::::#:::     :@:@:::::::::@::::::@::::::::@:::::@:::       :@  : 
     |  : : :::::#:::::::::@:@:::::::::@::::::@::::::::@:::::@:::    :  :@  : 
     |:::::::::::#::::    :@:@:::::::::@::::::@::::::::@:::::@:::    :  :@  : 
     |:::::::::::#::::    :@:@:::::::::@::::::@::::::::@:::::@:::    :  :@: : 
     |:::::::::::#::::    :@:@:::::::::@::::::@::::::::@:::::@:::::@:::::@::: 
     |:::::::::::#::::    :@:@:::::::::@::::::@::::::::@:::::@:::::@:::::@::::
     |:::::::::::#::::    :@:@:::::::::@::::::@::::::::@:::::@:::::@:::::@::::
   0 +----------------------------------------------------------------------->ki
     0                                                                   138.9

Number of snapshots: 95
 Detailed snapshots: [14 (peak), 20, 22, 34, 43, 56, 66, 76, 86]

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  0              0                0                0             0            0
  1          1,699              648                0             0          648
  2          3,235              720                0             0          720
  3          4,970              768                0             0          768
  4          6,229              612                0             0          612
  5          7,684              704                0             0          704
  6          9,711            1,700                0             0        1,700
  7         11,548              704                0             0          704
  8         13,296            1,684                0             0        1,684
  9         15,281            2,108                0             0        2,108
 10         16,476            1,840                0             0        1,840
 11         17,785            2,108                0             0        2,108
 12         19,217            2,196                0             0        2,196
 13         21,123            1,932                0             0        1,932
 14         23,134            2,436                0             0        2,436
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 15         24,841            1,424                0             0        1,424
 16         26,159            1,232                0             0        1,232
 17         28,479              964                0             0          964
 18         30,124              788                0             0          788
 19         40,672              932                0             0          932
 20         42,824              932                0             0          932
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 21         44,973            1,140                0             0        1,140
 22         46,540            1,140                0             0        1,140
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 23         47,775            1,364                0             0        1,364
 24         49,575              936                0             0          936
 25         51,078              936                0             0          936
 26         52,239            1,300                0             0        1,300
 27         54,277            1,300                0             0        1,300
 28         56,520            1,300                0             0        1,300
 29         58,557            1,300                0             0        1,300
 30         60,602            1,300                0             0        1,300
 31         62,034            1,300                0             0        1,300
 32         63,285            1,360                0             0        1,360
 33         64,729            1,300                0             0        1,300
 34         66,620              932                0             0          932
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 35         67,835            1,300                0             0        1,300
 36         69,051              932                0             0          932
 37         71,042            1,300                0             0        1,300
 38         72,567            1,300                0             0        1,300
 39         74,779            1,300                0             0        1,300
 40         76,388            1,300                0             0        1,300
 41         77,532              932                0             0          932
 42         78,873            1,300                0             0        1,300
 43         80,220            1,140                0             0        1,140
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 44         81,388              948                0             0          948
 45         83,137            1,140                0             0        1,140
 46         84,291            1,364                0             0        1,364
 47         85,712            1,300                0             0        1,300
 48         87,357            1,300                0             0        1,300
 49         88,885            1,300                0             0        1,300
 50         90,040            1,136                0             0        1,136
 51         91,234            1,300                0             0        1,300
 52         92,661            1,300                0             0        1,300
 53         93,811            1,140                0             0        1,140
 54         95,008            1,360                0             0        1,360
 55         96,408            1,300                0             0        1,300
 56         97,585            1,140                0             0        1,140
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 57         98,760            1,300                0             0        1,300
 58         99,910            1,156                0             0        1,156
 59        101,089            1,140                0             0        1,140
 60        102,246            1,360                0             0        1,360
 61        103,395            1,136                0             0        1,136
 62        104,743            1,156                0             0        1,156
 63        105,922              932                0             0          932
 64        107,309            1,156                0             0        1,156
 65        108,484              932                0             0          932
 66        109,740              932                0             0          932
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 67        110,893            1,300                0             0        1,300
 68        112,107              932                0             0          932
 69        113,266            1,360                0             0        1,360
 70        114,534            1,140                0             0        1,140
 71        115,693            1,360                0             0        1,360
 72        116,859              388                0             0          388
 73        118,005              436                0             0          436
 74        119,152              440                0             0          440
 75        120,301              440                0             0          440
 76        121,445              440                0             0          440
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 77        122,589              436                0             0          436
 78        123,779              180                0             0          180
 79        124,954              584                0             0          584
 80        126,107              764                0             0          764
 81        127,257              436                0             0          436
 82        128,407              384                0             0          384
 83        129,560              436                0             0          436
 84        130,798              700                0             0          700
 85        131,945            1,828                0             0        1,828
 86        133,095            1,816                0             0        1,816
00.00% (0B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 87        134,239              532                0             0          532
 88        135,395              492                0             0          492
 89        136,546              384                0             0          384
 90        137,695              380                0             0          380
 91        138,842              868                0             0          868
 92        139,994              388                0             0          388
 93        141,138              324                0             0          324
 94        142,283              324                0             0          324


Here, the peak snapshot is at 14 because that is the time when the stack calls are the maximum and the memory usage in the stack is maximum.






Optimized

--tool=massif ./nth_fibo_recursion 35 1

Command:            ./nth_fibo_recursion 35 1
Massif arguments:   (none)
ms_print arguments: massif.out.4839
--------------------------------------------------------------------------------


     B
  408^                                                                     ::#
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
     |                                                                     : #
   0 +----------------------------------------------------------------------->ki
     0                                                                   128.6

Number of snapshots: 4
 Detailed snapshots: [2 (peak)]

--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  0              0                0                0             0            0
  1        127,589              408              400             8            0
  2        131,681              408              400             8            0
98.04% (400B) (heap allocation functions) malloc/new/new[], --alloc-fns, etc.
->98.04% (400B) 0x80485B6: main (nth_fibo_recursion.c:46)
  
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
  3        131,681                0                0             0            0


The peak snaphot is at 2 because that's when the allocated heap size is maximum.

----------------------------------------------------------------------------------------------------------------------------------------



The no of times a given Fib(int) is called for a given fib is the no. of recursive calls it takes to calculate N. For example, it takes 286 calls to calculate Fib(11).


----------------------------------------------------------------------------------------------------------------------------------------


The n-th value for which the program becomes slow is around 39 using non-memoization technique.


-----------------------------------------------------------------------------------------------------------------------------------------

Compare loop

Recursive non-optimized

time ./nth_fibo_recursion 35 0

real	0m0.517s
user	0m0.516s
sys	0m0.000s



Recursive optimized

time ./nth_fibo_recursion 35 1

real	0m0.001s
user	0m0.000s
sys	0m0.000s



Loop

time ./nth_fibo_recursion 35 2

real	0m0.001s
user	0m0.000s
sys	0m0.000s


The loop takes the same time as the one where the recursion is optimized but takes much shorter time than the recursion which is not optimized


----------------------------------------------------------------------------------------------------------------------------------------------------

Callgrind



Non-optimized

valgrind --tool=callgrind ./nth_fibo_recursion 25 0

==8769== Callgrind, a call-graph generating cache profiler
==8769== Copyright (C) 2002-2015, and GNU GPL'd, by Josef Weidendorfer et al.
==8769== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==8769== Command: ./nth_fibo_recursion 25 0
==8769== 
==8769== For interactive control, run 'callgrind_control -h'.
Nth fibo = 75025
==8769== 
==8769== Events    : Ir
==8769== Collected : 16820800
==8769== 
==8769== I   refs:      16,820,800





Optimized

valgrind --tool=callgrind ./nth_fibo_recursion 25 1

==8944== Callgrind, a call-graph generating cache profiler
==8944== Copyright (C) 2002-2015, and GNU GPL'd, by Josef Weidendorfer et al.
==8944== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==8944== Command: ./nth_fibo_recursion 25 1
==8944== 
==8944== For interactive control, run 'callgrind_control -h'.
Nth fibo = 75025
==8944== 
==8944== Events    : Ir
==8944== Collected : 168256
==8944== 
==8944== I   refs:      168,256





Loop
valgrind --tool=callgrind ./nth_fibo_recursion 25 2

==8965== Callgrind, a call-graph generating cache profiler
==8965== Copyright (C) 2002-2015, and GNU GPL'd, by Josef Weidendorfer et al.
==8965== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==8965== Command: ./nth_fibo_recursion 25 2
==8965== 
==8965== For interactive control, run 'callgrind_control -h'.
Nth fibo = 75025
==8965== 
==8965== Events    : Ir
==8965== Collected : 161310
==8965== 
==8965== I   refs:      161,310


--------------------------------------------------------------------------------------------------------------------------------------------------------------------




