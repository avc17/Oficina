//ANDREY VASCONCELOS CHAVES GRR20172630
#include <stdio.h>
#include "lcrandom.h"
#define TAM 2147483648 

char v[TAM];

int main()
{
long i, cont = 0, aux;
	
	lcrandom_parms(1103515245, 12345, 2147483648);
	//inicia o vetor com zeros para que o while nao faça comparações com lixo de memoria
	for (i = 0; i<TAM; i++)
		v[i] = '0';
	
	
	aux = lcrandom();
	//insere 1 nos indices sorteados e para assim que encontrar um indice que contenha 1
	while (v[aux] == '0')
	{
		v[aux] = '1';
		aux = lcrandom();
		cont++;
	}
	
	printf("%ld\n", cont);
}
