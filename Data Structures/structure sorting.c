/* Q) Make an array of structures. You could consider using the struct student with int rollno,
      char name[20], age, address, m1, m2,m3. The data of this array should be initialized at
      time of declaration itself. Ask the user if you have to sort on rollno or on name.
      And accordingly sort the list and display. You may use any sorting algorithm to make this
      possible. */



#include<stdio.h>
struct student
{
    int rollno;
    char name[20];
    int age;
    char address[20];
    int m1,m2,m3;
};

#include"student sort.c"
#include"alphabetical order.c"


struct student s[4] = {10,"Rooney",26,"bcfg",35,50,65,
                       8,"Mata",25,"fdsaf",56,48,75,
                       7,"Dimaria",27,"asdasd",75,89,65,
                       21,"Herrera",24,"asdewq",90,91,93};

int main()
{
    int ch,i;
    printf("Press 1 to sort by name or 2 to sort by rollno\n");
    scanf("%d", &ch);
    if(ch==1)
    {
        printf("Sorting by name\n");
        charsort(s,4);
    }
    else
    {
        printf("Sorting by rollno\n");
        bubblesort(s,4);
    }
    for(i=0;i<4;i++)
    {
        printf("\n");
        puts(s[i].name);
        printf("Roll = %d\n", s[i].rollno);
        puts(s[i].address);
        printf("Age = %d\n", s[i].age);
        printf("Marks = %d %d %d \n", s[i].m1, s[i].m2, s[i].m3);
        printf("\n");
    }
}
