/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** file_management file
*/

#include "tetris.h"

static void display_error(char *path, int num)
{
	if (num == 1)
		my_putstr("Cannot open the file : '");
	if (num == 2)
		my_putstr("Cannot read the file : '");
	if (num == 3)
		my_putstr("Cannot close the file : '");
	my_putstr(path);
	my_putchar('\n');
}

char *load_file(char *path)
{
	int fd;
	char *buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	int offset = 0;
	int len;

	if (buff == NULL)
		return (NULL);
	if ((fd = open(path, O_RDONLY)) == -1)
		display_error(path, 1);
	while ((len = read(fd, buff, BUFF_SIZE - offset)) > 0)
		offset += len;
	buff[offset] = '\0';
	if (len < 0)
		display_error(path, 2);
	if (close(fd) == -1)
		display_error(path, 3);
	return (buff);
}

int size_line(char *file, int start)
{
	int i = 0;

	while (file[start] != '\n') {
		start += 1;
		i += 1;
	}
	return (i);
}

char *cut_line(char *file, int start, char c, int nb)
{
	int j = 0;
	char *tmp = malloc(sizeof(char) * (size_line(file, start) + 1));

	while (nb > 0) {
		if (file[start] == c)
			nb -= 1;
		start += 1;
	}
	while (file[start] != c && file[start] != '\n') {
		tmp[j] = file[start];
		start += 1;
		j += 1;
	}
	tmp[j] = '\0';
	return (tmp);
}
