#include <stdio.h>
#include <ctype.h>

/* Noah Lacorazza
 *
 * Continuously checks if inputted letters are vowels or consonants. # Exits the program.
 */
int main() {
	// The inputted char
	char i;

	// initial input
	printf("Enter a character: ");
	scanf(" %c", &i);

	i = tolower(i);

	// input loop. exits when # is inputted
	while (i != '#') {
		i = tolower(i);
		// logic to determine vowelitity and consonantity
		if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') {
			printf("'%c' is a vowel\n", i);
		} else if (i == 'b' || i == 'c' || i == 'd' || i == 'f' || i == 'g' || i == 'h' || i == 'j' || i == 'k' || i == 'l' || i == 'm' || i == 'n' || i == 'p' || i == 'q' || i == 'r' || i == 's' || i == 't' || i == 'v' || i == 'w' || i == 'x' || i == 'y' || i == 'z') {
			printf("'%c' is a consonant\n", i);
		} else {
			printf("'%c' is not a valid character\n", i);
		}
			
		// asks for a new input
		printf("Enter a character: ");
		scanf(" %c", &i);
	}

	return 0;
}
