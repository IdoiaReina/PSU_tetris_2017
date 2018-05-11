/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** debug file
*/

#include "tetris.h"

void display_special_char(int c)
{
	if (c == ' ')
		my_putstr("(space)");
	else if (c == KEY_LEFT)
		my_putstr("^EOD");
	else if (c == KEY_RIGHT)
		my_putstr("^EOC");
	else if (c == KEY_UP)
		my_putstr("^EOA");
	else if (c == KEY_DOWN)
		my_putstr("^EOB");
	else
		my_putchar(c);
}
