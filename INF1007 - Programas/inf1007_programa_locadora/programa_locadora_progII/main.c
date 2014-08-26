#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct filme
{
	char tit[51];
	int ano;
	int qtdTotal;
	int qtdEmp;
	float preco;
};

typedef struct filme Filme;
/* ate aqui nenhuma variavel foi criada */


void exibeFilme(Filme fil);

int verificaDisponivel(Filme fil, char *titProcurado);

void aumentaTotal(Filme *pfil, char *titProcurado, int inc);


int main(void)
{
	Filme fa, fb;
	char auxTit[51]; /* Auxiliar para ler uma cadeia do teclado */
	int respDisp; /*	Auxiliar para ler resposta */

	strcpy(fa.tit, "Raiva");
	fa.ano = 1999;
	fa.qtdTotal = 10;
	fa.qtdEmp = 2;
	fa.preco = 6.0;

	strcpy(fb.tit, "Briga");
	fb.ano = 2012;
	fb.qtdTotal = 5;
	fb.qtdEmp = 1;
	fb.preco = 8.0;

	/*Exibe filmes direto da main */
	/*
	printf("================================================");
	printf("\nFilmes:\n");
	printf("================================================\n");
	printf("%s\t%d\t%d\t%d\t%.2f \n\n", fa.tit, fa.ano, fa.qtdTotal, fa.qtdEmp, fa.preco);
	printf("%s\t%d\t%d\t%d\t%.2f \n\n", fb.tit, fb.ano, fb.qtdTotal, fb.qtdEmp, fb.preco);
	*/

	exibeFilme(fa);
	exibeFilme(fb);

	printf("\nEntre com o titulo desejado: ");
	scanf("%[^\n]", &auxTit);

	printf("\nTitulo: %s\n", auxTit);
	printf("================================\n\n");

	respDisp = verificaDisponivel(fa, auxTit);

	if(respDisp == 0)
		printf("Titulo nao encontrado\n\n");
	else if (respDisp == 1)
		printf("Titulo com quantidade disponivel\n\n");
	else
		printf("Titulo com quantidade indisponivel\n\n");

	respDisp = verificaDisponivel(fb, auxTit);

	if(respDisp == 0)
		printf("Titulo nao encontrado\n\n");
	else if (respDisp == 1)
		printf("Titulo com quantidade disponivel\n\n");
	else
		printf("Titulo com quantidade indisponivel\n\n");

	exibeFilme(fa);
	aumentaTotal(&fa, auxTit, 12);
	exibeFilme(fa);


	return 0;
}

void exibeFilme(Filme fil){

	printf("DADOS DO FILME:\n");
	printf("%s\t%d\t%d\t%d\tR$%.2f \n\n", fil.tit, fil.ano, fil.qtdTotal, fil.qtdEmp, fil.preco);
}

int verificaDisponivel(Filme fil, char *titProcurado)
{
	if(strcmp(fil.tit,titProcurado)!=0)
		return 0;
	if(fil.qtdTotal > fil.qtdEmp)
		return 1;
	else
		return -1;
}

void aumentaTotal(Filme *pfil, char *titProcurado, int inc)
{
	if(strcmp(pfil->tit,titProcurado)==0)
	{
		pfil->qtdTotal = pfil->qtdTotal + inc;
		printf("\nQuantidade Total atualizada!\n\n");
	}
	else
		printf("\nErro ao incremetar: Titulo nao encontrado\n\n");




}
