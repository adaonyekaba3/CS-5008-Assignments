// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H
# include <stdio.h>
# include <stdlib.h>

// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node{
	int data;
	struct node* next;
  	struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
	int count;		// count keeps track of how many items are in the DLL.
	node_t* head;		// head points to the first node in our DLL.
    node_t * tail;          //tail points to the last node in our DLL.
}dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t* create_dll(){
	// Modify the body of this function as needed.

	dll_t* myDLL = (dll_t*)malloc(sizeof(dll_t));	
	myDLL->head = NULL; // node dll initializes nodeDLL->head->tail->NULL
	myDLL->tail = NULL;
	myDLL->count = 0;
	
	return myDLL;

}

// Print dll function
void print_dll(dll_t* l){
		node_t* iterator = l->head;
	
	//printf("================\nCount: %d\n", l->count);
	
	iterator = l->head; 
	/*if (iterator){
		printf("Head: %d\n", iterator->data);
	}*/
	while(iterator != NULL){
		printf("%d ", iterator->data);
		iterator = iterator->next;
	}
	printf("\n\n");
	
	return;
}

// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
// Returns -1 if the dll is NULL.
int dll_empty(dll_t* l){

	
	// list is empty
	if(l->count == 0){
		return 1;
	}
	else{
		return 0;
	}
	return -1;


	if (l->count == 0){ // checks that dll is empty
		return 1; 		// states TRUE
	}
	else if (l->count >= 1) // checks if 1 dll is created
	{
		/* code */
		return 0; 			// states FALSE if successful.
	}
	else{
		return -1; 			// returns this cuz dll is empty.
	}

}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, int item){

	
	if (l == NULL ){
		return -1;
	}
	// initialize print new item at 
	// front of list 
	//printf("\npushing %d at front\n", item);
	
	// 1. allocate / create  new node at the front of dll
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	
	if (newNode == NULL){
		return 0;
	}
	// put in the data.
	newNode->data = item;
	// make next of new Node as head and previous NULL.
	newNode->next = l->head;
	newNode->previous = NULL;
	
	// change previous of head node to new node.
	//if (l != NULL){
	//l->head->previous = newNode;
	l->head = newNode;
	
	// if pushfront returns on failure. 	
	l->count++;
	return 1;

	// initializing inserting new node
	//printf("\npushing %d in back\n", item);

	// 1. create a new node
	if ( newNode == NULL ){
		newNode->data = item;
		newNode->next = NULL;
		newNode->previous = NULL;
		return -1;
	}
	else if (l->count == 0 )
	{
		// 2. MOVE the old head to the prev node
		// to point to this node.
		l->head = newNode; // 0(1)
		return 1;		   // newNode created successfully.
	}
	else{
		/* code */
		newNode->next = l->head;
		l->head->previous = newNode;
		l->head = newNode;
	}	
		l->count++;
		return 0;

}

// push a new item to the end of the DLL (after the last node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, int item){
	
	// print item to insert at back of dll
	//printf("\npushing %d at back\n", item);
	
	// 1. create a new node at end of dll
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	
	// 2. if newNode is empty(NULL)
	// return -1 
	if ( newNode == NULL){
		newNode->data = item;
		newNode->next = NULL;
		newNode->previous = NULL;
		return -1;
	}
	if (dll_empty(l)){
		l->head = l->tail = newNode;
	}
	// 3. returns 0 if new node fails 
	// to be created.
	if (l->count == 0){
		l->tail = newNode;
		newNode->next = l->head;
		l->head = newNode;
	}
	else{
		//newNode = l->tail;
		//l->next = newNode;
		l->tail = newNode;
	}	
	l->count++;
	//printf("\nnew item has been pushed into back dll!\n");
	return 0; 
}

// Returns the first item in the DLL and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL. 
// Assume no negative numbers in the list or the number zero.
int dll_pop_front(dll_t* t){
	
	// NULL Check 
	if ( t == NULL){
		return -1;
	}
	// initialize new item.
	int popItem = t->head->data;
	
	// print node removed from front dll. 
	// 1. return the first item to dll
	// remove it from the list 
	if ( t->count == 0 ){
		return 0;
	}
	else if (t->count == 1){
		free(t->head);
		t->head = NULL;
		t->tail = NULL;
	}
	else {	
		node_t* temp = t->head;
		temp->next->previous = NULL; 
		t->head = temp->next;
		free(temp);
	
		t->count--;
	}
	//printf("\nitem has been popped from front!\n");
	return popItem;
}

