#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data
{ 
	int dia, mes, ano;
};

typedef struct data Data;

struct concursado
{ 
	int ident;
	char nome[51];
	float nota;
	Data nasc;
};

typedef struct concursado Concursado;

void exibeVetConc (Concursado *vc, int n);

/* funcoes da aula de hoje */

void exibeVetPontConc (Concursado **vp, int n);
void bolhaCrescIdent (Concursado **vp, int n);
int compara (Concursado *c1, Concursado *c2);
void bolhaDecNotaCrescIdade (Concursado **vp, int n);

int main (void)
{
	Concursado vconc[10] ={ {444, "leo", 6.5f, {20, 10, 1990}}, {555, "ivo", 8.5f, {17, 11, 1992}}, 
							{111, "ana", 8.5f, {20, 12, 1995}}, {442, "rui", 6.5f, {30, 11, 1990}}, 
							{666, "eva", 4.6f, {13, 10, 1991}}, {339, "bia", 8.5f, {22, 11, 1990}}, 
							{101, "teo", 5.4f, {20, 12, 1990}}, {885, "uli", 4.3f, {24, 12, 1993}}, 
							{222, "edu", 6.5f, {11, 10, 1990}}, {330, "lea", 4.6f, {15, 10, 1990}} };

Concursado * vpontA[10];
Concursado * vpontB[10];

int i;

for (i = 0; i< 10; i++)
{ 
	vpontA[i] = &vconc[i];
	vpontB[i] = &vconc[i];
}

exibeVetConc (vconc, 10);
exibeVetPontConc(vpontA, 10);
bolhaCrescIdent(vpontA, 10);
exibeVetPontConc(vpontA, 10);
exibeVetPontConc(vpontB, 10);
bolhaDecNotaCrescIdade(vpontB, 10);
exibeVetPontConc(vpontB, 10);

return 0;

}

void exibeVetConc (Concursado *vc, int n)
{
	int i;

	printf("\nConcursados:\n");
	
	for (i=0; i<n; i++)
		printf("%d\t%s\t%.2f\t%d/%d/%d\n", vc[i].ident, vc[i].nome, vc[i].nota, vc[i].nasc.dia, vc[i].nasc.mes, vc[i].nasc.ano);
}

/* funcoes da aula de hoje */

void exibeVetPontConc (Concursado **vp, int n)
{
	int i;

	printf("\nConcursados:\n");
	
	for (i=0; i<n; i++)
		printf("%d\t%s\t%.2f\t%d/%d/%d\n", vp[i]->ident, vp[i]->nome, vp[i]->nota, vp[i]->nasc.dia, vp[i]->nasc.mes, vp[i]->nasc.ano);

}

void bolhaCrescIdent (Concursado **vp, int n)
{
	int i, fim;
	Concursado * aux;
	int troca;

	for(fim=n-1;fim>0;fim--)
	{
		troca = 0;
		for(i=0;i<fim;i++)
		{
			if(vp[i]->ident > vp[i+1]->ident)
			{
				aux = vp[i];
				vp[i]=vp[i+1];
				vp[i+1] = aux;
				troca = 1;
			}
		}
		if(troca == 0)
			return;
	}
}


int compara (Concursado *c1, Concursado *c2)
{ 
	if(c1->nota < c2->nota)
		return 1;
	if(c1->nota > c2->nota)
		return -1;
	if(c1->nota == c2->nota)
	{
		if(c1->nasc.ano == c2->nasc.ano)
		{
			if(c1->nasc.mes == c2->nasc.mes)
			{
				if(c1->nasc.dia > c2->nasc.dia)
					return 1;
				else if(c1->nasc.dia > c2->nasc.dia)
					return -1;
				else
					return 0;
			}
			else if(c1->nasc.mes > c2->nasc.mes)
				return 1;
			else
				return -1;
		}
		else if(c1->nasc.ano > c2->nasc.ano)
			return 1;
		else
			return -1;
	}		
}

void bolhaDecNotaCrescIdade (Concursado **vp, int n)
{
	int i, fim;
	Concursado * aux;
	int troca;

	for(fim=n-1;fim>0;fim--)
	{
		troca = 0;
		for(i=0;i<fim;i++)
		{
			if(compara(vp[i], vp[i+1])==1)
			{
				aux = vp[i];
				vp[i]=vp[i+1];
				vp[i+1] = aux;
				troca = 1;
			}
		}
		if(troca == 0)
			return;
	}
}