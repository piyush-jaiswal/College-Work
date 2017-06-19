/* Example program for time profiling. */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

// Declaring the counters for the various functions
struct function_counter {
	char function_name[50];
	int counter;
	double time_taken;
};
typedef struct function_counter *counter;

counter *function_counter_list;
int noOfFunctions = 16;

void
initialize_function_counters(void)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);

	int i;
	function_counter_list = (counter *) malloc(sizeof(counter) * noOfFunctions);
	for(i = 0; i < noOfFunctions; i++)
	{
		function_counter_list[i] = (counter) malloc (sizeof(struct function_counter));
		function_counter_list[i] -> counter = 0;
		function_counter_list[i] -> time_taken = 0;
	}
	
	strcpy(function_counter_list[0] -> function_name, "initialize_function_counters");
	strcpy(function_counter_list[1] -> function_name, "make_empty");
	strcpy(function_counter_list[2] -> function_name, "make_nonempty");
	strcpy(function_counter_list[3] -> function_name, "is_empty");
	strcpy(function_counter_list[4] -> function_name, "make_list_helper");
	strcpy(function_counter_list[5] -> function_name, "make_list");
	strcpy(function_counter_list[6] -> function_name, "append_lists");
	strcpy(function_counter_list[7] -> function_name, "get_num");
	strcpy(function_counter_list[8] -> function_name, "get_data");
	strcpy(function_counter_list[9] -> function_name, "insert_list");
	strcpy(function_counter_list[10] -> function_name, "sort_list");
	strcpy(function_counter_list[11] -> function_name, "sort_data");
	strcpy(function_counter_list[12] -> function_name, "print_list");
	strcpy(function_counter_list[13] -> function_name, "print_data");
	strcpy(function_counter_list[14] -> function_name, "show_function_counters");
	strcpy(function_counter_list[15] -> function_name, "main");
	
	function_counter_list[0] -> counter++;
	
	gettimeofday(&tv2, 0);
	function_counter_list[0] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
}


struct AList {
	int first;
	struct AList *rest;
};

typedef struct AList *List;

List data;

List
make_empty(void)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);
	
	function_counter_list[1] -> counter++;
	
	gettimeofday(&tv2, 0);
	function_counter_list[1] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
	
	return (NULL);
}

List
make_nonempty(int first, List rest)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);
		
	
	function_counter_list[2] -> counter++;
	
	List list;

	list = malloc(sizeof(struct AList));
	if (list == NULL) {
		fprintf(stderr, "Couldn't allocate list element.\n");
		exit(1);
	}
	list->first = first;
	list->rest = rest;
	
	gettimeofday(&tv2, 0);
	function_counter_list[2] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
	
	return (list);
}

bool
is_empty(List list)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);

	function_counter_list[3] -> counter++;
	
	gettimeofday(&tv2, 0);
	function_counter_list[3] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
	
	return (list == NULL);
}

List
make_list_helper(unsigned int size, List accum)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);
	
	List l;

	function_counter_list[4] -> counter++;
	

	if (size == 1) {
		l = (make_nonempty(size, accum));
		
		gettimeofday(&tv2, 0);
		function_counter_list[4] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
		
		return l;
	}
	else {
		l = (make_list_helper(size - 1, make_nonempty(size, accum)));
		
		gettimeofday(&tv2, 0);
		function_counter_list[4] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
		
		return l;
	}
}

List
make_list(unsigned int size)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);
	
	List l;

	function_counter_list[5] -> counter++;
	
	gettimeofday(&tv2, 0);
	function_counter_list[5] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
	
	l = (make_list_helper(size, make_empty()));
	
	gettimeofday(&tv2, 0);
	function_counter_list[5] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
		
	return l;
}

List
append_lists(List list1, List list2)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);
	
	List l;

	function_counter_list[6] -> counter++;

	List return_list;
    
    
	if (is_empty(list1)) {
		gettimeofday(&tv2, 0);
		function_counter_list[6] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
	
		return (list2);
	}
	else {
		return_list = make_nonempty(list1->first,
		    append_lists(list1->rest, list2));
		free(list1);
		
		gettimeofday(&tv2, 0);
		function_counter_list[6] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
		
		return (return_list);
	}
}

