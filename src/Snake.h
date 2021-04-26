#pragma once
#include <vector>

class SnakePiece {
private:
	bool isHead = false;
public:
	double x, y, width, height;
	ALLEGRO_COLOR color;
	//used for managing and tracking the direction of travel of the snake part, defaulted to -1, meaning no direction (static)
	int direction = -1;

	SnakePiece(double xIn, double yIn, double widthIn, double heightIn, ALLEGRO_COLOR colorIn);

	void Render();
};

class Snake {
private:
	std::vector<SnakePiece> snakeParts;


public:
	int snakeLength = snakeParts.size();

	void addPiece(SnakePiece newPiece);

	void moveSnake(int gridSize);

	void changeDirection(int direction);

	void render();

	Snake();
};

