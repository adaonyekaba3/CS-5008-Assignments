// Implement your part 2 solution here
// gcc -lpthread threads.c -o threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h> 
#include <sys/wait.h>

# define NTHREADS 64

// GLobal array - this is the canvas we are printing on.
// its 64 rows by 64 columns.
int colors[64][64*3];

int counter = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

// Thread with variable arguements.
void *thread(void *vargp){
	pthread_mutex_lock(&mutex1);
		counter += 1;
	pthread_mutex_unlock(&mutex1);
	return NULL;
}

// Define main 
int main(){
	// Store our pthread ID
	pthread_t tids[NTHREADS];
	printf("Counter starts at: %d\n", counter);
	
	// Create and execute multiple threads
	for(int i=0; i < NTHREADS; ++i){
		pthread_create(&tids[i], NULL, thread, NULL);
	}
	// Create and execute multiple threads.
	for(int i=0; i < NTHREADS; ++i){
		pthread_join(tids[i], NULL);
	}
	printf("Final Counter value: %d\n", counter);
	printf("MAsterpiece (threads.ppm) is being assembled\n");
	// Write out a ppm file
	FILE *fp;
	fp = fopen("threads.ppm", "w+");
	fputs("P3\n", fp);
	fputs("64 64\n", fp);
	fputs("255\n", fp);
	for(int i=0; i < 64; i++){
		for(int j=0; j < 64*3; j++){
			fprintf(fp, "%d", colors[i][j]);
			fputs(" ", fp);
		}
		fputs("\n", fp);
	}
	fclose(fp);
	// end program 
	return 0;
}


