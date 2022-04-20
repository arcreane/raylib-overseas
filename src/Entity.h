#pragma once

/* Librairie SDL */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* Inclusion des headers nécessaires*/
#include "Math.h"

/* Création de la classe Entity */
class Entity
{
public:
	/* Cosntructeur par paramètres */
	Entity(Vector2f p_pos, SDL_Texture* p_tex);

	/* Méthodes publiques */
	Vector2f& getPos()
	{
		return pos;
	}
	float getAngle()
	{
		return angle;
	}
	Vector2f getScale()
	{
		return scale;
	}
	void setPos(float x, float y);
	void setScale(float w, float h);
	void setAngle(float angle);
	void update(double deltaTime);
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();

private:
	/* Attributs privés */
	Vector2f pos;
	float angle = 0;
	Vector2f scale = Vector2f(1, 1);
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};