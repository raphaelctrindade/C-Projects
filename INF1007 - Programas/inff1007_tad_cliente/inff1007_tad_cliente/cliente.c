/*
Arquivo: cliente.c
"arquivo de implementação do TAD Cliente"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

struct cliente
{
	char nomeDoCliente[81];
	int CPF;
	float valorUltPedido;
};

Cliente*cliCria(char*n,int cpf, float ultValor)
{
	Cliente *novo;

	novo = (Cliente*)malloc(sizeof(Cliente));

	novo->CPF = cpf;
	novo->valorUltPedido = ultValor;
	strcpy(novo->nomeDoCliente,n);

}

int cliObtemCPF(Cliente*pcli)
{
	return pcli->CPF;
}

float cliObtemUltValor(Cliente*pcli)
{
	return pcli->valorUltPedido;
}

void cliExibe(Cliente*pcli);
void cliLibera(Cliente*pcli)
{
	free(pcli);
}