#include <stdio.h>
#include <stdlib.h>

#define MAX_APT 999

int le_arq(int mat[][7], int apt[36]){
	int i=0;
	int n=0;
	int num_apt=0;
	FILE* fp = fopen("predio.txt", "r");
	
	if(fp == NULL){
		exit(1);
	}
	
	while (fscanf(fp, "%d", &apt[i]) == 1) {
			n = apt[i];
			fscanf(fp, "%d %d %d %d %d %d", &mat[n][0], &mat[n][1], &mat[n][2], &mat[n][3], &mat[n][4], &mat[n][5]);
			num_apt++;
			i++;
			}

	
	return num_apt;
}

/*################################################################*/

int busca_apt(int mat[][7], int apt[36], int entrada, int n){
	int i;
	
	for(i=0;i<n;i++){
		if(apt[i]==entrada){
			if(mat[apt[i]][6] <=3)
				printf("*Lista Legra*");
			else
				printf("Não está na lista negra");
			return apt[i];
		}
		
	}
	
	if(entrada < 0)
		printf("Numero invalido");
	else	
	printf("Apartamento não encontrado");
	
	return 0;
}

/*################################################################*/

void mostra_lnegra(int mat[][7], int apt[36], int n){
	int i;
	
	
	printf("# LISTA NEGRA #########\n");
	for(i=0;i<n;i++){
		if(mat[apt[i]][6]<=3)
			printf("# Apartamento: %d    #\n", apt[i]);
	}
	printf("#######################");
}

/*################################################################*/

int lista_negra(int mat[][7], int apt[36], int n){
	int i, lnegra=0;
	
	for(i=0;i<n;i++){
		mat[apt[i]][6] = mat[apt[i]][0] + mat[apt[i]][1] + mat[apt[i]][2] + mat[apt[i]][3] + mat[apt[i]][4] + mat[apt[i]][5];
		//printf("%d\n", mat[apt[i]][6]);
		if(mat[apt[i]][6] <= 3){
			//printf("Apartamento: %d\n", apt[i]);
			lnegra++;
		}
	}
	
	return lnegra;
}

/*################################################################*/

int main(void) {
	int mat[MAX_APT][7];
	int num_apt, i, lnegra, numBusca, busca;
	int apt[36];
	char comando[10];

	
	num_apt = le_arq(mat, apt);
	lnegra = lista_negra(mat, apt, num_apt);
	
	printf("====================================\n");
	printf("Numero total de apts: %d\n", num_apt);
	printf("Numero de apts na *lista negra*: %d\n", lnegra);
	printf("====================================\n\n");
	
	mostra_lnegra(mat, apt, num_apt);
	
	printf("\n\nDigite o numero do apartamento que deseja buscar: ");
	scanf("%d", &numBusca);
	
	busca = busca_apt(mat, apt, numBusca, num_apt);
	
	
	while (numBusca >= 0) {
		printf("\n\nDigite o numero do apartamento que deseja buscar: ");
		scanf("%d", &numBusca);
		busca = busca_apt(mat, apt, numBusca, num_apt);
	}
	
	printf("\n\nFim do programa");
	
	
	
	
	
	
	/* TESTES */


//	IMPRIME APARTAMENTOS LIDOS NA FUNÇÃO LE_ARQ E SEUS PAGAMENTOS
//	for(i=0;i<num_apt;i++){
//		printf("%d\n", apt[i]);
//		printf("%d %d %d %d %d %d \n\n", mat[apt[i]][0], mat[apt[i]][1], mat[apt[i]][2], mat[apt[i]][3], mat[apt[i]][4], mat[apt[i]][5]);
//		if(apt[i] == 0){
//			return 0;
//		}
//	}
	
}
