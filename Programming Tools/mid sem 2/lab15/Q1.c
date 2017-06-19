#include <stdio.h>
#include <stdlib.h>

struct Date
{
  int day;
  int month;
  int year;
};

struct person
{
  char *name;
  int age;
  struct Date *dob;
};

void display(struct person** details, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("Name = %s\n", details[i] -> name);
    printf("Age = %d\n", details[i] -> age);
    printf("Date of birth in day/month/year = %d/%d/%d\n", details[i] -> dob -> day, details[i] -> dob -> month, details[i] -> dob -> year);     
  }
}

int main()
{
  int i;
  struct person **details = (struct person**) malloc(sizeof(struct person*) * 10);
  for (i = 0; i < 10; i++)
  {
    details[i] = (struct person*) malloc(sizeof(struct person));
    details[i] -> dob = (struct Date*) malloc (sizeof(struct Date));
    details[i] -> name = (char*) malloc (sizeof(char) * 20);
  }

  printf("Enter the details of 10 persons\n");

  for (i = 0; i < 3; i++)  
  {
    printf("Enter the name, age, DOB with day month and year in order\n");
    scanf("%s", details[i] -> name);
    scanf("%d", &details[i] -> age);
    scanf("%d", &details[i] -> dob -> day);
    scanf("%d", &details[i] -> dob -> month);
    scanf("%d", &details[i] -> dob -> year);    
  }

  display(details, 3);
  return 0;
}
