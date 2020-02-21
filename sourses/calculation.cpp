#include "header.h"

bool prime(char ch, steck* temp)
{
	if (temp == NULL)
		return true;
	if (value_prime(ch) > value_prime(temp->signs))
		return true;
	else
		return false;
}

int value_prime(char ch)
{
	int index = -1;

	if (ch == '+' || ch == '-')
		index = 1;
	if (ch == '*' || ch == '/'|| ch == '%')
		index = 2;
	if (ch == '^')
		index = 3;
	return index;
}

int addition(int a, int b)
{
	return a + b;
}

int multiplication(int a, int b)
{
	return a * b;
}

int subtraction(int a, int b)
{
	return a - b;
}
int division(int a, int b)
{
	return a / b;
}
int modulus(int a, int b)
{
	return a % b;
}

int master_power(int a, int b)
{
	int i, z;
	i = 0;
	z = 1;
	while (i < b)
	{
		z *= a;
		i++;
	}
	return z;
}
int calculation(char ch, int a, int b)
{
	int result;

	if (ch == '+')
		result = addition(a, b);
	if(ch == '*')
		result = multiplication(a, b);
	if (ch == '-')
		result = subtraction(a, b);
	if (ch == '/')
		result = division(a, b);
	if (ch == '%')
		result = modulus(a, b);
	if (ch == '^')
		result = master_power(a, b);

	return result;
}
int main_calculation(char* ch)
{
	steck* temp = NULL, * chr = NULL;
	int result;

	int i = 0;
	while (ch[i] != '\0')
	{

		if (i == 0 && ch[i] == '-' || ch[i] == '-' && (sign(ch[i - 1])||ch[i - 1] == '('))
		{
			temp = addsteck(-1, temp);
			chr = addsteck2('*', chr);
			i++;
		}

		if (check_num(ch[i]))
		{	
			int g = char_to_int(&ch[i]);
			temp = addsteck(g, temp);
			i += numb_long(&ch[i]) - 1;
		}

		if (sign(ch[i]))
		{
			while (!prime(ch[i], chr))
			{
				///
				result = calculation(chr->signs, temp->next->count, temp->count);
				temp = delsteck(temp);
				temp->count = result;
				chr = delsteck(chr);
				///
			}
			chr = addsteck2(ch[i], chr);

		}
		if (ch[i] == '(')
			chr = addsteck2(ch[i], chr);

		if (ch[i] == ')')
		{
			while (chr->signs != '(')
			{
				///
				result = calculation(chr->signs, temp->next->count, temp->count);
				temp = delsteck(temp);
				temp->count = result;
				chr = delsteck(chr);
				///
			}
			chr = delsteck(chr);
		}
		i++;

	}		
	while (chr)
	{
		///
		result = calculation(chr->signs, temp->next->count, temp->count);
		temp = delsteck(temp);
		temp->count = result;
		chr = delsteck(chr);
		///
	}

	return temp->count;
}