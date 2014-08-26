#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char cfis(float p , float a , char s ){
	float IMC;
	char letra;

	IMC=p/(a*a); // Cálculo matemático do IMC

	// IMC PARA HOMEM
	if(s=='H'){ 
		if(IMC<20.7)
			return 'A'; // 
		else if(IMC>=20.7 && IMC<=26.4)
			return 'B';
		else
			return 'C';
	}

	// IMC PARA MULHER
	if(s=='M'){ 
		if(IMC<19.1)
			return 'A';
		else if(IMC>=19.1 && IMC<=25.8)
			return 'B';
		else
			return 'C';
	}
}

/* Função que codifica o nome da pessoa */
char * codifica(char * nome){
	int tam, i;
	
	tam = strlen(nome);
	//printf("%d", tam)
	
	//printf("%c", nome[0]);
	
	for (i=0;i<tam;i++){
		
		if(nome[i] >= 110 && nome[i] <=122) // verifica letras minusculas entre "n" e "z"
			nome[i]=nome[i]-13;
		else if(nome[i] >= 78 && nome[i] <=90) // verifica letras maiusculas entre "N" e "Z"
			nome[i]=nome[i]-13;
		else if(nome[i]==32) // verfica "espaço˜
			nome[i]=nome[i];
		else // verifica todas as outras letras restantes
			nome[i]=nome[i]+13;
		
	}
	//printf("%s\n", nome);
	
	
	return nome;
}



/* Função que lê os dados das pessoas de um arquivo TXT*/
int le_arq(float p, float a, char s){
	char nome[40];
	int n,i=0;

	FILE * fp;

	fp = fopen ("pessoas.txt", "r"); // Abre arquivo .txt no modo READ

	if (fp == NULL) { // Código para caso não consiga abrir o arquivo .txt
		printf("Erro na abertura do arquivo.\n");
		return 1;
	}

	while(fscanf(fp, "%f %f %c %[^\n]s",&p, &a, &s, nome)==4){ //Lê os 4 dados de cada linha até a última
		printf("%s\nPeso:\t\t%.1fkg\nAltura:\t\t%.2fm\nSexo:\t\t(%c)\n",codifica(nome), p, a, s); //Imprime na tela os dados de cada pessoa lida no arquivo
		
		
		// Código que verifica os dados lidos e envia para a função cfis que calcula o IMC e imprime na tela o resultado
		if(cfis(p, a, s)=='A')
			printf("Abaixo do peso ideal");
		else if(cfis(p, a, s)=='B')
			printf("Peso normal");
		else if(cfis(p, a, s)=='C')
			printf("Acima do peso ideal");
		printf("\n\n***********************************\n\n");
	
	}

	fclose(fp);
	
	return i;
}


int main(void){
	int nump, i=0, numparq=0;
	float altura=0, peso=0;
	char s;


	numparq = le_arq(peso, altura, s); // carrega a funçao de leitura do arquivo .txt




// O código abaixo é caso queira fazer a leitura dos dados das pessoas via teclado (sem o arquivo .txt) 

/*
	printf("Entre com o numero de pessoas a serem verificadas: "); // verifica o número de pessoas a serem lidas
	scanf("%d", &nump);

	// Laço de repetição para serem inseridos os dados das pessoas 
	for(i=0; i<nump; i++){
		printf("\nPeso: ");
		scanf("%f", &peso);
		printf("Altura: ");
		scanf("%f", &altura);
		printf("Homem (H) ou Mulher (M)? ");
		scanf("%s", &s);
		
		
		// Código que verifica os dados lidos e envia para a função cfis que calcula o IMC e imprime na tela o resultado
		if(cfis(peso, altura, s)=='A')
			printf("Abaixo do peso ideal");
		else if(cfis(peso, altura, s)=='B')
			printf("Peso normal");
		else if(cfis(peso, altura, s)=='C')
			printf("Acima do peso ideal");
		printf("\n\n---------------------------\n\n");

		
	}
*/

	return 0;

}