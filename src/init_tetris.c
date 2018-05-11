/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** flags_management file
*/

#include "tetris.h"

void new_cmd(cmd_t *this, char *l_name, char *s_name, void (*func)(tetris_t *))
{
	this->l_name = l_name;
	this->s_name = s_name;
	this->func = func;
}

void init_cmd(cmd_t *this)
{
	new_cmd(&this[0], "help", "h", &display_help);
	new_cmd(&this[1], "level", "L", &set_level);
	new_cmd(&this[2], "key-left", "l", &set_key_left);
	new_cmd(&this[3], "key-right", "r", &set_key_right);
	new_cmd(&this[4], "key-turn", "t", &set_key_turn);
	new_cmd(&this[5], "key-drop", "d", &set_key_drop);
	new_cmd(&this[6], "key-quit", "q", &set_key_quit);
	new_cmd(&this[7], "key-pause", "p", &set_key_pause);
	new_cmd(&this[8], "map-size", "m", &set_map_size);
	new_cmd(&this[9], "without_next", "w", &set_without_next);
	new_cmd(&this[10], "debug", "D", &set_debug_mode);
}

void init_keys(tetris_t *this)
{
	this->keys[0] = KEY_LEFT;
	this->keys[1] = KEY_RIGHT;
	this->keys[2] = KEY_UP;
	this->keys[3] = KEY_DOWN;
	this->keys[4] = 'q';
	this->keys[5] = 'p';
}

tetris_t *init_tetris(void)
{
	tetris_t *this = malloc(sizeof(*this));

	if (this == NULL)
		return (NULL);
	init_cmd(this->cmd);
	init_keys(this);
	init_tetriminos(this);
	this->level = 1;
	this->map_size[0] = 20 + 2;
	this->map_size[1] = 10 + 2;
	this->without_next = 1;
	this->debug = 0;
	this->optarg = NULL;
	this->state = 'm';
	this->l_tetrim = malloc(sizeof(*(this->l_tetrim)));
	if (this->l_tetrim == NULL)
		return (NULL);
	this->l_tetrim->next = NULL;
	return (this);
}
