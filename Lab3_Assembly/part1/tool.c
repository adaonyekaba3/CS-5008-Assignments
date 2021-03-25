// Implement your cycle count tool here.

# include <stdio.h> // access standard output library
# include <string.h> 
# include <stdlib.h>

int main(int argc, char** argv) // argc - # charact char** argv - # strings 
{
    //set up arguement counter
    printf("argc is the arguement count: %d\n", argc);

    // this loop prints out all of the arguements
    for (int i=0; i < argc; i++){
    	printf("argv[%d] is %s\n", i, argv[i]);
   }

    // create a file that points to pointer
    FILE *file_p;

    // open barebones.s file and read 
    file_p = fopen(argv[1], "r");

    // read through a file iterating
    // over every word or line until the end
    if (file_p == NULL) // check whether barebones.s is open
        exit(EXIT_FAILURE);

    // initialize buffer to hold int values.
    char buffer[20]; // reading by character 

    // implement counter using do-while loop
    int ADD = 0;
    int MUL = 0;
    int MOV = 0;
    int SUB = 0;
    int DIV = 0;
    int LEA = 0;
    int PUSH = 0;
    int POP = 0;
    int RET = 0;

    // note output counts for file 
    /*ADD counts as 1 cycle
 *  SUB counts as 1 cycle
 *  MUL counts as 2 cycles
 *  DIV counts as 4 cycles
 *  MOV counts as 1 cycle
 *  LEA counts as 1 cycle
 *  PUSH counts as 1 cycle
 *  POP counts as 1 cycle
 *  RET counts as 1 cycle
 */

    while(1){

	fscanf(file_p, "%s\n", buffer);// read until new line (word)

    	printf("%s\n", buffer);
	
	// initialize counters for data
	if (!strcmp("add", buffer) || !strcmp("addb", buffer) || !strcmp("addw", buffer) || !strcmp("addl", buffer) ||
	    !strcmp("addq", buffer) || !strcmp("adds", buffer) || !strcmp("addd", buffer) || !strcmp("addt", buffer)){
		// increment counter
		ADD++;
	}
	if (!strcmp("sub", buffer) || !strcmp("subb", buffer) || !strcmp("subw", buffer) || !strcmp("subl", buffer) ||
	    !strcmp("subq", buffer) || !strcmp("subs", buffer) || !strcmp("subd", buffer) || !strcmp("subt", buffer)){
		//increment counter 
		SUB++;
	}
	if (!strcmp("mul", buffer) || !strcmp("mulb", buffer) || !strcmp("mubw", buffer) || !strcmp("mull", buffer) ||
	    !strcmp("mulq", buffer) || !strcmp("muls", buffer) || !strcmp("muld", buffer) || !strcmp("mult", buffer)){
		// increment counter 
		MUL++;
	}
	if (!strcmp("div", buffer) || !strcmp("divb", buffer) || !strcmp("divw", buffer) || !strcmp("divl", buffer) ||
	   !strcmp("divq", buffer) || !strcmp("divs", buffer) || !strcmp("divd", buffer) || !strcmp("divt", buffer)){
		// increment counter
		DIV++;
	}
	if (!strcmp("mov", buffer) || !strcmp("movb", buffer) || !strcmp("movw", buffer) || !strcmp("movl", buffer) ||
	    !strcmp("movq", buffer) || !strcmp("movs", buffer) || !strcmp("movd", buffer) || !strcmp("movt", buffer)){
		// increment counter
		MOV++;
	}
	if (!strcmp("lea", buffer) || !strcmp("leab", buffer) || !strcmp("leaw", buffer) || !strcmp("leal", buffer) ||
            !strcmp("leaq", buffer) || !strcmp("leas", buffer) || !strcmp("lead", buffer) || !strcmp("leat", buffer)){
		// increment counter 
		LEA++;
	}
	if (!strcmp("push", buffer) || !strcmp("pushb", buffer) || !strcmp("pushw", buffer) || !strcmp("pushl", buffer) ||
	    !strcmp("pushq", buffer) || !strcmp("pushs", buffer) || !strcmp("pushd", buffer) || !strcmp("pusht", buffer)){
		// increment counter 
		PUSH++;
	}
	if (!strcmp("pop", buffer) || !strcmp("popb", buffer) || !strcmp("popw", buffer) || !strcmp("popl", buffer) ||
	    !strcmp("popq", buffer) || !strcmp("pops", buffer) || !strcmp("popd", buffer) || !strcmp("popt", buffer)){
		// increment counter 
		POP++;
	}
	if (!strcmp("ret", buffer) || !strcmp("retb", buffer) || !strcmp("retw", buffer) || !strcmp("retl", buffer) ||
	    !strcmp("retq", buffer) || !strcmp("rets", buffer) || !strcmp("retd", buffer) || !strcmp("rett", buffer)){
		// increment counter 
		RET++;
	}
        // read to end of file. 
        if (feof(file_p)){
		printf("break\n"); // did you finish reading, then move to next. 
		break;
	}
	
    }
    printf("ADD=%d SUB=%d\n", ADD, SUB); //total counts  
    printf("MUL=%d DIV=%d\n", MUL, DIV); // total counts 
    printf("MOV=%d LEA=%d\n", MOV, LEA); // total counts 
    printf("PUSH=%d POP=%d\n", PUSH, POP); // total counts
    printf("RET=%d\n", RET); // total counts 
 
    int total_cycles = 0;
    total_cycles = ADD * 1 + SUB * 1 + MUL * 2 + DIV * 4 + MOV * 1 + LEA * 1 + PUSH * 1 + POP * 1 + RET * 1;
    printf("total cycles = %d\n", total_cycles);

    fclose(file_p); // always close files

    return 0;
}
