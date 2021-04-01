// Modify this file for your assignment
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sched.h>
#include <ctype.h>

// define GLOBAL Variables 
#define READ 0
#define WRITE 1
#define MAX_LIMIT 80
// MORE GLOBALS VARs
static char* myargv[MAX_LIMIT];
static struct node *start = NULL;
pid_t pid;
int command_pipe[2]; // Pipe operations.
int flag = 0;
int isInDir = 0;
int isOutDir = 0;
int rPos; int lPos;
static char line[80]; // for the input command 
static int fgProc = 0;



//store history of commands. 

// Clear the shell using especape sequences 
# define clear() printf("\033[H\033[J")

// Store history of commands
// Define struct for node 
typedef struct node
{
	char* data;
	struct node *next;
}node;

// 2. Declare your functions 

	/* Parse the given commands and write/call the functions to execute them
 * 		and returning the file descriptor for next command. 
 * 		
 * 		-cmd: gets entered by user 
 * 		-input: file descriptor -> 0 to STDIN
 * 		-first: considered a 'flag' used to identify if the current command is
 * 			first command in command pipeline.
 * 		-last: considered a 'flag' used to identify the last command in pipeline.  
 */
// Static int declaration. 
static int run(char* cmd, int input, int first, int last);
/* 	
 *  	This function parses the given input commands bove using 'run' 
 *  	and stores it in char data type 'cmd'
 *  	
 *  	Pipes will be handled in the following manner:
 *  		given input commands will parse till the first pipe is met. 
 *  		'command' will execute and the file descriptor will be returned for 
 *  		next command. 
 */

// 3. Declare next static function
static void parse(char* cmd);

/* 	
 *  	This function executes the given command and returns the 
 *  	file descriptor for next command. After input is parsed, 
 *  	this function is called. 
 *
 *  	Refer to the following commands:
 *  	- input: file descriptor -> 0 to STDIN
 *  	- first: flag -> used to identify whether 'command' is first in pipeline 
 *  	- last: flag -> used to identify whether 'command' is last in pipeline. 
 */

// 4. Declare next 'command' function
static int command(int input, int first, int last);

// 5. Skip whitespaces 
static char* skipwhitespaces(char* s){
	while(isspace(*s)) ++s;
	return s;
}

// 6. allocate/create new node.
node *create_node(char* data){

	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = (char*)malloc(sizeof(char));
	newNode->data = strdup(data);
	start = newNode;
	newNode->next = NULL;
	return start;
}

// 7. Display the LL. 
void display(node *start, int limit){
	
	node *ptr;
	ptr = start;

	int i=0;
	while(ptr && limit > 0){
		if (ptr->data[strlen(ptr->data) - 1] == '\n')
			ptr->data[strlen(ptr->data) - 1] = '\0';
	printf("%s\n", ptr->data);
	ptr = ptr->next;
		limit--;
		i++;
	}
}

// 8. Define function to insert first element.
node *insert(node *start, char *data){
	
	if(start){
		
		node* newNode = (node*)malloc(sizeof(node));
		newNode->data = (char*)malloc(sizeof(char));
		newNode->data = strdup(data);
		newNode->next = start;
		start = newNode;
		return start;
	}
	else{
		return create_node(data);
	}
}

// 9. initialize counter 
int counter(node *start){
	
	node *ptr;
	int counter = 0;
	ptr = start;
	while(ptr){
		counter++;
		ptr = ptr->next;
	}
	return counter;
}

// 10. init command function
static int command(int input, int first, int last){
	
	// create file pointer
	FILE* filePointer;
	int command_pipe[2];
	
	// 11. invoke the pipe.
	pipe(command_pipe);
	pid = fork();
	
	if (pid == 0){
		if (first == 1 && last == 0 && input == 0){
			// 12. initialize first command
			if(isInDir || isOutDir){
				if(isInDir){
					dup2( command_pipe[WRITE], STDOUT_FILENO );
					close(STDIN_FILENO);
					filePointer =  fopen(myargv[rPos+1], "r");
					myargv[rPos] = NULL;
				}else{
					dup2( command_pipe[WRITE], STDOUT_FILENO);
					close(STDIN_FILENO);
					filePointer = fopen(myargv[lPos+1], "w");
					myargv[lPos] =  NULL;
				}
			}else{
				dup2(command_pipe[WRITE], STDOUT_FILENO);
			}
		}else if(first == 0 && last == 0 && input != 0){
			// 13. Select the middle command
			dup2(input, STDIN_FILENO);
			dup2(command_pipe[WRITE], STDOUT_FILENO);
		}else{
			// 14. select last command.
			if ((isInDir) || (isOutDir)){
				if (isInDir){
					dup2(input, STDIN_FILENO);
					close(STDIN_FILENO);
					filePointer = fopen(myargv[rPos+1], "r");
					myargv[rPos] = NULL;
				}else{
					dup2(input, STDIN_FILENO);
					close(STDOUT_FILENO);
					filePointer = fopen(myargv[lPos+1], "w");
					myargv[lPos] = NULL;
				}
			}else{
				dup2(input, STDIN_FILENO);
			}
		
		}if(flag==1){
			setpgid(pid,0);
		}
		execvp(myargv[0], myargv);
		printf("Command not found--Please enter alternative command: ");
		exit(0);
	}
	if (input != 0){
		close(input);
	}close(command_pipe[WRITE]);
	
	if(last == 1){
		close(command_pipe[READ]);
	}
	return command_pipe[READ];
} 

