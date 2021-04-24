// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Creates new node for BST.
bstnode_t* create_node(int item){
	// init new node.
	bstnode_t* newNode = (bstnode_t*)malloc(sizeof(bstnode_t));
	newNode->data = item;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	
	return newNode;
}

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
	
	// Modify the body of this function as needed.
	bst_t* myBST = (bst_t*)calloc(1,sizeof(bst_t));
	myBST->size = 0;
	myBST->root = NULL;

	return myBST;	
}


// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
	
	return t->size == 0;
}


// Adds a new node containng item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
int bst_addHelper(bstnode_t* t, int item)
{
	if(t){
		if(item <= t->data){
			if(t->leftChild == NULL){
				// if new node created 
				t->leftChild = create_node(item);
				return 1; // if successful
			}else{
				if(bst_addHelper(t->leftChild,item) == 1)
					return 1; // if successful. 
				
			}
		}else{
			if(t->rightChild == NULL){
				// if new node created
				t->rightChild = create_node(item);
				return 1; // if successful	
			}else{
				if(bst_addHelper(t->rightChild,item) == 1){
					return 1; // if successful
				}
			}
		}
	}
	return -1; // if failed.
}
int bst_add(bst_t* t, int item)
{
	
	// init status integer & print
	int status = -1;
	
	if(t){
		if(t->root == NULL){						
			// if pointer at root is empty 
			// node is created.
			t->root = create_node(item);
			status = 1;	
		}else{
			// call addHeler at node 
			status = bst_addHelper(t->root, item);	
		}
	}else{
		if(status == 1){
			// create pointer for size 
			t->size++;
		}
	
	}
	return status;
}

// print bst in ascending order and then descending order
// if order = 0, then recursively call bst_print_ascending 
// starting from node to left then to rightChild 
// and for descending - start from node right to left 
void bst_print_ascending(bstnode_t* t)
{
	if(t){
		// print bst ascending from left to right
		bst_print_ascending(t->leftChild);
		printf("%d\n", t->data);

		bst_print_ascending(t->rightChild);
	}
}

//descending order bst print 
void bst_print_descending(bstnode_t* t)
{
	if(t){
		// print bst descending from right to left 
		bst_print_descending(t->rightChild);
		printf("%d\n", t->data);

		bst_print_descending(t->leftChild);
	}
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree -- print "(NULL)".
// It should run in O(n) time.
void bst_print(bst_t *t, int order){

	if(NULL == t){
		
		printf("(NULL)");

	}else{
		if(order == 0){	
			bst_print_ascending(t->root);
		}else{
			bst_print_descending(t->root);
		}


	}
}
// bst add -sumHelper 
// returns the sum of all nodes in the bst 
// exits the program for a NULL tree 
// runs in O(n) time
int sumHelper(bstnode_t* node)
{
	if(node){
		return node->data = sumHelper(node->leftChild) + sumHelper(node->rightChild);
	}
	// if true 
	return 0;	
}

// Returns the sum of all the nodes in the bst. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(bst_t *t){
	
	return sumHelper(t->root);
}

// bst findHelper function is needed. 
int findHelper(bstnode_t* node, int value)
{
	if(node)
	{
		if(node->data == value)
		{
			return 1; // if value is found successfully.
		}
		if(findHelper(node->leftChild,value) == 1)
		{
			return 1; // if value is found successfully in left child position.	
		}
		if(findHelper(node->rightChild,value) == 1)
		{
			return 1; // if value is successfully found!
		}
	
		
	}return 0;	
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exits the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){
	
	// recursive call findHelper function.
	findHelper(t->root,value);
	return 1;	
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t)
{
	
	if(t){
		return t->size;
	}else{
		exit(0);
	}
	return 0;
}

// create freeHelper function.
void freeHelper(bstnode_t* t)
{
	
	if(t){
		// recursively call freeHelper function from left to right
		freeHelper(t->leftChild);
		freeHelper(t->rightChild);
		// call built in free function on node
		free(t);
	}
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){
	
	// recursively call bst_free Helper function.
	freeHelper(t->root);
	t->size = 0;
	free(t); // free the node. 
}

