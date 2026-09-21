#include <stdio.h>

/* Noah Lacorazza
 * 
 * prints prime numbers, even numbers, odd numbers, natural numbers, and the sum of all natural numbers between 1 and a user-inputted positive integer n. 
 * If the user enters a negative integer or a character, the program will print "Invalid input".
 */

// prints prime numbers
void printPrimes(int n) {
    printf("Prime numbers between 1 and %d: ", n);
    
    // loop through numbers from 2 to n and check if they are prime
    for (int i = 2; i <= n; i++) {
        int isPrime = 1; // flag to check if the number is prime

        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = 0; // not a prime number
                break;
            }
        }

        if (isPrime) {
            printf("%d ", i);
        }
    }

    printf("\n");
}

// prints even numbers
void printEvens(int n) {
    printf("Even numbers between 1 and %d: ", n);

    for (int i = 2; i <= n; i += 2) {
        printf("%d ", i);
    }

    printf("\n");
}

// prints odd numbers
void printOdds(int n) {
    printf("Odd numbers between 1 and %d: ", n);

    for (int i = 1; i <= n; i += 2) {
        printf("%d ", i);
    }

    printf("\n");
}

// prints natural numbers
void printNaturals(int n) {
    printf("Natural numbers between 1 and %d: ", n);

    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }

    printf("\n");
}

// calculates the sum of all natural numbers between 1 and n
int sumNaturals(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    return sum;
}

int main() {
    int n; // holds the user's input for the positive integer

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    printPrimes(n);
    printEvens(n);
    printOdds(n);
    printNaturals(n);

    printf("Sum of natural numbers between 1 and %d: %d\n", n, sumNaturals(n));

    return 0;
}