/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** tetrimino file
*/

#include "tetris.h"

void new_tetrimino(tetris_t *tetris)
{
	int r = 0;
	list_pos_t *tmp = NULL;

	srand(time(NULL));
	r = rand() % tetris->nb_tetri;
	tmp = new_list_pos(tetris->tetrim[r]);
	push_tetrimino(&(tetris->l_tetrim), tmp, r);
}

int is_obstacle(tetriminos_t *this, int x, int y, tetris_t *tetris)
{
	list_pos_t *tmp = this->l_pos->next;
	list_pos_t *tpp;
	tetriminos_t *l_tetrim;

	while (tmp) {
		if (tmp->x + x + 1 >= tetris->map_size[0]) {
			this->activ = 0;
			return (1);
		}
		if (tmp->y + y + 1 >= tetris->map_size[1] || tmp->y + y <= 0)
			return (1);
		l_tetrim = tetris->l_tetrim->next;
		while (l_tetrim->activ == 0) {
			tpp = l_tetrim->l_pos->next;
			while (tpp) {
				if (tpp->x == tmp->x + x && tpp->y == tmp->y) {
					this->activ = 0;
					return (1);
				}
				if (tpp->y == tmp->y + y && tpp->x == tmp->x)
					return (1);
				tpp = tpp->next;
			}
			l_tetrim = l_tetrim->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void move_left(tetriminos_t *l_tetrim, tetris_t *tetris)
{
	list_pos_t *tmp = l_tetrim->l_pos->next;

	if (!is_obstacle(l_tetrim, 0, -1, tetris)) {
		while (tmp) {
			tmp->y -= 1;
			tmp = tmp->next;
		}
	}
}

void move_right(tetriminos_t *l_tetrim, tetris_t *tetris)
{
	list_pos_t *tmp = l_tetrim->l_pos->next;

	if (!is_obstacle(l_tetrim, 0, 1, tetris)) {
		while (tmp) {
			tmp->y += 1;
			tmp = tmp->next;
		}
	}
}

void drop(tetriminos_t *l_tetrim, tetris_t *tetris)
{
	list_pos_t *tmp = l_tetrim->l_pos->next;

	if (!is_obstacle(l_tetrim, 1, 0, tetris)) {
		while (tmp) {
			tmp->x += 1;
			tmp = tmp->next;
		}
	}
}
