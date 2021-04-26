#include "Primitives.h"

void drawRect(double x, double y, double width, double height, bool filled, ALLEGRO_COLOR color, int lineWidth)
{
	if (filled)
		al_draw_filled_rectangle(x, y, x + width, y + height, color);
	else
		al_draw_rectangle(x, y, x + width, y + height, color, lineWidth);
}