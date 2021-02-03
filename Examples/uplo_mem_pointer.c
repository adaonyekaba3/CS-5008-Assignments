#include <stdio.h>

void update(int arguement){
	arguement = 10;
}

int main(){
	int value = 5;
	int* p_value = &value;
	
	//prints address of value and value pointer stored.
	//and value of pointer.
	printf("Value is: %d\n", value);
	printf("The address of value is: %pd\n", p_value);
	printf("The value at p_value is: %d\n", *p_value);
	
	//update value of pointer.
	*p_value = 15; //used to be a 5, but now it is 15.
	
	// dereferenced pointer to print assigned new value.
	printf("The updated value at p_value is: %d\n", *p_value);
	//prints new stored value of variable address. 
	printf("Value updated is: %d\n", value); 
	return 0;
}
