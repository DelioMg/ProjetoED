#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define tamanho 2
#define MAX 10


// tipo carro
typedef struct tipo_carro{
char marca[15];
char cor[15];
struct tipo_carro *prox;
}Tcarro;

//Tcarro sem1;
//Tcarro sem2;

Tcarro *inicio = NULL;
Tcarro *fim = NULL;
Tcarro *noatual = NULL;
int tamFila;




//inserir carro na fila
void inserir(){
Tcarro *novono;
char marcal[15], corl[15];
char *cores[4]   = {"Vermelho", "Branco","Cinza", "Preto"};
char *carros[10] = {"Hb20","KA","Gol", "Palio","Mobi","Onix","Kwid","Argo","Uno","Renegade"};
int corsoteada, carsorteado;

        srand(time(NULL));
        corsoteada = rand() % 4;
        
        carsorteado = rand() % 10;
        
	
	//	printf("\nChegada de novo carro na fila\n");
	//	printf("\nMarca do carro: ");
		//fflush(stdin);
		//gets(marcal);
	//	*marcal = *carros[carsorteado];
	//	printf("\nPlaca do carro: ");
		//fflush(stdin);
		//gets(placal);
	//	*corl = *cores[corsoteada];
	//	printf("O sorteado foi: %s\n", cores[corsoteada]);
	//	printf("O sorteado foi: %s\n", carros[carsorteado]);

		tamFila++;
		
		novono = (Tcarro *)malloc(sizeof(Tcarro));
		strcpy(novono->marca, carros[carsorteado]);
		strcpy(novono->cor, cores[corsoteada]);
		novono->prox = NULL;
		
		if(inicio == NULL){
			inicio = novono;
			fim = novono;
		}else {
			fim->prox = novono;
			fim = novono;
		}
		
	//	printf("\n\nInserido com sucesso!\n\n");
}

//consultar o primeiro da fila
void consultarprimeiro(){

printf("\nConsultar primeiro carro da fila\n\n");

	if(inicio != NULL){
		printf("\n\nmMarca		Placa\n");
		printf("-------------------------------\n");
		printf("%-15s		%-15s\n", inicio->marca, inicio->cor);
		printf("-------------------------------\n");
	}else {
		printf("\nA fila está vazia!\n\n");
	}
}


//remover o primeiro da fila
void remover(){

		
		noatual = inicio;
		
		if(noatual != NULL){
			inicio = inicio->prox;
			free(noatual);
			tamFila--;
			printf("Carro %-15s%-15s passou no sinal\n");
			
		}//else{
		//	printf("Fila vazia!\n\n");
		//}	
}

