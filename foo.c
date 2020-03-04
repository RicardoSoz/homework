#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define NTHREADS	2;

void *function(void* var){
	int *ptr = (int *)malloc(sizeof(int));
	
	*ptr = rand()%10;
	
	return ptr;
}

int main(){

	pthread_t thread_id;
	int *result,i,j,sum=0;
	int values[5][2];

	for(i=0; i<5; i++){
		for(j=0;j<2;j++){
			pthread_create(&thread_id, NULL, function, NULL);
			pthread_join(thread_id, (void *)&result);
			values[5][2] = *result;
			sum = sum + values[5][2];
			printf("%d\t", values[5][2]);
		}
		printf("\n");	
	}

	printf("La suma total es: %d\n",sum);
	exit(0);

}

