/* Inclusion unique du fichier dans la compilation du projet */
#pragma once

/* Inclusion de la librairie externe SDL2 */
#include "Entity.h"

/* Création de la classe Tile héritée de la classe mère Entity */
class Tile : public Entity {
    public: 
    /* Constructeur par paramètres de la classe Ball */
    Tile(Vector2f p_pos, SDL_Texture* p_tex);
};