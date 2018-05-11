/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** src file
*/

#include "tetris.h"

int is_num(char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i += 1;
	}
	return (1);
}

void my_putnbr(int nb)
{
	if (nb < 0){
		nb *= -1;
		my_putchar('-');
	}
	if (nb > 9)
		my_putnbr(nb / 10);
	my_putchar(nb % 10 + '0');
}

char *malloc_dest_str_cat(char *s1, char *s2)
{
	char *dest;
	int i = 0;
	int j = 0;

	while (s1[i])
		i += 1;
	while (s2[j])
		j += 1;
	dest = malloc(sizeof(char *) * (i + j + 4));
	return (dest);
}

char *str_cat(char *s1, char *s2)
{
	char *dest = malloc_dest_str_cat(s1, s2);
	int i = 0;
	int j = 0;

	while (s1[i]) {
		dest[i] = s1[i];
		i += 1;
	}
	if (dest[i - 1] != '/')
		dest[i++] = '/';
	while (s2[j]) {
		dest[i + j] = s2[j];
		j += 1;
	}
	dest[i + j] = '\0';
	return (dest);
}
