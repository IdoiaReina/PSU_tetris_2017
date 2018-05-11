/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** flags_management file
*/

#include "tetris.h"

int init_load_tetrimino(tetris_t *this, char *file, char *filename, int i)
{
	if (cut_filename(filename) == NULL || !check_size_color(file))
		return (1);
	while (file[i] != '\n' && file[i] != '\0')
		i += 1;
	return (i);
}

int malloc_new_line_tetrimino(tetris_t *this, int j, int x, int y)
{
	this->tetrim[j][x] = malloc(sizeof(char) * 10);
	this->tetrim[j][x][y] = '\0';
	y = 0;
	return (y);
}

int load_tetrimino(tetris_t *this, int j, char *filename)
{
	int x = 0;
	int y = 0;
	char *file = load_file(filename);
	int i = 0;

	if (cut_filename(filename) == NULL || !check_size_color(file))
		return (1);
	while (file[i] != '\n' && file[i] != '\0')
		i += 1;
	this->tetrim[j] = malloc(sizeof(char *) * 10);
	this->tetrim[j][x] = malloc(sizeof(char) * 10);
	while (file[i]) {
		if (file[i] != '*' && file[i] != ' ' && file[i] != '\n')
			return (1);
		if (file[i] == '\n') {
			x += 1;
			y = malloc_new_line_tetrimino(this, j, x, y);
		}
		if (file[i] == '*' || file[i] == ' ') {
			this->tetrim[j][x][y] = file[i];
			y += 1;
		}
		i += 1;
	}
	this->tetrim[j][x] = 0;
}

int call_load_tetrimino(tetris_t *this, int j, int i, char **tab)
{
	while (i > 2) {
		if (load_tetrimino(this, j, tab[i - 3]) != 1)
			j += 1;
		i -= 1;
	}
	return (j);
}

int init_tetriminos(tetris_t *this)
{
	struct dirent *read_dir;
	DIR *dir = NULL;
	int i = 0;
	int j = 0;
	char **tab = malloc(sizeof(char *) * 100);

	this->tetrim = malloc(sizeof(char *) * 100);
	if ((dir = opendir("tetriminos")) == NULL)
		return (1);
	while ((read_dir = readdir(dir)) != NULL) {
		tab[i] = str_cat("tetriminos", read_dir->d_name);
		i += 1;
	}
	tab[i] = 0;
	sort_desc(tab);
	j = call_load_tetrimino(this, j, i, tab);
	closedir(dir);
	this->nb_tetri = j;
}