unsigned int
get_num(FILE *fp)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);	
	
	function_counter_list[7] -> counter++;

	unsigned int n = -1;
	char inp[20];

	if(!feof(fp) && fp != NULL) {
		fscanf(fp, "%s", inp);
		n = atoi(inp);
	}
		
	gettimeofday(&tv2, 0);
	function_counter_list[7] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
	
	return n;
}

/* Do interesting stuff to get some data. */
void
get_data(void)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);	

	function_counter_list[8] -> counter++;
	
	unsigned int size;
	FILE *fp;
    
    fp = fopen("testinput", "r");
    if(fp == NULL)
    	printf("ERROR in reading file.\n");
    	
	data = make_empty();

	printf("To create some data, enter a sequence of positive numbers.\n");
	printf("Terminate the list with a zero.\n");
	printf("Use at least moderately large numbers to create enough data "
	    "for good profiling.\n");
        printf("(However, you can run out of memory if you use numbers that "
            "are too large.)\n");
	while ((size = get_num(fp)) != 0)
		data = append_lists(data, make_list(size));
	
	fclose(fp);
	
	gettimeofday(&tv2, 0);
	function_counter_list[8] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
}

List
insert_list(int n, List list)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);	
	
	function_counter_list[9] -> counter++;

	List return_list, l;
    
	if (is_empty(list)) {
		l =  (make_nonempty(n, make_empty()));
		
		gettimeofday(&tv2, 0);
		function_counter_list[9] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
		
		return l;
	}
	else if (n <= list->first) {
		l = (make_nonempty(n, list));
		
		gettimeofday(&tv2, 0);
		function_counter_list[9] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
		
		return l;
	}
	else {
		return_list = make_nonempty(list->first,
		    insert_list(n, list->rest));
		free(list);
		
		gettimeofday(&tv2, 0);
		function_counter_list[9] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
		
		return (return_list);
	}
}

List
sort_list(List list)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);

	function_counter_list[10] -> counter++;

	List return_list;
    
	if (is_empty(list)) {
		gettimeofday(&tv2, 0);
		function_counter_list[10] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
	
		return (list);
	}
	else {
		return_list = insert_list(list->first, sort_list(list->rest));
		free(list);
		
		gettimeofday(&tv2, 0);
		function_counter_list[10] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
		
		return (return_list);
	}
}

void
sort_data(void)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);	
	
	function_counter_list[11] -> counter++;
	
	data = sort_list(data);
	
	gettimeofday(&tv2, 0);
	function_counter_list[11] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
}

void
print_list(List list)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);

	function_counter_list[12] -> counter++;

	if (is_empty(list))
		printf("\n");
	else {
		printf("%d ", list->first);
		print_list(list->rest);
	}
	
	gettimeofday(&tv2, 0);
	function_counter_list[12] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
}

/* Print out whatever data we have. */
void
print_data(void)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);
	
	function_counter_list[13] -> counter++;
	
	printf("The data:\n");
	print_list(data);
	
	gettimeofday(&tv2, 0);
	function_counter_list[13] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
}

// will not show the currect time taken
void
show_function_counters(void)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);	
	
	function_counter_list[14] -> counter++;
	
	int i;
	
	printf("\n\nNo of function calls:\n\n");
	for(i = 0; i < noOfFunctions; i++)
	{
		printf("%s: ", function_counter_list[i] -> function_name);
		printf("%d\n", function_counter_list[i] -> counter);
	}
	
	gettimeofday(&tv2, 0);
	function_counter_list[14] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
	
	printf("\n\nTime taken by function calls in microseconds per call:\n\n");
	for(i = 0; i < noOfFunctions; i++)
	{
		printf("%s: ", function_counter_list[i] -> function_name);
		printf("%f\n", function_counter_list[i] -> time_taken / function_counter_list[i] -> counter);
	}
	
}

// will not show the currect time difference
int
main(void)
{
	struct timeval tv1, tv2;
	gettimeofday(&tv1, 0);
	
	initialize_function_counters();
	get_data();
	print_data();
	/* Do something interesting on the data. */
	sort_data();
	print_data();
	
	function_counter_list[15] -> counter++;
	
	gettimeofday(&tv2, 0);
	function_counter_list[15] -> time_taken += difftime(tv2.tv_usec, tv1.tv_usec);
	show_function_counters();
	
	return (0);
}

