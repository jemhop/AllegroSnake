#include "Globals.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <string.h>
#include <algorithm>
#include "Grid.h"

Grid::Grid(int gridSizeIn)
{
	gridSize = gridSizeIn;
}

void Grid::setGridPos(int x, int y, int value)
{
	grid[y][x] = value;
}

void Grid::getGridPos(int x, int y, int value)
{
	grid[y][x] = value;
}

void Grid::render()
{
	for (int x = 0; x < SCREEN_WIDTH; x += gridSize)
		al_draw_line(x, 0, x, SCREEN_HEIGHT, al_map_rgba(50, 50, 50, 50), 1);

	for (int y = 0; y < SCREEN_HEIGHT; y += gridSize)
		al_draw_line(0, y, SCREEN_WIDTH, y, al_map_rgba(50, 50, 50, 50), 1);
}