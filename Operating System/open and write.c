#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd;
	fd = open("/home/user/Desktop/Piyush/message.txt", O_WRONLY | O_TRUNC | O_CREAT, 0666);
	
	if(fd<=0)
		printf("Error opening file\n");

	else
	{
		char c[1000];
		printf("Enter a message\n");
		gets(c);
		write(fd, c, strlen(c));
	}

	return 0;
}
