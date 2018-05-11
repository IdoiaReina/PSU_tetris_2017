/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** flags_management file
*/

#include "tetris.h"

void set_size(tetris_t *tetris, char *str)
{
	if (str[0] != '\0' && my_atoi(str) > 0)
		tetris->map_size[1] = my_atoi(str) + 2;
}

void set_map_size(tetris_t *tetris)
{
	int i = 0;
	int j = 0;
	int len = my_strlen(tetris->optarg) + 2;
	char *str = malloc(sizeof(char) * len);

	while (tetris->optarg[i] != ',' && tetris->optarg[i]) {
		str[i] = tetris->optarg[i];
		i += 1;
	}
	str[i] = '\0';
	if (str[0] != '\0' && my_atoi(str) > 0)
		tetris->map_size[0] = my_atoi(str) + 2;
	while (tetris->optarg[i] != '\0') {
		i += 1;
		str[j] = tetris->optarg[i];
		j += 1;
	}
	str[j] = '\0';
	set_size(tetris, str);
	free(str);
}
