#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	int fd[2];
	pipe(fd);
	printf("fd[0] = %d\n", fd[0]);
	printf("fd[1] = %d\n", fd[1]);

	int Pid = fork();
	if(Pid>0)
	{
		close(fd[0]);
		write(fd[1], "Hi this is parent process message displayed by child", sizeof("Hi this is parent process message displayed by child"));
	}

	else if(Pid==0)
	{
		close(fd[1]);
		char ch[100];
		int a = read(fd[0], ch, sizeof(ch));

		if(a>0)
			printf("Message by parent : %s, Parent ID = %d, Child ID = %d\n", ch, getppid(), getpid());
		else if(a==0)
			printf("No message to be displayed\n");
		else
			printf("Some error\n");
	}

	else
		printf("Some error occured\n");
}
