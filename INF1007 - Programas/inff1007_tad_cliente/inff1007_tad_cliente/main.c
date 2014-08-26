#include <stdio.h>
#include <stdlib.h>
#include "cliente.h" // Carrega funções do cliente.c pelo cliente.h

int main(void)
{
	Cliente*pUmCli;
	Cliente*vpcli[4];
	int i;
	int CPFlido = 333;

	pUmCli = cliCria("Luiz", 888, 50.50f);

	cliExibe(pUmCli);
	cliLibera(pUmCli);

	vpcli[0] = cliCria("Bia", 222, 80.50f);
	vpcli[1] = cliCria("Leo", 444, 90.50f);
	vpcli[2] = cliCria("Ana", 333, 10.50f);
	vpcli[3] = cliCria("Rui", 777, 60.50f);

	for(i=0;i<4;i++)
		cliExibe(vpcli[i]);

	for(i=0;i<4;i++)
		if(cliObtemCPF(vpcli[i]) == CPFlido)
		{
			printf("Ultimo Valo: %.2f\n", cliObtemUltValor(vpcli[i]));
			break;
		}

	return 0;
}
