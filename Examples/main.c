#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


int main()
{
	int randomNumber = 0;  // System number is stored here.
	int guess[5] = {1}; //keeps track of number of guesses. 
 	

	//think of this like 5 containers for guesses stored here.	

	printf("Welcome to Number Guessing Game !!!\n");
	printf("\n\n");

	for (int total_games = 0; total_games < 5; total_games++)
	{
		// this will generate a new number each game 
		srand(time(NULL));
		randomNumber = (rand() % 10) + 1; 
	
		// get user input 
		printf("CPU says - Pick a number between 1-10:\n");
		int num = 0; 
	do
	{
		scanf("%d", &num);
		printf("You guessed the number: %d \n", num);
		
		if (randomNumber < num)
		{
			printf("No guess lower! Make guess:\n");              
				guess[total_games]++;

		}                                                            
                else if (randomNumber > num)
		{                                                          
                        printf("No guess higher! Make a guess:\n");
		             	guess[total_games]++;
		}
	}
	while (num != randomNumber);

		printf("You got it! You won! \n");
		printf("%d\n", randomNumber);

	}
	for (int games = 0; games < 5; games++)
	{
		printf("In game %d, it took you %d times\n", games, guess[games]); 		
	}
	return 0;
}
