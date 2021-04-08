// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
int factorial(int n){
	
	int fact = 1;
	
	// iterate over each element in factorial 
	for(int i=1; i <= n; i++){
		fact=fact * i;
	}
	return fact;
}

// TODO: Implement recursive solution here
int factorial_rec(int n){
	
	if(n == 0){
		return 1;
	}
	return n * factorial(n-1);
}

int main(){

  // Both of these should print the same result!
  printf("factorial(10) = %d\n",factorial(10));
  printf("factorial_rec(10) = %d\n",factorial_rec(10));


  return 0;
}
