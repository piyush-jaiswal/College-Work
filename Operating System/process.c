#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	int Pid = fork();
	if(Pid>0)
	{
		wait(NULL);
		
		printf("Process Id = %d\n", getpid());
		execlp("cat","cat",argv[1],NULL);
	}
	
	else if(Pid==0)
	{
		
		printf("Child process = %d\n", getpid());
		printf("Parent process = %d\n", getppid());
		execvp(argv[2], &argv[2]);
	}
	
	else
		printf("Some error occured\n");
}

