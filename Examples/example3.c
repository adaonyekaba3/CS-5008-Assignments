#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(){
	int array[3] = {1, 2, 3};
	double array2[3] = {1.5, 2.3, 4.5};
	char array3[6] = {'h', 'e', 'l', 'l', 'o'};
	char array4[] = "Hello world!";
	
	/* char array3[6] = {'h','e','l','l','o', '\0'};*/
	printf("%s %s\n", array3, array4);

	/*array[0] = 12;
	array[1] = 24;
	array[2] = 36; 
	*/

	for ( int i = 0; i < 3; i++ ){
		array[i]= i*100;
	}	

	for ( int i = 0; i < 3; i++ ){
		printf("%d\n", array[i]);
	}
	return 0;
}
