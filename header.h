#include <stdio.h>
#include <stdlib.h>
#ifndef HEADER_H
#define HEADER_H

struct		steck
{
	int	count;
	char	signs;
	steck*	next;
};

steck*	addsteck(int nn, steck* temp);
steck*	delsteck(steck* temp);
void	printsteck(steck* temp);
steck*	addsteck2(char ch, steck* temp);
void	printsteck2(steck* temp);
bool	sign(char ch);
char	check_ch(char ch);
int		dec(int index);
int		char_to_int(char* ch);
bool	check_num(char ch);
int		numb_long(char* ch);
int		value_prime(char ch);
bool	prime(char ch, steck* temp);
int		addition(int a, int b);
int		multiplication(int a, int b);
int		main_calculation(char* ch);
int		calculation(char ch, int a, int b);
int		modulus(int a, int b);
int		division(int a, int b);
int		subtraction(int a, int b);
//bool	brackets(char ch);
int		master_power(int a, int b);

#endif