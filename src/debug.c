/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** debug file
*/

#include "tetris.h"

void put_tetrimino_nbr(int i)
{
	my_putstr("Tetriminos : ");
	my_putnbr(i - 2);
	my_putchar('\n');
}

static int display_tetriminos_debug(void)
{
	struct dirent *read_dir;
	DIR *dir = NULL;
	int i = 0;
	char **tab = malloc(sizeof(char *) * 100);

	if ((dir = opendir("tetriminos")) == NULL)
		return (1);
	while ((read_dir = readdir(dir)) != NULL) {
		tab[i] = str_cat("tetriminos", read_dir->d_name);
		i += 1;
	}
	tab[i] = 0;
	sort_desc(tab);
	put_tetrimino_nbr(i);
	while (i > 2) {
		check_tetrimino(tab[i - 3]);
		i -= 1;
	}
	closedir(dir);
}

static void display_key(tetris_t *tetris)
{
	my_putstr("\nKey Left : ");
	display_special_char(tetris->keys[0]);
	my_putstr("\nKey Right : ");
	display_special_char(tetris->keys[1]);
	my_putstr("\nKey Turn : ");
	display_special_char(tetris->keys[2]);
	my_putstr("\nKey Drop : ");
	display_special_char(tetris->keys[3]);
	my_putstr("\nKey Quit : ");
	display_special_char(tetris->keys[4]);
	my_putstr("\nKey Pause : ");
	display_special_char(tetris->keys[5]);
	my_putchar('\n');
}

void write_debug(tetris_t *tetris)
{
	my_putstr("Next : ");
	if (tetris->without_next == 1)
		my_putstr("Yes\n");
	else
		my_putstr("No\n");
	my_putstr("Level : ");
	my_putnbr(tetris->level);
	my_putstr("\nSize : ");
	my_putnbr(tetris->map_size[0]);
	my_putchar('*');
	my_putnbr(tetris->map_size[1]);
	my_putchar('\n');
}

void display_debug(tetris_t *tetris)
{
	struct termios info;
	char buf[1];

	buf[0] = 0;
	my_putstr("*** DEBUG MODE ***");
	display_key(tetris);
	write_debug(tetris);
	display_tetriminos_debug();
	my_putstr("Press any key to start Tetris\n");
	tcgetattr(0, &info);
	info.c_lflag &= ~ICANON;
	info.c_cc[VMIN] = 1;
	info.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &info);
	while (buf[0] == 0)
		read(0, buf, sizeof(buf));
}
