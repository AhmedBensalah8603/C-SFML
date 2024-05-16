#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Ziwziw
{

	const int gravity;
	const int flap_speed;
	float velocity_y;
	int anim_counter, texture_switch;
	bool should_fly;
public:
    Texture textures[3];
	Sprite Ziwziw_Sprite;
	Ziwziw();
	void setShouldFly(bool);
	void flapZiwziw(Time &dt);
	void resetZiwziwPosition();
	void update(Time&);
	float getRightBound();

};