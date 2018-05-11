/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** state file
*/

#include "tetris.h"

void scroll_menu_items(WINDOW **items, tetris_t *tet, int count, int selected)
{
	wbkgd(items[selected + 1], COLOR_PAIR(1));
	wnoutrefresh(items[selected + 1]);
	doupdate();
}

int scroll_menu(WINDOW **items, int count, tetris_t *tetris)
{
	int key;
	int selected = 0;

	while (1) {
		key = getch();
		if (key == KEY_DOWN || key == KEY_UP) {
			wbkgd(items[selected + 1], COLOR_PAIR(2));
			wnoutrefresh(items[selected + 1]);
			if (key == KEY_DOWN)
				selected = (selected + 1) % count;
			else
				selected = (selected + count - 1) % count;
			scroll_menu_items(items, tetris, count, selected);
		}
		else if (key == ESCAPE)
			return (1);
		else if (key == ENTER)
			return (selected + 1);
	}
}
