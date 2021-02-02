#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


int main(){
	int randomNumber = 0;  // System number is stored here.
	int num = 0;
	int i = 0;

	printf("Welcome to Number Guessing Game !!!\n");
	printf("\n\n");

	srand(time(NULL));
	randomNumber = (rand() % 10) + 1;
	
	printf("CPU says - Pick a number between 1-10:\n");
	scanf("%d", &num);
	printf("%d\n", num);  
		
	do 
	{

	}while (randomNumber < num | randomNumber > num);
	
		if (randomNumber < num)
		{
			printf("No guess higher! Make a guess:\n");
			scanf("%d", &num);
			printf("%d\n", num);
		}
		else if{
			printf("No guess lower! Make a guess:\n");
			scanf("%d", &num);
			printf("%d\n", num);
		}	

	else (randomNumber == num)
	{
		printf("You got it! You won! The right number is: \n");
		scanf("%d", &randomNumber);
		printf("%d\n", randomNumber);	
	}
	return 0;
}
