#include "stdio.h"

char* gNames[100];

void EnterNames();
void DisplayNames();

void main(void)
{
	printf("Starting\n\n");

	EnterNames();
	DisplayNames();

	printf("\nComplete");
	getch();
}

void EnterNames()
{
	int i = 0;

	while (i < 2)
	{
		char input[50] = { 0 };
		int size = 0;
		char *name = NULL;

		printf("Enter name: ");
		scanf("%s", input);

		size = strlen(input) * sizeof(char);
		name = malloc(size);
		strcpy(name, input);
		gNames[i] = name;

		i++;
	}
}

void DisplayNames()
{
	int i = 0;

	printf("\n");
	printf("\t Entered \n");
	printf("\t ---------- \n");

	while (i < 10)
	{
		printf("\t %d %s \n", i, gNames[i]);
		i++;
	}
}