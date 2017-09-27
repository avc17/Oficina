#include "dicionario.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ler_dicionario ( char dic[][MAX_WORD_SIZE])
{
FILE *arq = NULL;
long i;
        arq = fopen("/usr/share/dict/brazilian","r");
        if (!arq)
        {
                perror("erro");
        }
        else
        {
                for (i = 0; i<=275502; i++)
                        fscanf(arq, "%s\n", dic[i]);

        }
       
	 fclose(arq);
	

}
int comp (const void *s1, const void *s2)
{
//const char *key = s1;
//const char * const *arg = s2;
	return (strcmp(s1,s2));
	
}



void *pertence (unsigned char *key, char dic[][MAX_WORD_SIZE])
{

	return(bsearch(key, dic, N_WORDS, MAX_WORD_SIZE, comp));
	

}
