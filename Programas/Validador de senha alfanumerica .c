/*Validador de senha alfanumerica */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//Considere que a senha correta é o valor 12345abc.

int main() {
	char senha[200], padrao[200]="12345abc";
    printf("Digite sua senha: ");
    scanf("%s", &senha);
    
    if(strcmp(senha,padrao)==0){
    	printf("\n ----- SENHA CORRETA ----- \n");
	} else {
		printf("\n ----- SENHA INCORRETA ----- \n");
	}
	return 0;
	
}
