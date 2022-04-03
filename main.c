#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define tamanho 2
#define MAX 10


// tipo carro fila 1
typedef struct tipo_carro{
char modelo[15];
char cor[15];
struct tipo_carro *prox;
}Tcarro;

Tcarro *inicio = NULL;
Tcarro *fim = NULL;
Tcarro *noatual = NULL;
int tamFila;

// tipo carro fila 2
typedef struct tipo_carro2{
char marca2[15];
char cor2[15];
struct tipo_carro2 *prox2;
}Tcarro2;


Tcarro2 *inicio2 = NULL;
Tcarro2 *fim2 = NULL;
Tcarro2 *noatual2 = NULL;
int tamFila2;

typedef struct tipo_pilha{
    int dados[2];
    int ini;
    int topo;
}tipo_pilha;

tipo_pilha semafaro1;
tipo_pilha semafaro2;


void delay(){
   time_t start_t, end_t;
   double diff_t;

   //printf("Inicio do programa...\n");
   time(&start_t);
   while(diff_t<=0.500000){
    time(&end_t);
   diff_t = difftime(end_t, start_t);
}

   //printf("pronto passou 5 segundo\n");
}
//inserir carro na fila1
void inserir(){
Tcarro *novono;
char *cores[4]   = {"Vermelho", "Branco","Cinza", "Preto"};
char *carros[10] = {"Hb20","KA","Gol", "Palio","Mobi","Onix","Kwid","Argo","Uno","Renegade"};
int corsoteada, carsorteado;

        srand( (unsigned)time(NULL) );

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
            printf("Carro %-5s %-5s passou no sinal\n",inicio->modelo, inicio->cor);
			inicio = inicio->prox;
			free(noatual);
			tamFila--;
						
		}else{
			printf("\n\nFila vazia!\n\n");
		}	
}
//litaar os carros na fila
void listar(){
noatual = inicio;



	if(tamFila != 0){
		printf("Modelo		Cor\n");
		printf("----------------------------------------\n");
		
		while(noatual != NULL){
			printf("%-15s%-15s\n", noatual->modelo, noatual->cor);
			noatual = noatual->prox;
		}
		
		printf("---------------------------------------\n");
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
	
	fim2 = NULL;
}
//inserir carro na fila 2
void inserir2(){
Tcarro2 *novono2;
char marcal2[15], corl2[15];
int corsoteada2, carsorteado2;
char *cores2[4]   = {"Vermelho", "Branco","Cinza", "Preto"};
char *carros2[10] = {"Hb20","KA","Gol", "Palio","Mobi","Onix","Kwid","Argo","Uno","Renegade"};

        srand(time(NULL));
        corsoteada2 = rand() % 4;
        carsorteado2 = rand() % 10;
        	
	   	
		novono2 = (Tcarro2 *)malloc(sizeof(Tcarro2));
		strcpy(novono2->marca2,carros2[carsorteado2]);
		strcpy(novono2->cor2, cores2[corsoteada2]);
		novono2->prox2 = NULL;
		
		tamFila2++;

		if(inicio2 == NULL){
			inicio2 = novono2;
			fim2 = novono2;
		}else {
			fim2->prox2 = novono2;
			fim2 = novono2;
		}
		
	//	printf("\n\nInserido com sucesso!\n\n");
}
//remover o primeiro da fila 2
void remover2(){

		
		noatual2 = inicio2;
		
		if(noatual2 != NULL){
            printf("Carro %-5s %-5s passou no sinal\n",inicio2->marca2, inicio2->cor2);
			inicio2 = inicio2->prox2;
			free(noatual2);
			tamFila2--;
						
		}else{
			printf("\n\nFila vazia!\n\n");
		}	
}
//listar os carros na fila 2
void listar2(){
noatual2 = inicio2;

if(tamFila2 != 0){
		printf("Modelo		Cor\n");
		printf("----------------------------------------\n");
		
		while(noatual2 != NULL){
			printf("%-15s%-15s\n", noatual2->marca2, noatual2->cor2);
			noatual2 = noatual2->prox2;
		}
		
        printf("---------------------------------------\n");
		printf("Quantidade de carros na fila = %d.\n", tamFila2);
	}else{
		printf("Nao tem nenhum carro na fila\n");
	}
}
//liberar memoria da fila2 2
void limpafila2(){
	noatual2 = inicio2;
	
	while(noatual2 != NULL){
		inicio2 = noatual2->prox2;
		free(noatual2);
		noatual2 = inicio2;
	}
	
	fim2 = NULL;
}

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
   	printf("\n         Semafaro 1\n");//Listar carrros que estão na fila1 
    
	srand(time(NULL));
	ncarros1= rand() % 10; // gerando valores aleatórios na faixa de 0 a 6 para numero de carros que tem na fila
	for (int i = 0; i != ncarros1; i++)
	{
		delay();
		inserir();
	}
	listar(); 
    printf("\n         Semafaro 2\n");//Listar carrros que estão na fila1 
    ncarros2= rand() % 6; // gerando valores aleatórios na faixa de 0 a 6 para numero de carros que tem na fila
	for (int i = 0; i != ncarros2; i++)
	{
		delay();
		inserir2();
	}
	listar2(); 


   while(contador!=10){
 
 
   if (contador%2 != 0){
   
    empilha(2, &semafaro1);
    empilha(1, &semafaro1);
       
	   
    //semafaro 1
    //o que define o estado do semafaro 1, é o seu topo
    topo1 = topo(&semafaro1);
    
    //semafaro 1 - verde
    if (topo1 == 1){
    	printf("\n     Semaforo 1 - Verde\n");
        	if(ncarros1 > 3){
         for (int i = 0; i < 3; i++)
		{
			remover();
      ncarros1--;
		}
		        }else {
         	for (int i = ncarros1; i !=0; i--)
		    {
		     remover();
          }
     ncarros1=0;
        }

    
    aux = rand() % 6;
    if((aux + ncarros1)<MAX){
	ncarros1= ncarros1 + aux;
        for (int i = 0; i < aux; i++)
    {
	  delay();
      inserir();
    }	
    	printf("\n%d Novo(s) carro(s) no semafaro 1\n", aux);
      printf("Total de carros no semafaro 1:\n");
      listar();
    }else {
    	ncarros1 = MAX;
    	printf("Fila cheia de carros. %d carros no total.\n",ncarros1);
    }
    
    } else {
    	printf("\n     Semaforo 1 - Vermelho\n");
		aux = rand() % 6;
    if((aux + ncarros1)<MAX){
	ncarros1= ncarros1 + aux;
    for (int i = 0; i < aux; i++)
    {
	  delay();
      inserir();
    }
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
    	printf("\n     Semaforo 2 - Verde\n");
    if(ncarros2 > 3){
      for (int i = 0; i < 3; i++)
		     {
			   remover2();
         ncarros2--;
		     }
		}else {
         	for (int i = ncarros2; i !=0; i--)
		        {
			     remover2();
            }
     ncarros2=0;
        }

    aux = rand() % 6;
    if((aux + ncarros2)<MAX){
		for (int i = 0; i < aux; i++)
       {
		   delay();
		   inserir2();
       }
	      ncarros2= ncarros2 + aux;
    	 	printf("%d Novo(s) carro(s) no semafaro 1\n", aux);
        printf("Total de carros no semafaro 1:\n");
        listar2();
    }else {
    	ncarros2 = MAX;
    	printf("fila cheia de carros. %d carros no toal.\n",ncarros2);
    }
        } else {
    	printf("\n     semaforo 2 - Vermelho\n");
    	  aux = rand() % 6;
      if((aux + ncarros2)<MAX){
		        for (int i = 0; i < aux; i++)
        {
		 delay();
         inserir2();
        }
	    ncarros2= ncarros2 + aux;
    	
    	printf("%d Novo(s) carro(s) no semafaro 1\n", aux);
      printf("Total de carros no semafaro 1:\n");
      listar2(); 
    		}else {
    		ncarros2 = MAX;
    		printf("fila cheia de carros. %d carros no total.\n",ncarros2);
    		}
    } //fim do semafaro 2
    
	}else{
   empilha(1, &semafaro1);
   empilha(2, &semafaro1);
	topo1 = topo(&semafaro1);
    
    //semafaro 1 - verde
    if (topo1 == 1){
    	printf("\n     Semaforo 1 - Verde\n");
        	if(ncarros1 > 3){
         for (int i = 0; i < 3; i++)
		{
			remover();
      ncarros1--;
		}
	      }else {
         	for (int i = ncarros1; i !=0; i--)
		        {
			      remover();
            }
     ncarros1=0;
        }

    
    aux = rand() % 6;
    if((aux + ncarros1)<MAX){
		    for (int i = 0; i < aux; i++)
    {
	  delay();
      inserir();
    }
    
	ncarros1= ncarros1 + aux;
    	
    	printf("\n%d Novo(s) carro(s) no semafaro 1\n", aux);
      printf("Total de carros no semafaro 1:\n");
      listar();
    }else {
    	ncarros1 = MAX;
    	printf("fila cheia de carros. %d carros no toal.\n",ncarros1);
    }
    
    } else {
    	printf("\n     Semaforo 1 - Vermelho\n");
	aux = rand() % 6;
        
    if((aux + ncarros1)<MAX){
			for (int i = 0; i < aux; i++)
    {
      inserir();
    }
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
    	printf("\n     Semaforo 2 - Verde\n");
    if(ncarros2 > 3){
      for (int i = 0; i < 3; i++)
		     {
			   remover2();
         ncarros2--;
		     }
		}else {
         	for (int i = ncarros2; i !=0; i--)
		        {
			      remover2();
            }
     ncarros2=0;
        }

       if((aux + ncarros2)<MAX){
		       aux = rand() % 6;
      for (int i = 0; i < aux; i++)
       {
		   delay();
      inserir2();
       }
	      ncarros2= ncarros2 + aux;
    	 	printf("%d Novo(s) carro(s) no semafaro 2\n", aux);
        printf("Total de carros no semafaro 2:\n");
        listar2();
    }else {
    	ncarros2 = MAX;
    	printf("fila cheia de carros. %d carros no toal.\n",ncarros2);
    }
        } else {
    	printf("\n     semaforo 2 - Vermelho\n");
    	  aux = rand() % 6;
      if((aux + ncarros2)<MAX){
		for (int i = 0; i < aux; i++)
        {
		delay();
         inserir2();
        }
        ncarros2= ncarros2 + aux;
       	printf("%d Novo(s) carro(s) no semafaro 2\n", aux);
      printf("Total de carros no semafaro 2:\n");
      listar2(); 
    		}else {
    		ncarros2 = MAX;
    		printf("fila cheia de carros. %d carros no total.\n",ncarros2);
    		}
    } //fim do semafaro 2
  }
    contador++;	
  		printf("----------------------------------------\n");
		printf("Interacao:%d\n", contador);
        printf("---------------------------------------\n");
}
getche();
limpafila();
limpafila2();
}