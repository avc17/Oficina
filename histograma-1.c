//ANDREY VASCONCELOS CHAVES GRR20172630
#include <stdio.h>
#include "lcrandom.h"
#define MAXVALORES 1000000  // 10^6
#define TAM 100


int main ()
{
unsigned long v[TAM], i, j, maior = 0, aux;

	//preenche o vetor com 0 para a soma no proximo laço dar certo
	for (i = 0; i < TAM; i++)
	{
		v[i]=0;
	}	

	//gera o numero aleatorio e soma 1 no seu respectivo indice do vetor
	//usando variavel auxiliar pois v[(lcrandom() % TAM)] = (v[(lcrandom() % TAM)]+1) chama a função duas vezes e isso gera 2 valores diferentes
	for (i = 0; i < MAXVALORES; i++)
	{
		aux = (lcrandom() % 100);
		v[aux] = (v[aux]+1);	
	} 

	printf("   ");	
	for (i = 0; i <= TAM; i = i+10)
	{
		printf("%lu   ",i);
	}
	printf("\n");
	
	//3 espaços para alinhar com a coluna
	printf("   ");	
	for (i = 0; i <= TAM; i = i+10)
	{
		printf("+");
		//para nao gerar um "----" a mais, baseado no exemplo do site
		if ( i != TAM)
			printf("----");		
	}
	printf("\n");

	//identifica o maior elemento do vetor
	maior = 0;
	for (i = 0; i < TAM; i++)
	{
		if (v[i] > maior)
			maior = v[i];
	}
	
	for (i = 0; i < TAM; i++)
	{
		printf("%2lu |",i);
		
		//regra de tres usando o maior elemento do vetor como sendo o TAM do histograma
		for (j = 0; j < ((v[i]*50)/maior); j++)
			printf("*"); 	
		printf("\n");
	} 

	printf("   ");	
	for (i = 0; i <= TAM; i = i+10)
	{
		printf("+");
		
		if ( i != 100)
			printf("----");		
	}
	printf("\n");
	
	return 0;	

}

