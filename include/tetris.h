/*
** EPITECH PROJECT, 2018
** tetris.h
** File description:
** header files
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <curses.h>
#include <fcntl.h>
#include <getopt.h>
#include <dirent.h>
#include <time.h>
#include "termios.h"

#define BUFF_SIZE 100
#define ESCAPE 27
#define	ENTER 10
#define TICKRATE 100
#define DIFFICULTY 20000

enum {LEFT, RIGHT, TURN, DROP, QUIT, PAUSE};

static struct option long_options[] = {
	{"help",         no_argument,       0,  0 },
	{"level",        required_argument, 0,  0 },
	{"key-left",     required_argument, 0,  0 },
	{"key-right",    required_argument, 0,  0 },
	{"key-turn",     required_argument, 0,  0 },
	{"key-drop",     required_argument, 0,  0 },
	{"key-quit",     required_argument, 0,  0 },
	{"key-pause",    required_argument, 0,  0 },
	{"map-size",     required_argument, 0,  0 },
	{"without-next", no_argument,       0,  0 },
	{"debug",        no_argument,       0,  0 },
	{0,              0,                 0,  0 }
};

struct tetris_s;

typedef struct list_pos_s {
	int x;
	int y;
	struct list_pos_s *next;
} list_pos_t;

typedef struct tetriminos_s {
	int c;
	int activ;
	list_pos_t *l_pos;
	struct tetriminos_s *next;
} tetriminos_t;

typedef struct cmd_s {
	char *l_name;
	char *s_name;
	void (*func)(struct tetris_s *);
} cmd_t;

typedef struct tetris_s {
	WINDOW *win[3];
	int key;
	int level;
	int map_size[2];
	int without_next;
	int debug;
	int nb_tetri;
	int score;
	char state;
	int keys[6];
	char *optarg;
	char ***tetrim;
	tetriminos_t *l_tetrim;
	cmd_t cmd[11];
	clock_t etime;
} tetris_t;

tetris_t *init_tetris();
int init_tetriminos(tetris_t *this);
void init_curses();
int destroy_curses(tetris_t *);
int flags_manager(int , char **);
void free_list(tetriminos_t **);

int my_tetris(tetris_t *);
int state_tetris(tetris_t *);
void state_manager(tetris_t *tetris);
void display_message(char *msg);
void update_setting(tetris_t *tetris, WINDOW **menu);
void update_menu(tetris_t *tetris, WINDOW **menu);
void update_tetris(tetris_t *);
void game(tetris_t *);

/***Update Tetris***/
void free_list(tetriminos_t **this);
void push_pos(list_pos_t **l_pos, int x, int y);
list_pos_t *new_list_pos(char **tetrimino);
int is_activ(tetris_t *tetris);
void push_tetrimino(tetriminos_t **l_tetrim, list_pos_t *l_pos, int c);
void new_tetrimino(tetris_t *tetris);
int is_obstacle(tetriminos_t *this, int x, int y, tetris_t *tetris);
void move_left(tetriminos_t *l_tetrim, tetris_t *tetris);
void move_right(tetriminos_t *l_tetrim, tetris_t *tetris);
void drop(tetriminos_t *l_tetrim, tetris_t *tetris);
void rotate(tetriminos_t *l_tetrim, tetris_t *tetris);
tetriminos_t *find_activ(tetriminos_t *l_tetrim);
void update_tetriminos(tetris_t *tetris);
void pop_tetrimino(list_pos_t **this);
void destroy_line(int x, tetris_t **tetris);
int piece_on_line(int x, tetriminos_t *l_tetrim);
void drop_board(tetris_t *tetris, int x);
void check_line(tetris_t *tetris);
void display_tetriminos(tetris_t *tetris);
int check_all_tetriminos(tetris_t *tetris, list_pos_t *act);
void check_defeat(tetris_t *tetris);
void update_game(tetris_t *tetris);
void display_next_tetrimino(tetris_t *tetris);
void display_stats(tetris_t *tetris);

/*** Tetriminos ***/
char *cut_filename(char *);
int check_size_color(char *);
int check_tetrimino(char *);
void display_debug(tetris_t *);
void debug(void);
int check_extension(char *name, char *ext);

/*** flags functions ***/
void display_help(tetris_t *);
void set_level(tetris_t *);
void set_key_left(tetris_t *);
void set_key_right(tetris_t *);
void set_key_turn(tetris_t *);
void set_key_drop(tetris_t *);
void set_key_quit(tetris_t *);
void set_key_pause(tetris_t *);
void set_map_size(tetris_t *);
void set_without_next(tetris_t *);
void set_debug_mode(tetris_t *);

/*Set Keys*/
void set_level(tetris_t *tetris);
void set_key_left(tetris_t *tetris);
void set_key_right(tetris_t *tetris);
void set_key_turn(tetris_t *tetris);
void set_key_drop(tetris_t *tetris);

/*** Debug ***/
void display_special_char(int c);
void sort_desc(char **tab);
void swap_sort(char **tab, int i, int j);
void display_debug(tetris_t *tetris);

/*** Menu ***/
void draw_menubar(WINDOW *);
WINDOW **draw_setting(int);
WINDOW **draw_menu(int);
void delete_menu(WINDOW **, int);
int scroll_menu(WINDOW **, int, tetris_t *);

/*** File ***/
char *cut_line(char *, int, char, int);
char *load_file(char *);

void sort_desc(char **);

/*** SRC ***/
int my_putstr(char *);
void my_putchar(char);
int my_atoi(char *);
int my_strlen(char *);
int my_strcmp(char const *, char const *);
int is_num(char *);
void my_putnbr(int);
char *str_cat(char *, char *);
void    my_put_octal(unsigned int nb);
char *my_revstr(char *str);

#endif /* TETRIS_H_ */
