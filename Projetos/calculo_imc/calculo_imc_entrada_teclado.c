#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char cfis(float p , float a , char s ){
	float IMC;
	char letra;

	IMC=p/(a*a);

	if(s=='H'){ // IMC PARA HOMEM
		if(IMC<20.7)
			return 'A'; // 
		else if(IMC>=20.7 && IMC<=26.4)
			return 'B';
		else
			return 'C';
	}

	if(s=='M'){ // IMC PARA MULHER
		if(IMC<19.1)
			return 'A';
		else if(IMC>=19.1 && IMC<=25.8)
			return 'B';
		else
			return 'C';
	}
}



/*
int le_arq(float p, float a, char s){
	char nome[40];
	int n,i;

	FILE * fp;

	fp = fopen ("pessoas.txt", "r");

	if (fp == NULL) {
		printf("Erro na abertura do arquivo.\n");
		return 1;
	}

	while(fscanf(fp, "%f %f %c %s ",&p, &a, &s, nome)==4){
	}

	fclose(fp);

}

*/
int main(void){
	int nump, i=0;
	float altura=0, peso=0;
	char s;

	printf("Entre com o numero de pessoas a serem verificadas: ");
	scanf("%d", &nump);


	for(i=0; i<nump; i++){
		printf("\nPeso: ");
		scanf("%f", &peso);
		printf("Altura: ");
		scanf("%f", &altura);
		printf("Homem (H) ou Mulher (M)? ");
		scanf("%s", &s);
		
		
		if(cfis(peso, altura, s)=='A')
			printf("Abaixo do peso ideal");
		else if(cfis(peso, altura, s)=='B')
			printf("Peso normal");
		else if(cfis(peso, altura, s)=='C')
			printf("Acima do peso ideal");
		printf("\n\n---------------------------\n\n");

		
	}
	

	return 0;

}