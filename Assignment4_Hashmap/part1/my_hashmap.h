// =================== Support Code =================
// Hashmap 
//
// - Implement each of the functions to create a working hashmap.
// - Do not change any of the function declarations
//   - (i.e. hashmap_t* hashmap_create() should not have additional arguments)
// - You should not have any 'printf' statements in your functions other 
//   than functions that explicitly ask for printf  output. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// - You may add any helper functions that you think you need (if any, or otherwise for debugging)
// ==================================================
#ifndef MY_HASHMAP_T
#define MY_HASHMAP_T

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// A key value pair
// This is specifically for a (char*, char*) key value pair
typedef struct pair{
    char* key;
    char* value;
}pair_t;

// Each node holds a key and a value
typedef struct node{
    struct node* next;
    pair_t* kv;          // 'kv' stands for key/value pair
}node_t;


// Simple hash function that will put a key into a bucket
// You should not modify this
int stringHash(char* myKey, int numberOfBuckets){
    return strlen(myKey) % numberOfBuckets;
}
//
// Create a function prototype to a function that takes
// in a char* and an int.
typedef int(*hashFunctionPointer)(char*,int); 

// Chained implementation of a hashmap
typedef struct hashmap{
    unsigned int buckets;   // i.e. size of the hashmap
    node_t** arrayOfLists;  // An array of linked lists for our buckets
                            // Read another way
                            //      - an array of node_t*

    // A function pointer to a hash function
    // The hash_function must take in a 'char*' as a key, and have a
    // second parameter specifying the number of buckets.
    hashFunctionPointer hashFunction;
}hashmap_t;


// Creates a new hashmap
// Allocates memory for a new hashmap.
// Initializes the capacity(i.e. number of buckets)
hashmap_t* hashmap_create(unsigned int _buckets){
    // Allocate memory for our hashmap
    hashmap_t* myMap = (hashmap_t*)malloc(sizeof(hashmap_t));	
    // Set the number of buckets
    myMap->buckets = _buckets;
    // Initialize our array of lists for each bucket
    myMap->arrayOfLists = (node_t**)malloc(sizeof(node_t*)*_buckets);
    // Setup our hashFunction to point to our
    // stringHash function.
    // Iterate through all of our buckets and set to NULL.
    for (int i=0; i < _buckets; i++){
	myMap->arrayOfLists[i] = NULL; // ask CAT if this line is needed. 
    }
    myMap->hashFunction = stringHash;	
    // Return the new map that we have created
    return myMap;
}

// Frees a hashmap
// Responsibility to free a hashmap that has been previously allocated.
// Must also free all of the chains in the hashmap
// This function should run in O(n) time
void hashmap_delete(hashmap_t* _hashmap){
  	
	// initialize free hashmap and all elements of its memory.
	if (_hashmap != NULL){ 
		return;
	}
	// Free all memory used by the buckets.
	// free the hashmap struct
	free(_hashmap);

}

// Returns a boolean value if a key has been put into
// the hashmap
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Returns a '-9999' if the hashmap is NULL
// The algorithm is:
//  - Call the _hashmap's hash function on the key
//  - Search that bucket to see if the key exists.
// This function should run in average-case constant time
int hashmap_hasKey(hashmap_t* _hashmap, char* key){

	// check if hashmap is empty 
	if (_hashmap == NULL){
		return -9999;
	}
	// if a key exists return 1
	unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

	node_t* iterator = _hashmap->arrayOfLists[bucket];

	while( iterator != NULL){
		// using str comparison strcmp 
		// det if key is same/exists 
		// compare keys identifier
		if (strcmp(iterator->kv->key, key) == 0){ // 0 means found if both sides same
			return 1; // if not return 0.
		}
		 
	// if key does not exist return 0
		iterator = iterator->next; // keys no match, so keep looking!  
 	}
	return 0;// do not enter while loop on. 	
}
	
