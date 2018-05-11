/*
** EPITECH PROJECT, 2018
** 1
** File description:
** 1
*/

#include "tetris.h"

void free_list(tetriminos_t **this)
{
	tetriminos_t *tmp;

	while (*this) {
		tmp = (*this)->next;
		free(*this);
		*this = tmp;
	}
}

void push_pos(list_pos_t **l_pos, int x, int y)
{
	list_pos_t *new = NULL;
	list_pos_t *tmp = *l_pos;

	new = malloc(sizeof(*new));
	if (!(new))
		return;
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (*l_pos == NULL)
		*l_pos = new;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

list_pos_t *new_list_pos(char **tetrimino)
{
	int x = 0;
	int y = 0;
	list_pos_t *l_pos = malloc(sizeof(*l_pos));

	if (l_pos == NULL)
		return (NULL);
	l_pos->next = NULL;
	while (tetrimino[x]) {
		y = 0;
		while (tetrimino[x][y]) {
			if (tetrimino[x][y] == '*')
				push_pos(&l_pos, x, y + 5);
			y += 1;
		}
		x += 1;
	}
	return (l_pos);
}

int is_activ(tetris_t *tetris)
{
	int i = 0;
	tetriminos_t *tmp = tetris->l_tetrim->next;

	while (tmp) {
		if (tmp->activ == 1)
			i += 1;
		tmp = tmp->next;
	}
	return (i);
}

void push_tetrimino(tetriminos_t **l_tetrim, list_pos_t *l_pos, int c)
{
	tetriminos_t *new = NULL;
	tetriminos_t *tmp = *l_tetrim;

	new = malloc(sizeof(*new));
	if (!(new))
		return;
	new->c = c;
	new->activ = 1;
	new->l_pos = l_pos;
	new->next = NULL;
	if (*l_tetrim == NULL)
		*l_tetrim = new;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
