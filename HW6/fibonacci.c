#include <stdio.h>

/* Noah Lacorazza
 * 
 * This program calculates up to the nth Fibonacci number using recursion. The user is prompted to enter a non-negative integer n, and the program will output the Fibonacci sequence up to the nth number. If the user enters a negative integer or a character, the program will print "Invalid input".
 */


// recursive function to calculate up to the nth Fibonacci number
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1; 
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n; // holds the user's input for the Fibonacci sequence

    // prompt the user for input
    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input\n");
        return 0;
    }

    // print the Fibonacci sequence up to the nth number
    printf("Fibonacci sequence up to F(%d): ", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}