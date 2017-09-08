//ANDREY VASCONCELOS CHAVES GRR20172630
#include "lcrandom.h"

// A, C, M e x são variaveis globais pois serão usados por mais de uma função.
unsigned long A = 40692, C = 127, M = 10000000, x = 0;

// calcula e devolve um valor pseudoaleatório
unsigned long lcrandom()
{
	x = ((A*x+C) % M);	
	return x;
}

// define o valor inicial (semente) da sequência de aleatórios
void lcrandom_seed (unsigned long s)
{
	x = s;
	
}	

// informa o valor máximo que pode ser gerado (o mínimo é sempre zero)
unsigned long lcrandom_max()
{
	return M-1;

}

// modifica os parâmetros da equação do gerador
void lcrandom_parms (unsigned long A2, unsigned long C2, unsigned long M2)
{

	A = A2;
	C = C2;
	M = M2;
}