// Returns the last item in the DLL, and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL. 
// Assume no negative numbers in the list or the number zero.
int dll_pop_back(dll_t* t){
	
	if (dll_empty(t)){
		exit(1);
	}
	
	node_t* temp = t->tail;
	t->tail = temp->previous;
	
	if(t->tail == NULL){
		t->head = NULL;
	}
	else{
		t->tail->next = NULL;
		free(temp);
		t->count--;
	}
		return 0;
}

// Inserts a new node before the node at the specified position.
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
// Returns -1 if the list is NULL
int dll_insert(dll_t* l, int pos, int item){
	
	//int cur = 0;
	//node_t* ptr = l->head;

	// print to insert new node at pos. 
//	printf("\ninserting node %d at pos %d ", item, pos);
	
	// NULL CHECK  
	if (l == NULL || pos < 0 || pos >= l->count){
		return -1;
	}
	node_t* cur = l->head;
	for (int i=0; i < pos; i++){
		//cur = cur->next;
		cur++;
	}

	// initialize insert new node conditional statements 
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = item;
        newNode->previous = cur->previous;
        newNode->next = cur;	
	
	if (cur == l->head){ // if dll at head 
		l->head = newNode;
		cur->previous =  newNode;
	}
	l->count++;	
//	printf("\nnew node has been added!\n");
	return 0; // returns 0 on failure to insert new node.
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
//  (does not remove the item)
// Retruns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Returns -1 if the list is NULL
// Assume no negative numbers in the list or the number zero.
int dll_get(dll_t* l, int pos){
	
	// print where position is collected.
	//printf("\nitem inserted %d at pos", pos);
		
	int cur = 0;
	node_t* ptr = l->head;

	// set conditions to return item at pos = 0.
	if ( pos < 0 || pos  >= l->count || l->count == 0 ){
		return -1;
	
		//int cur = 0;
		//node_t* ptr = l->head;
	}
	while ( cur != pos ){
		ptr = ptr->next;
		cur++;
	}
	//printf("\nnew node has been added!\n");
	return ptr->data;	
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Retruns 0 on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Returns -1 if the list is NULL
// Assume no negative numbers in the list or the number zero.
int dll_remove(dll_t* l, int pos){
	
	// check if dll is NULL first!
	if ( l == NULL ){
		return -1;
	}
	// print pos where item is removed. 
	//printf("\nremoving item at pos %d", pos);	
	
	int cur = 0;
	node_t* ptr = l->head;
	
	// initialize to remove item at pos = 0.
	// returns -1 if dll node is empty.
	if (pos < 0 || pos >= l->count || l->count == 0){
		return -1;	
	}
	else if ( pos == 0){
		return dll_pop_front(l);
	}
	if (pos == l->count-1){
		return dll_pop_back(l); // init removing item from dll.
	}
	while ( cur != pos ){
		ptr = ptr->next;
		cur++;
	}
		//ptr->previous->next = ptr->next;
		ptr->next->previous = ptr->previous;
		free(ptr);
		l->count--;
		return 0; // if removing item fails.
 	
	//printf("\nnode has been removed!\n");
}

// DLL Size
// Queries the current size of a DLL
// Returns -1 if the DLL is NULL.
int dll_size(dll_t* t){
	
	// check if DLL IS NULL FIRST!
	if ( t == NULL ){
		return -1;
	}
	// print to free dll
	//printf("\nfreeing the dll\n");
	return t->count;
}

// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){

	// print to free dll
	//printf("\nfreeing the dll now\n");
	node_t* temp;

	// initialize free dll and all
	// elements of it memory. 
	//if ( t->count == 0 ){
	while ( t->head != NULL ){
		temp = t->head->next;
		free(t->head);
		t->head = temp;
	}	

	t->tail = NULL;
	t->count = 0;
//	printf("\nfreeing the dll now!\n");
	free(t);	
	
}

#endif
