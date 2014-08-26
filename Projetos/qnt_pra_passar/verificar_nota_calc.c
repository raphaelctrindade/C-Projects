#include <stdio.h>

int main(){
	float nota1=0, nota2=0, nota3=0, media;
	int qtprovas, provasfeitas;
	
	printf("Quantidade de Provas: ");
	scanf("%d", &qtprovas);
	printf("Provas Realizadas: ");
	scanf("%d", &provasfeitas);
	
	if(provasfeitas == 1){
		printf("Entre com a nota da G1: ");
		scanf("%f", &nota1);
		printf("Falta %.1f para passar faltando %d prova(s) para fazer!", 15 - nota1, qtprovas - provasfeitas);
	}
	
	else if(provasfeitas == 2){
		printf("Entre com a nota da G1: ");
		scanf("%f", &nota1);
		printf("Entre com a nota da G2: ");
		scanf("%f", &nota2);
		printf("Falta %.1f para passar faltando %d prova(s) para fazer!", 15 - (nota1 + nota2), qtprovas - provasfeitas);
		}
	//else if
	
	return 0;
	
	
}