#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
int szer = 754, wys = 388, rozmx = 0, rozmy = 0;
int main()
{
	al_init();
	al_install_keyboard();
	al_init_font_addon();
	al_init_image_addon();
	ALLEGRO_KEYBOARD_STATE klawiatura;
	ALLEGRO_DISPLAY *okno = al_create_display(szer, wys);
	al_set_window_title(okno, "Knights and Warriors");
	ALLEGRO_BITMAP *postac = al_load_bitmap("postac.png");
	ALLEGRO_BITMAP *postac_o = al_load_bitmap("postac_o.png");
	ALLEGRO_BITMAP *postac_hit = al_load_bitmap("postac_hit.png");
	ALLEGRO_BITMAP *wrogowie = al_load_bitmap("wrogowie.png");
	ALLEGRO_BITMAP *wrogowie_o = al_load_bitmap("wrogowie_o.png");
	ALLEGRO_BITMAP *tlo = al_load_bitmap("tlo.png");
	ALLEGRO_FONT * font8 = al_create_builtin_font();
	ALLEGRO_FONT * font9 = al_create_builtin_font();
	int   y = 200, hp_przeciwnika = 3, hp_gracza = 100;
	float  x1 = 700.0,  x = 50.0,  y1 = 200;
	double czas = al_get_time();
	al_get_keyboard_state(&klawiatura);
	int wybor = 1;
	
	while (!al_key_down(&klawiatura, ALLEGRO_KEY_ESCAPE))
	{
		
			al_get_keyboard_state(&klawiatura);
			if (al_get_time() > czas + 0.01)
			{
				if (al_key_down(&klawiatura, ALLEGRO_KEY_RIGHT) && x < szer - rozmx)
				{
					x = x + 1;
				}
				if (al_key_down(&klawiatura, ALLEGRO_KEY_LEFT) && x > -20)
				{
					x = x - 1;
				}
				if (al_key_down(&klawiatura, ALLEGRO_KEY_DOWN) && y < wys - rozmy &&  y < 250) y = y + 1;
				if (al_key_down(&klawiatura, ALLEGRO_KEY_UP) && y > 0 && y > 100)  y = y - 1;
				if (al_key_down(&klawiatura, ALLEGRO_KEY_SPACE))
				{

					al_draw_bitmap(postac_hit, x, y, 0);
					al_flip_display();
					al_rest(0.1);
				

				}
				if (al_key_down(&klawiatura, ALLEGRO_KEY_SPACE) && al_key_down(&klawiatura, ALLEGRO_KEY_RIGHT ))
				{

					al_draw_bitmap(postac_hit, x, y, 0);
					al_flip_display();
					al_rest(0.1);
				

				}
				
				czas = al_get_time();
			}


			al_draw_bitmap(tlo, 0, 0, 0);
			if (!al_key_down(&klawiatura, ALLEGRO_KEY_RIGHT) && !al_key_down(&klawiatura, ALLEGRO_KEY_LEFT) && !al_key_down(&klawiatura, ALLEGRO_KEY_SPACE))
				al_draw_bitmap(postac, x, y, 0);
			if (al_key_down(&klawiatura, ALLEGRO_KEY_RIGHT))
				al_draw_bitmap(postac, x, y, 0);
			if (al_key_down(&klawiatura, ALLEGRO_KEY_LEFT))
				al_draw_bitmap(postac_o, x, y, 0);
			if (y > y1)
				y1 = y1 + 0.1;
			else if (y < y1)
				y1 = y1 - 0.1;
			if (x1 >= x - 20)
				al_draw_bitmap(wrogowie, x1, y1, 0);
			if (x1 < x - 20)
				al_draw_bitmap(wrogowie_o, x1, y1, 0);
			if (x1 + 3 > x)
			{
				x1 = x1 - 0.1;

			}

			if (x1 + 3 <= x)
			{
				x1 = x1 + 0.1;

			}
			if (al_get_time() > czas + 0.01)
			{
				
				if (al_key_down(&klawiatura, ALLEGRO_KEY_SPACE) && x <= x1 + 30 && x > x1 - 30)
				{ 
				
					hp_przeciwnika = hp_przeciwnika - 1;
					
					if (hp_przeciwnika == 0)
					{
						x1 = 800;
						hp_przeciwnika = 3;
					}
				}
				if (x1 <= x + 30 && hp_gracza >= 0 && x < x1 + 30)
					hp_gracza = hp_gracza-2;
				if (hp_gracza == 0)
				{
					x = 50.0;
					x1 = 800.0;
				}

			}
			
			if (hp_gracza == 0)
			{
				al_get_keyboard_state(&klawiatura);
				while (!al_key_down(&klawiatura, ALLEGRO_KEY_SPACE))
					
				{
					al_get_keyboard_state(&klawiatura);
					ALLEGRO_BITMAP *smierc = al_create_bitmap(754, 384);
					al_clear_to_color(al_map_rgb(255, 255, 255));
					al_draw_text(font9, al_map_rgb(0, 0, 0), 230, 144, 0, "Jestes martwy, spacja zaczyna od nowa!");
					al_flip_display();
					hp_gracza = 100;
					
				
				}
			}

			al_draw_textf(font8, al_map_rgb(0, 0, 0), 10, 10, 0, "x=%0.1f , y=%3d", x, y);
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 10, 30, 0, "Twoje  HP: %3d ", hp_gracza);
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 10, 50, 0, "HP  przeciwnika: %3d", hp_przeciwnika);
			al_flip_display();
			al_rest(0.001);
			
		}
	
	al_destroy_bitmap(postac);
	al_destroy_bitmap(wrogowie);
	al_destroy_bitmap(wrogowie_o);
	al_destroy_bitmap(tlo);
	al_destroy_display(okno);
	al_shutdown_image_addon();
	return 0;
}