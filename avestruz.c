#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

pthread_t tid[3];
sem_t recurse1;
sem_t recurse2;

void *using_recurseA (void *arg){
	sem_wait(&recurse1);
	
	printf("Thread A usando recurso 1 \n");

	int a = 0;
	sleep(5);
	
	printf("Thread A esperando recurso 2 \n");
	sem_wait(&recurse2);
	
	sleep(5);

	printf("Thread A usando recurso 2 \n");

	sem_post(&recurse1);
	sem_post(&recurse2);

	return NULL;
}

void *using_recurseB (void *arg){
	sem_wait(&recurse2);

	printf("Thread B usando recurso 2 \n");

	int a = 0;
	sleep(5);

	printf("Thread B esperando recurso 1 \n");
	sem_wait(&recurse1);
	sleep(5);
	printf("Thread B usando recurso 1 \n");

	sem_post(&recurse2);
	sem_post(&recurse1);

	return NULL;
}

void *do_something_better(){
	sleep(5);
	for (int i = 0; i < 5; i++){
		printf("\nHAHA\n");
	}
}

int main(int argc, char const *argv[]){

	sem_init(&recurse1,1,1);
	sem_init(&recurse2,1,1);

	pthread_t tid1, tid2, tid3;

	if(pthread_create(&tid1, NULL, &using_recurseA, NULL))
		exit(1);
	if(pthread_create(&tid2, NULL, &using_recurseB, NULL))
		exit(1);
	if(pthread_create(&tid3, NULL, &do_something_better, NULL))
		exit(1);
		
		
	

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);

	return 0;
}