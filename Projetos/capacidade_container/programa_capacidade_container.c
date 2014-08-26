#include <stdio.h>

int main(void){
	int arroz, container, doacoes, quantidade, valoratual;
	float media;
	
	printf("Digite a capacidade do container: ");
	scanf("%d", &container);
	
	arroz = doacoes = 0;
	
	while (arroz < container) {
		printf("\nQuantidade da doação: ");
		scanf("%d", &quantidade);
		
		if(arroz+quantidade <= container){
			valoratual = arroz+=quantidade;
			doacoes++;
			printf("Falta %d para completar o container.\n\n", container-valoratual);
		}
		else if(arroz+quantidade == container){
			printf("Container Completo\n");
		}
		else
		printf("Ultrapassou a capacidade permitida pelo container, digite novamente…\n");
	}
	
	media = arroz/(float)doacoes;
	printf("\n Quantidade media: %.2f", media);
	return 0;	
	
}