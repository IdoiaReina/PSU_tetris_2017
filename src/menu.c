/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** state file
*/

#include "tetris.h"

void draw_menubar(WINDOW *menubar)
{
	wmove(menubar, 0, 0);
	wbkgd(menubar, COLOR_PAIR(4));
	waddstr(menubar, "Play");
	wattron(menubar, COLOR_PAIR(2));
	waddstr(menubar, "(M)");
	wattroff(menubar, COLOR_PAIR(2));
	wmove(menubar, 0, 15);
	waddstr(menubar, "Settings");
	wattron(menubar, COLOR_PAIR(2));
	waddstr(menubar, "(S)");
	wattroff(menubar, COLOR_PAIR(2));
}

WINDOW **draw_setting(int start_col)
{
	int i = 1;
	WINDOW **items = (WINDOW **) malloc(sizeof(WINDOW *) * 3);

	items[0] = newwin(4, 19, 1, start_col);
	wbkgd(items[0], COLOR_PAIR(2));
	box(items[0], ACS_VLINE, ACS_HLINE);
	while (i < 3) {
		items[i] = subwin(items[0], 1, 17, i + 1, start_col + 1);
		i += 1;
	}
	wprintw(items[1], "Without next");
	wprintw(items[2], "Back");
	wbkgd(items[1], COLOR_PAIR(1));
	wrefresh(items[0]);
	return (items);
}

WINDOW **draw_menu(int start_col)
{
	int i = 1;
	WINDOW **items = (WINDOW **) malloc(sizeof(WINDOW *) * 4);

	items[0] = newwin(5, 19, 1, start_col);
	wbkgd(items[0], COLOR_PAIR(2));
	box(items[0], ACS_VLINE, ACS_HLINE);
	while (i < 4) {
		items[i] = subwin(items[0], 1, 17, i + 1, start_col + 1);
		i += 1;
	}
	wprintw(items[1], "Start");
	wprintw(items[2], "Settings");
	wprintw(items[3], "Exit");
	wbkgd(items[1], COLOR_PAIR(1));
	wrefresh(items[0]);
	return (items);
}

void delete_menu(WINDOW **items, int count)
{
	int i = 0;

	while (i < count)
		delwin(items[i++]);
	free(items);
}
