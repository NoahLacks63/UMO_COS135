#include <stdio.h>

/* Noah Lacorazza
 *
 * Tracks a user's monthly budget and provides feedback on their spending habits.
 */

// Definitions for column widths
#define LABEL_WIDTH 18 
#define VALUE_WIDTH 12

int main() {
    float goal; // The user's monthly spending limit
    float rent; // Monthly cost for housing
    float utilities; // Monthly cost for electricity, water, etc.
    float transport; // Monthly cost for travel/gas
    float food; // Monthly cost for groceries/dining
    float carPayment = 581.99; // Additional fixed monthly expense
    float totalExpenses; // Sum of all individual expense categories
    float leftover; // Difference between the goal and total spending
    float savingsThreshold; // Calculated as 1/5th of the goal
    char name[] = "Noah"; // User's name to be displayed in the header

    // Data Input
    printf("Enter monthly expense goal: ");
    scanf("%f", &goal);
    printf("Enter rent expense: ");
    scanf("%f", &rent);
    printf("Enter utilities expense: ");
    scanf("%f", &utilities);
    printf("Enter transportation expense: ");
    scanf("%f", &transport);
    printf("Enter food expense: ");
    scanf("%f", &food);

    // Calculations
    totalExpenses = rent + utilities + transport + food + carPayment;
    leftover = goal - totalExpenses;
    savingsThreshold = goal / 5.0;

    printf("\n%s's Monthly Budget\n\n", name);
    
    printf("%-*s %-*s %-s\n", LABEL_WIDTH, "Item", VALUE_WIDTH, "Amount", "Percentage");
    printf("--------------------------------------------------\n");

    // Displaying each item
    printf("%-*s $%-*.2f %.2f%%\n", LABEL_WIDTH, "Rent", VALUE_WIDTH - 1, rent, (rent / totalExpenses) * 100);
    printf("%-*s $%-*.2f %.2f%%\n", LABEL_WIDTH, "Utilities", VALUE_WIDTH - 1, utilities, (utilities / totalExpenses) * 100);
    printf("%-*s $%-*.2f %.2f%%\n", LABEL_WIDTH, "Transportation", VALUE_WIDTH - 1, transport, (transport / totalExpenses) * 100);
    printf("%-*s $%-*.2f %.2f%%\n", LABEL_WIDTH, "Food", VALUE_WIDTH - 1, food, (food / totalExpenses) * 100);
    printf("%-*s $%-*.2f %.2f%%\n", LABEL_WIDTH, "Car Payment", VALUE_WIDTH - 1, carPayment, (carPayment / totalExpenses) * 100);

    // Summary
    printf("\nMonthly Goal:   $%.2f\n", goal); 
    printf("Total Expenses: $%.2f\n", totalExpenses); 
    printf("Amount Left:    $%.2f\n\n", leftover); 

    // If leftover is >= 1/5th of the goal, user is saving enough
    if (leftover >= savingsThreshold) {
        printf("Good job. You are saving enough!\n");
    } else {
        printf("Try to save more!\n");
    }

    return 0;
}