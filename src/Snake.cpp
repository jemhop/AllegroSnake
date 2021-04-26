#include "Primitives.h"
#include "Snake.h"
#include "Globals.h"


SnakePiece::SnakePiece(double xIn, double yIn, double widthIn, double heightIn, ALLEGRO_COLOR colorIn)
{
	x = xIn;
	y = yIn;
	width = widthIn;
	height = heightIn;
	color = colorIn;
}

void SnakePiece::Render()
{
	al_draw_filled_rectangle(x, y, x + width, y + height, color);
}


void Snake::addPiece(SnakePiece newPiece)
{
	snakeParts.push_back(newPiece);
}

void Snake::moveSnake(int gridSize)
{
	//copy last piece
	SnakePiece temp = snakeParts[snakeParts.size() - 1];
	//remove last piece
	snakeParts.pop_back();
	//change its direction
	temp.direction = snakeParts[0].direction;

	if (temp.direction == UP)
		temp.y = snakeParts[0].y - gridSize;
	if (temp.direction == DOWN)
		temp.y = snakeParts[0].y + gridSize;
	if (temp.direction == LEFT)
		temp.x = snakeParts[0].x - gridSize;
	if (temp.direction == RIGHT)
		temp.x = snakeParts[0].x + gridSize;

	//add to the front
	snakeParts.insert(snakeParts.begin(), temp);
}

Snake::Snake() {

}

void Snake::changeDirection(int direction)
{
	snakeParts[0].direction = direction;
}

void Snake::render()
{
	for (size_t i = 0; i < snakeParts.size(); i++)
	{
		snakeParts[0].Render();
	}
}