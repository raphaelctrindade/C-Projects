#include <stdio.h>

#include <string.h>

struct paciente
{ 
	int cpf;
	char nome[51];
	int idade;

};
typedef struct paciente Paciente;

void exibeVetPac(Paciente *v, int n);
int buscaBinaria(Paciente *v, int n, int cpfProc);

int main(void)

{

Paciente vpac[8] = {	{110, "edu", 51}, {222, "ana", 34},
						{331, "leo", 23}, {447, "rui", 24},
						{556, "ivo", 64}, {668, "lea", 33},
						{774, "eva", 50}, {883, "teo", 38} };

/* o vetor de Paciente esta ordenado crescentemente por cpf */

int cpfProc;
int pos;

exibeVetPac(vpac, 8);



printf ("\nCPF a ser procurado [CPF < 0 fim do programa]: ");
scanf("%d", &cpfProc);

while (cpfProc > 0)
{ 
	pos = buscaBinaria(vpac, 8, cpfProc);
	if (pos != -1)
		printf("\nEncontrado: %d-%s-%d",vpac[pos].cpf, vpac[pos].nome, vpac[pos].idade);
	else
	printf("\nNao Encontrado");

printf ("\nCPF a ser procurado [CPF < 0 fim do programa]: ");

scanf("%d", &cpfProc);

}

}

void exibeVetPac(Paciente *v, int n)
{
	int i;

	printf("\n**************** EXIBINDO VETOR ****************\n\n");
	for(i=0;i<n;i++)
		printf("%d\t%s\t%d\n",v[i].cpf, v[i].nome, v[i].idade);

	printf("\n");
}

int buscaBinaria(Paciente *v, int n, int cpfProc)
{
	int ini, meio, fim;
	
	ini = 0;
	fim = n-1;
	
	while(ini<=fim)
	{
		meio = (ini + fim)/2;
		if(v[meio].cpf == cpfProc)
			return meio;
		else if(v[meio].cpf > cpfProc)
			fim = meio-1;
		else
			ini = meio + 1;
	}
	return -1; // nao encontrou
}