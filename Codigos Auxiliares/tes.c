#include <stdio.h>
#include <conio.h>
#include<string.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include<stdio.h>
#include<time.h>//necessário p/ função time()
#define MAX 10

typedef struct tipo_carro {
    char modelo[15];
    char cor[15];
}Tcarro;

typedef struct tipo_carro2 {
    char modelo2[15];
    char cor2[15];
}Tcarro2;

void delay(){
   time_t start_t, end_t;
   double diff_t;

   time(&start_t);
   while(diff_t<=0.500000){
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    }
}

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

	printf("       %s		   %s\n", carro.modelo, carro.cor);
	
}

Tcarro2 inserir2(){
		
Tcarro2 carro2;

int corsoteada2, carsorteado2;
char *cores[4]   = {"Vermelho", "Branco","Cinza", "Preto"};
char *carros[10] = {"Hb20","KA","Gol", "Palio","Mobi","Onix","Kwid","Argo","Uno","Renegade"};

    srand(time(NULL));
    corsoteada2 = rand() % 4;
    carsorteado2 = rand() % 10;
        	

	strcpy(carro2.modelo2, carros[carsorteado2]);
	strcpy(carro2.cor2,cores[corsoteada2]);

return carro2;
}

void listar2(Tcarro2 carro2){

	printf("       %s		   %s\n", carro2.modelo2, carro2.cor2);
	
}


