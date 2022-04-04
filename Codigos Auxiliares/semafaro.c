#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<stdio.h>
#include<time.h>//necessário p/ função time()
#include<string.h>
#define MAX 10

int ncarros1=0, ncarros2=0; //Numero de Carros
int pcarro1=0, pcarro2=0; //Tempo que proximo carro vai entrar na fila 
int c1=0, c2=0; //conta tempo para proximo carro
int t1=0, t2=0; //tempo de cada cor, incremento equivale a 5s


void unistring( char *strinfinal, char *string1, char * string2  ){

    while (*string1 != '\0')
    {
        *strinfinal = *string1;
        ++string1;
        ++strinfinal;
    }

        while (*string2 != '\0')
    {
        *strinfinal = *string2;
        ++string2;
        ++strinfinal;
    }
    *strinfinal='\0'; 
    //strcat(colarAqui, copiarDaqui2);
   

}

void sortear(){
char comb[8];
char *cores[4]   = {"-Vermelho", "-Branco","-Cinza", "-Preto"};
char *carros[10] = {"Hb20","KA","Gol", "Palio","Mobi","Onix","Kwid","Argo","Uno","Renegade"};
int corsoteada, carsorteado;
char *si[10];
    
    for (int i = 0; i < 10; i++)
    {
            srand( (unsigned)time(NULL) );
    corsoteada = rand() % 4;
    carsorteado = rand() % 10;
     
    unistring(comb,carros[carsorteado],cores[corsoteada]);
    printf("Chegou o %s no sinal\n",comb);
    si[i]=*comb;
    printf("teste o %s no sinal\n",si[i]);

    }
    


  //  return(comb);
}

int main(void){
int aux;
    
    printf("\n           Programa Semafaro\n");
    srand(time(NULL));
    
    printf("\n              Semafaro 1\n");
    ncarros1= rand() % 6;// gerando valores aleatórios na faixa de 0 a 6 para numero inicial de carros que tem na fila 2
    printf("           %d carros na fila\n",ncarros1);
    printf("\n              Semafaro 2\n");
    ncarros2= rand() % 6; // gerando valores aleatórios na faixa de 0 a 6 para numero inicial de carros que tem na fila 2
    printf("           %d carros na fila\n\n",ncarros2);
        
    for(int contador = 1; contador <= 10; contador++){
        
        srand(time(NULL));
        
        printf("\n----------------------------------------\n");
        printf("          Semaforo 1 - Verde\n");
        sortear();
        if(ncarros1 > 3){ //retira 3 carros da fila
            
            ncarros1= ncarros1 -3;
    
        }else {
            ncarros1=0;
        }

        aux = rand() % 3;
        if((aux + ncarros1)<MAX){
	        ncarros1= ncarros1 + aux;
    	   	printf("    %d Novo(s) carro(s) no semafaro 1\n", aux);
    	    printf("     Total de %d carros no semafaro 1\n", ncarros1);
        
        }else {
    	    ncarros1 = MAX;
    	    printf("  fila cheia de carros. %d carros no total.\n",ncarros1);
        }
    

        printf("\n            Semaforo 2 - Vermelho\n");
        
        aux = rand() % 3;
        if((aux + ncarros2)<MAX){
	        ncarros2= ncarros2 + aux;
    	
    	    printf("    %d Novo(s) carro(s) no semafaro 2\n", aux);
    	    printf("    Total de %d carros no semafaro 2\n", ncarros2);
       
        }else {
    	    ncarros2 = MAX;
    	    printf("  fila cheia de carros. %d carros no total.\n",ncarros2);
        }

        printf("\n----------------------------------------\n");
        printf("          Semaforo 1 - Vermelho\n");
         aux = rand() % 3;
        if((aux + ncarros1)<MAX){
	        ncarros1= ncarros1 + aux;
    	
    	    printf("    %d Novo(s) carro(s) no semafaro 1\n", aux);
    	    printf("    Total de %d carros no semafaro 1\n", ncarros1);
    
        }else {
    	    ncarros1 = MAX;
    	    printf("  fila cheia de carros. %d carros no total.\n",ncarros1);
        }
    
    
        printf("\n          Semaforo 2 - Verde\n");
        if(ncarros2 > 3){
            ncarros2= ncarros2 -3;
    
        }else {
            ncarros2=0;
        }
     
        aux = rand() % 3;
        if((aux + ncarros2)<MAX){
	        ncarros2= ncarros2 + aux;
    	
        	printf("    %d Novo(s) carro(s) no semafaro 2\n", aux);
        	printf("    Total de %d carros no semafaro 2\n", ncarros2);
        }else {
        	ncarros2 = MAX;
        	printf("  fila cheia de carros. %d carros no total.\n",ncarros2);
    }
  }
 
    printf("\n----------------------------------------\n");
    getch();
}