/*
 * This is a skeleton program for the Assignment 6 (d)
 * You are NOT ALLOWED to change the given instructions including the function signatures.
 * @author NR
 */

#include <stdio.h>

// function signatures
void swap(int *x, int *y);
void rank_student_grades(int *num1, int *num2, int *num3);
void print_name(char text[]);

int main()
{
    char name[20];
    int g1, g2, g3;

    // read name and three grades
    // then save them in the variables
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter three grades: ");
    scanf(" %d %d %d", &g1, &g2, &g3);
    
    // example output: Adam James      68      87      79
    printf("Original grades: ");
    print_name(name);
    printf("%22d%4d%4d\n", g1, g2, g3);
    
    // call rank_student_grades() function
    rank_student_grades(&g1, &g2, &g3);
    
    // example output: Adam James      87      79      68      78.00
    // need to add the format specifier to output average
    printf("Ordered grades: ");
    print_name(name);
    printf("%22d%4d%4d%8.2f\n", g1, g2, g3, (g1 + g2 + g3) / 3.0);
    
    return 0;
}


/*
 change the values in num1, num2, and num3 in descending order
 */
void rank_student_grades(int *num1, int *num2, int *num3) {
    // compare num1 and num2, swap if num1 is smaller than num2
    if (*num1 < *num2) {
        swap(num1, num2);
    }
    // compare num1 and num3, swap if num1 is smaller than num3
    if (*num1 < *num3) {
        swap(num1, num3);
    }
    // compare num2 and num3, swap if num2 is smaller than num3
    if (*num2 < *num3) {
        swap(num2, num3);
    }
    
    // complete the comparison and rank
    return;
    
}


/*
 swap the values by reference (i.e., based on memory addresses)
 */
void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return;
}


/*
 print name in the array without the new line character
 */
void print_name(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] != '\n') {
            printf("%c", text[i]);
        }
    }
    // complete the printing name
    return;
}
