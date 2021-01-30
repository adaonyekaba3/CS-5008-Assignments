// Add your program here!

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


int main(){
	int randomNumber = 0;
	int guess = 0;
	int i = 0;
	int count = 0; 

	for (int i = 0; i < guess; i++){
		count++;
			
	srand(time(NULL));
	randomNumber = rand() % 10 + 1;

	printf("CPU says: For 5 turns, pick a number 1-10:\n");
	printf("Come on! Guess any number: %d\n", randomNumber);
}		

		if (guess > randomNumber)
			printf("No guess lower!\n");
		
		else if (guess < randomNumber)
			printf("No guess higher!\n");
	
		else{
			printf("Yes you got it! You win!\n"); 
		
	}while (guess != randomNumber);
	
	return 0;
}
