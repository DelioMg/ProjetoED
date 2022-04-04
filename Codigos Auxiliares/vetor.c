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

void delay(){
   time_t start_t, end_t;
   double diff_t;

   time(&start_t);
   while(diff_t<=0.500000){
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    }
}

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


int main(){

char *comb[8];

char *cores[4]   = {"-Vermelho", "-Branco","-Cinza", "-Preto"};
char *carros[10] = {"Hb20","KA","Gol", "Palio","Mobi","Onix","Kwid","Argo","Uno","Renegade"};
int corsoteada, carsorteado;
char *si[10];
    
    for (int i = 0; i < 10; i++)
    {
            srand( (unsigned)time(NULL) );
    corsoteada = rand() % 4;
    carsorteado = rand() % 10;
     delay();
    unistring(comb,carros[carsorteado],cores[corsoteada]);
    //printf("Chegou o %s no sinal\n",comb);
     
        while (*comb != '\0')
    {
        *si[i] = *comb;
        ++si[i];
        ++*comb[i];
    }
   // si[i]=comb;
    printf("teste o %s no sinal\n",si[i]);
     }
    printf("yesye");
   for (int i = 0; i < 10; i++)
   {
    printf("teste o %s no sinal\n",si[i]);
   }
   
}