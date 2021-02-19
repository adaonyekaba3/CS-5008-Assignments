# include <stdio.h> // access std input output library

int main(){
	// Create a file that 
	// points to an actual pointer
	FILE* filePointer;
	
	// Open new created file, 
	// use command file open -fopen("")
	// add command "r" =  data we wanna read 
	// add command "w" = data we wanna write 
	filePointer = fopen("data.txt", "r");

	// initialize buffer = buffer holds integer values 
	int buffer; 
 	
	// read (print) contents of the file 
	// init while loop with feof-file end of file 
	// passing in filePointer parameter 
	while (1==fscanf(filePointer, "%d", &buffer)){ 
		// in while we are not at end of file, go read some of the contents. 
		// so pass in parameter  to fscanf - read function profile
		// return filePointer integer and address of buffer(&buffer). 
		printf("I read: %d\n", buffer);
	
	// good practice = close the file that
	//  we want our data to point too.
	}
	fclose(filePointer);

	return 0; // man fscanf - access manual file pointers.  
}

