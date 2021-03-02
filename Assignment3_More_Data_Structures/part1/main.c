// Compile this assignment with: gcc -g -Wall main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.



// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	dll_t* dll = create_dll();
	/*
	populate_dll(dll);
	print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));*/
	
	dll_pop_front(dll);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	
	dll_pop_front(dll);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	
	dll_pop_back(dll);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	
	dll_pop_back(dll);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));

	dll_push_front(dll, 5);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	dll_push_back(dll, 20);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	
	dll_insert(dll, 1, 7);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	dll_insert(dll, 1, 6);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	dll_insert(dll, 5, 16);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	dll_insert(dll, 5, 15);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	
	printf("%d\n", dll_get(dll, 0)); 
	printf("%d\n", dll_get(dll, 1));
	printf("%d\n", dll_get(dll, 6));
	printf("%d\n", dll_get(dll, 7));  
    
	dll_remove(dll, 0);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	dll_remove(dll, 0);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	dll_remove(dll, 5);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	dll_remove(dll, 4);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	dll_remove(dll, 1);
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	dll_remove(dll, 1);    
	//print_dll(dll);
	printf("\ntotal: %d\n", dll_size(dll));
	
	free(dll);
	return 0;
}
