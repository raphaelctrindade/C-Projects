#include <stdio.h>
#include <stdlib.h>


void exibeVetor(int *vidade, int n)
{
	int i;

	printf("\nExibindo idades\n");
	for(i=0;i<n;i++)
		printf("%d\t", vidade[i]);
}

void obtemMenoresIdosos(int *vet, int n, int *ptMenores, int *ptMaiores, float *ptMedia)
{
	int i;
	//int soma;

	*ptMenores = 0;
	*ptMaiores = 0;
	*ptMedia = 0;

	for(i=0;i<n;i++)
	{
		if(vet[i]<18)
			(*ptMenores)++;
		else if(vet[i]>60)
			(*ptMaiores)++;
		*ptMedia = *ptMedia + vet[i];
	}
	
	*ptMedia = *ptMedia/n;
}


int main(void)
{
	int vet[10];
	int i,j=0;
	int menores, maiores;
	float media;

	int *vnovo; /* variável ponteiro para receber o end incial do novo vetor,
				   que será alocado dinamicaments */
	int contNovo=0; /* contador de idades entre 20 e 45 anos*/



	for(i=0;i<10;i++)
	{
		printf("Idade: ");
		scanf("%d", &vet[i]);

		if(vet[i]>=20 && vet[i]<=45)
			contNovo++;
	}
	
	exibeVetor(vet,10);
	obtemMenoresIdosos(vet, 10, &menores, &maiores, &media);

	printf("\nMenores: %d", menores);
	printf("\nMaiores: %d", maiores);
	printf("\nMedia: %.2f\n\n", media);

	printf("=================================");
	printf("\nEntre 20 e 45\n");
	printf("=================================");
	printf("\nQuantidade: %d\n\n", contNovo);

	vnovo = (int*)malloc(contNovo*sizeof(int)); // Cria vetor em que o tamanho corresponde ao numero de idade entre 20 e 45

	if(vnovo == NULL)
	{
		printf("ERRO: Nao foi possivel alocar espaço");
		exit(1);
	}

	for(i=0;i<10;i++)
	{
		if(vet[i]>=20 && vet[i]<=45)
		{
			vnovo[j]=vet[i];
			j++;
		}
	}

	for(i=0;i<contNovo;i++)
		printf("%d\n", vnovo[i]);

	
	exibeVetor(vnovo,contNovo);
	printf("\n");

	free(vnovo);

	return 0;
}