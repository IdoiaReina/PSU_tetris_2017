/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** state file
*/

#include "tetris.h"

void update_menu(tetris_t *tetris, WINDOW **menu)
{
	int selected;

	menu = draw_menu(0);
	selected = scroll_menu(menu, 3, tetris);
	delete_menu(menu, 3);
	if (selected == 1) {
		tetris->state = 'g';
		werase(tetris->win[0]);
	}
	if (selected == 2)
		tetris->state = 's';
	if (selected == 3)
		tetris->state = 'q';
	touchwin(stdscr);
	refresh();
}

void update_setting(tetris_t *tetris, WINDOW **menu)
{
	int selected = 0;

	menu = draw_setting(20);
	selected = scroll_menu(menu, 2, tetris);
	delete_menu(menu, 2);
	if (selected == 1) {
		if (tetris->without_next == 0)
			tetris->without_next = 1;
		else
			tetris->without_next = 0;
	}
	if (selected == 2)
		tetris->state = 'm';
	touchwin(stdscr);
	refresh();
}

void display_message(char *msg)
{
	int len = my_strlen(msg);

	move(LINES / 2, (COLS - len) / 2);
	printw(msg);
}

void state_manager(tetris_t *tetris)
{
	if (tetris->state == 'p' && tetris->key == 'p')
		tetris->state = 'g';
	else if (tetris->state == 'g' && tetris->key == 'p')
		tetris->state = 'p';
	if (tetris->state == 'l' && tetris->key == 'r') {
		tetris->state = 'g';
		tetris->score = 0;
		free_list(&(tetris->l_tetrim));
		tetris->l_tetrim = malloc(sizeof(*(tetris->l_tetrim)));
		if (tetris->l_tetrim == NULL)
			return;
	}
}
