/* 
0 = Mês não pago
1 = Mês pago
*/


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int apt = 0;
	int m1=0, m2=0, m3=0, m4=0, m5=0, m6=0;
	int lnegra=0;
	
	FILE* ent = fopen("predio.txt", "r");
	
	if(ent == NULL){
		exit(1);
	}
	
	while(fscanf(ent, "%d %d %d %d %d %d %d", &apt, &m1, &m2, &m3, &m4, &m5, &m6)==7){
		if(m1+m2+m3+m4+m5+m6 <= 3){
			lnegra++;
		}
		
	}
	
	printf("Total de apartamentos na lista negra: %d", lnegra);
	
	fclose(ent);

	return 0;
}
