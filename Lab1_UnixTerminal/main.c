// Add your program here!
//
#include <stdio.h>

double power(double base, double exponent){

    if(exponent==0){
	return 1; 
    }
    double result = base;
    while(exponent>1){
	result = result * base;
	exponent = exponent-1; 
    }

    return result; 
}

int main (){

    printf("power(2,0) = %f/n",power(2,0));
    printf("power(2,1) = %f/n",power(2,1));
    printf("power(2,2) = %f/n",power(2,2));
    printf("power(2,3) = %f/n",power(2,3));

    printf("power(3,0) = %f/n",power(3,0));
    printf("power(3,1) = %f/n",power(3,1));
    printf("power(3,2) = %f/n",power(3,2));
    printf("power(3,3) = %f/n",power(3,3));


    return 0;
}
