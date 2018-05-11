/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** flags_management file
*/

#include "tetris.h"

int find_cmd(char const *name, cmd_t *cmd)
{
	int i = 0;

	while (i < 11) {
		if (my_strcmp(name, cmd[i].l_name) == 0)
			return (i);
		i += 1;
	}
	return (-1);
}

int find_cmd_short(char name, cmd_t *cmd)
{
	int i = 0;

	while (i < 11) {
		if (name == cmd[i].s_name[0])
			return (i);
		i += 1;
	}
	return (-1);
}

void long_args_manager(char const *name, tetris_t *tetris)
{
	int index;

	if ((index = find_cmd(name, tetris->cmd)) != -1)
		tetris->cmd[index].func(tetris);
}

int flags_manager(int ac, char **av)
{
	tetris_t *tetris = init_tetris();
	int c = -1;
	int index = 0;
	int opt_indx = 0;
	char *all_opt = "L:l:r:t:d:q:p:wD";

	while (1) {
		opt_indx = 0;
		c = getopt_long(ac, av, all_opt, long_options, &opt_indx);
		tetris->optarg = optarg;
		if (c == -1)
			break;
		else if (c == 0)
			long_args_manager(long_options[opt_indx].name, tetris);
		else if ((index = find_cmd_short(c, tetris->cmd)) != -1)
			tetris->cmd[index].func(tetris);
		else if (c == '?')
			break;
		else {
			my_putstr("?? getopt returned character code 0");
			my_put_octal(c);
			my_putstr(" ??\n");
		}
	}
	if (tetris->debug == 1)
		display_debug(tetris);
	return (my_tetris(tetris));
}
