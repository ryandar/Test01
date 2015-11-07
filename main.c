#include "stdio.h"
#include "stdlib.h"

typedef enum { false, true } bool;

char* gInput[100];
char* gCache[10];
int gInputIndex = 0;

bool EnterName();
void Display();
void ClearScreen();

void main(void)
{
	Display();

	while (EnterName())
	{
		ClearScreen();
		Display();
	}
}

bool EnterName()
{
	char input[50] = { 0 };
	int size = 0;
	char *name = NULL;

	printf("\n");
	printf("Enter name or X to exit: ");
	scanf("%s", input);

	if (!strcmp("X",input))
	{
		return false;
	}

	size = strlen(input) * sizeof(char);
	name = malloc(size);
	strcpy(name, input);
	gInput[gInputIndex] = name;

	gInputIndex++;

	return true;
}

void Display()
{
	int i = 0;

	printf("\n");
	printf("\t");
	printf("\t");
	printf("Input");
	printf("\t");
	printf("\t");
	printf("Cache");
	printf("\n");
	printf("\t");
	printf("\t");
	printf("-----");
	printf("\t");
	printf("\t");
	printf("-----");
	printf("\n");

	while (i < 15)
	{
		printf("\t");
		printf("%d", i);
		printf("\t");

		if (gInput[i] == NULL)
		{
			printf("-");
		}
		else
		{
			printf("%s", gInput[i]);
		}

		printf("\t");
		printf("\t");

		if (i < 10)
		{
			if (gCache[i] == NULL)
			{
				printf("-");
			}
			else
			{
				printf("%s", gCache[i]);
			}
		}

		printf("\n");
		i++;
	}
}


void ClearScreen()
{
	system("cls");
}