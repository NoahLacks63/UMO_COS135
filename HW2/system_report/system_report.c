#include <stdio.h>

int main() {
	char LINE[] = "----------------------------";

	char LEFT_WIDTH = -18;
	char CPU_CORES = 8;
	char MEMORY = 16;

	short DISK_SIZE = 512;
	
	printf("SYSTEM REPORT\n%s\n", LINE); 
	// Explain what one printf() line in your program does
	// This is the first line that uses both width and format specifiers.
	printf("%*s %s\n", LEFT_WIDTH, "Name: ", "Jane Doe");
	printf("%*s %s\n", LEFT_WIDTH, "Course: ", "COS 135");
	printf("%*s %s\n", LEFT_WIDTH, "Semester: ", "Spring 2026");
	printf("%*s %i\n\n", LEFT_WIDTH, "Arguments passed: ", 1);
	// Explain why field width or alignment was used in your table output.
	// I used field width to get two nice columns 
	printf("%*s %s\n%s\n", LEFT_WIDTH, "Component", "Value", LINE);
	printf("%*s %d\n", LEFT_WIDTH, "CPU Cores: ", CPU_CORES);
	printf("%*s %d\n", LEFT_WIDTH, "Memory (GB): ", MEMORY);
	printf("%*s %d\n", LEFT_WIDTH, "Disk Size (GB): ", DISK_SIZE);

	// What part of this program did not work the first time you tried it, and how did you fix it?
	// I forgot a semicolon and a comma. To fix it, I added a semicolon and a comma.
}	
