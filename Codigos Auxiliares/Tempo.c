#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main(){
int i=0;
	clock_t timer;
	timer = clock();
	
	int sum=10;
	while(i<=50000)
	{
		sum=sum/(i+1);
		i++;	
	}
	
	timer = clock() - timer;
	
	printf("\n\n%f segundo(s) de execucao\n\n", ((float)timer)/CLOCKS_PER_SEC);

system("pause");
}