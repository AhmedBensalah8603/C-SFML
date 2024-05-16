#include"Chejra.h"
#include"Dimension.h"

Texture Chejra::texture_down, Chejra::texture_up;
int Chejra::Chejra_distance = 170, Chejra::move_speed = 400;

Chejra::Chejra(int y_pos)
{
	Chejra_fou9.setTexture(texture_down);
	Chejra_louta.setTexture(texture_up);

	Chejra_fou9.setScale(SCALE_FACTOR, SCALE_FACTOR);
	Chejra_louta.setScale(SCALE_FACTOR, SCALE_FACTOR);

	Chejra_louta.setPosition(WIN_WIDTH, y_pos);
	Chejra_fou9.setPosition(WIN_WIDTH, y_pos - Chejra_distance - Chejra_louta.getGlobalBounds().height);
}

void Chejra::loadTextures()
{
	texture_down.loadFromFile("assets/wood_log_down.png");
	texture_up.loadFromFile("assets/wood_log_up.png");
}

void Chejra::update(Time& dt)
{
	Chejra_louta.move(-move_speed * dt.asSeconds(), 0.f);
	Chejra_fou9.move(-move_speed * dt.asSeconds(), 0.f);
}
float Chejra::getRightBound()
{
	return Chejra_fou9.getGlobalBounds().left + Chejra_fou9.getGlobalBounds().width;
}