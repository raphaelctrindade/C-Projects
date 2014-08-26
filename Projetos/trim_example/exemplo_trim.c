#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char * String;
String trim(String s){

int i=0,j=0, k=0;
int ls = strlen(s); //tamanho da string s

String resp=(String) malloc(ls+1);

if(resp==NULL){
	return NULL;
}

for(i=0;i<ls;i++){
	if(s[i] != ' ')
	resp[j++]= s[i];
}

resp[j]= 0;

return resp;

}

int main(void)
{
	String vpal[7]={"Primeira","prova" ,"Prog2","-","Boa","Sorte","!" };
	String s;
	
	//s=mescla("PRLLPPD","AAEEIEO");
	
	//printf("\n%s",s); // teste da q2
	
	s=trim("     bla  bli blu     ");printf("%s",s); //teste da q1
	//s=montacadeia(vpal,7);printf("\n%s",s); //teste da q3
	// sai "Primeira prova Prog2 - Boa Sorte
	
	printf("\n\n-- FIM --\n");
	
	return 0;
}