#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidato{
	int		id;
	float	notaE;
	float	notaO;
};

typedef struct candidato Candidato;

Candidato *criaCandidato(int n, float nE, float nO);
void exibeCandidatos(Candidato **vp, int nCand);
float obtemNotaFinal(Candidato *c); 
int obtemMaiorNotaFinal(Candidato **vp, int nCand);
int verificaOrdenado(Candidato **vp, int nCand);
int buscaNoVetor(Candidato **vp, int nCand, int idProc);

int main(void)
{
	Candidato *vpCand[10];
	int qtdCand, i;
	int idAux, indMaiorNota, idBusca;
	float ntEAux, ntOAux;

	printf("Quantos candidatos deseja armazenar (1 a 10)?\n");
	scanf("%d", &qtdCand);

	for(i=0;i<qtdCand;i++)
	{
		printf("\nID:\t\t");			scanf("%d", &idAux);
		printf("Nota Escrita:\t");		scanf("%f", &ntEAux);
		printf("Nota Oral:\t");			scanf("%f", &ntOAux);

		vpCand[i] = criaCandidato(idAux, ntEAux, ntOAux);
	}

	exibeCandidatos(vpCand, qtdCand);

	//printf("%.2f",obtemNotaFinal(vpCand[0]));

	/* Verifica Maior Nota */	
	
	indMaiorNota = obtemMaiorNotaFinal(vpCand,qtdCand);
						
	if(indMaiorNota !=-1)
		printf("\n%d\t\t%.2f\t\t%.2f", vpCand[indMaiorNota]->id, vpCand[indMaiorNota]->notaE, vpCand[indMaiorNota]->notaO);
	
	/* Verifica Ordenação */
	
	if(verificaOrdenado(vpCand, qtdCand) == 1)
	{
		printf("\n\n** Está ordenado **");
	}
	else if(verificaOrdenado(vpCand, qtdCand) == -1)
	{
		printf("\n\n** Impossível Ordenar **");
	}
	else 
	{
		printf("\n\n** Não está ordenado **");
	}
	
	/* Verifica ID */
	
	printf("\n\nDigite o ID que deseja buscar: ");	scanf("%d", &idAux);
	
	idBusca = buscaNoVetor(vpCand, qtdCand, idAux);
	
	if(idBusca != -1)
	{
		printf("** ID encontrado **");
		printf("\n%d\t\t%.2f\t\t%.2f", vpCand[idBusca]->id, vpCand[idBusca]->notaE, vpCand[idBusca]->notaO);
	}
	else {
		printf("** ID não encontrado **");
	}


	

	return 0;
	
	for(i=0;i<qtdCand;i++)
		free(vpCand[i]);
}

Candidato *criaCandidato(int n, float nE, float nO)
{
	Candidato *c;

	c = (Candidato*) malloc (sizeof(Candidato));

	if(c==NULL)
	{
		printf("Erro");
		exit(1);
	}

	c->id = n;
	c->notaE = nE;
	c->notaO = nO;

	return c;
}


void exibeCandidatos(Candidato **vp, int nCand)
{
	int i;
	printf("\n\nInscricao\tNota Escrita\tNota Oral\n");
	for(i=0;i<nCand;i++)
		printf("\n%d\t\t%.2f\t\t%.2f", vp[i]->id, vp[i]->notaE, vp[i]->notaO);
	printf("\n\n");
}

float obtemNotaFinal(Candidato *c)
{
	return 0.6*c->notaE+0.4*c->notaO;
}


int obtemMaiorNotaFinal(Candidato **vp, int nCand)
{
	int i, indice=0;
	float maiorNota=0;
	float nFinal = 0;

	if(nCand == 0)
		return -1;
	
	maiorNota = obtemNotaFinal(vp[0]);

	for(i=0;i<nCand;i++)
	{
		nFinal = obtemNotaFinal(vp[i]);
		if(nFinal > maiorNota)
		{
			indice = i;
			maiorNota = nFinal;
		}
	}

	return indice;
}

int verificaOrdenado(Candidato **vp, int nCand)
{
	int i;
	
	if(nCand == 1)
		return -1;
	
	for(i=0;i<nCand;i++)
	{
		if(vp[i]->id > vp[i+1]->id)
			return 0;
	}
	return 1;
}

int buscaNoVetor(Candidato **vp, int nCand, int idProc)
{
	int i;
	
	for(i=0;i<nCand;i++)
	{
		if(idProc == vp[i]->id)
			return i;
	}
	return -1;
	
}
