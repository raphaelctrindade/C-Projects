#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILMES 100
#define MAX_NOME_FILME 32

/* Função para ler o arquivo txt e retornar o numero de filmes lidos */
int carrega_filmes(int cod[], float custo[], char nome[][33]){
	
	int i = 0;
	FILE* f = fopen("filmes.txt", "r"); // abre o arquivo filmes.txt
	
	/* verifica se consegue abrir o arquivo */
	if(f == NULL){
		printf("Erro ao abrir arquivo \"filmes.txt\"");
		exit(1);
	}
	
	while (fscanf(f, "%i %f %[^\n]", &cod[i], &custo[i], &nome[i]) == 3)
		i++;
	
	
	fclose(f);
	
	return i; // retorna o numero de filmes lidos
}

/* Função para buscar filme desejado */
int busca_filme(int n, char nome[][33], char filme[]){ 
	int i;
	
	for(i=0;i< n;i++){
		if(strcmp(nome[i], filme) == 0){ // compara se as 2 strings são iguais
			return i; // se a comparação for positiva, retorna o numero da posicao do filme desejado
		}
	}

	return -1;
}


int main(void){
	int codigo[100];
	float custo [100];
	char nome[100][32+1];
	char filme[32+1];
	int n, i;
	
	n = carrega_filmes(codigo, custo, nome);
	
	if(n == -1){
		printf("** Erro **\n");
		return -1;
	}
	
	printf("Digite o nome do filme: \n");
	scanf(" %32[^\n]", filme); 
	
	while(strcmp(filme, "#quit") != 0){
		i = busca_filme(n, nome, filme); 
		
		if (i != -1){
			printf("Codigo: %i || Custo: R$%.2f\n", codigo[i], custo[i]);
		}
		else
			printf("** Filme não encontrado **\n\n");
			
		printf("Digite o nome do filme: \n");
		scanf(" %32[^\n]", filme);
	}
	
	return 0;
}