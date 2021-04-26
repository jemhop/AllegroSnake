#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>


void drawRect(double x, double y, double width, double height, bool filled = true, ALLEGRO_COLOR color = al_map_rgba(255,255,255,255), int lineWidth = 1);