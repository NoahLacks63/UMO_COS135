#include <stdio.h>

/* Noah Lacorazza
 *
 * Prints out an itemized receipt from The Coding Store. 
 */

int main() {
	char STORE_NAME[] = "The Coding Store";

	double ITEM1_PRICE = 21.45;
	double ITEM2_PRICE = 10.00;
	double ITEM3_PRICE = 14.90;
	double ITEM4_PRICE = 33.50;
	double TOTAL_PRICE = ITEM1_PRICE * 2 + ITEM2_PRICE * 2 + ITEM3_PRICE * 2 + ITEM4_PRICE * 2;
	double GST_PERCENT = 0.12;

	int COLUMN1_WIDTH = -12;
	int COLUMN2_WIDTH = -8;
	int COLUMN3_WIDTH = -8;

	printf("Welcome to %s\n\n", STORE_NAME);
	printf("%*s$%*.2f%*s$%.2f\n", COLUMN1_WIDTH, "Item 1", COLUMN2_WIDTH, ITEM1_PRICE, COLUMN3_WIDTH, "x2", ITEM1_PRICE * 2.0);
	printf("%*s$%*.2f%*s$%.2f\n", COLUMN1_WIDTH, "Item 2", COLUMN2_WIDTH, ITEM2_PRICE, COLUMN3_WIDTH, "x2", ITEM2_PRICE * 2.0);
	printf("%*s$%*.2f%*s$%.2f\n", COLUMN1_WIDTH, "Item 3", COLUMN2_WIDTH, ITEM3_PRICE, COLUMN3_WIDTH, "x2", ITEM3_PRICE * 2.0);
	printf("%*s$%*.2f%*s$%.2f\n\n", COLUMN1_WIDTH, "Item 4", COLUMN2_WIDTH, ITEM4_PRICE, COLUMN3_WIDTH, "x2", ITEM4_PRICE * 2.0);
	printf("%*s$%.2f\n\n", COLUMN1_WIDTH, "Item total: ", TOTAL_PRICE);
	printf("%*s$%.2f\n", COLUMN1_WIDTH, "GST: ", TOTAL_PRICE * GST_PERCENT);
	printf("%*s$%.2f\n", COLUMN1_WIDTH, "Total: ", TOTAL_PRICE * (1 + GST_PERCENT));

	return 0;
}
