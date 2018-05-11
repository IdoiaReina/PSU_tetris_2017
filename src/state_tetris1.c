/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** state file
*/

#include "tetris.h"

void state_tetris_m_s(tetris_t *tetris, WINDOW **menu)
{
	if (tetris->state == 'm' || tetris->key == 'm')
		update_menu(tetris, menu);
	if (tetris->state == 's' || tetris->key == 's')
		update_setting(tetris, menu);
}

int state_tetris(tetris_t *tetris)
{
	WINDOW **menu;

	state_manager(tetris);
	if (tetris->state == 'g' && !(tetris->map_size[0] + 15 >= COLS	\
	|| tetris->map_size[1] + 15 >= LINES))
		game(tetris);
	else if (tetris->state == 'g')
		display_message("Resize your screen");
	state_tetris_m_s(tetris, menu);
	if (tetris->state == 'q') {
		destroy_curses(tetris);
		exit(1);
	}
	if (tetris->state == 'p')
		display_message("Pause");
	if (tetris->state == 'l')
		display_message("You lose: press R to restart");
	return (0);
}
