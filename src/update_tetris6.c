/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** tetrimino file
*/

#include "tetris.h"

void game(tetris_t *tetris)
{
	update_game(tetris);
	if (tetris->without_next == 1)
		display_next_tetrimino(tetris);
	display_stats(tetris);
}