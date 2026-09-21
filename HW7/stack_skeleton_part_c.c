/** 
 * Here is a skeleton of a stack implementation.
 *
 * @note This is only one way of doing it and it is not a must to use this example in your program.
 * @note This code cannot be compiled as it only contains dummy functions to help in your program design.
 *
 * @author Nimesha Ranasinghe (r.ranasinghe@maine.edu)
 *
 *
 * Compile:
 *  gcc -g -Wall stack_skeleton.c -o stack_skeleton
 *
 * Run:
 *  ./stack_skeleton
 *
 */

#include<stdio.h>
#include<stdlib.h>

/**
 * @brief  print all the elements in the stack
 * @note   passing the pointer to stack as a read-only by using const char *stack (same for size)
 * @param  *stack: Reference to the stack
 * @param  size: current length of the stack (size > 0)
 * @retval None
 */
void printstack(const char *stack, const int size) {
    
}

/**
 * @brief  shift all the stack elements to right before push a new element
 * @note
 * @param  *stack: Reference to the stack
 * @param  size: current length of the stack (size > 0)
 * @retval None
 */
void shiftright(char *stack, int size) {
    
}

/**
 * @brief  shift all the stack elements to left after pop
 * @note
 * @param  *stack: Reference to the stack
 * @param  size: current length of the stack (size > 0)
 * @retval None
 */
void shiftleft(char *stack, int size) {
    
}

/**
 * @brief  pop the top element from the stack (from beginning)
 * @note   if the stack is empty, returns a '_'
 * @param   *stack: Reference to the stack
 * @param   *size: pointer to the size variable defined in main() function
 * @retval character popped from the stack (first element)
 */
char pop(char *stack, int *size) {
    
}

/**
 * @brief  insert/push a new element to the top of the stack (from beginning)
 * @note   if the stack is empty, create a new memory; else add more memory
 * @param  *stack: Reference to the stack
 * @param  *size: pointer to the size variable defined in main() function
 * @retval None
 */
void push(char new_value, char *stack, int *size) {
    
}

/**
 * @brief  COS135 assignment 9
 * @note
 * @retval 0 if the program terminates without errors
 */
int main() {
    
    int size = 0; // maintain the size of the stack
    char* stack;  // reference to the char stack
    
    // your code goes here
    
    return 0;
    
}
