#include <stdio.h>
#include "operandoDoisInt.h"

int main(void)
{
	int a, b;

	printf("Entre com dois inteiros: ");
	scanf("%d %d", &a, &b);

	printf("\nSOMA:\t\t%d\n", calcSoma(a,b));
	printf("PRODUTO:\t%d\n", calcProd(a,b));
	printf("MAIOR:\t\t%d\n\n", obtemMaior(a,b));

	return 0;
}