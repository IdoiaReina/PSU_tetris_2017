/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** flags_management file
*/

#include "tetris.h"

void set_level(tetris_t *tetris)
{
	if (tetris->optarg)
		tetris->level = my_atoi(tetris->optarg);
}

void set_key_left(tetris_t *tetris)
{
	if (tetris->optarg)
		tetris->keys[0] = tetris->optarg[0];
}

void set_key_right(tetris_t *tetris)
{
	if (tetris->optarg)
		tetris->keys[1] = tetris->optarg[0];
}

void set_key_turn(tetris_t *tetris)
{
	if (tetris->optarg)
		tetris->keys[2] = tetris->optarg[0];
}

void set_key_drop(tetris_t *tetris)
{
	if (tetris->optarg)
		tetris->keys[3] = tetris->optarg[0];
}
