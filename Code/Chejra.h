#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Chejra
{
	static Texture texture_down, texture_up;
	static int Chejra_distance, move_speed;
public:
	Chejra(int);
	Sprite Chejra_louta, Chejra_fou9;
	static void loadTextures();
	void update(Time&);
	float getRightBound();
};