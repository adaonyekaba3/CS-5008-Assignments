#include <stdio.h> // access std lib
#include <stdlib.h> // malloc and free.

// Compile: clang -g debug.c -o debug 

// Create fuction called add. 
int add(int a, int b){
	return a+b;
}

int main(){
	// printf debugging to clear segmentation fault
	// at beginning of program. 

	// initialize pointer called 
	// instead of printf debugging, use gdb
	// gdb - says we didn't initialize array 
	// for however many integers we want.
	int* array = malloc(sizeof(int)*5);; 
	for(int i=0; i < 5; i++){ // create loop to access array and adding to it. 
		array[i] = add(i,100);
		printf("add(i,100) = %d\n", array[i]);
	}
	// do printf debugging at end of program 
	// to clear segmentation fault. 
	
	// replace/rmv printf("ending program \n");
	free(array);
	return 0; 
	// returns - segmentation fault (core dumped)
	// means we accessed something we dont have access to.
	// a segment we dont have access to.  
}
