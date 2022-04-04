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

void delay(){
   time_t start_t, end_t;
   double diff_t;

   time(&start_t);
   while(diff_t<=0.500000){
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    }
}

void uni2string( char *strinfinal, char *string, char * string2  ){

    while (*string != '\0')
    {
        *strinfinal = *string;
        ++string;
        ++strinfinal;
    }

        while (*string2 != '\0')
    {
        *strinfinal = *string2;
        ++string2;
        ++strinfinal;
    }
    *strinfinal='\0'; 
    
}

void transfere( char *strinfinal, char *string){

    while (*string != '\0')
    {
        *strinfinal = *string;
        ++string;
        ++strinfinal;
    }

   *strinfinal='\0'; 
    
}

void remover(char *str){
char rem[MAX][21];
//printf("O carro %s passou no sinal", str[1]);
for (int i = 1; i < MAX; i++)
{
    transfere(rem[i-1],str[i]);
}
for (int i = 0; i < MAX; i++)
{
    transfere(str[i],rem[i]);
}

}

void adicionar(char *stringf){
char comb[8];
char *cores[4]   = {"-Vermelho", "-Branco","-Cinza", "-Preto"};
char *carros[10] = {"Hb20","KA","Gol", "Palio","Mobi","Onix","Kwid","Argo","Uno","Renegade"};
int corsoteada, carsorteado;
    

            srand( (unsigned)time(NULL) );
    corsoteada = rand() % 4;
    carsorteado = rand() % 10;
     
    uni2string(comb,carros[carsorteado],cores[corsoteada]);
    //printf("Chegou o %s no sinal\n",comb);
    transfere(stringf,comb);
    delay();
    }

int main(void){

char fila1[MAX][21];
char fila2[MAX][21];
int aux;
    
    printf("\n           Programa Semafaro\n");
    srand(time(NULL));
    delay();
    printf("\n              Semafaro 1\n");
    ncarros1= rand() % 6;// gerando valores aleatórios na faixa de 0 a 6 para numero inicial de carros que tem na fila 2
    for (int i = 0; i <ncarros1 ; i++)
    {
        adicionar(fila1[i]);
        printf("              %s\n",fila1[i]);
    }
    printf("           %d carros na fila\n",ncarros1);

    printf("\n              Semafaro 2\n");
    ncarros2= rand() % 6; // gerando valores aleatórios na faixa de 0 a 6 para numero inicial de carros que tem na fila 2
    for (int i = 0; i <ncarros2 ; i++)
    {
        adicionar(fila2[i]);
        printf("              %s\n",fila2[i]);
    }   
    printf("           %d carros na fila\n\n",ncarros2);

    for(int contador = 1; contador <= 2; contador++){
        
        srand(time(NULL));
        
        printf("\n----------------------------------------\n");
        printf("          Semaforo 1 - Verde\n");
        
                if(ncarros1 > 3){ //retira 3 carros da fila
            for (int i = 0; i < 3; i++)
            {
                remover(fila1);
                ncarros1--;
            }
            
               
        }else {
            
            for (int j = 0; j < ncarros1; j++)
            {
                remover(fila1);
            }
            ncarros1=0;
        }

        aux = rand() % 3;
        if((aux + ncarros1)<MAX){
	        printf("    %d Novo(s) carro(s) no semafaro 1\n", aux);
    	    for (int i = ncarros1; i <ncarros1 + aux ; i++)
                {
                    adicionar(fila1[i]);
                    printf("              %s\n",fila1[i]);
                }   
                ncarros1= ncarros1 + aux ;
                for (int i = 0; i <ncarros1; i++)
                    {
                    printf("              %s\n",fila1[i]);
                } 
                printf("           %d carros na fila\n\n",ncarros1);
        
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
	        printf("    %d Novo(s) carro(s) no semafaro 1\n", aux);
    	    for (int i = ncarros1; i <ncarros1 + aux ; i++)
                {
                    adicionar(fila1[i]);
                    printf("              %s\n",fila1[i]);
                }   
                ncarros1= ncarros1 + aux ;
                for (int i = 0; i <ncarros1; i++)
                    {
                    printf("              %s\n",fila1[i]);
                } 
                printf("           %d carros na fila\n\n",ncarros1);
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
    //getch();
}