int main (){
int topo1, topo2, aux, contador=1;	
int n1,n2;
Tcarro c[10];
Tcarro2 c2[10];



    printf("\n             Programa Semafaro\n");
   	printf("\n                Semafaro 1\n");

	srand(time(NULL));
	n1 = rand() % 6;
	
	for (int i=0; i<n1; i++){
		
		c[i] = inserir();
		delay();
		
	}
	if(n1 != 0 ){
	
	    printf("----------------------------------------\n");
	    printf("      Modelo		   Cor\n");
	    printf("----------------------------------------\n");
	    
        for (int i=0; i<n1; i++){
		    listar(c[i]);
	    }
        
        printf("----------------------------------------\n");
	    printf("Quantidade de carros na fila = %d.\n", n1);
        printf("----------------------------------------\n");
        
    }else{
        printf("	      Fila vazia\n");	
	}

	printf("\n                Semafaro 2\n");

	srand(time(NULL));
	n2 = rand() % 6;
	for (int i=0; i<n2; i++)
        {
			c2[i] = inserir2();
		    delay();
		}
	if(n2 != 0 ){
	
	    printf("----------------------------------------\n");
	    printf("      Modelo		   Cor\n");
	    printf("----------------------------------------\n");
	    
        for (int i=0; i<n2; i++)
        {
		listar2(c2[i]);
	    }
        
        printf("----------------------------------------\n");
	    printf("Quantidade de carros na fila = %d.\n", n2);
        printf("----------------------------------------\n");
  
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
        printf("\n           Semafaro 1 - Verde\n");
    	if(n1 > 3){
            for (int i = 0; i < 3; i++)
	        {
                for(int j= 0; j < n1-1; j++){ //remover item
                   c[j] = c[j + 1];
    	    	}
                                       
                    //listar(c[i]);
               	    //printf(" passou no sinal\n");   
		        n1--; 
	       }

	    }else {
     	    for (int i = n1; i !=0; i--)
	        {
 
                for(int j= 0; j < n1-1; j++){ //remover item
                   c[j] = c[j + 1];
     	    	}
                                       
                    //listar(c[i]);
               	    //printf(" passou no sinal\n");   
		
            }
            n1=0; 
            
            printf("----------------------------------------\n");
		    printf("           Restaram na fila\n");
		    printf("	      Fila vazia\n");
		    printf("----------------------------------------\n");
	    
        }

            
        aux = rand() % 6;
        printf("\n    %d Novo(s) carro(s) no semafaro 1\n", aux);
        aux = aux + n1;
        for (int i = n1 ; i < aux; i++)
            {
	            c[i] = inserir();
		        delay();
             // listar(c[i]);
             // printf(" chegou a sinal");
           
            }
    	n1 = aux;
            
	
          
    	if(n1 != 0 ){
	
	       printf("----------------------------------------\n");
	       printf("      Modelo		   Cor\n");
	       printf("----------------------------------------\n");
	    
           for (int i=0; i<n1; i++)
            {
	    	    listar(c[i]);
	        }
        
            printf("----------------------------------------\n");
	        printf("Quantidade de carros na fila = %d.\n", n1);
            printf("----------------------------------------\n");
        
        }else{
            printf("Fila vazia\n");	
	    }	
    } //fim do semafaro 1 - verde
    
    
     //semafaro 2
     //o que define o estado do semafaro 2, Ã© o seu topo
    
    topo2 = 2;
    
     //semaforo 2 - vermelho
    if (topo2 == 2){

      	printf("\n           Semafaro 2 - Vermelho\n");
        aux = rand() % 6;
        printf("\n    %d Novo(s) carro(s) no semafaro 2\n", aux);
        aux = aux + n2;
     
        for (int i = n2 ; i < aux; i++)
        {
	        c2[i] = inserir2();
	        delay();
             // listar(c2[i]);
             // printf(" chegou a sinal");
        }
     
        n2 = aux;
            
	
          
    	if(n2 != 0 ){
	
	        printf("----------------------------------------\n");
	        printf("      Modelo		   Cor\n");
         	printf("----------------------------------------\n");
	        
            for (int i=0; i<n2; i++)
            {
		        listar2(c2[i]);
	        }
            
            printf("----------------------------------------\n");
	        printf("Quantidade de carros na fila = %d.\n", n2);
            printf("----------------------------------------\n");
        
        }else{
            printf("	      Fila vazia\n");	
     	}	
    } //fim do semafaro 2
    
	}else{
      
	topo1 = 2;
    
    //semafaro 1 - vermelho

        if (topo1 == 2){
    printf("\n           Semafaro 1 - Vermelho\n");
        	 aux = rand() % 6;
            printf("\n     %d Novo(s) carro(s) no semafaro 1\n", aux);
            aux = aux + n1;
            for (int i = n1 ; i < aux; i++)
            {
	          c[i] = inserir();
		      delay();
             // listar(c[i]);
             // printf(" chegou a sinal");
            }
    	    n1 = aux;
            
	
          
    	if(n1 != 0 ){
	
	printf("----------------------------------------\n");
	printf("      Modelo		   Cor\n");
	printf("----------------------------------------\n");
	for (int i=0; i<n1; i++){
		listar(c[i]);
	}
    printf("----------------------------------------\n");
	printf("Quantidade de carros na fila = %d.\n", n1);
    printf("----------------------------------------\n");
          }else{
          printf("	      Fila vazia\n");	
	}	
    		
        } //fim do semafaro 1

     //semaforo 2
    //o que define o estado do semafaro 2, eh o seu topo

    
        topo2 = 1;
    
        //semafaro 2 - verde
        if (topo2 == 1){
    	    printf("\n           Semafaro 2 - Verde\n");
        	if(n2 > 3){
                for (int i = 0; i < 3; i++)
		        {
                    for(int j= 0; j < n2-1; j++){ //remover item
                       c2[j] = c2[j + 1];
     		    	}
                                       
                    //listar(c[i]);
               	    //printf(" passou no sinal\n");   
			        n2--; 
	           }

		    }else {
         	    for (int i = n2; i !=0; i--)
		        {
 {
                    for(int j= 0; j < n2-1; j++){ //remover item
                       c2[j] = c2[j + 1];
     		    	}
                                       
                    //listar(c[i]);
               	    //printf(" passou no sinal\n");   
			       
	   			}  

                }
                n2=0; 
        printf("----------------------------------------\n");
		printf("             Restaram na fila\n");
		printf("	      Fila vazia\n");
		printf("----------------------------------------\n");
	    
            }

            
            aux = rand() % 6;
            printf("     \n%d Novo(s) carro(s) no semafaro 2\n", aux);
            aux = aux + n2;
            for (int i = n2 ; i < aux; i++)
            {
	          c2[i] = inserir2();
		      delay();
             // listar(c[i]);
             // printf(" chegou a sinal");
            }
    	    n2 = aux;
            
	
          
    	if(n2 != 0 ){
	
	printf("----------------------------------------\n");
	printf("      Modelo		   Cor\n");
	printf("----------------------------------------\n");
	for (int i=0; i<n2; i++){
		listar2(c2[i]);
	}
    printf("----------------------------------------\n");
	printf("Quantidade de carros na fila = %d.\n", n2);
    printf("----------------------------------------\n");
          }else{
          printf("	      Fila vazia\n");	
	}	
        }
    }
    contador++;	
}
printf("\nFinal");
getche();

	
}

