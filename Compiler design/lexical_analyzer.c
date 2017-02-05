#include<string.h>
#include<ctype.h>
#include<stdio.h>
void keyword(char str[10])
{
if(strcmp("for",str)==0||strcmp("while",str)==0||strcmp("do",str)==0||strcmp("int",str )==0||strcmp("float",str)==0||strcmp("char",str)==0||strcmp("double",str)==0||strcmp("static",str)==0||strcmp("switch",str)==0||strcmp("case",str)==0||strcmp("return",str)==0) //comparing str string to keywords
 		printf("\n%s is a keyword",str);
 	else
 		printf("\n%s is an identifier",str);
}
main()
{
 	FILE *f1,*f2,*f3,*f4; // Declaring 3 file pointers
 	char c,str[10],st1[10]; 
 	int num[100],lineno=0,tokenvalue=0,i=0,j=0,k=0, noc=0;
 	printf("\nEnter the c program\n");/*gets(st1);*/
 	f1=fopen("input","w"); //creating a text file input.txt
 	while((c=getchar())!=EOF) //accepting user input one char at a time
  	putc(c,f1); // writing the char to the input.txt file
 	fclose(f1); //closing the file pointer after writing the user input chars
 	f1=fopen("input","r"); //opening the input.txt file in read mode
 	f2=fopen("identifier","w"); //creating a text file identifier.txt
 	f3=fopen("specialchar","w"); //creating a text file specialchar.txt
	f4=fopen("operators","w"); //creating a text file for operators.txt
 	while((c=getc(f1))!=EOF)  // reading all chars from the input.txt file
 	{
 		if(isdigit(c))  //checking if char read from the file is digit		
 		{
 			tokenvalue=c-'0'; // converting a char to an integer
 		 	c=getc(f1); // reading the next char from input.txt
 			while(isdigit(c)) //checking if char read from the file is 						//digit
 			{
 				tokenvalue*=10+c-'0'; //shifting the previous digit to the tens place and storing the next digit in units place
 				c=getc(f1);  // reading the next char from input.txt
 			}
 			num[i++]=tokenvalue;//storing all numbers in the num[] array
 			ungetc(c,f1); //way of unreading the read char (places the file pointer to a character before the current position)
 		}

		else if(c=='+'||c=='-'||c=='*'||c=='/'||c=='%') //checking for operators
		{
			if(c=='+')
			{
				if((c=getc(f1))=='+')
				{
					putc('+',f4);
					putc('+',f4);
					putc(' ',f4);
				}

				else
				{
					putc('+',f4);
					putc(' ',f4);
					ungetc(c,f1);
				}
			}

			else if(c=='-')
			{
				if((c=getc(f1))=='-')
				{
					putc('-',f4);
					putc('-',f4);
					putc(' ',f4);
				}

				else
				{
					putc('+',f4);
					putc(' ',f4);
					ungetc(c,f1);
				}
			}
			
			else
			{
			putc(c,f4);
			putc(' ',f4);
			}
		}		
		
 		else
 		if(isalpha(c))  //checking if char read from the file is alphabet
 		{
 			putc(c,f2); //writing the char to the identifier.txt
 			c=getc(f1);  // reading the next char from input.txt
 			while(isdigit(c)||isalpha(c)||c=='_'||c=='$') //checking for digits, alphabets, underscores and dollar signs
 			{
 				putc(c,f2);
 				c=getc(f1);
 			}
 			putc(' ',f2); //writing the char to the identifier.txt
 			ungetc(c,f1); //way of unreading the read char
 		}
 		else
 		if(c==' '|| c=='\t') //checking for spaces and tabs
 			printf(" ");
		else if(c=='/') // checking for comments
		{
			c=getc(f1);
			if(c=='/')
			{
				noc++;
				while(getc(f1)!='\n');
				ungetc('\n',f1);
			}
			else
			{
				ungetc(c,f1);
				ungetc(c,f1);
			}
		}
 		else
 		if(c=='\n') 
 			lineno++; //counting newlines
 		else
 			putc(c,f3);//writing all special chars to the  							//specialchar.txt file
 	}
 	fclose(f2);// closing all file pointers
 	fclose(f3);
 	fclose(f1);
	fclose(f4);
 	printf("\nThe no's in the program are");
 	for(j=0;j<i;j++)
 	printf("%d, ",num[j]); //displaying all numbers in input.txt
 	printf("\n");
 	f2=fopen("identifier","r"); //opening identifier.txt in read mode
 	k=0;
 	printf("The keywords and identifiers are:");
 	while((c=getc(f2))!=EOF) //reading all chars in the file
 	{
 		if(c!=' ')
 			str[k++]=c; //writing all chars except spaces in the char 					// str[]  array of chars
 		else
 		{
 			str[k]='\0'; //terminating a word when a space in encounted
 			keyword(str); //calling function keyword with str 
 			k=0; //initialising k to 0
 		}
  	}
  	fclose(f2); //file pointer for identifier.txt closed
 	f3=fopen("specialchar","r");  //opening specialchar.txt in read mode
 	printf("\nSpecial characters are: ");
 	while((c=getc(f3))!=EOF) //reading all chars from specialchar.txt
 		printf("%c ",c); //printing all chars
 	printf("\n");
 	fclose(f3); // //file pointer for specialchar.txt closed
 	printf("Total no. of lines are:%d\n",lineno); //displaying no. of lines
	printf("The total no of comments are: %d\n", noc);

	f4 = fopen("operators","r"); //opening operators in read mode
	printf("The operators are : \n");
	while((c=getc(f4))!=EOF) //reading all operators in the file
	{
		if(c!=' ')
		{
			if(c=='+')
			{
				if((c=getc(f1))=='+')
				{
					printf("++ is an operator\n");
				}
				else
					printf("+ is an operator\n");
			}

			if(c=='-')
			{
				if((c=getc(f1))=='-')
				{
					printf("-- is an operator\n");
				}
				else
					printf("- is an operator\n");
			}
			
			else if(c!=' ')
			printf("%c is an operator\n", c);
		}
	}
	fclose(f4);
}
