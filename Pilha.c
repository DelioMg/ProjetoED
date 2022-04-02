#include <stdio.h>
#include <stdlib.h>
#define tamanho 2


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
	int aux;
    semafaro1.topo = 0;
    semafaro1.ini = 0;

    semafaro2.topo = 0;
    semafaro2.ini = 0;


    empilha(1, &semafaro1);
    empilha(2, &semafaro1);
    
    printf("%d\n", topo(&semafaro1));
    printf("%d\n", inicio(&semafaro1));	     
  
    
}