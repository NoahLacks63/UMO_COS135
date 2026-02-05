#include <stdio.h>

int main() {
	char LINE[] = "----------------------------";

	int CPU_CORES = 8;

	printf("SYSTEM REPORT\n%s\n", LINE);
	printf("%-18s %s\n", "Name: ", "Jane Doe");
	printf("%-18s %s\n", "Course: ", "COS 135");
	printf("%-18s %s\n", "Semester: ", "Spring 2026");
	printf("%-18s %i\n\n", "Arguments passed: ", 1);
	printf("%-18s %s\n%s\n", "Component", "Value", LINE);
	printf("%-18s %d\n", "CPU Cores: ", 8);
	printf("%-18s %d\n", "Memory (GB): ", 16);
	printf("%-18s %d\n", "Disk Size (GB): ", 512);
}	
