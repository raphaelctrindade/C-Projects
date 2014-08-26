#include <stdio.h>

// Não está mostrando o melhor aluno caso tenha mais de um aluno

int calc_melhor_aluno(void){
 	int id, melhorId;
	float media, maiorMedia;
	int i=1;
	
	printf("Matricula e a nota do %do aluno: ", i);
	scanf("%d %f", &id, &media);
	
	melhorId = id;
	maiorMedia = media;
	
	while(id > 0){
		printf("Matricula e a nota do %do aluno: ", ++i);
		scanf("%d %f", &id, &media);
		
		if(media > maiorMedia){
			maiorMedia = media;
			melhorId = id;
		}
	}
	
	if(melhorId<0){
		return -1;
	}

	return melhorId;
	
}



int main(void) {
	
	int id;
	
	id = calc_melhor_aluno();
	
	printf("O melhor aluno tem matricula %d", id);
	
	return 0;
	
	
}