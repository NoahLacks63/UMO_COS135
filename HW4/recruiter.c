#include <stdio.h>

/* Noah Lacorazza
 *
 *
 *
 *
 */
int main() {
	#define CURRENT_YEAR 2026

	char appName[50];
	
	int appYear;
	int appSalary;

	printf("New applicant's name: ");
	fgets(appName, sizeof(appName), stdin);
	
	for (int i = 0; i < sizeof(appName); i++) {
		if (appName[i] == '\n') {
			appName[i] = '\0';
			break;
		}
	}

	printf("New applicant's birth year: ");
	scanf(" %d", &appYear);

	printf("New applicant's preffered monthly salary (USD): ");
	scanf(" %d", &appSalary);

	printf("%s is a %d year old applicant and requests a monthly salary of $%.2f.\n", appName, CURRENT_YEAR - appYear, (float)appSalary);
	
	return 0;
}
