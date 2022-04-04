#include <stdio.h>

void inverte(char *string, char *string2){
	for (int i=5; i<0; i--) {
	string2[i]=string[i];
		printf("vet[%d] =  %s\n",i,string2[i]);
	}

}
int main() {
	char vet[5][21] = {"meu primeiro string",
				"segundão da lista",
				"terceiro",
				"to quase lá...",
				"o último!"};
	char test[5][21] ;			
	int i;
inverte();
	/* imprimo o vetor */

}