/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** tetrimino file
*/

#include "tetris.h"

int check_name(char *name)
{
	int i = 0;

	while (name[i] != '.' && name[i] != '\0')
		i += 1;
	return (i);
}

int check_extension(char *name, char *ext)
{
	int i = 0;
	int j = 0;
	char *tmp = malloc(sizeof(char) * my_strlen(name));

	if (tmp == NULL)
		return (0);
	i = check_name(name);
	if (i >= my_strlen(name))
		return (0);
	i += 1;
	while (name[i]) {
		tmp[j] = name[i];
		j += 1;
		i += 1;
	}
	tmp[j] = '\0';
	if (my_strcmp(ext, tmp) == 0)
		return (1);
	free(tmp);
	return (0);
}
