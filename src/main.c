/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** main file
*/

#include "tetris.h"

int main(int ac, char **av)
{
	if (ac < 1)
		return (84);
	return (flags_manager(ac, av));
}
