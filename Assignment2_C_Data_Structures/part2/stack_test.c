// Compile this assignment with:
//
// gcc stack_test.c -o stack_test
//
// Run with:
// ./stack_test
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "mystack.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

// Print Elements of the stack.
void printElements(stack_t* s){
	int i;
	if (stack_empty(s)){
		printf("The stack is empty! \n");
	}
	else
	{
		for (int i = 0; i < s-> capacity; i++){
		printf("%d\n");
	}		
}

// Print Separator Line. 
void printSeparator(){
	printf("=========================================================================================");
}



// A sample test of your program
// You can add as many unit tests as you like
// We will be adding our own to test your program.
void unitTest1(){
	
	printSeparator();
	
	stack_t* test1 = create_stack(1);
	printf("Attempting to add %d\n", 1);
	stack_enqueue(test1, 1);
	printf("Removing: %d\n", stack_dequeue(test1));
	
	free_stack(test1);
	printSeparator();
}

// Unit Test for overflow condition. 
void unitTest_overflow(){
	
	printSeparator();
	
	printf("Creating a stack of capacity 32... \n");
	stack_t* sampleStack = create_stack(1);
	
	printf("Size of stack is: %d\n", stack_size(sampleStack));
	printf("Attempting to add. Addition attempt success: %d\n", stack_enqueue(sampleStack, 1));
	printf("Attempting to add. Addition attempt success: %d\n", stack_enqueue(sampleStack, 2));
	printf("Attempting to add. Addition attempt success: %d\n", stack_enqueue(sampleStack, 3));
	printf("Attempting to add. Addition attempt success: %d\n", stack_enqueue(sampleStack, 4));
	printf("Size of the stack is: %d\n", stack_size(sampleStack));

	printf("Printing Elements... \n");
	printElements(sampleStack);
	
	free_stack(sampleStack);
	printSeparator();
}

// Unit Test for checking conditions when Stack is Full.

*int unitTest1(int status){
    printf("=======Stack unitTest1=======\n");
    stack_t* test1 = create_stack(MAX_DEPTH);
    stack_enqueue(test1,1);
    stack_dequeue(test1);

    free_stack(test1);

    return 1;
}

/*
int unitTest2(int status){
    printf("=======Stack unitTest2=======\n");
    stack_t* test1 = create_stack(MAX_DEPTH);
    stack_enqueue(test1,1);
    stack_enqueue(test1,2);
    stack_enqueue(test1,3);
    stack_enqueue(test1,4);
    stack_enqueue(test1,5);
    stack_enqueue(test1,6);
    stack_enqueue(test1,7);
    stack_enqueue(test1,8);
    stack_enqueue(test1,9);
    stack_enqueue(test1,10);

    free_stack(test1);

    return 1;
}

int unitTest3(int status){
    printf("========stack unitTest3========\n");
    stack_t* test3 = create_stack(32);
    int i =0;
    for(i=0; i < 32; i++){
        stack_enqueue(test3,1);
    }
    for(i=0; i < 32; i++){
        stack_dequeue(test3);
B
    }

    free_stack(test3);

    return 1;
}

int unitTest4(int status){
    printf("========stack unitTest4========\n");
    stack_t* test4 = create_stack(32);
    int i =0;
    for(i=0; i < 32; i++){
       stack_enqueue(test4,1);
    }
    for(i=0; i < 32; i++){
        stack_dequeue(test4);
    }
    for(i=0; i < 32; i++){
        stack_enqueue(test4,1);
    }
    for(i=0; i < 32; i++){
        stack_dequeue(test4);
    }
    free_stack(test4);

    return 1;
}

int unitTest5(int status){
    printf("=======Stack unitTest5=======\n");

    stack_t* test5 = create_stack(32);
    free_stack(test5);

    return 1;
}



// 

// TODO: Add tests here
int (*unitTests[])(int)={
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    NULL
}; */

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){

	unsigned int testsPassed = 0;
    	// List of Unit Tests to test your data structure
	/*unitTest();
	unitTest_overflow();
	unitTest_underflow();
	unitTest_stackFull();
	unitTest_stackEmpty();
	unitTest_stackInsertionAndDeletion();
	unitTest_sizeCheckOnNull();

	print("Reached end of program. \n");

    	*/
	return 0;
}


