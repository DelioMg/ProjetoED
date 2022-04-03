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

void delay(){
   time_t start_t, end_t;
   double diff_t;

   //printf("Inicio do programa...\n");
   time(&start_t);
   while(diff_t<=0.250000){
    time(&end_t);
   diff_t = difftime(end_t, start_t);
}

   //printf("pronto passou 5 segundo\n");
}

//inserir carro na fila
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

int main () {

for (int i = 0; i < 10; i++)
{
   delay();
   inserir();
}

listar();
   return(0);
}