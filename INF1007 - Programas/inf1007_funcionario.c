#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
	int mes;
	int ano;
};

typedef struct data Data;

struct funcionario
{
	char nome[51];
	float sal;
	Data dtAdm;
	Data dtDem;
};

typedef struct funcionario Funcionario;

Funcionario * criaFuncionario(char * nm, float s, int ma, int aa, int md, int ad);

void mostraFun(Funcionario *fun);

int main(void)
{
	Funcionario *pfu1;
	
	pfu1 = criaFuncionario("lia", 2000, 9, 2010, 5, 2013);

	mostraFun(pfu1);

	free(pfu1);


	return 0;
}

Funcionario * criaFuncionario(char * nm, float s, int ma, int aa, int md, int ad)
{
	Funcionario *pnovo;

	pnovo=(Funcionario*)malloc(sizeof(Funcionario));

	if(pnovo == NULL)
	{
		printf("Erro");
		return NULL;
	}

	strcpy(pnovo->nome,nm);
	pnovo->sal=s;
	pnovo->dtAdm.mes=ma;
	pnovo->dtAdm.ano=aa;
	pnovo->dtDem.mes=md;
	pnovo->dtDem.ano=ad;

	return pnovo;
}

void mostraFun(Funcionario *fun)
{
	printf("%s\t%.2f\t%d\t%d\t%d\t%d", fun->nome, fun->sal,fun->dtAdm.mes,fun->dtAdm.ano,fun->dtDem.mes,fun->dtDem.ano);
}