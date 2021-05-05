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

#include <stdlib.h>
// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node{
    void* data;
    struct node* next;
    struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
    int count;        // count keeps track of how many items are in the DLL.
    node_t* head;        // head points to the first node in our DLL.
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
    dll_t* myDLL= malloc(sizeof(dll_t));
    myDLL->count =0;
    myDLL->head = NULL;
    myDLL->tail = NULL;
    return myDLL;
}

// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
// Returns -1 if the dll is NULL.
int dll_empty(dll_t* l)
{
        if(l == NULL){
                return -1;
        }if(l->count == 0)
        {
                return 1;
        }if(l->count >= 1){
                return 0;
        }
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, void* item)
{
       if(l == NULL){
               return -1;
       }
       node_t* newNode = (node_t*)malloc(sizeof(node_t));

       if(newNode == 0){
               free(newNode);
               return 0;
       }
       // push a new item to the head
       node_t* new_temp_node = l->head;
       l->head = newNode;
       newNode->data = item;
       newNode->next = new_temp_node;
       newNode->previous = NULL;

       if(l->count != 0){
               new_temp_node->previous = newNode;
       }
       if(l->count == 0){
               l->tail = l->head;
       }
       l->count++;
       return 1;
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, void* item)
{
        if(l==NULL){
                return -1;
        }
        node_t* newNode = (node_t*)malloc(sizeof(node_t));

        if(newNode == 0){
                free(newNode);
                return 0;
        }
        // push setup for new item to the tail
        node_t* new_temp_node = l->tail;
        l->tail = newNode;
        newNode->data = item;
        newNode->next = NULL;
        newNode->previous = new_temp_node;

        if(l->count != 0){
                new_temp_node->next = newNode;
        }
        if(l->count == 0){
                l->head = l->tail;
        }
        l->count++;
        return 1;
}

// Returns the first item in the DLL and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL.
// Assume no negative numbers in the list or the number zero.
void* dll_pop_front(dll_t* t)
{
        if(t == NULL){
                return NULL;
        }
        if(dll_empty(t)){
                free(t);
                return 0;
        }
        char* del_front = t->head->data;
        node_t* tempNode = t->head;

        if(t->count == 0){
                t->head = NULL;
                t->tail = NULL;
        }else{
                t->head = tempNode->next;
                t->head->previous = NULL;
        }
        free(tempNode);

        t->count--;
        return del_front; // Note: This line is a 'filler' so the code compiles.
}

// Returns the last item in the DLL, and also removes it from the list.
// Returns 0 on failure, i.e. there is noting to pop from the list.
// Returns a -1 if the DLL is NULL.
// Assume no negative numbers in the list or the number zero.
void* dll_pop_back(dll_t* t)
{
        if(t == NULL){
               return NULL;
        }
        if(dll_empty(t)){
                free(t);
                return 0;
        }
        node_t* tempNode = t->tail->data;

        char* i = t->tail->data; // create new item

        if(t->count == 1){
                t->head = NULL;
                t->tail = NULL;
        }
        else{
                t->tail = tempNode->previous;
                t->tail->next = NULL;
        }
        free(tempNode);
        t->count--;
        return i; // Note: This line is a 'filler' so the code compiles.
}

