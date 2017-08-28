#include "lcrandom.h"


unsigned long A = 40692, C = 127, M = 10000000, x;


unsigned long lcrandom()
{

	x=(A*x+C) % M;
	return x;
}

void lcrandom_seed (unsigned long s);
{
	x = s;
	
}	

unsigned long lcrandom_max()
{
	return M-1;

}

void lcrandom_parms (unsigned long A2, unsigned long C2, unsigned long M2)
{

	A = A2;
	C = C2;
	M = M2;

}
