
#include "Entity.h"
/*
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
*/
/* Implémentation des méthodes de la classe Entity */
Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
	SDL_QueryTexture(p_tex, NULL, NULL, &currentFrame.w, &currentFrame.h);
}


/* Setters & getters */
void Entity::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

void Entity::setScale(float w, float h)
{
	scale.x = w;
	scale.y = h;
}
void Entity::setAngle(float p_angle)
{
	angle = p_angle;
}

/* Mise à jour */
void Entity::update(double deltaTime)
{

}

SDL_Texture* Entity::getTex()
{
	return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}