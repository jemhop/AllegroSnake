#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include "Primitives.h"
#include "Snake.h"
#include "Globals.h"
#include "Game.h"

Snake snake = Snake();

int main()
{
    Game game = Game();
    game.initAll();

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    const int KEY_SEEN = 1;
    const int KEY_RELEASED = 2;

    unsigned char key[ALLEGRO_KEY_MAX];
    memset(key, 0, sizeof(key));
    
    al_start_timer(game.timer);

    snake.addPiece(SnakePiece(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, gridSize, gridSize, al_map_rgba(255, 50, 100, 255)));

    while (1)
    {
        al_wait_for_event(game.queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_TIMER:
        {
            if (key[ALLEGRO_KEY_UP])
                snake.changeDirection(UP);
            if (key[ALLEGRO_KEY_DOWN])
                snake.changeDirection(DOWN);
            if (key[ALLEGRO_KEY_LEFT])
                snake.changeDirection(LEFT);
            if (key[ALLEGRO_KEY_RIGHT])
                snake.changeDirection(RIGHT);
            

            if (key[ALLEGRO_KEY_ESCAPE])
                done = true;

            for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
                key[i] &= KEY_SEEN;

            redraw = true;
        }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
            break;
        case ALLEGRO_EVENT_KEY_UP:
            key[event.keyboard.keycode] &= KEY_RELEASED;
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done)
            break;

        if (redraw && al_is_event_queue_empty(game.queue))
        {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_textf(game.font, al_map_rgb(255, 255, 255), 0, 0, 0, "X: %.1f Y: %.1f", snake.x, y);

            snake.render();

            for (int x = 0; x < SCREEN_WIDTH; x += gridSize)
                al_draw_line(x, 0, x, SCREEN_HEIGHT, al_map_rgba(50,50,50,50), 1);

            for (int y = 0; y < SCREEN_HEIGHT; y += gridSize)
                al_draw_line(0, y, SCREEN_WIDTH, y, al_map_rgba(50,50,50,50), 1);

            al_flip_display();

            redraw = false;
        }

    }
    
    game.destroyAll();

    return 0;
}