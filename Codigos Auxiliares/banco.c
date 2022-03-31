#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_cliente {
int conta, agencia;
char nome[15];
struct tipo_cliente *prox;
}Tcliente;

Tcliente *inicio = NULL;
Tcliente *fim = NULL;
Tcliente *noatual = NULL;
int tamFila;


void linha(){
int i;
	
	for (i-1; i<=80; i++){
		printf("-");
	}
printf("\n");
	
}


void cabec(){
system("cls");
printf("Banco\n");
linha();
}

//inserir cliente na fila
void inserir(){
Tcliente *novono;
int contal, agencial, continuar;
char nomel[15];

	do{
		cabec();
		printf("\nChegada de novo cliente na fila\n");
		printf("\nNumero da conta: ");
		scanf("%d", &contal);
		printf("\nNumero da agencia: ");
		scanf("%d", &agencial);
		printf("\nNome do cliente: ");
		fflush(stdin);
		gets(nomel);
		tamFila++;
		
		novono = (Tcliente *)malloc(sizeof(Tcliente));
		novono->conta = contal;
		novono->agencia = agencial;
		strcpy(novono->nome, nomel);
		novono->prox = NULL;
		
		if(inicio == NULL){
			inicio = novono;
			fim = novono;
		}else {
			fim->prox = novono;
			fim = novono;
		}
		
		printf("\n\nInserido com sucesso!\n\n");
		printf("\nContinuar inserindo (1-sim/0-nao)?");
		scanf("%d", &continuar);
	}while(continuar == 1);
}

//consultar o primeiro da fila
void consultarprimeiro(){
cabec();
printf("\nConsultar primeiro cliente da fila\n\n");

	if(inicio != NULL){
		printf("\n\nAgencia		conta		nome\n");
		printf("-------------------------------\n");
		printf("%7d		%5d		%-15s\n", inicio->agencia, inicio->conta, inicio->nome);
		printf("-------------------------------\n");
	}else {
		printf("\nA fila está vazia!\n\n");
	}
	
	printf("\n\nTecle enter para voltar para o menu.\n");
	getche();
}

//remover o primeiro da fila
void remover(){
int confrem, continuar;

	do{
		cabec();
		printf("\nRetirar primeiro cliente da fila\n");
		noatual = inicio;
		
		if(noatual != NULL){
			printf("\n\nAgencia		conta		nome\n");
			printf("-------------------------------\n");
			printf("%7d		%5d		%-15s\n", inicio->agencia, inicio->conta, inicio->nome);
			printf("-------------------------------\n");
			printf("Confirmar retirada do cliente (1-sim/0-nao)?");
			scanf("%d", &confrem);
			
			if(confrem == 1){
				inicio = inicio->prox;
				free(noatual);
				tamFila--;
				printf("\n\nRetirado da fila com sucesso!\n\n");
			}else{
				printf("\n\nRetirada concelada!\n\n");
			}
			
		}else{
			printf("\n\nFila vazia!\n\n");
		}
		
		printf("\n\nDeseja fazer nova retirada da fila(1-sim/0-nao)?");
		scanf("%d", &continuar);
	}while(continuar == 1);
	

}

//litaar os clientes na fila
void listar(){
noatual = inicio;
cabec();
printf("\nListagem de clientes da fila\n");

	if(tamFila != 0){
		printf("\n\nAgencia		Conta		nome\n");
		printf("-------------------------------\n");
		
		while(noatual != NULL){
			printf("%7d		%5d		%-15s\n", noatual->agencia, noatual->conta, noatual->nome);
			noatual = noatual->prox;
		}
		
		printf("-------------------------------\n");
		printf("Quantidade de clientes na fila = %d.\n", tamFila);
	}else{
		printf("\n\nNao tem nenhum cliente na fila");
	}
printf("\n\nTecle enter para voltar para o menu.\n");
getche();
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
		cabec();
		printf("\nOpcoes: \n");
		printf("\n\n 1 - Inserir cliente na fila");
		printf("\n\n 2 - Consultar primeiro da fila");
		printf("\n\n 3 - Retirar primeiro cliente da fila");
		printf("\n\n 4 - Listar todos os clientes da fila");
		printf("\n\n 0 - Sair \n");
		
		linha();
		
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