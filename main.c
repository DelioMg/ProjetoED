#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define tamanho 2
#define MAX 10

// tipo carro
typedef struct tipo_carro{
char modelo[15];
char cor[15];
struct tipo_carro *prox;
}Tcarro;

Tcarro sem2;
Tcarro sem1;

Tcarro *inicio = NULL;
Tcarro *fim = NULL;
Tcarro *noatual = NULL;
int tamFila;


//inserir carro na fila
void inserir(){
Tcarro *novono;
char modelol[15], corl[15];
char *cores[4]   = {"Vermelho", "Branco","Cinza", "Preto"};
char *carros[10] = {"Hb20","KA","Gol", "Palio","Mobi","Onix","Kwid","Argo","Uno","Renegade"};
int corsoteada, carsorteado;

        srand(time(NULL));
        corsoteada = rand() % 4;
        
        carsorteado = rand() % 10;
        
	
		tamFila++;
		
		novono = (Tcarro *)malloc(sizeof(Tcarro));
		strcpy(novono->modelo, carros[carsorteado]);
		strcpy(novono->cor, cores[corsoteada]);
		novono->prox = NULL;
		
		if(inicio == NULL){
			inicio = novono;
			fim = novono;
		}else {
			fim->prox = novono;
			fim = novono;
		}
		

}


//remover o primeiro da fila
void remover(){

		//printf("\nRetirar primeiro carro da fila\n");
		noatual = inicio;
		
		if(noatual != NULL){

			inicio = inicio->prox;
			free(noatual);
			tamFila--;
			printf("Carro %-5s %-5s passou no sinal\n",inicio->modelo, inicio->cor);
			
		}else{
			printf("\n\nFila vazia!\n\n");
		}	
}

//litaar os carros na fila
void listar(){
noatual = inicio;



	if(tamFila != 0){
		printf("Carro		Cor\n");
		printf("-------------------------------\n");
		
		while(noatual != NULL){
			printf("%-15s%-15s\n", noatual->modelo, noatual->cor);
			noatual = noatual->prox;
		}
		
		printf("-------------------------------\n");
		printf("Quantidade de carros na fila = %d.\n", tamFila);
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

int inici(tipo_pilha *pilha){
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
		inserir(sem1);
	}
	listar(sem1); 
    printf("              Semafaro 2\n");//Listar carrros que estão na fila1 
    ncarros2= rand() % 6; // gerando valores aleatórios na faixa de 0 a 6 para numero de carros que tem na fila
	for (int i = 0; i != ncarros2; i++)
	{
		inserir(sem2);
	}
	listar(sem2); 
    
    //inicializando a pilha do semafaro 1
    empilha(2, &semafaro1);
    empilha(1, &semafaro1);	     
    
	    
    //semafaro 1
    //o que define o estado do semafaro 1, é o seu topo
    topo1 = topo(&semafaro1);
    
    //semafaro 1 - verde
    if (topo1 == 1){
    	printf("\nSemaforo 1 - Verde\n");
        	if(ncarros1 > 3){
         for (int i = 0; i < 3; i++)
		{
			remover(sem1);
      ncarros1--;
		}
		        }else {
         	for (int i = ncarros1; i !=0; i--)
		        {
			      remover(sem1);
            }
     ncarros1=0;
        }

    
    aux = rand() % 6;
    for (int i = 0; i < aux; i++)
    {
      inserir(sem1);
    }
    
    if((aux + ncarros1)<MAX){
	ncarros1= ncarros1 + aux;
    	
    	printf("\n%d Novo(s) carro(s) no semafaro 1\n", aux);
      printf("Total de carros no semafaro 1:\n");
      listar(sem1);
    }else {
    	ncarros1 = MAX;
    	printf("fila cheia de carros. %d carros no toal.\n",ncarros1);
    }
    
    } else {
    	printf("\nsemaforo 1 - Vermelho\n");
    	printf("%d carros na fila\n",ncarros1);//Listar carrros que estão na pilha2
         for (int i = 0; i < aux; i++)
    {
      inserir(sem1);
    }
    
    if((aux + ncarros1)<MAX){
	ncarros1= ncarros1 + aux;
    	
    	printf("%d Novo(s) carro(s) no semafaro 1\n", aux);
      printf("Total de carros no semafaro 1:\n");
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
    
    //semafaro 2 - verde
    if (topo2 == 1){
    	printf("semaforo 2 - Verde\n");
    if(ncarros2 > 3){
      for (int i = 0; i < 3; i++)
		     {
			   remover(sem2);
         ncarros2--;
		     }
		}else {
         	for (int i = ncarros2; i !=0; i--)
		        {
			      remover(sem2);
            }
     ncarros2=0;
        }

    aux = rand() % 6;
    if((aux + ncarros2)<MAX){
     for (int i = 0; i < aux; i++)
       {
      inserir(sem2);
       }
    
       if((aux + ncarros1)<MAX){
	      ncarros1= ncarros1 + aux;
    	 	printf("%d Novo(s) carro(s) no semafaro 1\n", aux);
        printf("Total de carros no semafaro 1:\n");
        listar(sem2);
    }else {
    	ncarros2 = MAX;
    	printf("fila cheia de carros. %d carros no toal.\n",ncarros2);
    }
    
    } else {
    	printf("semaforo 2 - Vermelho\n");
    	printf("%d carros na fila\n",ncarros2);//Listar carrros que estão na pilha2
          aux = rand() % 6;
      for (int i = 0; i < aux; i++)
        {
         inserir(sem2);
        }
    
      if((aux + ncarros1)<MAX){
	    ncarros1= ncarros1 + aux;
    	
    	printf("%d Novo(s) carro(s) no semafaro 1\n", aux);
      printf("Total de carros no semafaro 1:\n");
      listar(sem2); 
    		}else {
    		ncarros2 = MAX;
    		printf("fila cheia de carros. %d carros no total.\n",ncarros2);
    		}
    } //fim do semafaro 2
    }
}