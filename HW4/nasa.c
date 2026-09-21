#include <stdio.h>

/* Noah Lacorazza
 *
 * Takes input from three "computers" and based on their criticality, outputs
 * wether or not they meet the criteria of that criticality.
 *
 * Critical must have 3 equal inputs else error.
 *
 * Non-critical must have 2 equal inputs else error.
 */

int main() {
	// priority 1-3
	char p1;
	char p2;
	char p3;

	// num 1-3
	int n1;
	int n2;
	int n3;

	// collect inputs
	printf("Enter first number: ");
	scanf("%c %d", &p1, &n1);
	
	printf("Enter second number: ");
	scanf(" %c %d", &p2, &n2);

	printf("Enter third number: ");
	scanf(" %c %d", &p3, &n3);

	// handles if all inputs are not of the same criticality
	if (!(p1 == p2 && p2 == p3 && (p1 == 'C' || p1 == 'N'))) {
		printf("Value: ERROR\n");
		
		return 0;
	}

	// handles non critical calculations by comparing all values
	if (p1 == 'N') {
		if (n1 == n2 || n1 == n3) {
			printf("Value: %d\n", n1);
		} else if (n2 == n3) {
			printf("Value: %d\n", n2);
		} else {
			printf("Value: ERROR\n");
		}

		return 0;
	}

	// handles critical calulations by comparing all values
	if (p1 == 'C') {
		if (n1 == n2 && n1 == n3 && n2 == n3) {
			printf("Value: %d\n", n1);
		} else {
			printf("Value: ERROR\n");
		}

		return 0;
	}

	return 0;
}
