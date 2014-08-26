#include <stdio.h>

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y){
	int valor;
	
	if((x > x0) && (x < x1) && (y > y0) && (y < y1))
		valor = 1;
	else
		valor = 0;
		
	return valor;
}


int main(void){
	int x, y;
	int x0, y0;
	int x1, y1;
	
	printf("Entre com a posicao do ponto x0: ");
	scanf("%d", &x0);
	printf("Entre com a posicao do ponto y0: ");
	scanf("%d", &y0);
	printf("Entre com a posicao do ponto x1: ");
	scanf("%d",&x1);
	printf("Entre com a posicao do ponto y1: ");
	scanf("%d",&y1);
	printf("Entre com a posicao do ponto x: ");
	scanf("%d",&x);
	printf("Entre com a posicao do ponto y: ");
	scanf("%d",&y);
	
	
	printf("\nRESPOSTA: %d", dentro_ret(x0, y0, x1, y1, x, y));
	return 0;	
}