/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** tetrimino file
*/

#include "tetris.h"

void rotate(tetriminos_t *l_tetrim, tetris_t *tetris)
{
	list_pos_t *tmp = l_tetrim->l_pos->next;
	int x = tmp->x - 1;
	int y = tmp->y - 1;
	int r;

	tmp = tmp->next;
	while (tmp) {
		r = tmp->y;
		tmp->y = tmp->x + y - x;
		tmp->x = x + y - r + 2;
		tmp = tmp->next;
	}
}

tetriminos_t *find_activ(tetriminos_t *l_tetrim)
{
	tetriminos_t *tmp = l_tetrim->next;

	while (tmp) {
		if (tmp->activ == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void update_tetriminos(tetris_t *tetris)
{
	tetriminos_t *tmp = find_activ(tetris->l_tetrim);
	clock_t cur_time = clock();

	if (tetris->key == tetris->keys[LEFT])
		move_left(tmp, tetris);
	if (tetris->key == tetris->keys[RIGHT])
		move_right(tmp, tetris);
	if (tetris->key == tetris->keys[DROP]) {
		drop(tmp, tetris);
		tetris->etime = cur_time;
	}
	if (tetris->key == tetris->keys[TURN])
		rotate(tmp, tetris);
	if (cur_time - tetris->etime > (DIFFICULTY - 500 * tetris->score)) {
		drop(tmp, tetris);
		tetris->etime = cur_time;
	}
}

void pop_tetrimino(list_pos_t **this)
{
	list_pos_t *tmp;

	tmp = (*this)->next;
	free(*this);
	*this = tmp;
}
