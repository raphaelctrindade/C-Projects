#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n_alunos=0;
    FILE *ent;
    FILE *sai;
    int n=0;
    //int i=0;
    float soma=0;
    float nota1, nota2, nota3;
    float media, media_turma;

    ent = fopen("entrada.txt", "r");

    if(ent == NULL){
        printf("Erro ao abrir o arquivo de entrada");
        exit(1);
    }

    sai = fopen("saida.txt", "w");

    if(sai == NULL){
        fclose(sai);
        printf("Erro ao abrir o arquivo de saida");
        exit(1);
    }

    //fscanf(ent, "%d", &n_alunos);
    
    while(fscanf(ent, "%d %f %f %f", &n, &nota1, &nota2, &nota3) == 4){
        //printf("Aluno %d: %.1f\n\n", n, nota);
        //soma+=nota;
        media = (nota1+nota2+nota3)/3;
        soma+=media;
        fprintf(sai, "%d - %.1f ", n, media);
        if(media >= 5)
            fprintf(sai, "AP\n");
        else
            fprintf(sai, "RM\n");
        n_alunos++;
    }

    /*while(i < n_alunos){
        fscanf(ent, "%d %f", &n, &nota);
        printf("Aluno %d: %.1f\n\n", n, nota);
        soma+=nota;
        i++;
    }*/

    media_turma = soma/n_alunos;
    fprintf(sai, "\nA media da turma foi: %.1f\n\n", media_turma);


    fclose(sai);
    
    fclose(ent);
    return 0;
}