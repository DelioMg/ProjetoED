#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
int i;
	clock_t timer;
	timer = clock();
	
	for(i=0 ; i<=50000; i++){
		printf("%d", i);	
	}
	
	timer = clock() - timer;
	
	printf("\n\n%f segundo(s) de execucao\n\n", ((float)timer)/CLOCKS_PER_SEC);

system("pause");
}