#include <stdio.h>

int main(void){
	float nota1, nota2, nota3, media, media_faculdade;
	printf("Entre com o valor da media de sua Faculdade: ");
	scanf("%f", &media_faculdade);
	printf("Entre com a nota da P1: ");
	scanf("%f", &nota1);
	printf("Entre com a nota da P2: ");
	scanf("%f", &nota2);
	printf("Entre com a nota da P3: ");
	scanf("%f", &nota3);
	media = (nota1 + nota2 + nota3)/3;
	if(media >= media_faculdade)
		printf("\nAluno Aprovado!");
	else
		printf("\nAluno Reprovado");
		
		printf("\n\nSua média: %f", media);
		
		return 0;
	
}