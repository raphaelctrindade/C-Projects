#include <stdio.h>

// ******** EXERCICIO 1 *********
int exe1()
{
	int val1, val2;

	printf("\nExercicio 1\n\n");

	printf("Digite 2 valores:\n");
	scanf("%d %d", &val1, &val2);

	if(val1 > val2)
		printf("Maior: %d | Menor: %d\n", val1, val2);
	else
		printf("Maior: %d | Menor: %d\n", val2, val1);

	return 0;
}

// ******** EXERCICIO 2 *********

int exe2a()
{
	int max, min;
	int num;

	printf("\nExercicio 2 - Versao 1 com while\n\n");

	printf("Digite 2 valores (Menor - Maior):\n");
	scanf("%d %d", &min, &max);

	num = min+1;
	while(num<=max)
	{
		if(num%2!=0)
			printf("%d ", num);
		num++;
	}
	printf("\n");
	return 0;
}

int exe2b()
{
	int max, min;
	int num;

	printf("\nExercicio 2 - Versao 1 com for\n\n");

	printf("Digite 2 valores:\n");
	scanf("%d %d", &min, &max);

	num = min+1;
	for(;num<max;num++)
	{
		if(num%2!=0)
			printf("%d ", num);
	}
	printf("\n");
	return 0;
}

int exe2c()
{
	int max, min;
	int num;

	printf("\nExercicio 2 - Versao 2 com while\n\n");

	printf("Digite 2 valores:\n");
	scanf("%d %d", &min, &max);

	if(min % 2 == 0)
		num = min+1;
	else
		num = min+2;

	while(num<max)
	{
		printf("%d ", num);
		num = num +2;
	}
	
	printf("\n");
	return 0;
}

int exe2d()
{
	int max, min;
	int num;

	printf("\nExercicio 2 - Versao 2 com for\n\n");

	printf("Digite 2 valores:\n");
	scanf("%d %d", &min, &max);

	if(min % 2 == 0)
		num = min+1;
	else
		num = min+2;

	for(;num<max;num=num+2)
	{
		printf("%d ", num);
	}
	
	printf("\n");
	return 0;
}
	

// ******** EXERCICIO 3 *********
int calcMedia(int vet[], int n){
	int i;
	int soma = 0;
	float media;

	for(i=0;i<n;i++){
		soma = soma + vet[i];
	}

	media = soma/n;

	return media;
}


void exe3()
{
	int num[10];
	int i, k=0;
	float media;

	printf("*********************************");
	printf("\nExercicio 3\n");
	printf("*********************************\n");

	for(i=0;i<10;i++){
		printf("%do: ", i+1);
		scanf("%d", &num[i]);
	}
	printf("\n");

	printf("\nValores Lidos: ");
	for(i=0;i<10;i++){
		printf("%d ", num[i]);
	}
	printf("\n\n");


	/*
	for(i=0;i<9;i++)
	{
		if(num[i]<num[9])
			printf("%d ", num[i]);
	}*/

	
	for(k=0;k<9;k++)
	{
		if(num[k]<num[9])
			printf("%d ", num[k]);
	}
	

	/*
	while(k<9 ){
		if(num[k] < num[9])
			printf("%d ", num[k]);
	k++;
	}*/

	media = calcMedia(num, 10);
	printf("\n%f\n", media);

	printf("\n");
}

// ******** EXERCICIO 4 *********
int calcSoma(int x, int y){
	int result;

	result = x + y;
	return result;
}
int calcDif(int x, int y){
	int result;

	result = x - y;
	return result;
}

int exe4(){
	int val1, val2;

	printf("*********************************");
	printf("\nExercicio 4\n");
	printf("*********************************\n");

	printf("Digite 2 valores: ");
	scanf("%d %d", &val1, &val2);

	printf("Soma: %d\n", calcSoma(val1, val2));
	printf("Diferenca: %d\n\n", calcDif(val1, val2));

	return 0;
}




int main(void)
{
	/*
	exe1();
	exe2a();
	exe2b();
	exe2c();
	exe2d();
	*/

	exe3();

	//exe4();

	return 0;
}