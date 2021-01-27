This is a conditions example. 

#include <stdio.h>

void guessNumber(int guess) {
     // TODO: write your code here 
     if (guess < 555) {
	printf("YOur guess is too low.\n");
     } else if (guess > 555) {
	printf("YOur guess is too high.\n");
     } else {
	printf("COrrect. You guessed it!\n");
     }
}

int main() {
    guessNumber(500);
    guessNumber(600);
    guessNumber(555);
}
