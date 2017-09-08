//ANDREY VASCONCELOS CHAVES GRR20172630
#include <stdio.h>
#include "lcrandom.h"
#define MAXVALORES 1000000  // 10^6
#define TAM 100


int main ()
{
unsigned long v[TAM], i, j, maior = 0, aux;


	lcrandom_parms(1103515245,12345,2147483648);

	//preenche o vetor com 0 para a soma no proximo laço dar certo
	for (i = 0; i < TAM; i++)
	{
		v[i]=0;
	}	
	
	//gera o numero aleatorio e soma um no seu respectivo indice do vetor
	//usando variavel auxiliar pois v[(lcrandom() % 100)] = (v[(lcrandom() % 100)]+1) chama a função duas vezes e isso gera 2 valores diferentes	
	for (i = 0; i < MAXVALORES; i++)
	{
		aux = (lcrandom() % 100);
		v[aux] = (v[aux]+1);	
	} 
	
	printf("   ");//3 espaços para alinhar
	
	for (i = 0; i <= TAM; i = i+10)
	{
		printf("%lu   ",i);
	}
	printf("\n");
	
	printf("   ");	
	for (i = 0; i <= TAM; i = i+10)
	{
		printf("+");
		//para nao gerar um "----" a mais, baseado no exemplo do site
		if ( i != 100)
			printf("----");		
	}
	printf("\n");

	//identifica o maior elemento do vetor
	for (i = 0; i < TAM; i++)
	{
		if (v[i] > maior)
			maior = v[i];
	}
	
	for (i = 0; i < TAM; i++)
	{
		printf("%2lu |",i);

		for (j = 0; j < ((v[i]*50)/maior); j++)
			printf("*"); 
	
		printf("\n");
	} 

	printf("   ");	
	for (i = 0; i <= TAM; i = i+10)
	{
		printf("+");
		
		if ( i != TAM)
			printf("----");		
	}
	printf("\n");

	return 0;	

}

