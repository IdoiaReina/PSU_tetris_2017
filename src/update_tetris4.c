/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** tetrimino file
*/

#include "tetris.h"

void destroy_line(int x, tetris_t **tetris)
{
	tetriminos_t *tmp = (*tetris)->l_tetrim;
	list_pos_t *l_pos;

	while (tmp->next) {
		l_pos = tmp->next->l_pos;
		while (l_pos->next) {
			if (l_pos->next->x == x)
				pop_tetrimino(&(l_pos->next));
			else
				l_pos = l_pos->next;
		}
		tmp = tmp->next;
	}
}

int piece_on_line(int x, tetriminos_t *l_tetrim)
{
	list_pos_t *tmp = l_tetrim->l_pos->next;
	int i = 0;

	while (tmp) {
		if (tmp->x == x)
			i += 1;
		tmp = tmp->next;
	}
	return (i);
}

void drop_board(tetris_t *tetris, int x)
{
	tetriminos_t *tmp = tetris->l_tetrim->next;
	list_pos_t *l_pos;

	for (int i = x - 1; i > 0; i -= 1) {
		tmp = tetris->l_tetrim->next;
		while (tmp) {
			l_pos = tmp->l_pos->next;
			while (l_pos) {
				if (l_pos->x == i)
					l_pos->x += 1;
				l_pos = l_pos->next;
			}
			tmp = tmp->next;
		}
	}
}

void check_line(tetris_t *tetris)
{
	tetriminos_t *tmp;
	int x = 0;
	int i = 0;

	while (x <= tetris->map_size[0]) {
		tmp = tetris->l_tetrim->next;
		i = 0;
		while (tmp) {
			i += piece_on_line(x, tmp);
			if (i == tetris->map_size[1] - 2) {
				tetris->score += 1;
				destroy_line(x, &tetris);
				drop_board(tetris, x);
				i = 0;
			}
			tmp = tmp->next;
		}
		x += 1;
	}
}

void display_tetriminos(tetris_t *tetris)
{
	tetriminos_t *tmp = tetris->l_tetrim->next;
	list_pos_t *l_pos;

	while (tmp->next) {
		l_pos = tmp->l_pos->next;
		while (l_pos) {
			wattron(tetris->win[0], COLOR_PAIR(tmp->c + 5));
			mvwaddch(tetris->win[0], l_pos->x, l_pos->y, '*');
			wattron(tetris->win[0], COLOR_PAIR(3));
			l_pos = l_pos->next;
		}
		tmp = tmp->next;
	}
}
