#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

// tipo carro
typedef struct tipo_carro{
char marca[15];
char placa[15];
struct tipo_carro *prox;
}Tcarro;

Tcarro *inicio = NULL;
Tcarro *fim = NULL;
Tcarro *noatual = NULL;
int tamFila;


//inserir carro na fila
void inserir(){
Tcarro *novono;
char marcal[15], placal[15];

	
		printf("\nChegada de novo carro na fila\n");
		printf("\nMarca do carro: ");
		fflush(stdin);
		gets(marcal);
		printf("\nPlaca do carro: ");
		fflush(stdin);
		gets(placal);
		tamFila++;
		
		novono = (Tcarro *)malloc(sizeof(Tcarro));
		strcpy(novono->marca, marcal);
		strcpy(novono->placa, placal);
		novono->prox = NULL;
		
		if(inicio == NULL){
			inicio = novono;
			fim = novono;
		}else {
			fim->prox = novono;
			fim = novono;
		}
		
		printf("\n\nInserido com sucesso!\n\n");
}

//consultar o primeiro da fila
void consultarprimeiro(){

printf("\nConsultar primeiro carro da fila\n\n");

	if(inicio != NULL){
		printf("\n\nmMarca		Placa\n");
		printf("-------------------------------\n");
		printf("%-15s		%-15s\n", inicio->marca, inicio->placa);
		printf("-------------------------------\n");
	}else {
		printf("\nA fila está vazia!\n\n");
	}
}


//remover o primeiro da fila
void remover(){

		printf("\nRetirar primeiro carro da fila\n");
		noatual = inicio;
		
		if(noatual != NULL){
			printf("\n\nMarca		Placa\n");
			printf("-------------------------------\n");
			printf("%-15s		%-15s\n", inicio->marca, inicio->placa);
			printf("-------------------------------\n");
			inicio = inicio->prox;
			free(noatual);
			tamFila--;
			printf("\n\nRetirado da fila com sucesso!\n\n");
			
		}else{
			printf("\n\nFila vazia!\n\n");
		}	
}

//litaar os carros na fila
void listar(){
noatual = inicio;

printf("\nListagem de carros da fila\n");

	if(tamFila != 0){
		printf("\n\nMarca		Placa\n");
		printf("-------------------------------\n");
		
		while(noatual != NULL){
			printf("%-15s		%-15s\n", noatual->marca, noatual->placa);
			noatual = noatual->prox;
		}
		
		printf("-------------------------------\n");
		printf("Quantidade de clientes na fila = %d.\n", tamFila);
	}else{
		printf("\n\nNao tem nenhum cliente na fila");
	}
}


//liberar memoria da fila
void limpafila(){
	noatual = inicio;
	
	while(noatual != NULL){
		inicio = noatual->prox;
		free(noatual);
		noatual = inicio;
	}
	
	fim = NULL;
}


main () {
int op;
tamFila = 0;

	do{
		printf("\nOpcoes: \n");
		printf("\n\n 1 - Inserir carro na fila");
		printf("\n\n 2 - Consultar primeiro carro da fila");
		printf("\n\n 3 - Retirar primeiro carro da fila");
		printf("\n\n 4 - Listar todos os carro da fila");
		printf("\n\n 0 - Sair \n");

		
		printf("\nEntre com a opcao desejada: ");
		scanf("%d", &op);
		
		switch(op){
			case 1: inserir(); break;
			case 2: consultarprimeiro(); break;
			case 3: remover(); break;
			case 4: listar(); break;
			case 0: limpafila(); break;
			default: printf("\n\nOpcao Invalida!");
				getche(); break; 
		}	
	}while(op != 0);
}