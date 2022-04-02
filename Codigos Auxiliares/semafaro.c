#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<stdio.h>
#include<time.h>//necessário p/ função time()
#define MAX 10

int ncarros1=0, ncarros2=0; //Numero de Carros
int pcarro1=0, pcarro2=0; //Tempo que proximo carro vai entrar na fila 
int c1=0, c2=0; //conta tempo para proximo carro
int t1=0, t2=0; //tempo de cada cor, incremento equivale a 5s

int main(void){
int aux;
    
    printf("\n        Programa Semafaro\n");
    srand(time(NULL));
    ncarros1= rand() % 6; // gerando valores aleatórios na faixa de 0 a 6 para numero de carros que tem na fila
    //Inserir a quantidade ncarros1 na fila1
    printf("%d carros na fila do semafaro 1\n",ncarros1);//Listar carrros que estão na pilha1 
    
    ncarros2= rand() % 6; // gerando valores aleatórios na faixa de 0 a 6 para numero de carros que tem na fila
    //Inserir a quantidade ncarros2 na fila2
    printf("%d carros na fila do semafaro 2\n\n",ncarros2);//Listar carrros que estão na pilha2
        
int contador = 1; 
  
  for(contador = 1; contador <= 10; contador++)
  {
      srand(time(NULL));
printf("\n");
printf("semaforo 1 - Verde\n");
         //retira 3 carros da fila
    if(ncarros1 > 3){
        ncarros1= ncarros1 -3;
    }else {
        ncarros1=0;
    }
    printf("%d carros na fila\n",ncarros1);//Listar carrros que estão na pilha1 
    aux = rand() % 3;
    if((aux + ncarros1)<MAX){
	ncarros1= ncarros1 + aux;
    	
    	printf("%d Novo(s) carro(s) no semafaro 1\n", aux);
    	printf("Total de %d carros no semafaro 1\n", ncarros1);
    }else {
    	ncarros1 = MAX;
    	printf("fila cheia de carros. %d carros no total.\n",ncarros1);
    }
    

    printf("semaforo 2 - Vermelho\n");
    printf("%d carros na fila\n",ncarros2);//Listar carrros que estão na pilha2
     aux = rand() % 3;
     if((aux + ncarros2)<MAX){
	ncarros2= ncarros2 + aux;
    	
    	printf("%d Novo(s) carro(s) no semafaro 2\n", aux);
    	printf("Total de %d carros no semafaro 2\n\n\n", ncarros2);
    }else {
    	ncarros2 = MAX;
    	printf("fila cheia de carros. %d carros no total.\n\n\n",ncarros2);
    }

    

    printf("semaforo 1 - Vermelho\n");
    printf("%d carros na fila\n",ncarros1);//Listar carrros que estão na pilha2
     aux = rand() % 3;
     if((aux + ncarros1)<MAX){
	ncarros1= ncarros1 + aux;
    	
    	printf("%d Novo(s) carro(s) no semafaro 1\n", aux);
    	printf("Total de %d carros no semafaro 1\n", ncarros1);
    }else {
    	ncarros1 = MAX;
    	printf("fila cheia de carros. %d carros no total.\n",ncarros1);
    }
    
    
    printf("semaforo 2 - Verde\n");
         //retira 3 carros da fila
    if(ncarros2 > 3){
        ncarros2= ncarros2 -3;
    }else {
        ncarros2=0;
    }
    printf("%d carros na fila\n",ncarros2);//Listar carrros que estão na pilha1 
    aux = rand() % 3;
    if((aux + ncarros2)<MAX){
	ncarros2= ncarros2 + aux;
    	
    	printf("%d Novo(s) carro(s) no semafaro 2\n", aux);
    	printf("Total de %d carros no semafaro 2\n", ncarros2);
    }else {
    	ncarros2 = MAX;
    	printf("fila cheia de carros. %d carros no total.\n\n\n",ncarros2);
    }
    
    
   
  }

}