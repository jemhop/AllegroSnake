#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include "Globals.h"
#include "Game.h"


void Game::initAll()
{
	checkInit(al_init(), "allegro");
	checkInit(al_install_keyboard(), "keyboard");
	checkInit(al_init_primitives_addon(), "primitives");

	timer = al_create_timer(1.0 / FRAME_RATE);
	checkInit(timer, "timer");

	queue = al_create_event_queue();
	checkInit(queue, "queue");

	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

	disp = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
	checkInit(disp, "display");

	font = al_create_builtin_font();
	checkInit(font, "font");

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(disp));
	al_register_event_source(queue, al_get_timer_event_source(timer));
}

void Game::destroyAll()
{
	al_destroy_font(font);
	al_destroy_display(disp);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
}


void Game::checkInit(bool test, const char* description)
{
	if (test) return;

	printf("Couldn't initialize %s\n", description);
	exit(1);
}

