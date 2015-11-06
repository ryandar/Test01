#include "stdio.h"

void main(void)
{
	char c;

	printf("Starting\n\n");

	printf("Enter:");
	c = getch();

	printf("Entered %c\n", c);

	printf("Complete\n\n");

	getch();
}