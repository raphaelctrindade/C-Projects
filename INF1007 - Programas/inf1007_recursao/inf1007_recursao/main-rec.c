#include <stdio.h>
#include <stdlib.h>


void exibeVetRec(int *vet, int n);
void exibeParesRec(int *vet, int n);
int contaParesRec(int *vet, int n);

int main(void)
{
	int v[4] = {33, 22, 55, 44};
	int tp;

	exibeVetRec(v, 4);
	exibeParesRec(v, 4);
	tp = contaParesRec(v, 4);

	printf("%d\n", tp);

	return 0;
}

void exibeVetRec(int *vet, int n)
{
	if(n == 0)
	{
		printf("\n");
		return;
	}
	printf("%d \n", vet[0]);

	exibeVetRec(&vet[1], n-1);
}

void exibeParesRec(int *vet, int n)
{
	if(n == 0)
	{
		printf("\n");
		return;
	}

	else if(vet[0] % 2 == 0)
		printf("%d \n", vet[0]);
	
	exibeParesRec(&vet[1], n-1);
}

int contaParesRec(int *vet, int n)
{
	if(n == 0)
		return 0;


	if(vet[0] % 2 == 0)
		return(1 + contaParesRec(&vet[1], n-1));
	else
		return contaParesRec(&vet[1], n-1);;

}