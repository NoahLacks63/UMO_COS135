#include <stdio.h>

/* Noah Lacorazza
 * 
 * Calculates the total of even numbers between two integers n and m. If n is greater than m, 
 * or either is negative, or either is a character, the program will print "Invalid input".
 */

int main() {
    int n; // holds the user's first integer input
    int m; // holds the user's second integer input
    int total = 0; // holds the sum of even numbers between n and m

    // scanf() two ints and save them in variables n and m
    printf("Enter two integers: ");
    if (scanf(" %d %d", &n, &m) != 2) {
        printf("Invalid input\n");
        return 0;
    }

    // compares n and m. If n is greater than m, or either is negative, or either is a character, print "Invalid input".
    if (n > m || n < 0 || m < 0) {
        printf("Invalid input\n");
        return 0;
    } else {
        // calculate the total of even numbers between n and m (inclusive)
        for (int i = n; i <= m; i++) {
            if (i % 2 == 0) {
                total += i;
            }
        }
        // print the total of the even numbers
        printf("Total of even numbers between %d and %d: %d\n", n, m, total);
    }


    return 0;
}