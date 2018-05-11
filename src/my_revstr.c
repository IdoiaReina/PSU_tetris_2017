/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** Day06/Task03
*/

#include "tetris.h"

char	*my_revstr(char *str)
{
	int i = 0;
	int j = 0;
	char temp;

	while (str[i] != '\0') {
		i = i + 1;
	}
	i = i - 1;
	while (j < i) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i = i - 1;
		j = j + 1;
	}
	return (str);
}
