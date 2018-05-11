/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** tetrimino file
*/

#include "tetris.h"

char *cut_filename(char *name)
{
	int i = 1;
	int j = 0;
	char *cut = malloc(sizeof(char) * my_strlen(name));

	if (cut == NULL || !(check_extension(name, "tetrimino")))
		return (NULL);
	while (name[i - 1] != '/')
		i += 1;
	while (name[i] != '.') {
		cut[j] = name[i];
		i += 1;
		j += 1;
	}
	if (i - j == 0)
		return (NULL);
	cut[j] = '\0';
	return (cut);
}

int check_size_color(char *file)
{
	char *tmp;

	for (int i = 0; i < 3; i += 1) {
		tmp = cut_line(file, 0, ' ', i);
		if (!is_num(tmp))
			return (0);
		free(tmp);
	}
	return (1);
}

int display_tetrimino(char *file)
{
	int i = 0;

	while (file[i] != '\n')
		i += 1;
	while (file[i]) {
		if (file[i] != '*' && file[i] != ' ' && file[i] != '\n')
			return (0);
		my_putchar(file[i]);
		i += 1;
	}
	return (1);
}

int check_tetrimino(char *filename)
{
	char *file = load_file(filename);
	char *name;

	if ((name = cut_filename(filename)) == NULL)
		return (1 + my_putstr("Error\n"));
	my_putstr("Tetriminos : Name ");
	my_putstr(name);
	free(name);
	if (!check_size_color(file))
		return (1 + my_putstr(" : Error\n"));
	my_putstr(" : Size ");
	my_putstr(cut_line(file, 0, ' ', 0));
	my_putchar('*');
	my_putstr(cut_line(file, 0, ' ', 1));
	my_putstr(" : Color ");
	my_putstr(cut_line(file, 0, ' ', 2));
	my_putstr(" : ");
	if (!display_tetrimino(file))
		return (1 + my_putstr("Error\n"));
	return (0);
}
