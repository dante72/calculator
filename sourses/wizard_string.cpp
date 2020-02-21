#include "header.h"

bool sign(char ch)
{
	if (ch == check_ch(ch))
		return true;
	return false;
}

/*bool brackets(char ch)
{
	if (ch == '(' || ch == ')')
		return true;
	else false;
}*/
char check_ch(char ch)
{
	char str[] = "*/+-%^";
	int i = 0;

	while (str[i] != '\0')
	{
		if (ch == str[i])
			return ch;
		i++;
	}

		return 0;
}

bool check_num(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	else 
		return false;
}

int char_to_int(char* ch)
{
	int lng, summ;
	int j;
	lng = numb_long(ch);
	//printf("%d", lng);
	j = 0;
	summ = 0;
	while (check_num(ch[j]))
	{
		summ += (ch[j] - '0') * dec(lng - j);
		//printf("%d", summ);
		//printf("\n");
		j++;
	}
	return summ;
}

int dec(int index)
{
	int i, d;

	d = 1;
	i = 0;
	while (i < index - 1)
	{
		d *= 10;
		i++;
	}
	return d;
}

int numb_long(char* ch)
{
	int i = 0;
	while (check_num(ch[i]))
		i++;
	return i;
}