#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    char *cores[4]   = {"Vermelho", "Branco","Cinza", "Preto"};
    char *carros[10] = {"Hb20","KA","Gol", "Palio","Mobi","Onix","Kwid","Argo","Uno","Renegade"};


    int corsoteada,carsorteado;

    srand(time(NULL));
        corsoteada = rand() % 4;
        printf("O sorteado foi: %s\n", cores[corsoteada]);
        carsorteado = rand() % 4;
        printf("O sorteado foi: %s\n", carros[carsorteado]);
    

    //getchar();
    return(0);
}