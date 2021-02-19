# include <stdio.h> // access std library 

// This file compares Singly Linked List 
// to Doubly Linked List Data Structure. 

// Create  Singly Linked List Node 
// use typedef struct to initialze 
// that struct singly LL.
typedef struct ll_node{
	int data; // tells us that data is in stack
	struct node* next; // tells us movement forward in LL

}ll_node_t;

// Create Doubly Linked List Node 
// use typedef struct to initialize DLL.
typedef struct dll_node{
	int data; // tells us some data in stack.
	struct node* next; // traverses forward - tells us new created dll_node*  
	struct node* prev; // traverses in reverse - can move back.
}dll_node_t;


int main(){
	// initialize node to get size of actual ll_node & dll_node
	// %lu\n data type - look this up! 
	// sizeof() - returns the amount of bytes we have. 
	printf("ll_node_t: %lu\n", sizeof(ll_node_t));
	printf("dll_node_t: %lu\n", sizeof(dll_node_t));
	return 0; // returns less btyes for ll than dll. (16,24)
// little more space and time is required for doubly and singly linked list. 
}
