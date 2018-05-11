/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** flags_management file
*/

#include "tetris.h"

void set_key_quit(tetris_t *tetris)
{
	if (tetris->optarg)
		tetris->keys[4] = tetris->optarg[0];
}

void set_key_pause(tetris_t *tetris)
{
	if (tetris->optarg)
		tetris->keys[5] = tetris->optarg[0];
}

void set_without_next(tetris_t *tetris)
{
	tetris->without_next = 1;
}

void set_debug_mode(tetris_t *tetris)
{
	tetris->debug = 1;
}
