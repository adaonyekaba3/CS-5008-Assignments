# Exercises

In order to start thinking a bit algorithmically, modify this file and answer the following questions. Be sure to add/commit/push any changes made to this file to our repository.

1. In the worst case in our guessing game--how many guesses could it take to get the right number if we had no hint at all? Explain.
2. In the worst case in our guessing game--how many guesses does it take to get the right number if we get a hint of 'higher or lower' when guessing numbers 1-10? *Hint* In your answer show this mathematically with the [log function](https://www.mathsisfun.com/algebra/logarithms.html).

## Answers

1. It would take approximately 50 guesses to find the right number without a hint. Since we are given 10 digits in an array and also given 5 turns to guess the chances of selecting the right number decreases to 2 out of 5 possible chances for a correct answer. 

2. considering applying a binary search to find the number of guesses, we would use log2(array_size). assume an sorted array of size 10; the best way to calculate is to compare the number of times 2 needs to be multiplied to get 10. You can conceptualize by comparing turns in the guessing game below:

Turn 1: 10/2 = 5 | Turn 2: 5/2 = 2.5 | Turn 3: 2.5/2 = 1.25 | 
Turn 4: 1.25/2 = .0625 | Turn 5: .0625/2 = .31..

By the tume you finish 5 turns and you do not select the right number, you would pass up to 50 or so turns. Good luck! 

