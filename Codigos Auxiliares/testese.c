#include <stdio.h>
#include <conio.h>
#include<string.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<stdio.h>
#include<time.h>//necessário p/ função time()
#define MAX 10



void delay(){
   time_t start_t, end_t;
   double diff_t;

   time(&start_t);
   while(diff_t<=0.500000){
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    }
}


typedef struct tipo_carro {
    char modelo[15];
    char cor[15];
}Tcarro;



Tcarro inserir(){
		
Tcarro carro;

int corsoteada, carsorteado;
char *cores[4]   = {"Vermelho", "Branco","Cinza", "Preto"};
char *carros[10] = {"Hb20","KA","Gol", "Palio","Mobi","Onix","Kwid","Argo","Uno","Renegade"};

    srand(time(NULL));
    corsoteada = rand() % 4;
    carsorteado = rand() % 10;
        	

	strcpy(carro.modelo, carros[carsorteado]);
	strcpy(carro.cor,cores[corsoteada]);

return carro;
}

void listar(Tcarro carro){
	printf("\n%s			%s", carro.modelo, carro.cor);
	
}

void remover(){

}

int main (){
int topo1, topo2, aux, contador=1;	
int n1;
Tcarro c[4];



          printf("\n        Programa Semaforo\n");
   	printf("\n         Semaforo 1\n");

	srand(time(NULL));
	n1= 5;
	
	for (int i = 0; i<n1; i++){
		
		c[i] = inserir();
		delay();
		
	}
	if(n1 != 0 ){
	
	printf("------------------------------\n");
	printf("Modelo			Cor\n");
	printf("------------------------------\n");

	for (int i=0; i<n1; i++){
		listar(c[i]);
	}
	printf("\nQuantidade de carros na fila = %d.\n", n1);
          }else{
          printf("Fila vazia\n");	
	}
	  
         
    while(contador!=3){
 
 	    printf("----------------------------------------\n");
		printf("Interacao:%d\n", contador);
        printf("---------------------------------------\n");
 
    if (contador%2 != 0){
   
       
	   
    //semafaro 1
    //o que define o estado do semaforo 1, eh o seu topo
        topo1 = 1;
    
    //semafaro 1 - verde
        if (topo1 == 1){
    	    printf("\n     Semaforo 1 - Verde\n");
       	if(n1 > 3){
                for (int i = 0; i < 3; i++)
		        {
				    	//remover item
				for(int j = 0; j < n1-2; j++){
               			 c[j] = c[j + 1];
				printf("\n     Semaforo 1 - removendo\n");
             
	   			}	
			    n1--; 
	      }
	       
                	printf("\n\n------------------------------\n");
		printf(     "Restaram na fila\n");
		printf("Modelo			Cor\n");
		printf("------------------------------\n");
		for (int i=0; i<n1; i++){
		printf("\n%d:\n", i+1);
		listar(c[i]);
		}

		    }else {
         	    for (int i = n1; i !=0; i--)
		        {
		            	//remover item
				for(int i = 0; i < n1-1; i++){
               			 c[i] = c[i + 1];
             
	   			}  

                }
                n1=0; 
        printf("\n\n------------------------------\n");
		printf(     "Restaram na fila\n");
		printf("	Fila vazia\n");
		printf("------------------------------\n");
	
            }

     /*
            aux = rand() % 6;

            for (i = 0; i < aux; i++)
            {
	          c[i] = inserir();
		delay();
            }
    	  printf("\n%d Novo(s) carro(s) no semaforo 1\n", aux);
          
	n1 =n1 + aux;
          
    	if(n1 != 0 ){
	
	printf("------------------------------\n");
	printf("Modelo			Cor\n");
	printf("------------------------------\n");
	for (i=0; i<n1; i++){
		listar(c[i]);
	}
	printf("\nQuantidade de carros na fila = %d.\n", n1);
          }else{
          printf("Fila vazia\n");	
	}	*/
        } //fim do semafaro 1 - verde
    
    //semafaro 1 - vermelho
        if (topo1 == 2){
        	printf("\n     Semaforo 1 - Vermelho\n");
	/*        aux = rand() % 6;
       		for (i = 0; i < aux; i++)
                {
                    c[i] = inserir();
		delay();
                }
	        n1= n1 + aux;
    	
    	  printf("%d Novo(s) carro(s) no semaforo 1\n", aux);
            	if(n1 != 0 ){
	
	printf("------------------------------\n");
	printf("Modelo			Cor\n");
	printf("------------------------------\n");
	for (i=0; i<n1; i++){
		listar(c[i]);
	}
	printf("\nQuantidade de carros na fila = %d.\n", n1);
          }else{
          printf("Fila vazia\n");	
	}
    	*/	
        } //fim do semaforo 1

    }
    contador++;	
}
printf("\nFinal");
//getche();

	
}
