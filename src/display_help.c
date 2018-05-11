/*
** EPITECH PROJECT, 2018
** TETRIS
** File description:
** flags_management file
*/

#include "tetris.h"

void display_help(tetris_t *this)
{
	my_putstr("Usage: ./tetris [options]\nOptions:\n");
	my_putstr("  --help\t\tDisplay this help\n");
	my_putstr("  -L --level={num}\tStart Tetris at level num (def: 1)\n");
	my_putstr("  -l --key-left={K}\tMove the tetrimino LEFT using the K ");
	my_putstr("key (def: left arrow)\n");
	my_putstr("  -r --key-right={K}\tMove the tetrimino RIGHT using the ");
	my_putstr("K key (def: right arrow)\n");
	my_putstr("  -t --key-turn={K}\tTURN the tetrimino clockwise 90d ");
	my_putstr("using the K key (def: top arrow)\n");
	my_putstr("  -d --key-drop={K}\tDROP the tetrimino using the K key");
	my_putstr(" (def: down arrow)\n");
	my_putstr("  -q --key-quit={K}\tQUIT the game using the K key (def:");
	my_putstr(" ‘q’ key)\n");
	my_putstr("  -p --key-pause={K}\tPAUSE/RESTART the game using the ");
	my_putstr("K key (def: space bar)\n");
	my_putstr("  --map-size={row,col}\tSet the numbers of rows and");
	my_putstr(" columns of the map (def: 20,10)\n");
	my_putstr("  -w --without-next\tHide next tetrimino (def: false)\n");
	my_putstr("  -D --debug\t\tDebug mode (def: false)\n");
	exit(0);
}
