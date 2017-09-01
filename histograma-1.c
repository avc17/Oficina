#include <stdio.h>
#include "lcrandom.h"
#define MAXVALORES 1000000  // 10^6
#define TAM 100

int regra_de_tres (int y)
{
	return (5*y/10);
}



int main ()
{
int v[TAM];

	for (i = 0; i < MAXVALORES; i++)
	{
		v[lcrandom() % 100] = v[lcrandom() % 100] + 1;	
	} 

}

