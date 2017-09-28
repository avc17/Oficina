#include "dicionario.h"
#include <stdio.h>
#include <string.h>

char dic[N_WORDS][MAX_WORD_SIZE];
int eh_letra (int c)
{
	if (((c >= 65) && (c<=90)) || 
	   ((c>=97) && (c <= 122)) || 
	   ((c >= 192) && (c <= 195)) ||
	   (c == 199) || ((c >= 201) && 
	   (c <= 202) ) || (c == 205) ||
	   ((c >= 211) && (c <= 213)) || 
	   (c == 218) || ((c >= 224) &&
	   (c <= 227)) || (c == 231) ||
	   ((c >= 233) && (c <= 234)) || 
	   (c == 237) || ((c >= 243) && 
	   (c <= 245)) || (c == 250) || 
	   (c == 252) || (c == 220))
		return 1;
	return 0;

}

int minuscula (unsigned char palavra[], int tam)
{
unsigned char str[25];
int i;

	//strcpy(str, palavra);
	i = 0;
	if (pertence(palavra, dic) != NULL )
		return 1;
		
 	if (((palavra[i] >= 'A') && (palavra[i] <= 'Z')) || ((palavra[i] >= 192) && (palavra[i] <= 218))) 
		str[i] = palavra[i];
	else
		str[i] = palavra[i] + 32;

	for (i = 1; i <= tam; i++)
	{
    
 		 if (((palavra[i] >= 'A') && (palavra[i] <= 'Z')) || ((palavra[i] >= 192) && (palavra[i] <= 218))) 
			    str[i] = palavra[i] + 32;
		 else
			    str[i] = palavra[i];
	}  
	if (pertence(str,dic) != NULL)
		return 1;
                 		
	for (i = 0; i <= tam; i++)
	{
    
 		 if (((palavra[i] >= 'A') && (palavra[i] <= 'Z')) || ((palavra[i] >= 192) && (palavra[i] <= 218))) 
			    str[i] = palavra[i] + 32 ;
		 else
			    str[i] = palavra[i];  
                 		
	}
	if (pertence(str,dic) == NULL)
		return 0;
	return 1;
}





int main()
{
int c;
unsigned char palavra[25];
int i;
	ler_dicionario(dic);
	c = getchar();
	//for (i = 0; i <= N_WORDS; i++)
	//	printf("%s",dic[i]);
	
	while (c != EOF)
	{
		
		
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
			if (minuscula(palavra,i))
				printf("%s",palavra);
			else
				printf("[%s]",palavra);
		}
		
			printf("%c",c);
			c = getchar();

	}

}
