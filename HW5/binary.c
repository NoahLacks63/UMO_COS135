#include <stdio.h>

/* Noah Lacorazza
 *
 * Converts binary to decimal and vise versa.
 */
int main() {
	// Binary or decimal indicator
    char type;
	// Number input
    int inputNum = 0;
	// Current char
    char c;

    printf("Enter input (e.g., b1011 or d42): ");
    
    type = getchar();

    // Read the rest of the numeric input until Enter (\n)
    while ((c = getchar()) != '\n') {
        if (c >= '0' && c <= '9') {
            inputNum = inputNum * 10 + (c - '0');
        }
    }

    if (type == 'd') {
		// Holds the decimal number
        int decimal = inputNum;
		// Holds the binary number
        int binary = 0;
		// Holds the place value
        int place = 1;

		// Loop to convert decimal to binary
        while (decimal > 0) {
            binary = binary + ((decimal % 2) * place);
            place = place * 10;
            decimal = decimal / 2;
        }
        printf("Binary number is: %d\n", binary);
    }

    // Binary to decimal
    else if (type == 'b') {
		// Holds the binary number
        int binary = inputNum;
		// Holds the decimal number
        int decimal = 0;
		// Holds the place value
        int place = 1;
		// Tracks the loop pass to determine place value
        int loopPass = 1;

		// Loop through each digit of the binary number
        while (binary > 0) {
            if (loopPass == 1) {
                place = place * 1;
            } else {
                place = place * 2;
            }

            decimal = decimal + (binary % 10) * place;
            binary = binary / 10;
            loopPass = loopPass + 1;
        }
        printf("Decimal number is: %d\n", decimal);
    } 
    else {
        printf("Invalid indicator. Use 'b' or 'd'.\n");
    }

    return 0;
}
