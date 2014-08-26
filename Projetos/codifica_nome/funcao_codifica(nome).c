#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
	printf("%s\n", nome);
	
	
	return nome;
}






int main(void){
	char nome[40];
	
	printf("Digite o nome a ser codificado: ");
	scanf("%[^\n]s", nome);
	//printf("%s\n", nome);
	
	codifica(nome);
	
	
	return 0;
}