//litaar os carros na fila
void listar(){
noatual = inicio;

if(tamFila != 0){
		printf("Modelo		Cor\n");
		printf("-------------------------------\n");
		
		while(noatual != NULL){
			printf("%-15s		%-15s\n", noatual->marca, noatual->cor);
			noatual = noatual->prox;
		}
		
		printf("-------------------------------\n");
		printf("Quantidade de carro = %d.\n", tamFila);
	}else{
		printf("Nao tem nenhum carro na fila\n");
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

typedef struct tipo_pilha{
    int dados[2];
    int ini;
    int topo;
}tipo_pilha;

tipo_pilha semafaro1;
tipo_pilha semafaro2;

void empilha(int elemento, tipo_pilha *pilha){
    if(pilha->topo == tamanho){
       // printf("Pilha cheia.\n");
        system("pause");
    }
    else
    {
        pilha->dados[pilha->topo] = elemento;
        pilha->topo++;
    }
}

int desempilha(tipo_pilha *pilha){
    int elemento;

    if(pilha->topo == pilha->ini){
        system("pause");
    }
    else
    {
        pilha->topo--;
        elemento = pilha->dados[pilha->topo];
        return elemento;
    }
}

int topo(tipo_pilha *pilha){
    int aux;
    pilha->topo--;
    aux = pilha->dados[pilha->topo];
 return aux;
}

int inicio(tipo_pilha *pilha){
    int aux;
    aux = pilha->dados[pilha->ini];
    pilha->ini++;
 return aux;
}

int main(){
    int topo1, topo2, aux, contador=1;
    int ncarros1=0, ncarros2=0;
    
    //inicializando com zero, os semafaros
    semafaro1.topo = 0;
    semafaro1.ini = 0;
    semafaro2.topo = 0;
    semafaro2.ini = 0;

    
    printf("\n        Programa Semafaro\n");
   	printf("              Semafaro 1\n");//Listar carrros que estão na fila1 
    
	srand(time(NULL));
	ncarros1= rand() % 10; // gerando valores aleatórios na faixa de 0 a 6 para numero de carros que tem na fila
	for (int i = 0; i != ncarros1; i++)
	{
		inserir();
	}
	listar(); 
   /*     
    printf("\n              Semafaro 2\n");//Listar carrros que estão na fila1 
	ncarros2= rand() % 6; // gerando valores aleatórios na faixa de 0 a 6 para numero de carros que tem na fila
	for (int i = 0; i != ncarros2; i++)
	{
		inserir(sem2);
		i++;
	}
	
	listar(sem2); 
    //Inserir a quantidade ncarros2 na fila2
     */
    //inicializando a pilha do semafaro 1
    empilha(2, &semafaro1);
    empilha(1, &semafaro1);	     
    
	    
    //semafaro 1
    //o que define o estado do semafaro 1, é o seu topo
    topo1 = topo(&semafaro1);
    
    //semafaro 1 - verde
    if (topo1 == 1){
    	printf("\nsemaforo 1 - Verde\n");
    	if(ncarros1 > 3){
         for (int i = 0; i < 3; i++)
		{
			remover();
		}
		//ncarros1= ncarros1 -3;
        }else {
          ncarros1=0;
		  		for (int i = 0; i == ncarros1; i++)
		{
			remover();
		}

        }
        listar();
        aux = rand() % 6;
           if((aux + ncarros1)<MAX){
	        ncarros1= ncarros1 + aux;
    	    printf("%d Novo(s) carro(s) no semafaro 1\n", aux);
			for (int i = 0; i < aux; i++)
			{
			inserir();
			}
						
			printf("\n Total de carros\n");
			listar();
    	    }else {
    	    ncarros1 = MAX;
    	    printf("fila cheia de carros. %d carros no total.\n",ncarros1);
           }
    
    } else {
    	printf("\nsemaforo 1 - Vermelho\n");
		listar();
        aux = rand() % 6;
           if((aux + ncarros1)<MAX){
	        ncarros1= ncarros1 + aux;
    	    printf("%d Novo(s) carro(s) no semafaro 1\n", aux);
			for (int i = 0; i < aux; i++)
			{
			inserir();
			}
			printf("\n Total de carros\n");
			listar();
    	    }else {
    	    ncarros1 = MAX;
    	    printf("fila cheia de carros. %d carros no total.\n",ncarros1);
           }
    } //fim do semafaro 1

     //semafaro 1
    //o que define o estado do semafaro 1, é o seu topo
    
    
    empilha(desempilha(&semafaro1),&semafaro2);
    
    topo2 = topo(&semafaro2);
   /* 
    //semafaro 2 - verde
	
    if (topo2 == 1){
		printf("-------------------------------\n");
    	printf("semaforo 2 - Verde\n");
    	if(ncarros2 > 3){
          ncarros2= ncarros2 -3;
        }else {
          ncarros2=0;
        }

        listar(sem2);
        aux = rand() % 6;
        if((aux + ncarros2)<MAX){
	      ncarros2= ncarros2 + aux;
    	  printf("%d Novo(s) carro(s) no semafaro 2\n", aux);
			inserir(sem2);
			printf("\n Total de carros\n");
			listar(sem2);
        }else {
    	  ncarros2 = MAX;
    	  printf("fila cheia de carros. %d carros no toal.\n",ncarros2);
        }
    
    } else {
		printf("-------------------------------\n");
    	printf("semaforo 2 - Vermelho\n");
    	aux = rand() % 6;
     	if((aux + ncarros2)<MAX){
		  ncarros2= ncarros2 + aux;
    	  printf("%d Novo(s) carro(s) no semafaro 2\n", aux);
		  for (int i = 1; i < aux; i++)
		  {
			 inserir(sem2); 
			 ncarros2++;
		  }
		  
		  printf("\n Total de carros\n");
		  listar(sem2);
    	}else {
    	  ncarros2 = MAX;
    	  printf("fila cheia de carros. %d carros no total.\n",ncarros2);
    	}
    } //fim do semafaro 2
*/
}
