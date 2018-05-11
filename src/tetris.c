/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** tetrimino file
*/

#include "tetris.h"

void init_color_type(void)
{
	start_color();
	init_color(COLOR_WHITE, 900, 900, 900);
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_GREEN);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_BLACK);
	init_pair(9, COLOR_BLUE, COLOR_BLACK);
	init_pair(10, COLOR_CYAN, COLOR_BLACK);
	bkgd(COLOR_PAIR(3));
}

void init_curses(void)
{
	initscr();
	timeout(TICKRATE);
	keypad(stdscr, TRUE);
	leaveok(stdscr, FALSE);
	raw();
	noecho();
	curs_set(0);
	init_color_type();
}

int destroy_curses(tetris_t *tetris)
{
	for (int i = 0; i < 3; i += 1)
		delwin(tetris->win[i]);
	noraw();
	echo();
	endwin();
	return (0);
}

int my_tetris(tetris_t *tetris)
{
	WINDOW *menubar;
	int len = my_strlen("Resize your screen");

	init_curses();
	menubar = subwin(stdscr, 1, COLS, 0, 0);
	while ((tetris->key = getch()) != tetris->keys[QUIT]) {
		clear();
		draw_menubar(menubar);
		refresh();
		state_tetris(tetris);
	}
	return (destroy_curses(tetris));
}
