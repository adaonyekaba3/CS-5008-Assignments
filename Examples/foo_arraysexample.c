#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//This is a foo void; function and arrays example. 

void foo(int arg1){
	printf("From foo: %d\n", arg1);
}

int sum (int a, int b){
	return a + b; 
}

void bar();

int countEven(int array[], int size){
	int counter = 0; 
	for ( int i = 0; i < size; i++){
		if ( array[i] % 2 == 0){
			counter ++;
		}
	}
	return counter;
}

int main(){
	int array[] = {1, 2, 3,4, 5, 6};
	int numEven = countEven( array, 6 );
	printf("Number of Even elements is: %d\n", numEven);

	foo(23);
	bar();
	return 0;
}

void bar(){
	int num1 = 5;
	int num2 = 6;
	int result = sum(num1, num2);
	printf("%d + %d = %d\n", num1, num2, result); 
};
