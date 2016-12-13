#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <ctime>

enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };

int main(void)
{
	//variables
	int width = 754;
	int height = 388;
	int FPS = 60;

	srand(time(NULL));
	bool done = false;
	int x = 50;
	float x1 = (rand() % 100) + 500;
	float y = 200.0;
	float y1 = y;
	int hp_przeciwnika=3, hp_gracza=100, ilosc_zabic=0;
	int test = 0;

	bool keys[5] = { false, false, false, false, false };
	bool przeciwnik_hit = false;
	int pos_moneta=0;
	bool wys_monete = false;

	//allegro variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	if (!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);	
	ALLEGRO_KEYBOARD_STATE klawiatura;     //create our display object

	if (!display)										//test display object
		return -1;

	//addon init
	al_install_keyboard();
	al_init_image_addon();
	 ALLEGRO_BITMAP *postac = al_load_bitmap("images/postac/postac_0.png");
	 ALLEGRO_BITMAP *postac2_o = al_load_bitmap("images/postac/postac_2_o.png");
	 ALLEGRO_BITMAP *postac2 = al_load_bitmap("images/postac/postac_2.png");
	ALLEGRO_BITMAP *postac_o = al_load_bitmap("images/postac/postac_o.png");
	ALLEGRO_BITMAP *postac_hit = al_load_bitmap("images/postac/postac_hit.png");
	ALLEGRO_BITMAP *postac_hit_o = al_load_bitmap("images/postac/postac_hit_o.png");
	ALLEGRO_BITMAP *wrogowie = al_load_bitmap("images/wrogowie/wrogowie.png");
	ALLEGRO_BITMAP *wrogowie_o = al_load_bitmap("images/wrogowie/wrogowie_o.png");
	ALLEGRO_BITMAP *wrogowie_hit = al_load_bitmap("images/wrogowie/wrogowie_hit.png");
	ALLEGRO_BITMAP *wrogowie_hit_o = al_load_bitmap("images/wrogowie/wrogowie_hit_o.png");
	ALLEGRO_BITMAP *tlo = al_load_bitmap("images/tlo/tlo.png");
	ALLEGRO_BITMAP *moneta = al_load_bitmap("images/tlo/moneta.png");
	ALLEGRO_FONT * font8 = al_create_builtin_font();
	ALLEGRO_FONT * font9 = al_create_builtin_font();

//	al_convert_mask_to_alpha(image, al_map_rgb(255, 0, 255));

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[SPACE] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
				
			}
		}
		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (y >= 100.0 && y < 250.0 )
			y -= keys[UP] * 1;
			else if (y <= 101.0) y++;
			else if (y >= 250.0) --y;
			if (y >= 100.0 && y < 250.0)
			y += keys[DOWN] * 1;
			else if (y <= 101.0) y++;
			else if (y >= 250.0) --y;
			if (x >= -20.0 && x <= 680.0)
			x -= keys[LEFT] * 1;
			else if (x <= -21.0) x++;
			else if (x >= 681.0) x--;
			if (x >= -20.0 && x <= 680.0)
			x += keys[RIGHT] * 1;
			else if ( x <= -21.0) x++;
			else if (x >= 681.0) x--;
			al_draw_bitmap(tlo, 0, 0, 0);

			

			//przeciwnik
			if (y > y1 + 15)
				y1 = y1 + 0.5;

			else if (y < y1 -15)
				y1 = y1 - 0.5;

			if (x1 <= x + 30 && hp_gracza > 0 && x < x1 + 30)
			{
				przeciwnik_hit = true;
				hp_gracza = hp_gracza - 1;
			}
			
			
				if (x1 >= x - 20 && przeciwnik_hit == false)
					al_draw_bitmap(wrogowie, x1, y1, 0);

				if (x1 < x - 20 && przeciwnik_hit == false)
					al_draw_bitmap(wrogowie_o, x1, y1, 0);

				if (przeciwnik_hit == true && x1 >= x - 20)
				{
					al_draw_bitmap(wrogowie_hit, x1, y1, 0);
					przeciwnik_hit = false;
				}
				if (przeciwnik_hit == true && x1 < x - 20)
				{
					al_draw_bitmap(wrogowie_hit_o, x1, y1, 0);
					przeciwnik_hit = false;
				}

			if (x1 -15 > x)
			{
				x1 = x1 - 0.5;
			}

			if (x1 + 15 <= x)
			{
				x1 = x1 + 0.5;
			}
			
			//uderzenie
			if (keys[SPACE] && !keys[LEFT])
				al_draw_bitmap(postac_hit, x, y, 0);
			if (!keys[SPACE] && !keys[LEFT])
			{
				if (x % 10 < 10)
				{
					test = 0;
				}
				if (x % 20 >= 10)
				{
					test = 1;
				}

				if (test == 0 || !keys[RIGHT] && !keys[SPACE])
				{
					al_draw_bitmap(postac, x, y, 0);
				}
				if (test == 1 && keys[RIGHT])
				{
					al_draw_bitmap(postac2, x, y, 0);
				}
			}
				//back animacja

				if (!keys[SPACE] && keys[LEFT])
				{
					if (x % 10 < 10)
					{
						test = 0;
					}
					if (x % 20 >= 10)
					{
						test = 1;
					}

					if (test == 0)
					{
						al_draw_bitmap(postac_o, x, y, 0);
					}
					if (test == 1)
					{
						al_draw_bitmap(postac2_o, x, y, 0);
					}
			}
		
			if (keys[LEFT] && keys[SPACE])
				al_draw_bitmap(postac_hit_o, x, y, 0);

			//interakcja
			if (keys[SPACE] && x <= x1 + 30.0 && x > x1 - 30.0)
			{
				hp_przeciwnika = hp_przeciwnika - 1;
				keys[SPACE] = false;


				if (hp_przeciwnika == 0)
				{
					x1 = (rand() % 200) + 600;
					hp_przeciwnika = 3;
					ilosc_zabic++;
				}
			}
			
			//moneta

			if (pos_moneta == ilosc_zabic)
			{
				pos_moneta = (rand() % 400) + 100;
				pos_moneta++;
				wys_monete = true;
			}
			if (wys_monete == true)
			{
				al_draw_bitmap(moneta, pos_moneta, pos_moneta, 0);
			}
			
			//smierc
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
					x = 50.0;
					x1 = (rand() % 200) + 600;
					
				}
			}
			//fonty
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 10, 10, 0, "x=%0.f , y=%0.f", x, y);
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 10, 30, 0, "Twoje  HP: %d ", hp_gracza);
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 10, 50, 0, "HP  przeciwnika: %d", hp_przeciwnika);
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 630, 10, 0, "Ilosc zabic: %d", ilosc_zabic);
			al_flip_display();
		}
		
	}
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						
	
	return 0;
}