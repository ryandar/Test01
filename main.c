#include "stdio.h"
#include "stdlib.h"

struct cache_item
{
	char* name;
	int time_to_live;
};

typedef enum { false, true } bool;

char* gInput[100];
int gInputIndex = 0;

struct cache_item* gCacheItems[10];

bool EnterName();
void Display();
void ClearScreen();

void AddCacheItem(char* name)
{
	int index = GetCacheIndex(name);
	int available_index;

	if (index == -1)
	{
		available_index = GetAvailableIndex();
		if (available_index == -1)
		{
			return;
		}
		
		gCacheItems[available_index] = malloc(sizeof(struct cache_item));

		gCacheItems[available_index]->name = name;
		gCacheItems[available_index]->time_to_live = 30;
		
		return;
	}

	gCacheItems[index]->time_to_live = 30;
}

int GetAvailableIndex()
{
	int count = sizeof(gCacheItems)/sizeof(gCacheItems[0]);
	int i;

	for (i=0; i<count; i++)
	{
		if (gCacheItems[i] == NULL)
		{
			return i;
		}
	}

	return -1;
}

int GetCacheIndex(char* name)
{
	int count = sizeof(gCacheItems)/sizeof(gCacheItems[0]);
	int i;

	for (i=0; i<count; i++)
	{
		if (gCacheItems[i] != NULL && strcmp(gCacheItems[i]->name, name) == 0)
		{
			return i;
		}
	}

	return -1;
}

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
	
	AddCacheItem(name);

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
			if (gCacheItems[i] == NULL)
			{
				printf("-");
			}
			else
			{
				printf("%s ", gCacheItems[i]->name);
				printf("(%d)", gCacheItems[i]->time_to_live);
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