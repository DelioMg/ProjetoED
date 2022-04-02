#include <stdio.h>
#include <stdlib.h>
#define tamanho 2
#define MAX 10


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
    ncarros1= rand() % 6; // gerando valores aleatórios na faixa de 0 a 6 para numero de carros que tem na fila
    //Inserir a quantidade ncarros1 na fila1
    printf("%d carros na fila do semafaro 1\n",ncarros1);//Listar carrros que estão na fila1 
    
    ncarros2= rand() % 6; // gerando valores aleatórios na faixa de 0 a 6 para numero de carros que tem na fila
    //Inserir a quantidade ncarros2 na fila2
    printf("%d carros na fila do semafaro 2\n\n",ncarros2);//Listar carrros que estão na fila2
    
    //inicializando a pilha do semafaro 1
    empilha(2, &semafaro1);
    empilha(1, &semafaro1);	     
    
	    
    //semafaro 1
    //o que define o estado do semafaro 1, é o seu topo
    topo1 = topo(&semafaro1);
    
    //semafaro 1 - verde
    if (topo1 == 1){
    	printf("\n\nsemaforo 1 - Verde\n");
    	if(ncarros1 > 3){
        ncarros1= ncarros1 -3;
        }else {
          ncarros1=0;
        }
        printf("%d carros na fila\n",ncarros1);//Listar carrros que estão na pilha1 
        aux = rand() % 6;
           if((aux + ncarros1)<MAX){
	        ncarros1= ncarros1 + aux;
    	    printf("%d Novo(s) carro(s) no semafaro 1\n", aux);
    	    printf("Total de %d carros no semafaro 1\n", ncarros1);
           }else {
    	    ncarros1 = MAX;
    	    printf("fila cheia de carros. %d carros no toal.\n",ncarros1);
           }
    
    } else {
    	printf("\n\nsemaforo 1 - Vermelho\n");
    	printf("%d carros na fila\n",ncarros1);//Listar carrros que estão na pilha2
        aux = rand() % 6;
     		if((aux + ncarros1)<MAX){
		     ncarros1= ncarros1 + aux;
    	  	 printf("%d Novo(s) carro(s) no semafaro 1\n", aux);
    	     printf("Total de %d carros no semafaro 1\n", ncarros1);
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
          ncarros2= ncarros2 -3;
        }else {
          ncarros2=0;
        }

        printf("%d carros na fila\n",ncarros2);//Listar carrros que estão na pilha1 
        aux = rand() % 6;
        if((aux + ncarros2)<MAX){
	      ncarros2= ncarros2 + aux;
    	  printf("%d Novo(s) carro(s) no semafaro 2\n", aux);
    	  printf("Total de %d carros no semafaro 2\n", ncarros2);
        }else {
    	  ncarros2 = MAX;
    	  printf("fila cheia de carros. %d carros no toal.\n",ncarros2);
        }
    
    } else {
    	printf("semaforo 2 - Vermelho\n");
    	printf("%d carros na fila\n",ncarros2);//Listar carrros que estão na pilha2
        aux = rand() % 6;
     	if((aux + ncarros2)<MAX){
		  ncarros2= ncarros2 + aux;
    	  printf("%d Novo(s) carro(s) no semafaro 2\n", aux);
    	  printf("Total de %d carros no semafaro 2\n", ncarros2);
    	}else {
    	  ncarros2 = MAX;
    	  printf("fila cheia de carros. %d carros no total.\n",ncarros2);
    	}
    } //fim do semafaro 2

}

