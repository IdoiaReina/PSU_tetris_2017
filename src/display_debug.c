/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** debug file
*/

#include "tetris.h"

void swap_sort(char **tab, int i, int j)
{
	char *tmp;

	while (tab[i][j]) {
		if (tab[i][j] == tab[i + 1][j])
			j += 1;
		else if (tab[i][j] < tab[i + 1][j]) {
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			break;
		}
		else
			break;
	}
}

void sort_desc(char **tab)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (tab[k + 1] != 0) {
		i = 0;
		while (tab[i + 1] != 0) {
			j = 0;
			swap_sort(tab, i, j);
			i += 1;
		}
		k += 1;
	}
}
