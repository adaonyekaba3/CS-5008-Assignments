// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
	
	int data;
	
	// print statement to indicate memory allocation
	printf("Enter data of node to be insrted: ");
	scanf("%d", &data);

	// Modify the body of this function as needed.
	bst_t* myBST = (bst_t*)malloc(1*sizeof(bst_t));
	
	if(myBST == NULL){
		return NULL;	
	}else{
		myBST->root = NULL;
		// SET count to 0, as no node is added to BST. 
		myBST->size = 0;
	}
	return myBST;	
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
	
	// NULL Check!
	if(t == NULL){
		return 1; // True if binary search tree is empty!
	}else{
		return 0; // False if at least 1 element is found!
	}
}

// bst_insert(1, t) inserts item 1 into the bst tree
// effects: modifies t if i is not already in t.
// function must be called from add_BST() function
node_insert(bstnode_t* bstnode, int key){
	
	// perform NULL Check!
	if(bstnode == NULL){
		// allocate memory for new node 
		bstnode* temp = (bstnode*)malloc(sizeof(bstnode));
		// initialize node by value && set left/righ child to NULL.
		temp->data = key;
		temp->leftChild = NULL;
		temp->rightChild = NULL;
		return temp;
	// else recurse down the tree.
	} // insert at left child 
	if(key < bstnode->data){
		bstnode->leftChild = node_insert(bstnode->leftChild, key);	

	}else if(key > bstnode->data){
		bstnode->rightChild = node_insert(bstnode->rightChild, key);
	}
	return bstnode;
}	
/*
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
int bst_add(bst_t* t, int item){
	
	// NULL Check first!
	if(t==NULL){
		return NULL;
	}
	printf("item added: %d now\n", item);
	
	// 1. allocate/create new node to bst
	bstnode_t* new_bstnode = insert(t->root, item);
	
	// if insertion fails
	if(new_bstnode == NULL){
		return 1;

	}for(int i=0; i <  
	// set new_bstnode as root of BSTtree
	t->root = new_bstnode;
	// incrememnt count
	t->count++;
	return 0;
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree -- print "(NULL)".
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
    if(NULL == t){
        printf("(NULL)");
    }else{

    }
}

// Returns the sum of all the nodes in the bst. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(bst_t *t){
  return 0;
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exits the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){

	// NULL Check!
	if (t == NULL){
		exit(0);
	}else{
		return 1;
	}
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
    return 0;
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){
	// Frees the complete BST from memory.
	if(!root){
		return;
	}
	bst_free(root->leftChild);
	bst_free(root->rightChild);
	free(root);
}
*/