// 13. Declare cleanup function 
static void cleanup(){
	
	
	for(int i=0; i<fgProc; i++){
		wait(NULL);
	}
}
// 15. Declare static parse function.
static void parse(char* cmd){
	cmd = skipwhitespaces(cmd);
	char* next = strchr(cmd, ' ');
	int i = 0;

	while(next != NULL){
		next[0] = '\0';
		myargv[i] = cmd;
		++i;
		cmd = skipwhitespaces(next+1);
		next = strchr(cmd, ' ');
	}
	if(cmd[0] != '\0'){
		myargv[i] = cmd;
		next = strchr(cmd, '\n');
		next[0] = '\0';
		++i;
	}
	myargv[i] = NULL;
	
	/*// < /> check 
	for(int j=0; (myargv[j]) != NULL ; j++){
		if(strcmp(myargv[j], "<") == 0){
			isInDir = 1;
			rPos = j;
			break;
		}else{
			isInDir = 0;
			rPos = -1;
		}
	
	}for(int j = 0, (myargv[j]) != NULL ; j++){
		if(strcmp(myargv[j], ">") == 0){
			isOutDir = 1;
			lPos = j;
			break;
		}else{
			isOutDir = 0;
			lPos = -1;
		}
	}*/
}


// 14. Declare run function for shell 
static int run(char* cmd, int input, int first, int last){
	
	int Return, count = 0;
	parse(cmd);
	
	if (myargv[0] != NULL){
		if(strcmp(myargv[0], "exit") == 0){
			exit(0);
		}
	}if(strcmp(myargv[0], "help") == 0){

		printf("Welcome to Ada's minishell!\n");
			printf("The shell supports standard unix/linux shell commands\n");
			printf("To execute a command, use the following syntax\n >command[args]* [ | command [args]* ]* \n ex. \nAda's mini-shell>ls -l | wc\n\n");
			printf("\nThe following are certain built-in commands:\n");
			printf("cd: changes the directory to the said directory if it exists.\n	Syntax cd <directory path> \n ex. \nAda's mini-shell>cd newDir\n\n");
			printf("exit: exits the shell. or CTRL+C\n ex. \nAda's mini-shell>exit\n\n");
			printf("last [n]: prints the last n commands entered into the shell.\n");
			printf("ex: last 4 -> prints the last 4 commands OR last 4 commands entered.\n");
			return 0;
	}
	if (strcmp(myargv[0], "cd") == 0){
		if(chdir(myargv[1]) != 0){
			
			printf("%s : No such directory exist! \n", myargv[1]);
		}
		return 0; 
		
	}if(strcmp(myargv[0], "last") == 0){
		
		if(myargv[1] != NULL){
			int limit = (int)strtol(myargv[1], (char **)NULL, 10);
			display(start, limit);
		}else{
			display(start, counter(start));
		}
		return 0;
	}else{
		while(myargv[count] != NULL){
			count++;
		}
		if(strcmp(myargv[--count], "&") == 0 ){
			flag = 1; // indicates background process
			myargv[count] = NULL;
		}else{
			flag=0;
			fgProc+=1;
		}
		return command(input, first, last);
	}
	return 0;
}		

// Greeting to initialize shell during startup!
void init_shell(){


	// clears the screen at startup
	clear();
	printf("\n\n\n\n *******************************"
		"************************************");
	printf("\n\n\n\t****ADA'S HAPPY-PLACE****");
	printf("\n\n\t- FEEL FREE TO EXPLORE & LEARN! ");
	printf("\n\n\n\n********************************"
		"********************************");

}

// 5. Define signal handler function for CTRL+C.
void sigint_handler(int sig){
	printf(" Terminating through signal handler \n");
	exit(0);
}

// 6. Define signal handler to exit child process.
void child_exit(){
	
	// initialize wstat
	union wait wstat;
	pid_t cpid;
	while(1){
		int cipd;
	
		cpid = wait3(&wstat, WNOHANG, (struct rusage *)NULL );
		if (cipd == 0){
			return;
		}else if(cipd == -1){
			return;
		}else{
			printf("Process %d Done. Return code is: %d\n", cpid, wstat.w_retcode);
		}
	}
}

int main(){

	// initialize the shell 
	init_shell();
	// 1. prompt 'minishell' in front of
	// each command that is typed out 
	printf("enter 'help' for instructions on how to use the shell\n");
	signal(SIGINT, sigint_handler);
	signal(SIGCHLD, child_exit);
		
	while(1){
		/* print the command prompt */
		printf("minishell> ");
		fflush(NULL);
		/* READ A COMMAND LINE! */
		if(!fgets(line, MAX_LIMIT, stdin))
			return 0;
			
		isOutDir = 0;
		rPos = -1;
		isInDir = 0;
		lPos = -1;
		int input = 0;
		int first = 1;
		char* cmd = line;
		start = insert(start,cmd);
		char* next = strchr(cmd, '|'); // find first instance 

		while(next != NULL){
			
		/* 'next' points to '|' */
		*next = '\0';
		input = run(cmd, input, first, 0);
			
		cmd = next+1; 
		next = strchr(cmd, '|');  //find next '|' 
		first = 0;
		}
		input = run(cmd, input, first, 1);
		cleanup(); // wait for all foreground processes to complete execution.
		fgProc = 0; // All processes should have completed.*/
	}
	return 0;
}
