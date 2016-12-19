#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <ctime>

enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };

int main(void)
{
	//variables
	int width = 754;
	int height = 438;
	int FPS = 90;

	srand(time(NULL));
	bool done = false;
	int postac_x = 50;
	int wrog_x = (rand() % 100) + 500;
	int wrog1_x = (rand() % 100) + 500;
	int wrog2_x = (rand() % 100) + 500;
	float postac_y = 200.0;
	int wrog_y = postac_y;
	int wrog1_y = 150;
	int wrog2_y = 250;
	int hp_przeciwnika=5, hp_gracza=5, ilosc_zabic=0;
	int hp_przeciwnika1 = 5;
	int hp_przeciwnika2 = 5;
	int postac_ruch = 0, wrog_ruch=0;
	bool zyje = false, zyje1 = false, zyje2 = false;
	bool biega1 = true, biega2 = true;

	bool keys[5] = { false, false, false, false, false };
	bool przeciwnik_hit = false;
	bool wys_monete = false, dodaj_monete =false;
	int licz_monety = 0, pos_moneta_x, pos_moneta_y, ilosc_monet = 0, ilosc_wrogow = 1;
	int naboje = 9, przeladowanie = 160;

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
	 ALLEGRO_BITMAP *postac = al_load_bitmap("images/postac/postac/postac0.png");
	 ALLEGRO_BITMAP *postac1 = al_load_bitmap("images/postac/postac/postac1.png");
	 ALLEGRO_BITMAP *postac2 = al_load_bitmap("images/postac/postac/postac2.png");
	 ALLEGRO_BITMAP *postac3 = al_load_bitmap("images/postac/postac/postac3.png");
	 ALLEGRO_BITMAP *postac4 = al_load_bitmap("images/postac/postac/postac4.png");
	 ALLEGRO_BITMAP *postac5 = al_load_bitmap("images/postac/postac/postac5.png");

	 ALLEGRO_BITMAP *postac_s = al_load_bitmap("images/postac/postac/postac0_s.png");
	 ALLEGRO_BITMAP *postac1_s = al_load_bitmap("images/postac/postac/postac1_s.png");
	 ALLEGRO_BITMAP *postac2_s = al_load_bitmap("images/postac/postac/postac2_s.png");
	 ALLEGRO_BITMAP *postac3_s = al_load_bitmap("images/postac/postac/postac3_s.png");
	 ALLEGRO_BITMAP *postac4_s = al_load_bitmap("images/postac/postac/postac4_s.png");
	 ALLEGRO_BITMAP *postac5_s = al_load_bitmap("images/postac/postac/postac5_s.png");

	 ALLEGRO_BITMAP *postac1_o = al_load_bitmap("images/postac/postac/postac0_o.png");
	 ALLEGRO_BITMAP *postac2_o = al_load_bitmap("images/postac/postac/postac1_o.png");
	 ALLEGRO_BITMAP *postac3_o = al_load_bitmap("images/postac/postac/postac2_o.png");
	 ALLEGRO_BITMAP *postac4_o = al_load_bitmap("images/postac/postac/postac3_o.png");
	 ALLEGRO_BITMAP *postac5_o = al_load_bitmap("images/postac/postac/postac4_o.png");

	 ALLEGRO_BITMAP *wrog0 = al_load_bitmap("images/postac/wrog/wrog0.png");
	 ALLEGRO_BITMAP *wrog1 = al_load_bitmap("images/postac/wrog/wrog1.png");
	 ALLEGRO_BITMAP *wrog2 = al_load_bitmap("images/postac/wrog/wrog2.png");
	 ALLEGRO_BITMAP *wrog3 = al_load_bitmap("images/postac/wrog/wrog3.png");
	 ALLEGRO_BITMAP *wrog4 = al_load_bitmap("images/postac/wrog/wrog4.png");
	 ALLEGRO_BITMAP *wrog5 = al_load_bitmap("images/postac/wrog/wrog5.png");
	 ALLEGRO_BITMAP *wrog6 = al_load_bitmap("images/postac/wrog/wrog6.png");
	 ALLEGRO_BITMAP *wrog7 = al_load_bitmap("images/postac/wrog/wrog7.png");
	 ALLEGRO_BITMAP *wrog8 = al_load_bitmap("images/postac/wrog/wrog8.png");


	 ALLEGRO_BITMAP *tlo_dol = al_load_bitmap("images/tlo/tlo_dol.jpg");
	 ALLEGRO_BITMAP *naboj = al_load_bitmap("images/inne/naboj.png");
	ALLEGRO_BITMAP *wrogowie = al_load_bitmap("images/wrogowie/wrogowie.png");
	ALLEGRO_BITMAP *wrogowie_o = al_load_bitmap("images/wrogowie/wrogowie_o.png");
	ALLEGRO_BITMAP *wrogowie_hit = al_load_bitmap("images/wrogowie/wrogowie_hit.png");
	ALLEGRO_BITMAP *wrogowie_hit_o = al_load_bitmap("images/wrogowie/wrogowie_hit_o.png");
	ALLEGRO_BITMAP *tlo = al_load_bitmap("images/tlo/tlo.png");
	ALLEGRO_BITMAP *moneta = al_load_bitmap("images/tlo/moneta.png");
	ALLEGRO_FONT * font8 = al_create_builtin_font();
	ALLEGRO_FONT * font9 = al_create_builtin_font();

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
				if (naboje>0)
				naboje--;
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
		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (postac_y >= 110.0 && postac_y < 285.0)
				postac_y -= keys[UP] * 1;
			else if (postac_y <= 101.0) postac_y++;
			else if (postac_y >= 250.0) --postac_y;
			if (postac_y >= 110.0 && postac_y < 285.0)
				postac_y += keys[DOWN] * 1;
			else if (postac_y <= 110.0) postac_y++;
			else if (postac_y >= 285.0) --postac_y;
			if (postac_x >= -20 && postac_x <= 680)
				postac_x -= keys[LEFT] * 1;
			else if (postac_x <= -21) postac_x++;
			else if (postac_x >= 681) postac_x--;
			if (postac_x >= -20 && postac_x <= 680)
				postac_x += keys[RIGHT] * 1;
			else if (postac_x <= -21) postac_x++;
			else if (postac_x >= 681) postac_x--;
			al_draw_bitmap(tlo, 0, 0, 0);
			al_draw_bitmap(tlo_dol, 0, 388, 0);
			//naboje
			if (naboje == 9)
			{
				al_draw_bitmap(naboj, 10, 395, 0);
				al_draw_bitmap(naboj, 30, 395, 0);
				al_draw_bitmap(naboj, 50, 395, 0);
				al_draw_bitmap(naboj, 70, 395, 0);
				al_draw_bitmap(naboj, 90, 395, 0);
				al_draw_bitmap(naboj, 110, 395, 0);
				al_draw_bitmap(naboj, 130, 395, 0);
				al_draw_bitmap(naboj, 150, 395, 0);
				al_draw_bitmap(naboj, 170, 395, 0);
			}
			if (naboje == 8)
			{
				al_draw_bitmap(naboj, 10, 395, 0);
				al_draw_bitmap(naboj, 30, 395, 0);
				al_draw_bitmap(naboj, 50, 395, 0);
				al_draw_bitmap(naboj, 70, 395, 0);
				al_draw_bitmap(naboj, 90, 395, 0);
				al_draw_bitmap(naboj, 110, 395, 0);
				al_draw_bitmap(naboj, 130, 395, 0);
				al_draw_bitmap(naboj, 150, 395, 0);
			}
			if (naboje == 7)
			{
				al_draw_bitmap(naboj, 10, 395, 0);
				al_draw_bitmap(naboj, 30, 395, 0);
				al_draw_bitmap(naboj, 50, 395, 0);
				al_draw_bitmap(naboj, 70, 395, 0);
				al_draw_bitmap(naboj, 90, 395, 0);
				al_draw_bitmap(naboj, 110, 395, 0);
				al_draw_bitmap(naboj, 130, 395, 0);
			}
			if (naboje == 6)
			{
				al_draw_bitmap(naboj, 10, 395, 0);
				al_draw_bitmap(naboj, 30, 395, 0);
				al_draw_bitmap(naboj, 50, 395, 0);
				al_draw_bitmap(naboj, 70, 395, 0);
				al_draw_bitmap(naboj, 90, 395, 0);
				al_draw_bitmap(naboj, 110, 395, 0);
			}
			if (naboje == 5)
			{
				al_draw_bitmap(naboj, 10, 395, 0);
				al_draw_bitmap(naboj, 30, 395, 0);
				al_draw_bitmap(naboj, 50, 395, 0);
				al_draw_bitmap(naboj, 70, 395, 0);
				al_draw_bitmap(naboj, 90, 395, 0);
			}
			if (naboje == 4)
			{
				al_draw_bitmap(naboj, 10, 395, 0);
				al_draw_bitmap(naboj, 30, 395, 0);
				al_draw_bitmap(naboj, 50, 395, 0);
				al_draw_bitmap(naboj, 70, 395, 0);
			}
			if (naboje == 3)
			{
				al_draw_bitmap(naboj, 10, 395, 0);
				al_draw_bitmap(naboj, 30, 395, 0);
				al_draw_bitmap(naboj, 50, 395, 0);
			}
			if (naboje == 2)
			{
				al_draw_bitmap(naboj, 10, 395, 0);
				al_draw_bitmap(naboj, 30, 395, 0);
			}
			if (naboje == 1)
			{
				al_draw_bitmap(naboj, 10, 395, 0);
			}
			if (naboje == 0)
			{
				przeladowanie--;
				al_draw_text(font9, al_map_rgb(255, 255, 255), 330, 144, 0, "Przeladowywanie!");
			}
			if (przeladowanie == 0)
			{
				naboje = 9;
				przeladowanie = 160;
			}
			//moneta

			if (licz_monety == ilosc_zabic)
			{
				pos_moneta_x = (rand() % 400) + 100;
				pos_moneta_y = (rand() % 100) + 200;
				wys_monete = true;
				licz_monety++;
			}
			if (wys_monete == true)
			{
				al_draw_bitmap(moneta, pos_moneta_x, pos_moneta_y, 0);
				if (postac_x <= pos_moneta_x + 10 && postac_x >= pos_moneta_x - 30)
				{
					dodaj_monete = true;
					if (dodaj_monete == true && wys_monete == true)
					{
						ilosc_monet++;
						dodaj_monete = false;
						wys_monete = false;
					}
				}
			}


			//przeciwnik
			if (postac_y > wrog_y + 15)
				wrog_y++;

			else if (postac_y < wrog_y - 15)
				wrog_y--;

			if (wrog_x <= postac_x + 30 && hp_gracza > 0 && postac_x < wrog_x + 30)
			{
				przeciwnik_hit = true;
				hp_gracza = hp_gracza - 1;
				ilosc_wrogow = 3;
			}

			//animacja wroga
			if (ilosc_wrogow >0)
			{
				if (wrog_x % 10 < 10)
				{
					wrog_ruch = 0;
				}
				if (wrog_x % 20 >= 10 && wrog_x % 20 < 20)
				{
					wrog_ruch = 1;
				}
				if (wrog_x % 30 >= 20 && wrog_x % 30 < 30)
				{
					wrog_ruch = 2;
				}
				if (wrog_x % 40 >= 30 && wrog_x % 40 < 40)
				{
					wrog_ruch = 3;
				}
				if (wrog_x % 50 >= 40 && wrog_x % 50 < 50)
				{
					wrog_ruch = 4;
				}
				if (wrog_x % 60 >= 50 && wrog_x % 60 < 60)
				{
					wrog_ruch = 5;
				}
				if (wrog_x % 70 >= 60 && wrog_x % 70 < 70)
				{
					wrog_ruch = 6;
				}
				if (wrog_x % 80 >= 70 && wrog_x % 80 < 80)
				{
					wrog_ruch = 7;
				}
				if (wrog_x % 90 >= 80 && wrog_x % 90 < 90)
				{
					wrog_ruch = 8;
				}

				if (wrog_ruch == 0)
				{
					al_draw_bitmap(wrog0, wrog_x, wrog_y, 0);
				}
				if (wrog_ruch == 1)
				{
					al_draw_bitmap(wrog1, wrog_x, wrog_y, 0);
				}
				if (wrog_ruch == 2)
				{
					al_draw_bitmap(wrog2, wrog_x, wrog_y, 0);
				}
				if (wrog_ruch == 3)
				{
					al_draw_bitmap(wrog3, wrog_x, wrog_y, 0);
				}
				if (wrog_ruch == 4)
				{
					al_draw_bitmap(wrog4, wrog_x, wrog_y, 0);
				}
				if (wrog_ruch == 5)
				{
					al_draw_bitmap(wrog5, wrog_x, wrog_y, 0);
				}
				if (wrog_ruch == 6)
				{
					al_draw_bitmap(wrog6, wrog_x, wrog_y, 0);
				}
				if (wrog_ruch == 7)
				{
					al_draw_bitmap(wrog7, wrog_x, wrog_y, 0);
				}
				if (wrog_ruch == 8)
				{
					al_draw_bitmap(wrog8, wrog_x, wrog_y, 0);
				}
			}
			//animacja wroga1
			if (ilosc_wrogow >=2 && ilosc_wrogow <=3 && zyje1==false)
			{
				wrog1_x--;
				biega1 = true;
			if (wrog1_x % 10 < 10)
			{
				wrog_ruch = 0;
			}
			if (wrog1_x % 20 >= 10 && wrog1_x % 20 < 20)
			{
				wrog_ruch = 1;
			}
			if (wrog1_x % 30 >= 20 && wrog1_x % 30 < 30)
			{
				wrog_ruch = 2;
			}
			if (wrog1_x % 40 >= 30 && wrog1_x % 40 < 40)
			{
				wrog_ruch = 3;
			}
			if (wrog1_x % 50 >= 40 && wrog1_x % 50 < 50)
			{
				wrog_ruch = 4;
			}
			if (wrog1_x % 60 >= 50 && wrog1_x % 60 < 60)
			{
				wrog_ruch = 5;
			}
			if (wrog1_x % 70 >= 60 && wrog1_x % 70 < 70)
			{
				wrog_ruch = 6;
			}
			if (wrog1_x % 80 >= 70 && wrog1_x % 80 < 80)
			{
				wrog_ruch = 7;
			}
			if (wrog1_x % 90 >= 80 && wrog1_x % 90 < 90)
			{
				wrog_ruch = 8;
			}

			if (wrog_ruch == 0)
			{
				al_draw_bitmap(wrog0, wrog1_x, wrog1_y, 0);
			}
			if (wrog_ruch == 1)
			{
				al_draw_bitmap(wrog1, wrog1_x, wrog1_y, 0);
			}
			if (wrog_ruch == 2)
			{
				al_draw_bitmap(wrog2, wrog1_x, wrog1_y, 0);
			}
			if (wrog_ruch == 3)
			{
				al_draw_bitmap(wrog3, wrog1_x, wrog1_y, 0);
			}
			if (wrog_ruch == 4)
			{
				al_draw_bitmap(wrog4, wrog1_x, wrog1_y, 0);
			}
			if (wrog_ruch == 5)
			{
				al_draw_bitmap(wrog5, wrog1_x, wrog1_y, 0);
			}
			if (wrog_ruch == 6)
			{
				al_draw_bitmap(wrog6, wrog1_x, wrog1_y, 0);
			}
			if (wrog_ruch == 7)
			{
				al_draw_bitmap(wrog7, wrog1_x, wrog1_y, 0);
			}
			if (wrog_ruch == 8)
			{
				al_draw_bitmap(wrog8, wrog1_x, wrog1_y, 0);
			}
		}

			//animacja wroga2
			if ( ilosc_wrogow == 3 && zyje2==false)
			{
				wrog2_x--;
				biega2 = true;
				if (wrog2_x % 10 < 10)
				{
					wrog_ruch = 0;
				}
				if (wrog2_x % 20 >= 10 && wrog2_x % 20 < 20)
				{
					wrog_ruch = 1;
				}
				if (wrog2_x % 30 >= 20 && wrog2_x % 30 < 30)
				{
					wrog_ruch = 2;
				}
				if (wrog2_x % 40 >= 30 && wrog2_x % 40 < 40)
				{
					wrog_ruch = 3;
				}
				if (wrog2_x % 50 >= 40 && wrog2_x % 50 < 50)
				{
					wrog_ruch = 4;
				}
				if (wrog2_x % 60 >= 50 && wrog2_x % 60 < 60)
				{
					wrog_ruch = 5;
				}
				if (wrog2_x % 70 >= 60 && wrog2_x % 70 < 70)
				{
					wrog_ruch = 6;
				}
				if (wrog2_x % 80 >= 70 && wrog2_x % 80 < 80)
				{
					wrog_ruch = 7;
				}
				if (wrog2_x % 90 >= 80 && wrog2_x % 90 < 90)
				{
					wrog_ruch = 8;
				}

				if (wrog_ruch == 0)
				{
					al_draw_bitmap(wrog0, wrog2_x, wrog2_y, 0);
				}
				if (wrog_ruch == 1)
				{
					al_draw_bitmap(wrog1, wrog2_x, wrog2_y, 0);
				}
				if (wrog_ruch == 2)
				{
					al_draw_bitmap(wrog2, wrog2_x, wrog2_y, 0);
				}
				if (wrog_ruch == 3)
				{
					al_draw_bitmap(wrog3, wrog2_x, wrog2_y, 0);
				}
				if (wrog_ruch == 4)
				{
					al_draw_bitmap(wrog4, wrog2_x, wrog2_y, 0);
				}
				if (wrog_ruch == 5)
				{
					al_draw_bitmap(wrog5, wrog2_x, wrog2_y, 0);
				}
				if (wrog_ruch == 6)
				{
					al_draw_bitmap(wrog6, wrog2_x, wrog2_y, 0);
				}
				if (wrog_ruch == 7)
				{
					al_draw_bitmap(wrog7, wrog2_x, wrog2_y, 0);
				}
				if (wrog_ruch == 8)
				{
					al_draw_bitmap(wrog8, wrog2_x, wrog2_y, 0);
				}
			}


				if (przeciwnik_hit == true && wrog_x >= postac_x - 20)
				{
					al_draw_bitmap(wrogowie_hit, wrog_x, wrog_y, 0);
					przeciwnik_hit = false;
				}
				if (przeciwnik_hit == true && wrog_x < postac_x - 20)
				{
					al_draw_bitmap(wrogowie_hit_o, wrog_x, wrog_y, 0);
					przeciwnik_hit = false;
				}

			if (wrog_x -15 > postac_x)
			{
				wrog_x--;
			}

			if (wrog_x + 15 <= postac_x)
			{
				wrog_x++;
			}
			
			//uderzenie
			

			if (wrog_x == postac_x )
			{
				hp_gracza--;
				wrog_x = (rand() % 200 + 800);
			}

			if (wrog1_x == postac_x)
			{
				hp_gracza--;
				wrog1_x = (rand() % 150 + 800);
			}

			if (wrog2_x == postac_x)
			{
				hp_gracza--;
				wrog2_x = (rand() % 250 + 800);
			}
			//animacja
			if (!keys[SPACE] && !keys[LEFT])
			{
				if (postac_x % 10 < 10 && !keys[RIGHT])
				{
					postac_ruch = 0;
				}
				if (postac_x % 20 >= 10 && postac_x % 20 < 20)
				{
					postac_ruch = 1;
				}
				if (postac_x % 30 >= 20 && postac_x % 30 < 30 )
				{
					postac_ruch = 2;
				}
				if (postac_x % 40 >= 30 && postac_x % 40 < 40)
				{
					postac_ruch = 3;
				}
				if (postac_x % 50 >= 40 && postac_x % 50 < 50)
				{
					postac_ruch = 4;
				}
				if (postac_x % 60 >= 50 && postac_x % 60 < 60)
				{
					postac_ruch = 5;
				}

				if (postac_ruch == 0 || !keys[RIGHT] && !keys[SPACE])
				{
					al_draw_bitmap(postac, postac_x, postac_y, 0);
				}
				if (postac_ruch == 1 && keys[RIGHT])
				{
					al_draw_bitmap(postac1, postac_x, postac_y, 0);
				}
				if (postac_ruch == 2 && keys[RIGHT])
				{
					al_draw_bitmap(postac2, postac_x, postac_y, 0);
				}
				if (postac_ruch == 3 && keys[RIGHT])
				{
					al_draw_bitmap(postac3, postac_x, postac_y, 0);
				}
				if (postac_ruch == 4 && keys[RIGHT])
				{
					al_draw_bitmap(postac4, postac_x, postac_y, 0);
				}
				if (postac_ruch == 5 && keys[RIGHT])
				{
					al_draw_bitmap(postac5, postac_x, postac_y, 0);
				}
			}
			//animacja strzelania
			if (keys[SPACE] && !keys[LEFT])
			{
				if (!keys[RIGHT])
				{
					postac_ruch = 0;
				}
				if (postac_x % 20 >= 10 && postac_x % 20 < 20)
				{
					postac_ruch = 1;
				}
				if (postac_x % 30 >= 20 && postac_x % 30 < 30)
				{
					postac_ruch = 2;
				}
				if (postac_x % 40 >= 30 && postac_x % 40 < 40)
				{
					postac_ruch = 3;
				}
				if (postac_x % 50 >= 40 && postac_x % 50 < 50)
				{
					postac_ruch = 4;
				}
				if (postac_x % 60 >= 50 && postac_x % 60 < 60)
				{
					postac_ruch = 5;
				}

				if (postac_ruch == 0 || !keys[RIGHT] && keys[SPACE])
				{
					al_draw_bitmap(postac_s, postac_x, postac_y, 0);
				}
				if (postac_ruch == 1 && keys[RIGHT])
				{
					al_draw_bitmap(postac1_s, postac_x, postac_y, 0);
				}
				if (postac_ruch == 2 && keys[RIGHT])
				{
					al_draw_bitmap(postac2_s, postac_x, postac_y, 0);
				}
				if (postac_ruch == 3 && keys[RIGHT])
				{
					al_draw_bitmap(postac3_s, postac_x, postac_y, 0);
				}
				if (postac_ruch == 4 && keys[RIGHT])
				{
					al_draw_bitmap(postac4_s, postac_x, postac_y, 0);
				}
				if (postac_ruch == 5 && keys[RIGHT])
				{
					al_draw_bitmap(postac5_s, postac_x, postac_y, 0);
				}
			}
				//back animacja

				if (!keys[SPACE] && keys[LEFT])
				{
					
					if (postac_x % 20 >= 10 && postac_x % 20 < 20)
					{
						postac_ruch = 1;
					}
					if (postac_x % 30 >= 20 && postac_x % 30 < 30)
					{
						postac_ruch = 2;
					}
					if (postac_x % 40 >= 30 && postac_x % 40 < 40)
					{
						postac_ruch = 3;
					}
					if (postac_x % 50 >= 40 && postac_x % 50 < 50)
					{
						postac_ruch = 5;
					}

				
					if (postac_ruch == 1 && keys[LEFT])
					{
						al_draw_bitmap(postac1_o, postac_x, postac_y, 0);
					}
					if (postac_ruch == 2 && keys[LEFT])
					{
						al_draw_bitmap(postac2_o, postac_x, postac_y, 0);
					}
					if (postac_ruch == 3 && keys[LEFT])
					{
						al_draw_bitmap(postac3_o, postac_x, postac_y, 0);
					}
					if (postac_ruch == 5 && keys[LEFT])
					{
						al_draw_bitmap(postac5_o, postac_x, postac_y, 0);
					}
			}
		
			

			//interakcja z wrogiem1
			if (keys[SPACE] && naboje>0)
			{
				if (postac_x <= wrog_x && postac_y > wrog_y - 30 && postac_y < wrog_y + 30)
				{
					hp_przeciwnika = hp_przeciwnika - 1;
					keys[SPACE] = false;


					if (hp_przeciwnika == 0)
					{
						wrog_x = (rand() % 200) + 700;

						hp_przeciwnika = 5;
						ilosc_zabic++;
						ilosc_wrogow = 3;
						if (biega1 == false)
						{
							zyje1 = (rand() % 2 + 0);
							biega1 = true;
						}
						if (biega2 == false)
						{
							zyje2 = (rand() % 2 + 0);
							biega2 = true;
						}
					}
				}
				//interakcja z wrogiem2
				if (postac_x <= wrog1_x && postac_y > wrog1_y - 30 && postac_y < wrog1_y + 30)
				{
					hp_przeciwnika1 = hp_przeciwnika1 - 1;
					keys[SPACE] = false;


					if (hp_przeciwnika1 == 0)
					{
						wrog1_x = (rand() % 150) + 700;
						wrog1_y =  (rand() % 110) + 200;
						hp_przeciwnika1 = 5;
						ilosc_zabic++;
						biega1 = false;
						


					}
				}
				//interakcja z wrogiem3
				if (postac_x <= wrog2_x && postac_y > wrog2_y - 30 && postac_y < wrog2_y + 30)
				{
					hp_przeciwnika2 = hp_przeciwnika2 - 1;
					keys[SPACE] = false;


					if (hp_przeciwnika2 == 0)
					{
						wrog2_x = (rand() % 250) + 700;
						wrog2_y = (rand() % 80) + 200;
						hp_przeciwnika2 = 5;
						ilosc_zabic++;
						ilosc_wrogow--;
						
						biega2 = false;

					}
				}

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
					hp_gracza = 5;
					postac_x = 50;
					wrog_x = (rand() % 200) + 800;
					wrog1_x = (rand() % 150) + 800;
					wrog2_x = (rand() % 250) + 800;
					
				}
			}
			//fonty
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 10, 10, 0, "x=%d , y=%0.f", postac_x, postac_y);
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 10, 30, 0, "Twoje  HP: %d ", hp_gracza);
			if(ilosc_wrogow == 1)
			al_draw_textf(font8, al_map_rgb(0, 0, 0), wrog_x+10, wrog_y-5, 0, "HP: %d", hp_przeciwnika);
			if (ilosc_wrogow == 2)
			{
				al_draw_textf(font8, al_map_rgb(0, 0, 0), wrog_x+10, wrog_y-5, 0, "HP: %d", hp_przeciwnika);
				al_draw_textf(font8, al_map_rgb(0, 0, 0), wrog1_x+10, wrog1_y-5, 0, "HP: %d", hp_przeciwnika1);
			}
			if (ilosc_wrogow == 3)
			{
				al_draw_textf(font8, al_map_rgb(0, 0, 0), wrog_x+10, wrog_y-5, 0, "HP: %d", hp_przeciwnika);
				al_draw_textf(font8, al_map_rgb(0, 0, 0), wrog1_x+10, wrog1_y-5, 0, "HP: %d", hp_przeciwnika1);
				al_draw_textf(font8, al_map_rgb(0, 0, 0), wrog2_x+10, wrog2_y-5, 0, "HP: %d", hp_przeciwnika2);
			}
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 630, 10, 0, "Ilosc zabic: %d", ilosc_zabic);
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 630, 30, 0, "Ilosc monet: %d", ilosc_monet);
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 600, 70, 0, "Ilosc monet: %d", naboje);
			al_flip_display();
		}
		
	}
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						
	
	return 0;
}