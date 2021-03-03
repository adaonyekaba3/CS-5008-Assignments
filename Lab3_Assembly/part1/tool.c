// Implement your cycle count tool here.

# include <stdio.h> // access standard output library
# include <fstream> // for line based parsing using string streams 

int main()
 {
    // set up arguement counter
     printf("argc is the arguement count: %d\n", argc);

    // this loop prints out all of the arguements
    for (int i=0; i < argc; i++){
        printf("argv[%d] is %s\n", i, argv[i]);
    }

    // create a file that points to pointer
    FILE *file_p;

    // open barebones.s file
    file_p = fopen("barebones.s", "r"); // read from file

    // read through a file iterating
    // over every word or line until the end
    if (filePointer == NULL) // check whether barebones.s is open
        exit(EXIT_FAILURE);

    // initialize buffer to hold int values.
    int buffer;

    // implement counter using do-while loop
    //
    while(fscanf(file_p, "%d", &buffer))
    {
        for (int ADD = 0; ADD < 5; ADD++){}
    }
        printf("I read ADD: %d\n", buffer);
        printf("I read SUB: %d\n", buffer);
        printf("I read MUL: %d\n", buffer);
        printf("I read DIV: %d\n", buffer);
        printf("I read MOV: %d\n", buffer);
        printf("I read LEA: %d\n", buffer);
        printf("I read PUSH: %d\n", buffer);
        printf("I read POP: %d\n", buffer);
        printf("I read RET: %d\n", buffer);
    }

    fclose(file_p); // always close files

    return 0;
}