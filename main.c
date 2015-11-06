#include "stdio.h"

void main(void)
{
	char c;
	printf("Starting\n\n");

	printf("Enter character:");
	c = getch();

	printf("\n");
	printf("Entered %c\n", c);

	printf("\nComplete");
	getch();
}