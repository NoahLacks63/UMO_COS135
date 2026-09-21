#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Users can pass command line arguments when they execute a C program
 *
 * e.g., following command will execute the 'test_program' and supply 5 as the first argument
 * ./test_program 5
 *
 * e.g., following command will execute the 'test_program' and supply "COS135" as the first argument and "Hello" as the second
 * ./test_program COS135 Hello
 *
 * Notice the change to the main() function, int argc, char *argv[]
 * int argc - refers to the number of arguments passed (including the program name; so if you are passing one argument, the value of argc will be 2)
 * char *argv[] - is a pointer array which points to each argument passed to the program
 *
 * Noted that argv[0] holds the name of the program itself and argv[1] is a pointer to the first command line argument supplied,
 * and *argv[n] is the last argument.
 * If no arguments are supplied, argc will be one, and if you pass one argument then argc is set at 2.
 *
 */

int main(int argc, char *argv[]) {
    int* queue = malloc(atoi(argv[1]) * sizeof(int));
    
    // argv[0] is always the program name
    printf("Program name %s\n", argv[0]);
    
    // argc contains the number of arguments supplied.
    // if no arguments, it is 1 as the first argument, by default, is the program name
    printf("There are %d arguments.\n", argc);
    
    // The first argument is at argv[1] array location. Note that these values are in char arrays (i.e., strings)
    // you can use functions in stdlib.h to convert to numbers, if necessary
    // e.g., atoi(), atof(), strtod(), or strtol() functions
    // check sample codes at week8-2-codes.zip
    // note: you cannot typecast string (char array) to int
    if (argc == 2 ) {
        printf("The first argument supplied is %s\n", argv[1]);
    }
    else if ( argc > 2 ) {
        printf("More than one arguments supplied. The list of arguments supplied are: \n");
        // using a loop to output all the arguments
        for(int i = 1; i < argc; i++)
            printf("%s\n", argv[i]);
        putchar('\n');

        return 1;
    }
    else {  // just making sure at least one argument should be given
        printf("One argument expected.\n");

        return 1;
    }


    char c[5];
    int n;
    int tail = 0;

    while (strcmp(c, "quit") != 0) {
        printf("Enter command (push, print, or quit): ");

        scanf(" %s", c);

        if (strcmp(c, "push") != 0 && strcmp(c, "print") != 0 && strcmp(c, "quit") != 0) {
            printf("Invalid input\n");
            continue;
        }

        if (strcmp(c, "push") == 0) {
            scanf( "%d", &n);

            if (tail >= atoi(argv[1])) {
                printf("Overflow %d\n", queue[tail-1]);
                continue;
            }
            
            for(int i = tail; i > 0; i--) {
                queue[i] = queue[i-1];
            }
            queue[0] = n;
            tail = tail == atoi(argv[1]) ? tail : tail + 1;
        } else if (strcmp(c, "print") == 0) {
            for (int i = 0; i < tail; i++) {
                printf("%d ", queue[i]);
            }

            printf("\n");
        } else if (strcmp(c, "quit") == 0) {
            return 0;
        }
    }

    free(queue);
    return 0;
}

