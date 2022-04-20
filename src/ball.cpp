/* Inclusion du header de la classe Ball */
#include "Ball.h"

/**
 * TODO: Generalize the ball class according to UML and create subclasses from this generalized class
 * TODO: Colored balls subsclasss are expected to be implented in another files (.h /.cpp)
 */

/* Implémentation des méthodes de la classe Ball */
Ball::Ball(Vector2f p_pos, SDL_Texture* p_tex, SDL_Texture* p_pointTex, SDL_Texture* p_powerMTexFG, SDL_Texture* p_powerMTexBG, int p_index) : Entity(p_pos, p_tex) {
    index = p_index;
    points.push_back(Entity(Vector2f(-64, -64), p_pointTex));
    powerBar.push_back(Entity(Vector2f(-64, -64), p_powerMTexBG));
    powerBar.push_back(Entity(Vector2f(-64, -64), p_powerMTexFG));
}

/* Ascesseur (getter/setter) des attributs privés de la classe */
Vector2f& Ball::getVelocity() {
	return velocity;
}

Vector2f& Ball::getInitialMousePos() {
    return initialMousePos;
}

std::vector<Entity> Ball::getPoints() {
    return points;
}

std::vector<Entity> Ball::getPowerBar() {
    return powerBar;
}

int Ball::getStrokes() {
    return strokes;
}

bool Ball::isWin() {
    return win;
}

void Ball::setVelocity(float x, float y) {
    velocity.x = x;
    velocity.y = y;
}

void Ball::setLaunchedVelocity(float x, float y) {
    launchedVelocity.x = x;
    launchedVelocity.y = y;
}

void Ball::setInitialMousePos(float x, float y) {
    initialMousePos.x = x;
    initialMousePos.y = y;
}

void Ball::setWin(bool p_win) {
    win = p_win;
}