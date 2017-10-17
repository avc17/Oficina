#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

cabecalho head;
int main (int argc, char *argv[])
{
FILE *audio, *output;  
char filename[TAM];
char saida[TAM];
int i;	
    saida[0] = 0;	
	filename[0] = 0;
	for(i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-i")==0)
			strcpy (filename, argv[i+1]);
		if (strcmp(argv[i], "-o")==0)
			strcpy (saida, argv[i+1]); 
	}
	
	if (filename[0] == 0)
		audio = stdin;
	else
		audio = fopen(filename, "r");

	if (audio == NULL)
	{	
		perror("Erro");
		return -1;
	}

	load_header(audio, &head);

	if (saida[0] != 0)
	{
		output = fopen(saida, "w");
		print_info(output, &head);
	}
	else
	{
		print_info(stdout, &head);
	}
}
