/*
** EPITECH PROJECT, 2017
** octal
** File description:
** octal
*/

#include "tetris.h"
#include <stdarg.h>
#include <stdlib.h>

void	my_put_octal(unsigned int nb)
{
	char *modulo = malloc(sizeof(char) * 12);
	int i = 0;

	modulo[i] = nb % 8 + 48;
	i += 1;
	while (nb > 7) {
		nb = nb / 8;
		modulo[i] = nb % 8 + 48;
		i += 1;
	}
	my_revstr(modulo);
	my_putstr(modulo);
}
