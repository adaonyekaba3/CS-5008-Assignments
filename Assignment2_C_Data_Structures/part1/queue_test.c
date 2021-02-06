// Compile this assignment with:
// gcc queue_test.c -o queue_test
//
// Run with: ./queue_test
//
// This is a way to test your code.
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "myqueue.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// To print the queue elements. 
// should print from front of the queue.
void printElements(queue_t* q){
		
	if (queue_empty(q)){
		printf("The Queue is empty!\n");
	}
	else if (q->back > q->front){
		for (int i = q->front; i < q->back; i++){
			printf("%d\n", q->data[i]);
		}
	}
	else{
		for (int i = q->front; i < q->capacity; i++){
			printf("%d\n", q->data[i]);
		}
	}

}	

// To Print Seperator Line. 
void printSeparator(){
	printf("==============================================================================================\n");	
}

// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
int unitTest2(){
    	printf("========queue unitTest2========\n");
    	queue_t* test2 = create_queue(10);
    	queue_enqueue(test2,1);
    	queue_enqueue(test2,2);
    	queue_enqueue(test2,3);
    	queue_enqueue(test2,4);
    	queue_enqueue(test2,5);
    	queue_enqueue(test2,6);
    	queue_enqueue(test2,7);
    	queue_enqueue(test2,8);
    	queue_enqueue(test2,9);
    	queue_enqueue(test2,10);

    	free_queue(test2);

    	return 1;
}

int unitTest3(){
    	printf("========queue unitTest3========\n");
    	queue_t* test3 = create_queue(32);
    	int i =0;
 	for(i=0; i < 32; i++){
        	queue_enqueue(test3,1);
    	}
    	for(i=0; i < 32; i++){
        	queue_dequeue(test3);
    	}

    	free_queue(test3);

    	return 1;
}

int unitTest4(){
	printf("========queue unitTest4========\n");
	queue_t* test4 = create_queue(32);
	int i =0;
	for(i=0; i < 32; i++){
		queue_enqueue(test4,1);
    	}	
	for(i=0; i < 32; i++){
		queue_dequeue(test4);
    	}	
	for(i=0; i < 32; i++){
        	queue_enqueue(test4,1);
    	}	
    	for(i=0; i < 32; i++){
        	queue_dequeue(test4);
    	}
    	free_queue(test4);

    	return 1;
}

void unitTest1(){
	printSeparator();
	
	queue_t* test1 = create_queue(1);
	printf("Attempting to add %d\n", 1);
	queue_enqueue(test1, 1);
	printf("Removing: %d\n", queue_dequeue(test1));

	free_queue(test1);
	printSeparator();
	//return 1;
}

// Unit Test for Overflow 
void unitTest_Overflow(){
	
	printSeparator();

	printf("Creating a queue with capacity equivalent to 3...\n");
	queue_t* sampleQueue = create_queue(3);

	printf("Size of the queue is: %d\n", queue_size(sampleQueue));
	printf("Add to queue has been initiated. Confirm attempt Success: %d\n", queue_enqueue(sampleQueue, 1));
	printf("Add to queue has been initiated. Confirm attempt Success: %d\n", queue_enqueue(sampleQueue, 2));
	printf("Add to queue has been initiated. Confirm attempt Success: %d\n", queue_enqueue(sampleQueue, 3));
	printf("Add to queue has been initiated. Confirm attempt Success: %d\n", queue_enqueue(sampleQueue, 4));
	printf("Size of the queue is: %d\n", queue_size(sampleQueue));

	printf("Print Elements... \n");
	printElements(sampleQueue);
	
	free_queue(sampleQueue);
	printSeparator();
	
}


// TODO: Add more tests here.

// Unit test Underflow
void unitTest_Underflow(){
	
	printSeparator();
	printf("Creating queue of capacity: 1...\n");
	
	queue_t* sampleQueue = create_queue(1);
	printf("Size of queue is: %d\n", queue_size(sampleQueue));
	printf("Preparing to delete... \n");
	queue_dequeue(sampleQueue);

	free_queue(sampleQueue);
	printSeparator();
}

// Unit test to check conditions when queue is FULL. 
void unitTest_queueFull(){
	
	printSeparator();
	printf("Creating queue of capacity: 1...\n");

	queue_t* sampleQueue = create_queue(1);
	printf("Is the Queue full: %d\n", queue_full(sampleQueue));
	printf("Add to que has been initiated. Confirm attempt Success: %d\n", queue_enqueue(sampleQueue, 1));
	printf("Is Queue full: %d\n", queue_full(sampleQueue));
	
	free_queue(sampleQueue);
	printSeparator();
}

// Unit test to check conditions when queue is EMPTY. 
void unitTest_queueEmpty(){
	
	printSeparator();
	printf("Creating queue of capacity: 1...\n");

	queue_t* sampleQueue = create_queue(1);
	printf("Is the Queue empty: %d\n", queue_empty(sampleQueue));
	printf("Add to que has been initiated. Confirm attempt Success: %d\n", queue_enqueue(sampleQueue, 1)); 
	printf("Is the Queue empty: %d\n", queue_empty(sampleQueue));
	printf("Removing: %d\n", queue_dequeue(sampleQueue));
	printf("Is the Queue empty: %d\n", queue_empty(sampleQueue));
	
	free_queue(sampleQueue);
	printSeparator();
}

// Unit Test to check conditions for insertion and deletion. 
void unitTest_insertionAndDeletion(){
	
	printSeparator();
	printf("Creating a queue of capacity: 3...\n");
	
	queue_t* sampleQueue = create_queue(3);

	printf("Printing Elements... \n");
	printElements(sampleQueue);
	
	printf("Initiatingr set of added Elements... \n");
	queue_enqueue(sampleQueue, 8);
	queue_enqueue(sampleQueue, 88);
	queue_enqueue(sampleQueue, 888);

	printf("Printing Elements... \n");
        printElements(sampleQueue);

	printf("Removing Elements... \n");
	printf("Removing: %d\n", queue_dequeue(sampleQueue));
	printf("Removing: %d\n", queue_dequeue(sampleQueue));
	
	printf("Printing Elements... \n");
	printElements(sampleQueue);

	printf("Initiating another set of added Elements again... \n");
	queue_enqueue(sampleQueue, 97);
	queue_enqueue(sampleQueue, 977);
	queue_enqueue(sampleQueue, 1477);

	printElements(sampleQueue);
	
	printf("The front is: %d\n", sampleQueue->front);
	printf("The back is: %d\n", sampleQueue->back);

	printf("Removing: %d\n", queue_dequeue(sampleQueue));
	printf("The front is: %d\n", sampleQueue->front);
	printf("The back is: %d\n", sampleQueue->back);	
	
	printf("Initiating another set of added Elements again...\n");
	queue_enqueue(sampleQueue, 1595);
	printf("Printing Output Elements...\n");
	printElements(sampleQueue);
	printf("The front is: %d\n", sampleQueue->front);
	printf("The back is: %d\n", sampleQueue->back);

	printSeparator();	
}

void unitTest_sizeCheckNull(){

	queue_size(NULL);
}


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
	unsigned int testsPassed = 0;
	int counter =0;
	int i;
    // List of Unit Tests to test your data structure
   
	unitTest1();
	unitTest_Overflow();
	unitTest_queueFull();
	unitTest_queueEmpty();
	unitTest_insertionAndDeletion();
	unitTest_sizeCheckNull();
	
	printf("...Reached end of program\n");
	
	return 0;
}
