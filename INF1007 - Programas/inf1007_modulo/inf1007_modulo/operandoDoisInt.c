/* arquivo de implementação operandoDoisInt.c */

#include "operandoDoisInt.h"

int calcSoma(int x, int y)
{
	return x + y;
}

int calcProd(int x, int y)
{
	return (x * y);
}

int obtemMaior(int x, int y)
{
	if(x>y)
		return x;
	else
		return y;
}
