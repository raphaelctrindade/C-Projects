#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char * String;

String trim(String s)
{
	int i=0,j=0, k=0;
	int ls = strlen(s); //tamanho da string s
	String resp=(String) malloc(ls+1);
	
	if(resp==NULL){
		return NULL;
	}

	for(i=0;s[i]==' ';i++); // anda com o contador "i" até a caractere incial depois dos espaços
	
	for(j=ls-1;s[j]==' ';j--); // anda com o contador "j" de trás para frente até a última caractere
	
	for(k=i;k<=j;k++)
		resp[k-i]=s[k]; // coloca na "resp" 

	resp[k-i]='\0';
	
	//printf("[ ls=%d ] [ i=%d ] [ j=%d ] [ k=%d ]\n",ls,i,j, k);

	return resp;
}


String mescla(String s1, String s2)
{ 
	int i, ls1=strlen(s1),ls2=strlen(s2),ls=ls1+ls2;
	int j=0, k=0;
	String resp=(String) malloc(ls); 
	
	for(i=0;i<ls;i++){
		if(i % 2 == 0)
		{
			resp[i] = s1[j];
			j++;
			//printf(" i=%d j=%d ", i, j);
		}
		else{
			resp[i] = s2[k];
			//printf("i=%d k=%d | ", i, k);
			k++;
		}
	}
	
	
	//printf("[ string lenght: %d ]\n",ls);
	
	resp[ls+1]='\0';
	
	return resp;
}



String montacadeia (String *Palavras, int n)
{

	int i, tam = 0;

	String resp;

	for (i = 0; i < n; i++) 
	{
		tam = tam + strlen(Palavras[i]); 
	}
	
	resp = (String) malloc ((tam+n) * sizeof (char)); // conta espacos

	if (resp == NULL){
		return NULL;
	}

	

	for (i = 0; i < n; i++){
		strcat(resp,Palavras[i]);
		
		if(i < n-1){
			strcat(resp," ");
		}
		
	}
	
	strcat(resp,"\0");

	return resp;

}

int

main(void){
String vpal[7]={"Primeira","prova" ,"Prog2","-","Boa","Sorte","!" };
String s;

//=========== QUESTAO 1 =============//
printf("------- QUESTAO 1 ------- \n");
s=trim("     bla bli blu     ");
printf("\n%s\n\n",s); //teste da q1
//================================//

//=========== QUESTAO 2 =============//
printf("------- QUESTAO 2 ------- \n");
s=mescla("PRLLPPD","AAEEIEO"); 
printf("\n%s\n\n",s); // teste da q2
//================================//

//=========== QUESTAO 3 =============//
printf("------- QUESTAO 3 ------- \n");
s=montacadeia(vpal,7);printf("\n%s",s); //teste da q3
// sai "Primeira prova Prog2 - Boa Sorte

printf("\n\n-- FIM --\n");

return 0;
}