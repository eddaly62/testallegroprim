// testallegroprim.c

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#define BLACK al_map_rgb(0, 0, 0)
#define WHITE al_map_rgb(255, 255, 255)
#define RED al_map_rgb(255, 0, 0)
#define BLUE al_map_rgb(0, 0, 255)
#define GREEN al_map_rgb(0, 255, 0)

#define RESOURCES_DIR "resources"
#define TEST_TEXT "Hello World"
#define FONT_FILE "YARDSALE.TTF"
#define FONT_SIZE 64

int main()  {
    
    bool running = true;
    int bbx;
    int bby;
    int bbw;
    int bbh;

    float points[8] = {0.0f, 0.0f, 100.00f, 100.00f, 200.00f, 100.00f, 640.00f, 150.00f};
    float polygon[8] = { 640.0f, 100.0f, 640.0f, 300.0f, 380.0f, 350.0f, 200.0f, 200.0f };
    
    ALLEGRO_DISPLAY *display;
    ALLEGRO_FONT *font;

    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();

    ALLEGRO_PATH *path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path, RESOURCES_DIR);
    al_change_directory(al_path_cstr(path, '/'));
    al_destroy_path(path);

    display = al_create_display(640, 480);
    
    font = al_load_ttf_font(FONT_FILE, FONT_SIZE, 0);

    while (running) {
        al_clear_to_color(BLACK);
        
        al_draw_line(0, 0, al_get_display_width(display), al_get_display_height(display), RED, 5.0);
        al_draw_rectangle(100, 100, 300, 300, GREEN, 1);
        //al_draw_ellipse(300, 300, 120, 50, al_map_rgb(0, 0, 255), 3);
        //al_draw_spline(points, al_map_rgb(128, 128, 0), 8);
        //al_draw_polygon(polygon, 8, ALLEGRO_LINE_JOIN_BEVEL, al_map_rgb(255, 15, 15),3,1);
        //al_draw_filled_polygon(polygon, 8, al_map_rgb(255, 0, 0));

        al_get_text_dimensions(font, TEST_TEXT, &bbx, &bby, &bbw, &bbh);

        printf("bbx=%d, bby=%d, bbw=%d, bbh=%d\n", bbx, bby, bbw, bbh);
        //al_draw_rectangle(bbx, bby, bbx+bbw, bby+bbh, GREEN, 1);
        al_draw_filled_rectangle(bbx, bby, bbx+bbw, bby+bbh, WHITE);

        al_draw_text(font, BLACK, 0, 0, 0, TEST_TEXT);

        al_flip_display();

        sleep(1);
    }

    al_destroy_font(font);
    al_destroy_display(display);

    return 0;
}
