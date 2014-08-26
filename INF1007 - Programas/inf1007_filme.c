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

void exibeFilme(Filme fil);
int verificaDisp(Filme fil, char *titProc);
void aumentaTotal(Filme *pfil, char *titProc, int acrescimo);
void leUmLivroDoTec(Filme *pfil);

int main(void){
	char titAux[51];
	int acrescimo;
	Filme f1,f2;
	
	strcpy(f1.tit,"Raiva");
	f1.ano=1999; f1.qtdTotal=10; f1.qtdEmp=2; f1.preco=6.0;
	
	strcpy(f2.tit,"Briga");
	f2.ano=2013; f2.qtdTotal=5; f2.qtdEmp=1; f2.preco=8.0;
	
	printf("Nome\tAno\t\tQtd Total\tQtdEmp\tPreco\n");
	
	exibeFilme(f1);
	exibeFilme(f2);
	
	printf("\nVerifica filme disponivel: ");
	scanf(" %[^\n]", titAux);
	
	printf("\n=== Testando 1o Filme ===\n");
	if(verificaDisp(f1, titAux)==0)
		printf("Nome não confere");
	else if (verificaDisp(f1, titAux)==1) {
		printf("Nome = [ok] | Disponibilidade = [ok]");
	}
	else
		printf("Nome = [ok] | Disponibilidade = [não]");

	printf("\n=== Testando 2o Filme ===\n");
	if(verificaDisp(f2, titAux)==0)
		printf("Nome não confere");
	else if (verificaDisp(f2, titAux)==1) {
		printf("Nome = [ok] | Disponibilidade = [ok]");
	}
	else
		printf("Nome = [ok] | Disponibilidade = [não]");		
	
	/* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX */
	/* Adicionar quantidade     			                    */
	/* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX */
	
	printf("\n\nNome do filme para adicionar quantitade: ");
	scanf("%s", titAux);
	printf("Quantitade: ");
	scanf("%d", &acrescimo);
	
	
	exibeFilme(f1);
	aumentaTotal(&f1, titAux, acrescimo);
	
	exibeFilme(f2);
	aumentaTotal(&f2, titAux, acrescimo);
	
	/* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX */
	/* Adicionar filme do teclado     			                */
	/* XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX */
	
	leUmLivroDoTec(&f1);
	leUmLivroDoTec(&f2);
		

}

void exibeFilme(Filme fil){
	
	printf("%s\t%d\t%d\t\t\t%d\t\t%.2f\n", fil.tit,fil.ano,fil.qtdTotal,fil.qtdEmp,fil.preco);
}

int verificaDisp(Filme fil, char *titProc)
{
	if(strcmp(fil.tit,titProc)==0){
		if((fil.qtdTotal-fil.qtdEmp)>0)
			return 1;
		else
			return -1;
	}
	else
		return 0;
}

void aumentaTotal(Filme *pfil, char *titProc, int n){
	if(strcmp(pfil->tit,titProc)==0)
	{
		pfil->qtdTotal = pfil->qtdTotal + n;
		printf("=== [%d] Unidade(s) adicionada(s) no filme [%s] === \n", n, titProc);
		exibeFilme(*pfil);
	}
}

void leUmLivroDoTec(Filme *pfil)
{
	printf("Nome: "); scanf("%s", pfil->tit);
	printf("Ano: "); scanf("%d", &pfil->ano);
	printf("QtdTotal: "); scanf("%d", &pfil->qtdTotal);
	printf("QtdEmprestada: "); scanf("%d", &pfil->qtdEmp);
	printf("Preco: "); scanf("%f", &pfil->preco);
	printf("Nome\tAno\t\tQtd Total\tQtdEmp\tPreco\n");
	exibeFilme(*pfil);
}