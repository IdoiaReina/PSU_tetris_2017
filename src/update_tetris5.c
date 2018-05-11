/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** tetrimino file
*/

#include "tetris.h"

int check_all_tetriminos(tetris_t *tetris, list_pos_t *act)
{
	tetriminos_t *tmp = tetris->l_tetrim->next;
	list_pos_t *l_pos;

	while (tmp->next) {
		l_pos = tmp->l_pos->next;
		while (l_pos) {
			if (l_pos->x == act->x && l_pos->y == act->y	\
			&& tmp->activ == 0)
				return (1);
			l_pos = l_pos->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void check_defeat(tetris_t *tetris)
{
	tetriminos_t *tmp = find_activ(tetris->l_tetrim);
	list_pos_t *l_pos = tmp->l_pos->next;

	while (l_pos) {
		if (check_all_tetriminos(tetris, l_pos) == 1)
			tetris->state = 'l';
		l_pos = l_pos->next;
	}
}

void update_game(tetris_t *tetris)
{
	int h = tetris->map_size[0];
	int w = tetris->map_size[1];

	tetris->win[0] = subwin(stdscr, h, w, 4, 6);
	wclear(tetris->win[0]);
	if (is_activ(tetris) <= 1) {
		check_line(tetris);
		new_tetrimino(tetris);
		tetris->key = 0;
	}
	else
		update_tetriminos(tetris);
	check_defeat(tetris);
	display_tetriminos(tetris);
	box(tetris->win[0], 0, 0);
	wrefresh(tetris->win[0]);
}

void display_next_tetrimino(tetris_t *tetris)
{
	int h = tetris->map_size[0];
	int w = tetris->map_size[1] + 8;
	tetriminos_t *l_tetrim = tetris->l_tetrim->next;
	list_pos_t *tmp;

	tetris->win[1] = subwin(stdscr, 7, 10, 4, w);
	wclear(tetris->win[1]);
	while (l_tetrim->next)
		l_tetrim = l_tetrim->next;
	tmp = l_tetrim->l_pos->next;
	while (tmp) {
		wattron(tetris->win[1], COLOR_PAIR(l_tetrim->c + 5));
		mvwaddch(tetris->win[1], tmp->x + 1, tmp->y - 1, '*');
		wattron(tetris->win[1], COLOR_PAIR(3));
		tmp = tmp->next;
	}
	mvwprintw(stdscr, 11, w, "Next block:");
	box(tetris->win[1], 0, 0);
	wrefresh(tetris->win[1]);
}

void display_stats(tetris_t *tetris)
{
	int h = tetris->map_size[0];
	int w = tetris->map_size[1];
	clock_t cur_time = clock();
	int s = (cur_time / 25000) % 60;
	int m = (cur_time / (25000 * 60));

	tetris->win[2] = subwin(stdscr, 10, 15, 13, 8 + w);
	wclear(tetris->win[2]);
	wattron(tetris->win[2], COLOR_PAIR(7));
	mvwprintw(tetris->win[2], 2, 1, "Score: %d\n", tetris->score);
	mvwprintw(tetris->win[2], 4, 1, "Level: %d\n", tetris->score / 10);
	mvwprintw(tetris->win[2], 6, 1, "Time: %d:%d\n", m, s);
	wattron(tetris->win[2], COLOR_PAIR(3));
	box(tetris->win[2], 0, 0);
	wrefresh(tetris->win[2]);
}
