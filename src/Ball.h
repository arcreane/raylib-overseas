/* Inclusion unique du fichier dans la compilation du projet */
#pragma once

/* Inclusion de la classe Vector pour la STL*/
#include <vector>

/* Inclusion des headers des autres classes du projet */
#include "Hole.h"
#include "Tile.h"
#include "Entity.h"

/* Inclusion de la librairie externe SDL2 */
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

/* Création de la classe Ball héritée de la classe mère Entity */
class Ball : public Entity {
    public:
        /* Constructeur par paramètres de la classe Ball */
        Ball(Vector2f p_pos, SDL_Texture* p_tex, SDL_Texture* p_pointTex, SDL_Texture* p_powerMTexFG, SDL_Texture* p_powerMTexBG, int p_index);
        
        /* Méthodes publiques de la classe */
        Vector2f& getVelocity();
        Vector2f& getInitialMousePos();
        std::vector<Entity> getPoints();
        std::vector<Entity> getPowerBar();
        int getStrokes();
        bool isWin();
        void setWin(bool p_win);
        void setInitialMousePos(float x, float y);
        void setVelocity(float x, float y);
        void setLaunchedVelocity(float x, float y);
        void update(double deltaTime, bool mouseDown, bool mousePressed, std::vector<Tile> tiles, Hole hole,Mix_Chunk* chargeSfx, Mix_Chunk* swingSfx, Mix_Chunk* holeSfx);
    
    private:
        /* Attributs privés de la classe */
        Vector2f velocity;
        Vector2f target;
        Vector2f launchedVelocity;
        float velocity1D;
        float launchedVelocity1D;
        Vector2f initialMousePos;
        bool canMove = true;
        bool playedSwingFx = true;
        int index;
        int strokes = 0;
        int dirX = 1;
        int dirY = 1;
        bool win = false;
        float friction;
        std::vector<Entity> points;
        std::vector<Entity> powerBar;
};