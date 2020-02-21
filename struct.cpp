#include "header.h"

steck* addsteck(int nn, steck* temp)
{
	steck* p = (steck*)malloc(sizeof(steck));
	p -> count = nn;
	p -> next = temp;

	return p;
}
steck* addsteck2(char tt, steck* temp)
{
	steck* p;
	p = (steck*)malloc(sizeof(steck));
	p -> signs = tt;
	p -> next = temp;

	return p;
}

steck* delsteck(steck* temp)
{
	steck* p;
	p = temp->next;
	delete temp;
	return p;
}

void printsteck(steck* temp)
{
	while (temp)
	{
		printf("%d\n", temp->count);
		temp = temp->next;
	}
}

void printsteck2(steck* temp)
{
	while (temp)
	{
		printf("%c", temp->signs);
		printf("\n");
		temp = temp->next;
	}
}
