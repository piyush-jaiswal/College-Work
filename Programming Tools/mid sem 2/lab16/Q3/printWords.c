#include <stdio.h>
#include <string.h>
#include "struct.h"

void wordsInFile(ingsAndOccurences **x)
{
    int i;
	FILE *fp;
	fp = fopen("output.txt", "w");

	fputs("WORD\t\tOCCURENCES\n", fp);
	
	for (i = 0; i < 200; i++)
	{
		if(x[i] -> occurences == -1)
			break;
		fputs(x[i] -> word, fp);
		fprintf(fp, "\t\t%d\n", x[i] -> occurences);
	}
	fclose(fp);
}
