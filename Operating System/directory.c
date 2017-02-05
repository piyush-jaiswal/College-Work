#include<stdio.h>
#include<dirent.h>

int main()
{
	DIR *pt;
	struct dirent *pt1;
	pt = opendir("dir_1_S45");
	
	if(pt==NULL)
		printf("No such directory\n");
	else
	{
		pt1 = readdir(pt);
		if(pt1==NULL)
			printf("No files\n");
		else
		{
			while(pt1!=NULL)
			{
				printf("%s\n", pt1->d_name);
				pt1 = readdir(pt);
			}
		}
	}
	return 0;	
}


