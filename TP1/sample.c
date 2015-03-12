#include <stdlib.h>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

#define SQUARE_SIZE 10
#define DEAD 0
#define ALIVE 1
#define SPACE 1
#define M 50
#define N 50
#define HEIGHT 630
#define WIDTH 630

void show_matrix(ALLEGRO_DISPLAY *display, int grid[M][N])
{
    int i, j;
    ALLEGRO_BITMAP *square_alive = al_create_bitmap(SQUARE_SIZE, SQUARE_SIZE),
                    *square_dead = al_create_bitmap(SQUARE_SIZE, SQUARE_SIZE);

    al_set_target_bitmap(square_alive);
    al_clear_to_color(al_map_rgb(219,147,112));
    al_set_target_bitmap(square_dead);
    al_clear_to_color(al_map_rgb(163,163,163));

    al_set_target_bitmap(al_get_backbuffer(display));

    for(i = 0; i < M; i++ )   {
        for(j = 0; j < N; j++)   {
            if(grid[i][j] == ALIVE)
                al_draw_bitmap(square_alive, i*SQUARE_SIZE+i*SPACE, j*SQUARE_SIZE+j*SPACE, 0);
            else
                al_draw_bitmap(square_dead, i*SQUARE_SIZE+i*SPACE, j*SQUARE_SIZE+j*SPACE, 0);
        }
    }

    al_destroy_bitmap(square_alive);
    al_destroy_bitmap(square_dead);

}

void initialize_matrix(int grid[M][N])
{
    int i, j;
    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++)
            grid[i][j] = (rand() %4) <= 1? ALIVE: DEAD;

}



int main(int argc, char **argv)
{

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;

    int grid[M][N];

    srand(time(NULL));
    initialize_matrix(grid);


    if(!al_init())     {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
                                   NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    if(!al_init_image_addon())     {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
                                   NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    display = al_create_display(HEIGHT, WIDTH);

    if(!display)     {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                   NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    event_queue = al_create_event_queue();
    if(!event_queue)     {
        al_show_native_message_box(display, "Error", "Error", "failed to create event_queue",
                                   NULL, ALLEGRO_MESSAGEBOX_ERROR);

        al_destroy_display(display);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_clear_to_color(al_map_rgb(0,0,0));

    al_flip_display();



    while(1)    {
        ALLEGRO_EVENT ev;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.06);

        bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

        if(get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)     {
            break;
        }

        al_clear_to_color(al_map_rgb(0,0,0));

        show_matrix(display, grid);


        al_flip_display();
    }

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);


    return 0;
}
