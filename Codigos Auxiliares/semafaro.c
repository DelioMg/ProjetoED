#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<stdio.h>
#include<time.h>//necessário p/ função time()

int ncarros1=0, ncarros2=0; //Numero de Carros
int pcarro1=0, pcarro2=0; //Tempo que proximo carro vai entrar na fila 
int c1=0, c2=0; //conta tempo para proximo carro
int t1=0, t2=0; //tempo de cada cor, incremento equivale a 5s

int main(void){

    
    printf("\n        Programa Semafaro\n");
    srand(time(NULL));
    ncarros1= rand() % 6; // gerando valores aleatórios na faixa de 0 a 6 para numero de carros que tem na fila
    //Inserir a quantidade ncarros1 na fila1
    printf("%d carros na fila do semafaro 1\n",ncarros1);//Listar carrros que estão na pilha1 
    
    ncarros2= rand() % 6; // gerando valores aleatórios na faixa de 0 a 6 para numero de carros que tem na fila
    //Inserir a quantidade ncarros2 na fila2
    printf("%d carros na fila do semafaro 2\n\n",ncarros2);//Listar carrros que estão na pilha2
        
int contador = 1; 
  
  while (contador <= 10) 
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
    if(c1 == 0){
    pcarro1= rand() % 30; // gerando valores aleatórios na faixa de 0 a 30 para tempo que proximo carro vai entrar na fila
    c1= pcarro1/5;
      if(c1 == 0){
        printf("Novo carro no semafaro 1\n");
        //insere um carro na fila 
        ncarros1 ++;
        c1=0;
        t1=0;  
      }
      t1++;
    }
    if(c1 == t1){
        printf("Novo carro no semafaro 1\n");
        //insere um carro na fila 
        ncarros1 ++;
        c1=0;
        t1=0;
    }

    
    
    printf("semaforo 2 - Vermelho\n");
    printf("%d carros na fila\n",ncarros2);//Listar carrros que estão na pilha2
    if(c2 == 0){
    pcarro2= rand() % 30; // gerando valores aleatórios na faixa de 0 a 30 para tempo que proximo carro vai entrar na fila
    c2= pcarro2/5;
      if(c2 == 0){
        printf("Novo carro no semafaro 2\n");
        //isere um carro na fila 2 
        ncarros2 ++;
        c2=0;
        t2=0;  
      }
      t2++;
    }
    if(c2 == t2){
        printf("Novo carro no semafaro 2\n");
        //isere um carro na fila 2
        ncarros2 ++;
        c2=0;
        t2=0;
    }
    
    //Segundo sinal
    printf("\n");
    printf("semaforo 1 - Vermelho\n");
    printf("%d carros na fila\n",ncarros1);//Listar carrros que estão na pilha1
    if(c1 == 0){
    pcarro1= rand() % 30; // gerando valores aleatórios na faixa de 0 a 30 para tempo que proximo carro vai entrar na fila
    c1= pcarro2/5;
      if(c1 == 0){
        printf("Novo carro no semafaro 2\n");
        //insere um carro na fila 2 
        ncarros1 ++;
        c1=0;
        t1=0;  
      }
      t1++;
    }
    if(c1 == t1){
        printf("Novo carro no semafaro 2\n");
        //insere um carro na fila 2
        ncarros1 ++;
        c1=0;
        t1=0;
    }
     

    
    printf("semaforo 2 - Verde\n");
    //retira 3 carros da fila
        if(ncarros2 > 3){
        ncarros2= ncarros2 -3;
    }else {
        ncarros2=0;
    }
    printf("%d carros na fila\n",ncarros2);//Listar carrros que estão na pilha2
    
    if(c2 == 0){
    pcarro2= rand() % 30; // gerando valores aleatórios na faixa de 0 a 30 para tempo que proximo carro vai entrar na fila
    c2= pcarro2/5;
      if(c2 == 0){
        printf("Novo carro no semafaro 1\n");
        //insere um carro na fila 
        ncarros2 ++;
        c2=0;
        t2=0;  
      }
      t2++;
    }
    if(c2 == t2){
        printf("Novo carro no semafaro 1\n");
        //insere um carro na fila 
        ncarros2 ++;
        c2=0;
        t2=0;
    }
    contador++;
  }

}