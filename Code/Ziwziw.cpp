#include"Ziwziw.h"
#include"Dimension.h"
Ziwziw::Ziwziw() :
	gravity(11),
	flap_speed(300),
	anim_counter(0),
	texture_switch(1),
	should_fly(false)
{
	textures[0].loadFromFile("assets/bird_s1 (1).png");//assets/1.png
	textures[1].loadFromFile("assets/bird_s2 (1).png");
	textures[2].loadFromFile("assets/bird_s1 (1).png");

	Ziwziw_Sprite.setTexture(textures[0]);
	Ziwziw_Sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
    resetZiwziwPosition();
}

void Ziwziw::setShouldFly(bool should_fly)
{
	this->should_fly = should_fly;
}

void Ziwziw::flapZiwziw(Time& dt)
{
	velocity_y = -flap_speed * dt.asSeconds();
}

void Ziwziw::resetZiwziwPosition()
{
	Ziwziw_Sprite.setPosition(260, 270); //100,99
	velocity_y = 0;
}

void Ziwziw::update(Time& dt)
{
	if (Ziwziw_Sprite.getGlobalBounds().top < 548 && should_fly)
	{
		if (anim_counter == 5)
		{
			Ziwziw_Sprite.setTexture(textures[texture_switch]);
			if (texture_switch == 2) texture_switch = 0;
			else if (texture_switch == 0) texture_switch = 1;
			else texture_switch = 2;
			anim_counter = 0;
		}
		anim_counter++;

		velocity_y += (gravity )  * dt.asSeconds() ;
		Ziwziw_Sprite.move(0, velocity_y);

		if (Ziwziw_Sprite.getGlobalBounds().top < 0)
            //
			Ziwziw_Sprite.setPosition(100, 0);
            //Ziwziw_Sprite.setTexture(textures[3]);
	}
}

float Ziwziw::getRightBound()
{
	return Ziwziw_Sprite.getGlobalBounds().left + Ziwziw_Sprite.getGlobalBounds().width;
}