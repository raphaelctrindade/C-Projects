#include<stdio.h> 

int main() 
{ 
   int numero, resto; 
   printf("\n\nEste programa verifica se o numero e par ou impar.\n");
   printf("\nDigite o numero a ser verificado.\n");
   scanf("%d", &numero); 
   resto = numero % 2 ;//'%'igual a 'mod' 

   if (resto != 0)//'= =' operador de igualdade nao confundir com '=' que e atribuicao 
      printf("O numero e impar.\n\n");
   else
      printf("O numero e par.\n\n");

}