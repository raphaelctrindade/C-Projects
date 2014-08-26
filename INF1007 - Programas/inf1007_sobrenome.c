#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *pegaUltNome(char *nc);


int main(void)
{
	char name[81];
	char *lastName;
	
	printf("Digite seu nome completo: ");
	scanf(" %[^\n]", name);
	
	lastName = pegaUltNome(name);
	printf("%s",lastName);
	//printf("%s", name);	
	
	free(lastName);
	
	return 0;
}

char *pegaUltNome(char *nc)
{
	char *nome;
	int tam, i, j, tamNova;
	
	tam = strlen(nc);
	
	if(tam!=0)
	{
		i=tam-1;
		while(i!=-1 && nc[i]!=' ')
		{
			i--;
		}
		i++;
	}
	else
	{
		i=0;
	}
	
	tamNova=tam-i;
	
	nome=(char*)malloc((tamNova+1)*sizeof(char));
	
	if(nome==NULL)
	{
		printf("Erro");
		exit(1);
	}
	
	j=0;
	
	while(nc[i]!=' ')
	{
		nome[j]=nc[i];
		j++; i++;
	}
	j++;
	nome[j]='\0';
	
	
	return nome;
		
		
}