/* Inclusion unique du fichier dans la compilation du projet */
#pragma once

/* Inclusion des headers des autres classes du projet */
#include "Entity.h"
#include "Math.h"

/* Création de la classe Entity héritée de la classe mère Entity */
class Hole : public Entity
{
    public: 
        Hole(Vector2f p_pos, SDL_Texture* p_tex);
        
    private:
};