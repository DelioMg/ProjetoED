#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 30

typedef struct {
int codigo;
char titulo[30];
}TLivro;

TLivro pilhal[30];
int op, tamp;

//-----------------------------------//

void linha(){
int i;
	
	for (i-1; i<=80; i++){
		printf("-");
	}
printf("\n");
	
}


void cabec(){
system("cls");
printf("Livraria");
linha();
}

//empilhar
void empilha(){
int continuar;

	do {
		cabec();
		printf("\nColocar livro no topo da pilha\n");
			if(tamp<MAX){
				printf("\nCodigo do livro: ");
				scanf("%d", &pilhal[tamp].codigo);
				printf("\nTitulo do livro: ");
				fflush(stdin);
				gets(pilhal[tamp].titulo);
				tamp++;
				printf("\nInserido com sucesso");
			} else {
				printf("\n\nPilha cheia! Não pode inserir mais livros!\n\n");
				getche();
				break;
			}
		printf("\nContinuar inserindo(1-sim/0-nao)?");
		scanf("%d", &continuar);
	}while(continuar == 1);
}


//consultar valor que esta no topo
void consultaTopo(){
cabec();
printf("\nConsultar topo da pilha\n");

	if(tamp !=0){
		printf("\n\nCodigo		Titulo\n");
		printf("-------------------------------\n");
		printf("%6d		%-20s\n", pilhal[tamp-1].codigo, pilhal[tamp-1].titulo);
	}else{
		printf("\n\nA pilha esta vazia!\n\n");
	}
	
	printf("\n\nTecle enter para voltar para o menu.\n");
	getche();
}


//desempilhar
void desempilha(){
int continuar, confrem;

	do {
		cabec();
		printf("\nRetirar livro do topo da pilha\n");
		if(tamp != 0){
			printf("\n\nCodigo		Titulo\n");
			printf("-------------------------------\n");
			printf("%6d		%-20s\n", pilhal[tamp-1].codigo, pilhal[tamp-1].titulo);
			printf("-------------------------------\n");
			printf("\n\nConfirmar retirada do livro(1-sim/0-nao)?");
			scanf("%d", &confrem);
			
			if(confrem == 1){
				tamp--;
				printf("\n\nRetirada da pilha com sucesso!\n");
			}else{
				printf("\n\nRetirada cancelada!\n\n");
			}
		
		}else{
			printf("\n\nPilha Vazia");
			getche();
			break;
		}
		
		printf("\n\nDeseja retirar outro livro(1-sim/0-nao)?");
		scanf("%d", &continuar);
	}while(continuar == 1);
}


//listar os livros
void listar(){
int i;
cabec();
printf("\nListagem dos livros da pilha\n");

	if(tamp != 0){
		printf("\n\nCodigo		Titulo\n");
		printf("-------------------------------\n");
		
		for(i=tamp-1; i>=0; i--){
			printf("%6d		%-20s\n", pilhal[i].codigo, pilhal[i].titulo);	
		}
		
		printf("-------------------------------\n");
		printf("\n\nQuantidade de livros na pilha = %d. \n", tamp);
	}else {
		printf("\n\nNao tem nenhum livro na pilha");
	}
	
	printf("\n\nTecle enter para voltar para o menu.\n");
	getche();
}


main(){
	
tamp =0;

	do{
		cabec();
		printf("\nOpcoes: \n");
		printf("\n\n 1 - Inserir livro na pilha");
		printf("\n\n 2 - Consultar topo da pilha");
		printf("\n\n 3 - Retirar livro do topo");
		printf("\n\n 4 - Listar todos os livros da pilha");
		printf("\n\n 0 - Sair \n");
		
		linha();
		
		printf("\nEntre com a opcao desejada: ");
		scanf("%d", &op);
		
		switch(op){
			case 1: empilha(); break;
			case 2: consultaTopo(); break;
			case 3: desempilha(); break;
			case 4: listar(); break;
			case 0: break;
			default: printf("\n\nOpcao Invalida!");
				getche(); break; 
		}	
	}while(op != 0);	
}