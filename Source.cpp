#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <ctime>

enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE, W, S, A, D, LSHIFT };

int main(void)
{
	//variables
	int width = 754;
	int height = 438;
	int FPS = 90;

	srand(time(NULL));
	bool done = false;
	int postac_x = 50;
	int postac2_x = 50;
	int wrog_x =  750;
	int wrog1_x =  1400;
	int wrog2_x =  800;
	int wrog3_x =  1650;
	int wrog4_x =  900;
	int postac_y = 200;
	int postac2_y = 100;
	int wrog_y = 300;
	int wrog1_y = 90;
	int wrog2_y = 250;
	int wrog3_y = 200;
	int wrog4_y = 150;
	int hp_przeciwnika=5, hp_gracza=10, ilosc_zabic=0;
	int hp_przeciwnika1 = 5;
	int hp_przeciwnika2 = 5;
	int hp_przeciwnika3 = 5;
	int hp_przeciwnika4 = 5;
	int postac_ruch = 0, wrog_ruch=0, postac2_ruch=0;
	bool zyje = false, zyje1 = false, zyje2 = false,zyje3=false,zyje4=false;

	bool keys[10] = { false, false, false, false, false, false , false , false ,false ,false };
	bool przeciwnik_hit = false;
	bool wys_monete = false, dodaj_monete = false, licz_monety = false;
	int pos_moneta_x, pos_moneta_y, ilosc_monet = 0, ilosc_wrogow = 5;
	int naboje = 9, przeladowanie = 50;

	//allegro variable
	ALLEGRO_DISPLAY *display = nullptr;
	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
	ALLEGRO_TIMER *timer = nullptr;


	if (!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);	
	al_set_window_title(display, "Stickman and Zombies");
	ALLEGRO_KEYBOARD_STATE klawiatura;     //create our display object

	if (!display)										//test display object
		return -1;

	int pomocnicza = 0, pomocnicza1 = 0, pomocnicza2=0, pomocnicza3=0, pomocnicza4=0;

	//addon init
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	 ALLEGRO_BITMAP *postac = al_load_bitmap("images/postac/postac/postac0.png");
	 ALLEGRO_BITMAP *postac1 = al_load_bitmap("images/postac/postac/postac1.png");
	 ALLEGRO_BITMAP *postac2 = al_load_bitmap("images/postac/postac/postac2.png");
	 ALLEGRO_BITMAP *postac3 = al_load_bitmap("images/postac/postac/postac3.png");
	 ALLEGRO_BITMAP *postac4 = al_load_bitmap("images/postac/postac/postac4.png");
	 ALLEGRO_BITMAP *postac5 = al_load_bitmap("images/postac/postac/postac5.png");

	 ALLEGRO_BITMAP *postac20 = al_load_bitmap("images/postac/postac/postac0.png");
	 ALLEGRO_BITMAP *postac21 = al_load_bitmap("images/postac/postac/postac1.png");
	 ALLEGRO_BITMAP *postac22 = al_load_bitmap("images/postac/postac/postac2.png");
	 ALLEGRO_BITMAP *postac23 = al_load_bitmap("images/postac/postac/postac3.png");
	 ALLEGRO_BITMAP *postac24 = al_load_bitmap("images/postac/postac/postac4.png");
	 ALLEGRO_BITMAP *postac25 = al_load_bitmap("images/postac/postac/postac5.png");

	 ALLEGRO_BITMAP *postac_s = al_load_bitmap("images/postac/postac/postac0_s.png");
	 ALLEGRO_BITMAP *postac1_s = al_load_bitmap("images/postac/postac/postac1_s.png");
	 ALLEGRO_BITMAP *postac2_s = al_load_bitmap("images/postac/postac/postac2_s.png");
	 ALLEGRO_BITMAP *postac3_s = al_load_bitmap("images/postac/postac/postac3_s.png");
	 ALLEGRO_BITMAP *postac4_s = al_load_bitmap("images/postac/postac/postac4_s.png");
	 ALLEGRO_BITMAP *postac5_s = al_load_bitmap("images/postac/postac/postac5_s.png");

	 ALLEGRO_BITMAP *postac20_s = al_load_bitmap("images/postac/postac/postac0_s.png");
	 ALLEGRO_BITMAP *postac21_s = al_load_bitmap("images/postac/postac/postac1_s.png");
	 ALLEGRO_BITMAP *postac22_s = al_load_bitmap("images/postac/postac/postac2_s.png");
	 ALLEGRO_BITMAP *postac23_s = al_load_bitmap("images/postac/postac/postac3_s.png");
	 ALLEGRO_BITMAP *postac24_s = al_load_bitmap("images/postac/postac/postac4_s.png");
	 ALLEGRO_BITMAP *postac25_s = al_load_bitmap("images/postac/postac/postac5_s.png");

	 ALLEGRO_BITMAP *postac1_o = al_load_bitmap("images/postac/postac/postac0_o.png");
	 ALLEGRO_BITMAP *postac2_o = al_load_bitmap("images/postac/postac/postac1_o.png");
	 ALLEGRO_BITMAP *postac3_o = al_load_bitmap("images/postac/postac/postac2_o.png");
	 ALLEGRO_BITMAP *postac4_o = al_load_bitmap("images/postac/postac/postac3_o.png");
	 ALLEGRO_BITMAP *postac5_o = al_load_bitmap("images/postac/postac/postac4_o.png");

	 ALLEGRO_BITMAP *postac21_o = al_load_bitmap("images/postac/postac/postac0_o.png");
	 ALLEGRO_BITMAP *postac22_o = al_load_bitmap("images/postac/postac/postac1_o.png");
	 ALLEGRO_BITMAP *postac23_o = al_load_bitmap("images/postac/postac/postac2_o.png");
	 ALLEGRO_BITMAP *postac24_o = al_load_bitmap("images/postac/postac/postac3_o.png");
	 ALLEGRO_BITMAP *postac25_o = al_load_bitmap("images/postac/postac/postac4_o.png");

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
	 ALLEGRO_BITMAP *czacha = al_load_bitmap("images/inne/czacha.png");
	ALLEGRO_BITMAP *wrogowie = al_load_bitmap("images/wrogowie/wrogowie.png");
	ALLEGRO_BITMAP *wrogowie_o = al_load_bitmap("images/wrogowie/wrogowie_o.png");
	ALLEGRO_BITMAP *wrogowie_hit = al_load_bitmap("images/wrogowie/wrogowie_hit.png");
	ALLEGRO_BITMAP *wrogowie_hit_o = al_load_bitmap("images/wrogowie/wrogowie_hit_o.png");
	ALLEGRO_BITMAP *tlo = al_load_bitmap("images/tlo/tlo.png");
	ALLEGRO_BITMAP *moneta = al_load_bitmap("images/tlo/moneta.png");
	ALLEGRO_BITMAP *mur = al_load_bitmap("images/inne/mur.png");
	ALLEGRO_BITMAP *wybuch = al_load_bitmap("images/inne/bang.png");

	ALLEGRO_FONT * font8 = al_create_builtin_font();
	ALLEGRO_FONT * font9 = al_create_builtin_font();
	ALLEGRO_FONT * font_ttf = al_load_ttf_font("SHOWG.TTF", 36, 0);
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
			case ALLEGRO_KEY_W:
				keys[W] = true;
				break;
			case ALLEGRO_KEY_S:
				keys[S] = true;
				break;
			case ALLEGRO_KEY_A:
				keys[A] = true;
				break;
			case ALLEGRO_KEY_D:
				keys[D] = true;
				break;
			case ALLEGRO_KEY_LSHIFT:
				keys[LSHIFT] = true;
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
			case ALLEGRO_KEY_W:
				keys[W] = false;
				break;
			case ALLEGRO_KEY_S:
				keys[S] = false;
				break;
			case ALLEGRO_KEY_A:
				keys[A] = false;
				break;
			case ALLEGRO_KEY_D:
				keys[D] = false;
				break;
			case ALLEGRO_KEY_LSHIFT:
				keys[LSHIFT] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
				
			}
		}
		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			if (postac_y >= 60 && postac_y < 305)
				postac_y -= keys[UP] * 1;
			else if (postac_y <= 61) postac_y++;
			else if (postac_y >= 305) --postac_y;
			if (postac_y >= 60 && postac_y < 305)
				postac_y += keys[DOWN] * 1;
			else if (postac_y <= 60.0) postac_y++;
			else if (postac_y >= 305.0) --postac_y;
			if (postac_x >= 10 && postac_x <= 72)
				postac_x -= keys[LEFT] * 1;
			else if (postac_x <= 9) postac_x++;
			else if (postac_x >= 73) postac_x--;
			if (postac_x >= 10 && postac_x <= 680)
				postac_x += keys[RIGHT] * 1;
			else if (postac_x <= 9) postac_x++;
			else if (postac_x >= 73) postac_x--;
			//postac2
			if (postac2_y >= 60 && postac2_y < 305)
				postac2_y -= keys[W] * 1;
			else if (postac2_y <= 61) postac2_y++;
			else if (postac2_y >= 305) --postac2_y;
			if (postac2_y >= 60 && postac2_y < 305.0)
				postac2_y += keys[S] * 1;
			else if (postac2_y <= 60) postac2_y++;
			else if (postac2_y >= 305) --postac2_y;
			if (postac2_x >= 10 && postac2_x <= 72)
				postac2_x -= keys[A] * 1;
			else if (postac2_x <= 9) postac2_x++;
			else if (postac2_x >= 73) postac2_x--;
			if (postac2_x >= 10 && postac2_x <= 680)
				postac2_x += keys[D] * 1;
			else if (postac2_x <= 9) postac2_x++;
			else if (postac2_x >= 73) postac2_x--;
			//WAZNEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
			al_draw_bitmap(tlo, 0, 0, 0);
			al_draw_bitmap(tlo_dol, 0, 388, 0);
			al_draw_bitmap(czacha, 470, 392, 0);
			al_draw_bitmap(moneta, 620, 397, 0);
			al_draw_bitmap(mur, 245, 397, 0);
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
				przeladowanie = 50;
			}
			
			
			//moneta

			if (licz_monety == false && wys_monete == false)
			{
				pos_moneta_x = (rand() % 70) + 0;
				pos_moneta_y = (rand() % 240) + 70;
				wys_monete = true;
				licz_monety = true;
			}
			if (wys_monete == true)
			{
				al_draw_bitmap(moneta, pos_moneta_x, pos_moneta_y, 0);
				if (postac_y <= pos_moneta_y + 10 && postac_y >= pos_moneta_y - 30)
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

			//animacja wroga
			if (ilosc_wrogow >0 && wrog_x !=125 )
			{
				wrog_x--;
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
			if (ilosc_wrogow > 1 && zyje1 == false && zyje2 == false && zyje3 == false && zyje4 == false || zyje1 == true && wrog1_x !=125)
			{
				wrog1_x--;
				zyje1 = true;
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
			if (ilosc_wrogow > 2 && zyje2 == false && zyje3 == false && zyje4 == false || zyje2 == true && wrog2_x !=125)
			{
				wrog2_x--;
				zyje2 = true;
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
			//animacja wroga 3
			if (ilosc_wrogow > 3 && zyje3 == false && zyje4 == false || zyje3 == true && wrog3_x != 125)
			{
				wrog3_x--;
				zyje3 = true;
				{
					if (wrog3_x % 10 < 10)
					{
						wrog_ruch = 0;
					}
					if (wrog3_x % 20 >= 10 && wrog3_x % 20 < 20)
					{
						wrog_ruch = 1;
					}
					if (wrog3_x % 30 >= 20 && wrog3_x % 30 < 30)
					{
						wrog_ruch = 2;
					}
					if (wrog3_x % 40 >= 30 && wrog3_x % 40 < 40)
					{
						wrog_ruch = 3;
					}
					if (wrog3_x % 50 >= 40 && wrog3_x % 50 < 50)
					{
						wrog_ruch = 4;
					}
					if (wrog3_x % 60 >= 50 && wrog3_x % 60 < 60)
					{
						wrog_ruch = 5;
					}
					if (wrog3_x % 70 >= 60 && wrog3_x % 70 < 70)
					{
						wrog_ruch = 6;
					}
					if (wrog3_x % 80 >= 70 && wrog3_x % 80 < 80)
					{
						wrog_ruch = 7;
					}
					if (wrog3_x % 90 >= 80 && wrog3_x % 90 < 90)
					{
						wrog_ruch = 8;
					}

					if (wrog_ruch == 0)
					{
						al_draw_bitmap(wrog0, wrog3_x, wrog3_y, 0);
					}
					if (wrog_ruch == 1)
					{
						al_draw_bitmap(wrog1, wrog3_x, wrog3_y, 0);
					}
					if (wrog_ruch == 2)
					{
						al_draw_bitmap(wrog2, wrog3_x, wrog3_y, 0);
					}
					if (wrog_ruch == 3)
					{
						al_draw_bitmap(wrog3, wrog3_x, wrog3_y, 0);
					}
					if (wrog_ruch == 4)
					{
						al_draw_bitmap(wrog4, wrog3_x, wrog3_y, 0);
					}
					if (wrog_ruch == 5)
					{
						al_draw_bitmap(wrog5, wrog3_x, wrog3_y, 0);
					}
					if (wrog_ruch == 6)
					{
						al_draw_bitmap(wrog6, wrog3_x, wrog3_y, 0);
					}
					if (wrog_ruch == 7)
					{
						al_draw_bitmap(wrog7, wrog3_x, wrog3_y, 0);
					}
					if (wrog_ruch == 8)
					{
						al_draw_bitmap(wrog8, wrog3_x, wrog3_y, 0);
					}
				}
			}
			//animacja wroga 4
			
			if (ilosc_wrogow > 4 && zyje4 == false || zyje4==true && wrog4_x != 125)
			{
				zyje4 = true;
				wrog4_x--;
			}
			{
				if (wrog4_x % 10 < 10)
				{
					wrog_ruch = 0;
				}
				if (wrog4_x % 20 >= 10 && wrog4_x % 20 < 20)
				{
					wrog_ruch = 1;
				}
				if (wrog4_x % 30 >= 20 && wrog4_x % 30 < 30)
				{
					wrog_ruch = 2;
				}
				if (wrog4_x % 40 >= 30 && wrog4_x % 40 < 40)
				{
					wrog_ruch = 3;
				}
				if (wrog4_x % 50 >= 40 && wrog4_x % 50 < 50)
				{
					wrog_ruch = 4;
				}
				if (wrog4_x % 60 >= 50 && wrog4_x % 60 < 60)
				{
					wrog_ruch = 5;
				}
				if (wrog4_x % 70 >= 60 && wrog4_x % 70 < 70)
				{
					wrog_ruch = 6;
				}
				if (wrog4_x % 80 >= 70 && wrog4_x % 80 < 80)
				{
					wrog_ruch = 7;
				}
				if (wrog4_x % 90 >= 80 && wrog4_x % 90 < 90)
				{
					wrog_ruch = 8;
				}

				if (wrog_ruch == 0)
				{
					al_draw_bitmap(wrog0, wrog4_x, wrog4_y, 0);
				}
				if (wrog_ruch == 1)
				{
					al_draw_bitmap(wrog1, wrog4_x, wrog4_y, 0);
				}
				if (wrog_ruch == 2)
				{
					al_draw_bitmap(wrog2, wrog4_x, wrog4_y, 0);
				}
				if (wrog_ruch == 3)
				{
					al_draw_bitmap(wrog3, wrog4_x, wrog4_y, 0);
				}
				if (wrog_ruch == 4)
				{
					al_draw_bitmap(wrog4, wrog4_x, wrog4_y, 0);
				}
				if (wrog_ruch == 5)
				{
					al_draw_bitmap(wrog5, wrog4_x, wrog4_y, 0);
				}
				if (wrog_ruch == 6)
				{
					al_draw_bitmap(wrog6, wrog4_x, wrog4_y, 0);
				}
				if (wrog_ruch == 7)
				{
					al_draw_bitmap(wrog7, wrog4_x, wrog4_y, 0);
				}
				if (wrog_ruch == 8)
				{
					al_draw_bitmap(wrog8, wrog4_x, wrog4_y, 0);
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

			
			//uderzenie wroga
			
			if (wrog_x == 125 )
			{
				
				if (pomocnicza == 10)
				{
					wrog_x = (rand() % 200 + 1200);
				}
				al_draw_bitmap(wybuch, wrog_x, wrog_y,0);
				pomocnicza++;
				if (pomocnicza == 11)
				{
					pomocnicza = 0;
					hp_gracza--;
				}
			}

			if (wrog1_x == 125)
			{
				if (pomocnicza1 == 10)
				wrog1_x = (rand() % 150 + 800);
				al_draw_bitmap(wybuch, wrog1_x, wrog1_y,0);
				pomocnicza1++;
				if (pomocnicza1 == 11)
				{
					hp_gracza--;
					pomocnicza1 = 0;
				}
			}

			if (wrog2_x == 125)
			{
				if (pomocnicza2 == 10)
				wrog2_x = (rand() % 250 + 800);
				al_draw_bitmap(wybuch, wrog2_x, wrog2_y,0);
				pomocnicza2++;
				if (pomocnicza2 == 11)
				{
					pomocnicza2 = 0;
					hp_gracza--;
				}
			}
			if (wrog3_x == 125)
			{
		
				if (pomocnicza3 == 10)
				wrog3_x = (rand() % 250 + 800);
				al_draw_bitmap(wybuch, wrog3_x, wrog3_y,0);
				pomocnicza3++;
				if (pomocnicza3 == 11)
				{
					pomocnicza3 = 0;
					hp_gracza--;
				}
			}
			if (wrog4_x == 125)
			{

				
				if (pomocnicza4 == 10)
				wrog4_x = (rand() % 250 + 800);
				al_draw_bitmap(wybuch, wrog4_x, wrog4_y,0);
				pomocnicza4++;
				if (pomocnicza4 == 11)
				{
					pomocnicza4 = 0;
					hp_gracza--;
				}
			}
			//animacja w prawo
	
				postac_ruch = 0;
			if (postac_ruch == 0 && !keys[RIGHT] && (!keys[UP] && !keys[DOWN]) && !keys[LEFT])
			{
				al_draw_bitmap(postac, postac_x, postac_y, 0);
			}
			if (!keys[SPACE] && !keys[LEFT] && ((keys[UP] || keys[DOWN] || keys[RIGHT])))
			{
				
				if (postac_x % 10 >= 0 && postac_x % 10 < 10)
				{
					postac_ruch = 1;
				}
				if (postac_x % 20 >= 10 && postac_x % 20 < 20 )
				{
					postac_ruch = 2;
				}
				if (postac_x % 30 >= 20 && postac_x % 30 < 30)
				{
					postac_ruch = 3;
				}
				if (postac_x % 40 >= 30 && postac_x % 40 < 40)
				{
					postac_ruch = 4;
				}
				if (postac_x % 50 >= 40 && postac_x % 50 < 50)
				{
					postac_ruch = 5;
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

			//animacja w prawo POSTAC2
			postac2_ruch = 0;
			if (postac2_ruch == 0 && !keys[D] && (!keys[W] && !keys[S]) && !keys[A])
			{
				al_draw_bitmap(postac20, postac2_x, postac2_y, 0);
			}
			if (!keys[LSHIFT] && !keys[A] && ((keys[W] || keys[S] || keys[D])))
			{

				if (postac2_x % 10 >= 0 && postac2_x % 10 < 10)
				{
					postac2_ruch = 1;
				}
				if (postac2_x % 20 >= 10 && postac2_x % 20 < 20)
				{
					postac2_ruch = 2;
				}
				if (postac2_x % 30 >= 20 && postac2_x % 30 < 30)
				{
					postac2_ruch = 3;
				}
				if (postac2_x % 40 >= 30 && postac2_x % 40 < 40)
				{
					postac2_ruch = 4;
				}
				if (postac2_x % 50 >= 40 && postac2_x % 50 < 50)
				{
					postac2_ruch = 5;
				}


				if (postac2_ruch == 1 && keys[D])
				{
					al_draw_bitmap(postac21, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 2 && keys[D])
				{
					al_draw_bitmap(postac22, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 3 && keys[D])
				{
					al_draw_bitmap(postac23, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 4 && keys[D])
				{
					al_draw_bitmap(postac24, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 5 && keys[D])
				{
					al_draw_bitmap(postac25, postac2_x, postac2_y, 0);
				}
			}


			//animacja pion
			
			if ((keys[UP] || keys[DOWN]) && !keys[LEFT] && !keys[RIGHT])
			{
				if (postac_y % 20 >= 10 && postac_y % 20 < 20)
				{
					postac_ruch = 1;
				}
				if (postac_y % 30 >= 20 && postac_y % 30 < 30)
				{
					postac_ruch = 2;
				}
				if (postac_y % 40 >= 30 && postac_y % 40 < 40)
				{
					postac_ruch = 3;
				}
				if (postac_y % 50 >= 40 && postac_y % 50 < 50)
				{
					postac_ruch = 4;
				}
				if (postac_y % 60 >= 50 && postac_y % 60 < 60)
				{
					postac_ruch = 5;
				}

				if (postac_ruch == 1)
				{
					al_draw_bitmap(postac1, postac_x, postac_y, 0);
				}
				if (postac_ruch == 2)
				{
					al_draw_bitmap(postac2, postac_x, postac_y, 0);
				}
				if (postac_ruch == 3)
				{
					al_draw_bitmap(postac3, postac_x, postac_y, 0);
				}
				if (postac_ruch == 4)
				{
					al_draw_bitmap(postac4, postac_x, postac_y, 0);
				}
				if (postac_ruch == 5)
				{
					al_draw_bitmap(postac5, postac_x, postac_y, 0);
				}
			}

			//animacja pion POSTAC2
			if ((keys[W] || keys[S]) && !keys[A] && !keys[D])
			{
				if (postac2_y % 20 >= 10 && postac2_y % 20 < 20)
				{
					postac2_ruch = 1;
				}
				if (postac2_y % 30 >= 20 && postac2_y % 30 < 30)
				{
					postac2_ruch = 2;
				}
				if (postac2_y % 40 >= 30 && postac2_y % 40 < 40)
				{
					postac2_ruch = 3;
				}
				if (postac2_y % 50 >= 40 && postac2_y % 50 < 50)
				{
					postac2_ruch = 4;
				}
				if (postac2_y % 60 >= 50 && postac2_y % 60 < 60)
				{
					postac2_ruch = 5;
				}

				if (postac2_ruch == 1)
				{
					al_draw_bitmap(postac21, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 2)
				{
					al_draw_bitmap(postac22, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 3)
				{
					al_draw_bitmap(postac23, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 4)
				{
					al_draw_bitmap(postac24, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 5)
				{
					al_draw_bitmap(postac25, postac2_x, postac2_y, 0);
				}
			}
			//animacja strzelania
			if (keys[SPACE] && !keys[LEFT])
			{
				if (!keys[RIGHT] && (!keys[UP] && !keys[DOWN]))
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
			//animacja strzelania POSTAC2
			if (keys[LSHIFT] && !keys[A])
			{
				if (!keys[D] && (!keys[W] && !keys[S]))
				{
					postac2_ruch = 0;
				}
				if (postac2_x % 20 >= 10 && postac2_x % 20 < 20)
				{
					postac2_ruch = 1;
				}
				if (postac2_x % 30 >= 20 && postac2_x % 30 < 30)
				{
					postac2_ruch = 2;
				}
				if (postac2_x % 40 >= 30 && postac2_x % 40 < 40)
				{
					postac2_ruch = 3;
				}
				if (postac2_x % 50 >= 40 && postac2_x % 50 < 50)
				{
					postac2_ruch = 4;
				}
				if (postac2_x % 60 >= 50 && postac2_x % 60 < 60)
				{
					postac2_ruch = 5;
				}

				if (postac2_ruch == 0 || !keys[D] && keys[LSHIFT])
				{
					al_draw_bitmap(postac20_s, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 1 && keys[D])
				{
					al_draw_bitmap(postac21_s, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 2 && keys[D])
				{
					al_draw_bitmap(postac22_s, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 3 && keys[D])
				{
					al_draw_bitmap(postac23_s, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 4 && keys[D])
				{
					al_draw_bitmap(postac24_s, postac2_x, postac2_y, 0);
				}
				if (postac2_ruch == 5 && keys[D])
				{
					al_draw_bitmap(postac25_s, postac2_x, postac2_y, 0);
				}
			}
				//back animacja

				if (!keys[SPACE] && keys[LEFT] || (keys[UP] || keys[DOWN]) )
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
				//back animacja POSTAC2

				if (!keys[LSHIFT] && keys[A] || (keys[W] || keys[S]))
				{

					if (postac2_x % 20 >= 10 && postac2_x % 20 < 20)
					{
						postac2_ruch = 1;
					}
					if (postac2_x % 30 >= 20 && postac2_x % 30 < 30)
					{
						postac2_ruch = 2;
					}
					if (postac2_x % 40 >= 30 && postac2_x % 40 < 40)
					{
						postac2_ruch = 3;
					}
					if (postac2_x % 50 >= 40 && postac2_x % 50 < 50)
					{
						postac2_ruch = 5;
					}


					if (postac2_ruch == 1 && keys[A])
					{
						al_draw_bitmap(postac21_o, postac2_x, postac2_y, 0);
					}
					if (postac2_ruch == 2 && keys[A])
					{
						al_draw_bitmap(postac22_o, postac2_x, postac2_y, 0);
					}
					if (postac2_ruch == 3 && keys[A])
					{
						al_draw_bitmap(postac23_o, postac2_x, postac2_y, 0);
					}
					if (postac2_ruch == 5 && keys[A])
					{
						al_draw_bitmap(postac25_o, postac2_x, postac2_y, 0);
					}
				}
		
			

			//interakcja z wrogiem1
			if (keys[SPACE] && naboje>0 || keys[LSHIFT])
			{
				if (postac_x <= wrog_x && postac_y > wrog_y - 30 && postac_y < wrog_y + 30 && keys[SPACE] || (postac2_x <= wrog_x && postac2_y > wrog_y - 30 && postac2_y < wrog_y + 30 && keys[LSHIFT]))
				{
					hp_przeciwnika = hp_przeciwnika - 1;
					keys[SPACE] = false;
					keys[LSHIFT] = false;


					if (hp_przeciwnika == 0)
					{
						wrog_x = (rand() % 200) + 800;
						ilosc_wrogow = (rand() % 5) + 1;
						hp_przeciwnika = 5;
						ilosc_zabic++;
						licz_monety = false;
						
					}
				}
				//interakcja z wrogiem2
				if (postac_x <= wrog1_x && postac_y > wrog1_y - 30 && postac_y < wrog1_y + 30 && keys[SPACE] || (postac2_x <= wrog1_x && postac2_y > wrog1_y - 30 && postac2_y < wrog1_y + 30 && keys[LSHIFT]))
				{
					hp_przeciwnika1 = hp_przeciwnika1 - 1;
					keys[SPACE] = false;
					keys[LSHIFT] = false;


					if (hp_przeciwnika1 == 0)
					{
						wrog1_x = (rand() % 150) + 800;
						wrog1_y =  (rand() % 100) + 100;
						hp_przeciwnika1 = 5;
						ilosc_zabic++;
						zyje1 = false;


					}
				}
				//interakcja z wrogiem3
				if (postac_x <= wrog2_x && postac_y > wrog2_y - 30 && postac_y < wrog2_y + 30 && keys[SPACE] || (postac2_x <= wrog2_x && postac2_y > wrog2_y - 30 && postac2_y < wrog2_y + 30 && keys[LSHIFT]))
				{
					hp_przeciwnika2 = hp_przeciwnika2 - 1;
					keys[SPACE] = false;
					keys[LSHIFT] = false;


					if (hp_przeciwnika2 == 0)
					{
						wrog2_x = (rand() % 350) + 800;
						wrog2_y = (rand() % 100) + 70;
						hp_przeciwnika2 = 5;
						ilosc_zabic++;
						zyje2 = false;
					}
				}
				//interakcja z wrogiem 4
				if (postac_x <= wrog3_x && postac_y > wrog3_y - 30 && postac_y < wrog3_y + 30 && keys[SPACE] || (postac2_x <= wrog3_x && postac2_y > wrog3_y - 30 && postac2_y < wrog3_y + 30 && keys[LSHIFT]))
				{
					hp_przeciwnika3 = hp_przeciwnika3 - 1;
					keys[SPACE] = false;
					keys[LSHIFT] = false;


					if (hp_przeciwnika3 == 0)
					{
						wrog3_x = (rand() % 350) + 800;
						wrog3_y = (rand() % 100) + 170;
						hp_przeciwnika3 = 5;
						ilosc_zabic++;
						zyje3 = false;

					}
				}
				//interakcja z wrogiem 5
				if (postac_x <= wrog4_x && postac_y > wrog4_y - 30 && postac_y < wrog4_y + 30 && keys[SPACE]|| (postac2_x <= wrog4_x && postac2_y > wrog4_y - 30 && postac2_y < wrog4_y + 30 && keys[LSHIFT]))
				{
					hp_przeciwnika4 = hp_przeciwnika4 - 1;
					keys[SPACE] = false;
					keys[LSHIFT] = false;


					if (hp_przeciwnika4 == 0)
					{
						wrog4_x = (rand() % 250) + 800;
						wrog4_y = (rand() % 80) + 220;
						hp_przeciwnika4 = 5;
						ilosc_zabic++;
						zyje4 = false;

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
					hp_gracza = 10;
					postac_x = 50;
					wrog_x = (rand() % 200) + 800;
					wrog1_x = (rand() % 150) + 800;
					wrog2_x = (rand() % 250) + 800;
					ilosc_monet = 0;
					ilosc_zabic = 0;
					
					
				}
			}
			//fonty
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 10, 10, 0, "x=%d , y=%d", postac_x, postac_y);
				al_draw_textf(font8, al_map_rgb(0, 0, 0), wrog_x + 10, wrog_y - 5, 0, "HP: %d", hp_przeciwnika);
				al_draw_textf(font8, al_map_rgb(0, 0, 0), wrog1_x + 10, wrog1_y - 5, 0, "HP: %d", hp_przeciwnika1);
				al_draw_textf(font8, al_map_rgb(0, 0, 0), wrog2_x + 10, wrog2_y - 5, 0, "HP: %d", hp_przeciwnika2);
				al_draw_textf(font8, al_map_rgb(0, 0, 0), wrog3_x + 10, wrog3_y - 5, 0, "HP: %d", hp_przeciwnika3);
				al_draw_textf(font8, al_map_rgb(0, 0, 0), wrog4_x + 10, wrog4_y - 5, 0, "HP: %d", hp_przeciwnika4);
				al_draw_textf(font8, al_map_rgb(0, 0, 0), postac_x + 10, postac_y - 10, 0, "Player 1");
				al_draw_textf(font8, al_map_rgb(0, 0, 0), postac2_x + 10, postac2_y - 10, 0, "Player 2");
		
			al_draw_textf(font_ttf, al_map_rgb(255, 255, 255), 290, 400, 0, "%d", hp_gracza);
			al_draw_textf(font_ttf, al_map_rgb(255, 255, 255), 510, 400, 0, "%d", ilosc_zabic);
			al_draw_textf(font_ttf, al_map_rgb(255, 255, 255), 660, 400, 0, "%d", ilosc_monet);
			al_draw_textf(font8, al_map_rgb(0, 0, 0), 630, 50, 0, "Ilosc wrogow: %d", ilosc_wrogow);
			al_flip_display();
		}
		
	}
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						
	
	return 0;
}