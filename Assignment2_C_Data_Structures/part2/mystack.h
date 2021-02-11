// =================== Support Code =================
// Stack
//
//
//
// - Implement each of the functions to create a working stack.
// - Do not change any of the function declarations
//   - (i.e. stack_t* create_stack() should not have additional arguments)
// - You should not have any 'printf' statements in your stack functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdio.h> // FOR IO operations
#include <stdlib.h> // for malloc/free 

// Stores the maximum 'depth' of our stack.
// Our implementation enforces a maximum depth of our stack.
// (i.e. capacity cannot exceed MAX_DEPTH for any stack)
# define MAX_DEPTH 32

// Create a node data structure to store data within
// our stack. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* next;
}node_t;

// Create a stack data structure
// Our stack holds a single pointer to a node, which
// is a linked list of nodes.
typedef struct stack{
	int count;		// count keeps track of how many items
				// are in the stack.
	unsigned int capacity;	// Stores the maximum size of our stack
	struct node_t* head;		// head points to a node on the top of our stack.
}stack_t;

// Creates a stack
// Returns a pointer to a newly created stack.
// The stack should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The stacks fields should also be initialized to default values.
// Create a new node with value-data and next-Null.
stack_t* create_stack(unsigned int capacity){	
	stack_t* myStack = (stack_t*)malloc(sizeof(stack_t));
	myStack ->capacity = MAX_DEPTH;
	myStack->count = 0;
	myStack->head = NULL;
	return myStack;
}

// Stack empty
// Check if the stack is empty
// Returns 1 if true (The stack is completely empty)
// Returns 0 if false (the stack has at least one element enqueued)
int stack_empty(stack_t* s){ 

	if (s->count == s->capacity){
		return 1; 
	}
	else{
		return 0;
	}
}

// Stack Full
// Check if the stack is full
// Returns 1 if true (The Stack is completely full, i.e. equal to capacity)
// Returns 0 if false (the Stack has more space available to enqueue items)
int stack_full(stack_t* s){
	
	if (s->count == s->capacity){
		return 1;
	}
	else{
		return 0;
	}
}

// Create new node with value as data and next as NULL.
node_t* create_node(int data){
node_t* new_node = (node_t*)malloc(sizeof(node_t));
new_node->data = data;
new_node->next = NULL;	
}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the Stack is full that is an error, but does not crash the program).
int stack_enqueue(stack_t* s, int new_item){

	if (stack_full(s)){
		return -1;
	}
		node_t* new_node = create_node(new_item);
		return 0;
	
}

/*
// Dequeue an item
// Returns the item at the front of the stack and
// removes an item from the stack.
// Removing from an empty stack should crash the program, call exit(1).
int stack_dequeue(stack_t* s){
	if (stack_empty(s)){
		exit(1); // Note: This line should crash the program if stack empty.
	}
	else{
		int val = s->head->data;
		s->head = s-> head->next;
		s->count = s->count-1;
		return val;
	}
}

// Stack Size
// Queries the current size of a stack
// A stack that has not been previously created will crash the program.
// (i.e. A NULL stack cannot return the size)
//unsigned int stack_size(stack_t* s){
	
//	if (s == NULL){
//		exit(1);
//	}
//	else{
//		return s->count;
//	}
//}

// Free stack
// Removes a stack and ALL of its elements from memory.
// This should be called before the proram terminates.
//void free_stack(stack_t* s){
//
//	while (s->capacity != 1){
//	}	
//	stack_dequeue(s);
//}

/*
// To output stack capacity.
void print_stack(stack_t* s){
	
	//if s->count =0, then stack is empty.
	if (s->count == 0){
		printf("Stack is empty!\n");
	}
	return;
}*/

// main function here
int main(){
	struct node* head = NULL;
	int size, element;
	int counter = 0;
	int myNode;	
	
}

#endif
