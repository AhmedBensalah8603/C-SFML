#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<vector>
#include<random>
#include"Ziwziw.h"
#include"Chejra.h"
using namespace sf;
class Game
{
	Texture bg_texture, ground_texture, game_over,ready_tex,replay_tex,help_tex,BM_tex,GM_tex,SM_tex,new_tex,pause_tex,resume_tex,pause_tab_texture,sound1_tx,sound2_tx;
	Sprite bg_sprite, ground_sprite1, ground_sprite2, game_over_sprite,ready_spr,replay_sp,help_sp,BM_sp,GM_sp, SM_sp,new_sp,pause_sp,resume_sp,pause_tab_sprite,sound1_sp,sound2_sp;
	Ziwziw Asfour;
	bool is_enter_pressed, run_game, ziwziw_t3adda ,is_new,is_paused=false ,sound_on=false , is_help=false;
	const int move_speed = 270;
	void draw();
	void moveGround(Time&);
	void doProcessing(Time& dt);
	void checkCollisions();
	void restartGame();
	void checkScore();
	std::string toString(int);
	int Chejra_counter, Chejra_frequency, score, best_score;
	std::vector<Chejra> Chejrat;
	std::random_device rd;
	std::uniform_int_distribution<int> dist{ 250,550 };
	Font font , font2 ,font3;
	Text score_text, start_text,best_score_text,flappy_ziw,text_help,Good_luck;
	Music deadSound, flapSound, scoreSound, bgSound ,pauseSound;
    std::string help_msg;
    RectangleShape border;
public:
	Game(RenderWindow&);
	RenderWindow& win;
	void startGameLoop();
};