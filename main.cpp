#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

int main()
{
	char ch[300];
	printf("Enter one number and press ENTER for EXIT!\n");
	while (ch[1] != '\0')
	{
		scanf("%s", ch);
		printf("%d\n\n", main_calculation(ch));		
	}
	return 0;
}



