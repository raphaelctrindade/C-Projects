#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * criaNovaCadeia(void);
void exibeVetDeCadeias(char *v[], int nc);
int buscaNoVet(char * v[], int nc, char * cproc);

int main (void)
{
	char *vpcad[50];
	int ncad, i, pos;
	char cadProc[51];

	printf("Entre com o numero de cadeias (ate 50): ");
	scanf("%d", &ncad);
	for(i=0;i<ncad;i++)
		vpcad[i]=criaNovaCadeia();
	exibeVetDeCadeias(vpcad, ncad);
	
	printf("Entre com a cadeia a ser procurada: ");
	scanf(" %[^\n]", cadProc);
	pos = buscaNoVet(vpcad, ncad, cadProc);

	if(pos!=-1)
		printf("Esta na posicao: %d\n\n", pos);
	else
		printf("Nao encontrado\n\n");

	for(i=0;i<ncad;i++)
		free(vpcad[i]);
		
	return 0;
}

char * criaNovaCadeia(void)
{
	char * cad;
	char cadAux [51];
	int tam, i, j=0;

	printf("Cadeia: "); 
	scanf(" %[^\n]", cadAux);

	tam = (strlen(cadAux) + 1);

	cad = (char*) malloc (tam*sizeof(char));

	if(cad == NULL)
	{
		printf("Erro na alocacao");
		exit(1);
	}

	for(i=0;i<tam;i++)
	{
		cad[i] = cadAux[j];
		j++;
	}

	return cad;
}

void exibeVetDeCadeias(char *v[], int nc)
{
	int i;

	printf("\n************* EXIBINDO CADEIAS *************\n\n");

	for(i=0;i<nc;i++)
	{
		printf("%s\n", v[i]);
	}

	printf("\n");
}

int buscaNoVet(char * v[], int nc, char * cproc)
{
	int i, pos;

	for(i=0;i<nc;i++)
	{
		if((strcmp(v[i], cproc))==0)
			return i;
	}

	return -1;

}