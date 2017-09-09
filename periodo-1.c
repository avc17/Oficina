//ANDREY VASCONCELOS CHAVES GRR20172630
#include <stdio.h>
#include "lcrandom.h"
#define TAM 10000000

char v[TAM];

int main()
{
long i, cont = 0, aux;

	//inicia o vetor com zeros para fazer a comparação no while
	for (i = 0; i<TAM; i++)
		v[i] = '0';
	
	
	aux = lcrandom();
	while (v[aux] == '0')
	{
		v[aux] = '1';
		aux = lcrandom();
		cont++;
	}
	
	printf("%ld\n", cont);
}
