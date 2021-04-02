// Implement your part 1 solution here
// gcc vfork.c -o vfork

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h> 	// allows for all heap blocks to be freed from child processes. 

// GLobal array - this is the canvas we are painting on. 
// its 64 rows by 64 columns (each pixel stores 3 color components, R, G, B)
int colors[64][64*3];

// Modify your paint function here. 
void paint(int workID){
	printf("Artist %d is painting\n", workID);
	
	// workID corresponds to the 'artist'
	// each artist gets one row to paint on.
	// an artist paints along each pixel 1 at a time, painting an 
	// R,B,G value 
	for(int i=0; i < 64*3; i++){
		colors[workID][i] = workID; 
	}
}

// free memory function
void free(void *ptr);
	
// main 
int main(int argc, char** argv){
	
	// malloc an integer array with 8000 integers 
	int* integers = malloc(sizeof(int)*8000);

	int numberOfArtists = 64; 	// Assign # of child processes
	
	pid_t pid;
	// main loop where we fork new threads
	for(int i = 0; i< numberOfArtists; i++){
		// Perform a fork 
		pid = vfork();
		
		// (2) Make only the child do some work (i.e paint) and then terminate. 
		if(pid == 0){
			// Make the child paint. 
			paint(i);
			// Then terminate/ exit the child process. 
			exit(0);
		}
		//printf("Child created: %d\n", pid);
		
	}
	pid_t wpid;
	int status = 0;
	while((wpid = wait(&status)) > 0);

	//printf("parent is exiting (last artist out!)\n");
	printf("Masterpiece(vfork.ppm) is being assembled\n");
	
	// Write out the PPM file 
	FILE *fp;
	fp = fopen("vfork.ppm", "w+");
	fputs("P3\n", fp);
	fputs("64 64\n", fp);
	fputs("225\n", fp);
	for(int i=0; i < 64; i++){
		for(int j=0; j < 64*3; j++){
			fprintf(fp, "%d", colors[i][j]);
			fputs(" ", fp);
		}
		fputs("\n", fp);
	}
	fclose(fp);

	free(integers); // Free function is not working. 
	return 0;	
}
