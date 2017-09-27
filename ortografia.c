#include "dicionario.h"
#include <stdio.h>
#include <string.h>

char dic[N_WORDS][MAX_WORD_SIZE];
int eh_letra (unsigned char c)
{
	if (((c >= 65) && (c<=90)) || ((c>=97) && (c <= 122)))
		return 1;
	return 0;

}

char *minuscula (unsigned char palavra[])
{
unsigned char str[25];
int i;

	//strcpy(str, palavra);
	i = 0;
	while (palavra[i] != '\0')
	{
    
 		 if ((palavra[i] >= 'A') && (palavra[i] <= 'Z')) 
			    str[i] = palavra[i] + 32 ;
		 else
			    str[i] = palavra[i];  
                 i++;		
	}
	return pertence(str,dic);
}





int main()
{
unsigned char c;
unsigned char palavra[25];
int i;
	ler_dicionario(dic);
	c = getchar();
	//for (i = 0; i <= N_WORDS; i++)
	//	printf("%s",dic[i]);	
	while (c != EOF)
	{
		//while (!eh_letra(c))	
	//	{
	//		printf("%c",c);
	//		c = getchar();
	//	}
		
		i = 0;
		while (eh_letra(c))
		{
			palavra[i] = c;
			c = getchar();
			i= i+1;
		}
		palavra[i] = '\0';
		if ( palavra[0] != '\0' )
		{
			if (minuscula(palavra))
				printf("%s",palavra);
			else
				printf("[%s]",palavra);
		}
		
		printf("%c", c);
		c = getchar();
	}

}
