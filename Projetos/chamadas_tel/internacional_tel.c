#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	FILE *ent, *sai;
	int id, quant, i;
	float dur, soma_dur, soma_tudo;


	ent = fopen("ci.txt", "r");
	
	if(ent==NULL){
		printf("Erro ao abrir arquivo de entrada\n");
		exit(1);
	}
	
	sai = fopen("totais.txt", "w");
	
	if(sai==NULL){
		printf("Não foi possível abrir arquvio de saída\n");
		fclose(ent);
		exit(1);
	}
	
	soma_tudo = 0.0;
	
	while (fscanf(ent,"%d %d", &id, &quant)==2){
		if(quant>0){
			soma_dur = 0.0;
			fprintf(sai, "ID: %d - ", id);
			for (i=0;i<quant;i++){
				fscanf(ent,"%f", &dur);
				soma_dur += dur;
			}
			fprintf(sai,"Duração chamada: %.1f\n", soma_dur);
			soma_tudo += soma_dur;
		}
	}
	fprintf(sai,"========================================================\n");
	fprintf(sai,"Duração Geral:%.1f", soma_tudo);
	
	fclose(ent);
	fclose(sai);
	
	return 0;	
}