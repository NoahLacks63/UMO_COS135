#include <stdio.h>

int main() {
	// Part A
	char chr = 88;

	printf("Character having ASCII value %i is %c.\n", chr, chr);

	// Part B
	int i_number = 12;
	float f_number = 3.125;
	double d_number = 7.5345345;
	char character = 'T';
	char text[] = "COS 135";

	printf("%i %f %f %c %s\n", i_number, f_number, d_number, character, text);

	return 0;
}