// Inserts a new node before the node at the specified position.
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
// Returns -1 if the list is NULL
int dll_insert(dll_t* l, int pos, void* item)
{
        if(l == NULL){
                return -1;
        }
        node_t* newNode = malloc(sizeof(node_t));

        if(newNode == NULL || l->count <= 0 || pos < 0 || pos >= l->count){
                free(newNode);
                return 0;
        }

        node_t* new_pos_node = l->head;
        int i = 0;
        for(i = 0; i < pos; i++){
                new_pos_node = new_pos_node->next;
        }
        newNode->data = item;
        newNode->next = new_pos_node;

        if(pos == 0){
                new_pos_node->previous = NULL;
                l->head = newNode;
        }
        else{
                newNode->previous = new_pos_node->previous;
                new_pos_node->previous->next = newNode;
        }
        new_pos_node->previous = newNode;
        l->count++;
        return 1; // Note: This line is a 'filler' so the code compiles.
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
//  (does not remove the item)
// Retruns 0 on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Returns -1 if the list is NULL
// Assume no negative numbers in the list or the number zero.
void* dll_get(dll_t* l, int pos)
{
        if(l == NULL){
                return NULL;
        }
        if(dll_empty(l) || pos < 0 || pos >= l->count){
                free(l);
                return 0;
        }
        else{
                node_t* pos_node = l->head; // new temp node
                int i; // initialized and declare an index node
                for(i=0; i < pos; i++){
                        pos_node = pos_node->next;
                }
                return pos_node->data;
        }
        // Note: This line is a 'filler' so the code compiles.
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Retruns NULL on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Returns NULL if the list is NULL
// Assume no negative numbers in the list or the number zero.
void* dll_remove(dll_t* l, int pos)
{
        if(l == NULL){
                return NULL;
        }
        int cur = 0;
        node_t* ptr = l->head;

        if(pos < 0 || pos >= l->count || l->count == 0){
                return 0;
        }
        else if(pos == 0){
                return dll_pop_front;
        }
        if(pos == l->count-1){
                return dll_pop_back;
        }
        while(cur != pos){
                ptr = ptr->next;
                cur++;
        }
                ptr->next->previous = ptr->previous;
                free(ptr);
                l->count--;
                return 0;
        // Note: This line is a 'filler' so the code compiles.
}

// DLL Size
// Queries the current size of a DLL
// Returns -1 if the DLL is NULL.
int dll_size(dll_t* t)
{
        if(t == NULL){
                return -1;
        }else{
                return t->count;
        }
        // Note: This line is a 'filler' so the code compiles.
}

// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t)
{
        node_t* temp_node;
        while(t->head != NULL){
                temp_node = t->head->next;
                free(t->head);
                t->head = temp_node; 
        }
        t->tail = NULL;
        t->count = 0;
        free(t); 
}

//Helper method

int DLL_find(dll_t *l, void *data)
{

        if (l == NULL)
        {
                return -1;
        }

        node_t *iterator = l->head;
        while (iterator != NULL)
        {
                if (iterator->data = data)
                {
                        return 1;
                }
                iterator = iterator->next;
        }
        return 0;
}

//Helper method
int dll_remove_value(dll_t *l, void *item)
{

        if (l == NULL)
        {
                return -1;
        }
        node_t *iterator = l->head;

        while (iterator != NULL)
        {
                if (iterator->data == item)
                {
                        iterator->previous->next = iterator->next;
                        iterator->next->previous = iterator->previous;
                        free(iterator);
                        l->count -= 1;
                        return 1;
                }
                iterator = iterator->next;
        }
        return 0;
}

//Helper method
int find_helper_dll(dll_t *l, void *item)
{

        if (l == NULL)
        {
                return -1;
        }

        node_t *iterator = l->head;
        while (iterator != NULL)
        {
                if (iterator->data == item)
                {
                        return 1;
                }
                iterator = iterator->next;
        }
        return 0;
}

//Remove Helper
int dll_remove_helper(dll_t *l, void *value)
{

        if (l == NULL)
        {
                return -1;
        }

        node_t *iterator = l->head;
        int i = 0;
        for (i = 0; i < l->count; i++)
        {
                if (iterator->data == value)
                {
                        if (i == 0)
                        {
                                dll_pop_front(l);
                        }
                        else if (i == l->count - 1)
                        {
                                dll_pop_back(l);
                        }
                        else
                        {
                                iterator->previous->next = iterator->next;
                                iterator->next->previous = iterator->previous;
                                free(iterator);
                                l->count--;
                                return 1;
                        }
                        iterator = iterator->next;
                }
                return 0;
        }
}
#endif
