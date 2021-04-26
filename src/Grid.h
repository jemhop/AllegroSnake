#pragma once
class Grid {
private:
	int grid[SCREEN_HEIGHT / gridSize][SCREEN_WIDTH / gridSize]{};
	int gridSize;
public:

	Grid(int gridSizeIn);

	void setGridPos(int x, int y, int value);

	void getGridPos(int x, int y, int value);

	void render();


protected:





};