// Insert a new key/value pair into a hashmap
// The algorithm is:
//  - If a key already exists, do not add it--return
//  - Call the _hashmap's hash function on the key
//  - Store the key/value pair at the end of the buckets chain
//      - You should malloc the key/value in this function
// This function should run in average-case constant time
void hashmap_insert(hashmap_t* _hashmap,char* key,char* value){
	
	// void returns nothing
	if (hashmap_hasKey(_hashmap, key)){
		return; // if hashkey returned 1, 116 T
   	}
	// create new pair
	// malloc space - check if malloc returns NULL 
	pair_t *new_pair = (pair_t*)malloc(sizeof(pair_t));
	
	// pair_t consists of a key & value, so we also need
	// to allocate memory that we are allocating for is based on
	// the string length of the 'key' and 'value' that were passed in
	// from the function
	new_pair->key = (char*)malloc(strlen(key) * sizeof(char)+1); // adding +1 for null terminator
	new_pair->value = (char*)malloc(strlen(value) * sizeof(char)+1); // add +1 for null terminator	
	// check that new_pair node is empty
	if (new_pair == NULL){
		exit(1); // NULL Check
	}
	// copy new string
	strcpy(new_pair->key, key); // my_strcpy - helper function needed
	strcpy(new_pair->value , value);	

	if (new_pair->key == NULL){ // did this fail, if so exit!
		exit(1);	
	}
	// create a new node 
   	node_t* new_node = (node_t*)malloc(sizeof(node_t));
	
	if (new_node == NULL){ // new_node empty - space not malloc!
		exit(1);
	}
	new_node->kv = new_pair;
	new_node->next = NULL;
	
	// LOCATE THE BUCKET 
	unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);
	
	// ADD NEW NODE
	node_t *iterator = _hashmap->arrayOfLists[bucket];
	
	if (iterator == NULL){
		_hashmap->arrayOfLists[bucket] = new_node;
	}
	else{
		while(iterator->next != NULL){
			iterator=iterator->next;
		}
		iterator->next = new_node; // inserts the new node!
	}
	return;
}

// Return a value from a key 
// Returns NULL if the key is not found
// The algorithm is: hashkey
//  - If the key does not exist, then--return NULL if not found.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and return the value
// This function should run in average-case constant time
char* hashmap_getValue(hashmap_t* _hashmap, char* key){
		
	// if key is not found in hashmap, return NULL
	if (hashmap_hasKey(_hashmap, key) == 0){
		return NULL;
	}
	// call the hashmap function on the key
	unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets); 
 	
	node_t* iterator = _hashmap->arrayOfLists[bucket];
	
	// Search the _hashmap's bucket for the key and return the value
	while( iterator != NULL){
		if (strcmp(iterator->kv->key, key) == 0){
			iterator = iterator->next;
			return key;// key is found
			
		}
	}
	return 0;						
}

// Remove a key from a hashmap
// The algorithm is:
//  - Determine if the key exists--return if it does not.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and then remove it
// This function should run in average-case constant time
void hashmap_removeKey(hashmap_t* _hashmap, char* key){
	// Determine if the key exists, return if yes
	if (hashmap_hasKey(_hashmap, key)){
		return;
	}
	// call the hashap function on the key
	unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

	node_t* iterator = _hashmap->arrayOfLists[bucket];
	
	// search the hashmap's bucket for the key, then remove it
	while( iterator != 0 ){
		if (strcmp(iterator->kv->key, key) == 0){
				 	
		// remove from bucket by freeing memory 
		}
		iterator = iterator->next;
	}
	free(key);	
}

// Update a key with a new Value
// The algorithm is:
//  - Returns immediately if the key does not exist
//  - Call the _hashmap's hash function on the key
//  - Updates the value of the key to the new value
// This function should run in average-case constant time
// ASK SONG AT 10AM HOW TO DRAFT THIS!!
void hashmap_update(hashmap_t* _hashmap, char* key, char* newValue){
	
	// Determine if key exists, then return
	if (hashmap_hasKey(_hashmap, key)){
		return;
	}
	// call the hashmap function on the key.
	unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);
		
	node_t* iterator = _hashmap->arrayOfLists[bucket];
	
	// update the value of the key to the new value.
	// seach the hashmap's bucket for the new key
	while ( iterator != 0 ){
		if ( strcmp(iterator->kv->key, key )){
			return;  
		}
		iterator = iterator->next; 
	}
	// ask how to demonstrate update new value successfully 
	//free(key);
}

// Prints all of the keys in a hashmap
// The algorithm is:
//  - Iterate through every bucket and print out the keys
// This function should run in O(n) time
void hashmap_printKeys(hashmap_t* _hashmap){
		
	// iterate through all of our buckets.
	for (int i=0; i < _hashmap->buckets; i++){
		printf("\nBucket# %d\n", i);
		// Iterate through all of the lists 
		// starting at each bucket
		node_t* iterator =  _hashmap->arrayOfLists[i];
		while( iterator != NULL){
			// Remember a node consists of a key/value
			printf("\tKey=%s\n", iterator->kv->key);
			// Move our iterator in that particular bucket 
			// forward one node until we reach the end of our chain.
			iterator =  iterator->next;		
		}
	}
}


#endif
