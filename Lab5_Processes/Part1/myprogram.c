// Take a look at some of the previous examples to create your own program!
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	// initialize file descriptors and their values
	// Access the values by name. 
	// input, output, and errors.
	printf("STDIN_FILENO = %d\n", STDIN_FILENO);
	printf("STDOUT_FILENO = %d\n", STDOUT_FILENO);
	printf("STDERR_FILENO = %d\n", STDERR_FILENO);

	// Create a 'pipe':  2 processes to communicate with one another. 
	// init storage for our file descriptors.
	int fd[2];
	
	// Now use the pipe command. 
	pipe(fd);

	// Print the file descriptors out to confirm.
	printf("pipe fd[0](for reading) = %d\n", fd[0]);
	printf("pipe fd[1](for writing) = %d\n\n", fd[1]);
	
	// Now set up 2 separate processes to talk to one another.
	// We must launch another process so we can connect our pipe between the 2 processes. 
	// Use the 'fork()' command to create a new child process. 
	
	// Store the new child process id.
	pid_t childProcessID;
	// Store the child process ID in int value
	// shows when the child process has finished executing.
	int child_status;
	
	// Execute fork and duplicate the parent 
	childProcessID = fork();
	// Check that child was successfully created.
	if(-1== childProcessID){
		printf("fork failed for some reason!");
		exit(EXIT_FAILURE);
	}
	
	// Execute the child code here. 
	if(childProcessID==0){
		// Child will execute here 
		// child inherits everything from parent 
		// print the child descriptors 
		printf("child copy of pipe fd[0] = %d\n", fd[0]);
		printf("child copy of pipe fd[1] = %d\n\n", fd[1]);
		
		// Execute ls command in child process. 

		char* myargv[16]; 	// Lets store up to 16 arguments.
		myargv[0]="/bin/ls"; 	// launch first arguement. 
		myargv[1]="-F";		// use flags 
		myargv[2]=NULL;		// Terminate argument list.
		
		// Now execute this command in child process.
		// Set up communication through our pipe and make sure child does not output
		// as soon as it executes to the terminal.
		close(STDOUT_FILENO);
		
		// now capture the output using the 'dup2' command to duplicate the file descriptor 
		// fd[1] into STDOUT_FILENO. 
		dup2(fd[1], STDOUT_FILENO);
		
		// Write some output data into our pipe now. 
		dprintf(fd[1], "hello msg from child sent and buffered in pipe\n");

		// close the file descriptor when we are done with it.
		close(fd[1]); 	// we are done with fd[1].
		close(fd[0]); 	// we do not need stdin.
	
		// now that everything is set up, execute our child. 
		execvp(myargv[0], myargv);
	
	}if(childProcessID==0){
		
		// Child will execute here.
		printf("child copy of pipe fd[0] = %d\n", fd[0]);
		printf("child copy of pipe fd[1] = %d\n\n",fd[1]);
		
		// Lets execute another child process 
		char* myargv[3];
		myargv[0]= "echo";
		myargv[1]= "testing\n";
		myargv[2]= NULL;

		// Set up our communication through the pipe. 
		close(STDOUT_FILENO);
		
		// Duplicate the file descriptor using 'dup2' command 
		dup2(fd[1],STDOUT_FILENO);
		
		// Write data into our pipe now.
		dprintf(fd[1],"hello msg from child sent and buffered in pipe\n");
		
		// close the file descriptor here.
		close(fd[1]);
		close(fd[0]);

		// call the execute our child command. 
		execvp(myargv[0],myargv);
	
	}if(childProcessID==0){
		// variable 'x' allocated on the stack. 
		int x = 1; 
		// print the child file descriptors.
		printf("child: x=%d\n", ++x);
		printf("parent: x=%d\n", --x);
		
	}else{
		// parent process executes this section of our code here. 
		// call the 'waitpid' command - it allows us to wait on the specific child process id
		// wait for the child process ID to be stored.	
		wait(NULL);
		//waitpid(childProcessID,&child_status,NULL); 
		printf("This always prints last\n");	
		

	// Lets finish process communication!

	close(STDIN_FILENO); 	// close stdin - comes from our child process
	dup2(fd[0], 0); 	// new 'stdin' comes from the read end of pipe
	close(fd[1]);	 	// close the 'write' file descriptor 
	
	// Lets write out the data in our pipe.
	printf("========= In parent process ========\n");
	char c;
	while(read(STDIN_FILENO, &c, 1) >0){
		write(STDOUT_FILENO, &c, 1);
	}
	}// We are done! Pipe created
	return 0;  
}
