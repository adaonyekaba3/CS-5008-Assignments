#include <stdio.h> 
 
//This is a structs example - UNION OR CLASSES DATA TYPES

struct student{
	int id;
	int age;
	double creditHours;
};


struct student makeStudent(int id, int age, double creditHours){
	struct student tempStudent;
	tempStudent.id = id;
	tempStudent.age = age;
	tempStudent.creditHours = creditHours;
	return tempStudent;
}

void printStudent(struct student aStudent){
	printf("Student: %d %d %f\n", aStudent.id, 
					aStudent.age, 
					aStudent.creditHours);
}

int main(){
	struct student s1 = makeStudent(1001, 23, 14.5);
	struct student s2 = makeStudent(2002, 24, 13.0);
	
	printStudent(s1);
	printStudent(s2);

	return 0;
}
