/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** src file
*/

#include "tetris.h"

int my_putstr(char *str)
{
	int i = 0;

	while (str[i]) {
		my_putchar(str[i]);
		i += 1;
	}
	return (0);
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_atoi(char *str)
{
	int i = 0;
	int ret = 0;

	while (str[i]) {
		ret = (10 * ret) + str[i] - '0';
		i += 1;
	}
	return (ret);
}

int my_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i += 1;
	return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	while (s1[i] && s1[i] == s2[i])
		i += 1;
	return (s1[i] - s2[i]);
}
