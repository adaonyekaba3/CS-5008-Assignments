// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// Create your node_t type here - STRUCT.
typedef struct node{
	struct node* next; 
	int wins;
	int years;

}node_t;

// Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

//Create the list.
node_t* create_list(){
	node_t* year2018 = malloc(sizeof(node_t));
	node_t* year2017 = malloc(sizeof(node_t));
	node_t* year2016 = malloc(sizeof(node_t));

	// Set up data in each node 
	year2018->years = 2018;
	year2017->years = 2017; 
	year2016->years = 2016; 
	year2018->wins = 108;
	year2017->wins = 93; 
	year2016->wins = 92; 

	// Link the list. 
	year2018->next = year2017;
	year2017->next = year2016;
	year2016->next = NULL;
	
	return year2018;
}
// create print list function here. 
void print_list(node_t* head){
	
	while ( node_t* != NULL){
		printf("%d \n", node_t->head);
	}
	printf("\n");
}

// create free list function. 
//void free_list(node_t* head){

//}

int main(){
	node_t* redsox = NULL;
	redsox = create_list();
	print_list(redsox);

	// iterate
	// point to head of list -> redsox.
	node_t* itr = redsox;
	while( itr != NULL){

		printf("wins in %d are %d\n", itr->years, itr-> wins);
	
		itr = itr->next;
	}

	// free our memory	
//	free_list(redsox);
	
	return 0;
}	  
 
